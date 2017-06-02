#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <regex.h>
#include <getopt.h>
#include "FixPathInclude.h"
#include "config.h"


class RegEx : public regex_t
{
    public:
        RegEx(const char* expr)
        {
            int ret = regcomp(this, expr, REG_EXTENDED);
            if (ret) 
            {
                char errorBuffer[100];
                regerror(ret, this, errorBuffer, sizeof(errorBuffer));
                cerr << "regcomb(..., \"" << expr << "\", REG_EXTENDED) failed with '" 
                    << errorBuffer << "'" << endl;
                exit(1);
            }    
        }
};

class Option : public option
{
    static string descr[64];
    static const char* argname[64];
    static int cnt;

    public:
    Option(const char* n, int ha, int* f, int v, const char* d = "", const char* an = "") 
    {
	    name = n;
        has_arg = ha;
        flag = f;
	    val = v;
        argname[cnt] = an;
        string tmp = d;
        while (tmp.length() > 41)
        {
            int pos = tmp.rfind(' ', 41);
            if (pos == string::npos)
                break;
            descr[cnt] += tmp.substr(0, pos);
            descr[cnt] += '\n';
            descr[cnt].append(39, ' ');
            tmp.erase(0, pos+1);
        }
        descr[cnt++] += tmp;
    }
    void PrintUsage(const string& d, const char* an) const
    {
        if (has_arg == 0)
            fprintf(stdout, "  --%-15s (-%c)               %s\n", name, val, d.c_str());
        else if (has_arg == 1)
            fprintf(stdout, "  --%-15s (-%c) %-12s  %s\n", name, val, an, d.c_str());
        else if (has_arg == 2)
            fprintf(stdout, "  --%-15s (-%c) [%-10s] %s\n", name, val, an, d.c_str());
    }
    void Print(int ha, const char* an) const
    {
        if (has_arg == 0 && has_arg == ha)
            fprintf(stdout, "%c", val);
        else if (has_arg == 1 && has_arg == ha)
            fprintf(stdout, " -%c %s", val, an);
        else if (has_arg == 2 && has_arg == ha)
            fprintf(stdout, " -%c [%s]", val, an);
    }
    static void PrintUsage(const Option* options)
    {
        fprintf(stdout, "Usage: \n");
        fprintf(stdout, "fixpath --longoptions -");
        
        for (int i = 0; i < cnt-1; i++)
        {
            options[i].Print(0, argname[i]);
        }
        
        for (int i = 0; i < cnt-1; i++)
        {
            options[i].Print(1, argname[i]);
        }
        
        for (int i = 0; i < cnt-1; i++)
        {
            options[i].Print(2, argname[i]);
        }
        fprintf(stdout, "\n\n");
        
        fprintf(stdout, "    %-20s %-13s %s\n", "long option", "arg", "Description");
        for (int i = 0; i < cnt-1; i++)
        {
            options[i].PrintUsage(descr[i], argname[i]);
        }

        string tmp =
            "Fixpath processes the output of a make process. When nested projects are used "
            "the resolving of the file names in some IDE's fails. The reported error/warning "
            "location is relative to the build directory which varies. This is resolved by "
            "processing the Entering and Leaving directory statements (use make -w). With "
            "this information the paths are made absolute. Normally fixpath is used in the "
            "following manner: `make -j4 -w 2>&1 | fixpath` It processes the stdin and puts "
            "the altered output to stdout. There are options to perform some filtering at the "
            "same time, these options are described above. Lines starting with: "
            "'clang', 'gcc', 'clang++', 'g++', 'c++', 'CC' and 'GCC' are classified as "
            "compiler lines.";

        string descr;
        while (tmp.length() > 80)
        {
            int pos = tmp.rfind(' ', 80);
            if (pos == string::npos)
                break;
            descr += tmp.substr(0, pos);
            descr += '\n';
            tmp.erase(0, pos+1);
        }
        descr += tmp;

        cout << descr << endl;
    }
    static string GetOpt(const Option* options)
    {
        string opt;
        for (int i = 0; i < cnt-1; i++)
        {
            if (64 < options[i].val && options[i].val < 123)
            {
                opt += char(options[i].val);
                if (options[i].has_arg)
                {
                    opt += ':';
                }
            }
        }

        return opt;
    }
};

int Option::cnt = 0;
string Option::descr[64];
const char* Option::argname[64];

int main(int argc, char** argv)
{
    bool removeOptionsFromLine = 0;
    bool removeSameOptionsFromLine = 0;
    bool skipOtherLine = 0;
    bool skipCompilerLine = 0;
    bool skipDirectoryLine = 0;
    bool appendReadyLine = 0;
    
    static Option options[] = { 
        Option("help",            no_argument,        0,  'h', 
            "Print this help."), 
        Option("version",         no_argument,        0,  'v', 
            "Shows the current version of fixpath."),
        Option("remove_options",   no_argument,        0,  'x', 
            "Removes the options from recognized compiler lines."),
        Option("remove_same_opt",  no_argument,        0,  's', 
            "Removes the options from recognized compiler line if they are the same as on the previous compiler line."),
        Option("skip_other",      no_argument,        0,  'o', 
            "Skip lines that are not recognized as compiler or Entering/Leaving directory lines."),
        Option("skip_compiler",   no_argument,        0,  'c', 
            "Skip lines that are recognized as compiler lines."),
        Option("skip_directory",  no_argument,        0,  'd', 
            "Skip lines that are recognized as Entering/Leaving directory lines."),
        Option("skip_all",        no_argument,        0,  'a', 
            "Skip all lines from output."),
        Option("skip_most",       no_argument,        0,  'm', 
            "Skip all lines from output except those recognized as compiler lines."),
        Option("append_ready",    no_argument,        0,  'r', 
            "Append a line at end, so its clear we are ready."),
//        Option("input",           required_argument,  0,  'f', "Use infile instead of stdin.", "infile"),
//        Option("output",          required_argument,  0,  'o', "Use outfile instead of stdout.", "infile"),
        Option(0,                 0,                  0,  0)
    };

    int long_index =0;
    int opt;
    while ((opt = getopt_long(argc, argv, Option::GetOpt(options).c_str(), 
                   options, &long_index )) != -1) {
        switch (opt) 
        {
            case 'x' : 
                removeOptionsFromLine = true; 
                removeSameOptionsFromLine = false; 
                break;
            case 's' : 
                removeSameOptionsFromLine = true; 
                removeOptionsFromLine = false; 
                break;
            case 'o' : 
                skipOtherLine = true; 
                break;
            case 'c' : 
                skipCompilerLine = true; 
                break;
            case 'd' : 
                skipDirectoryLine = true; 
                break;
            case 'a' : 
                skipOtherLine = true; 
                skipDirectoryLine = true; 
                skipCompilerLine = true; 
                break;
            case 'm' : 
                skipOtherLine = true; 
                skipDirectoryLine = true; 
                break;
            case 'r' : 
                appendReadyLine = true; 
                break;
            /*
            case 'f' : 
                infile = optarg; 
                break;
            case 'o' : 
                outfile = optarg;
                break;
                */
            case 'v' : 
                fprintf(stdout, "%s\n", PACKAGE_STRING);
                exit(0);
                break;
            case ':':
            case '?':
            case 'h' :
            default:
                Option::PrintUsage(options);
                exit(0);
                break;
        }
    }

/*    
    cout << "removeOptionsFromLine: " << removeOptionsFromLine << endl;
    cout << "skipOtherLine: " << skipOtherLine << endl;
    cout << "skipCompilerLine: " << skipCompilerLine << endl;
    cout << "skipDirectoryLine: " << skipDirectoryLine << endl;
    cout << "appendReadyLine: " << appendReadyLine << endl;
*/
    // Recognize the warning/error line
    RegEx regex_we("^(.*):([0-9]+):([0-9]+): +(warning|error): +(.*)$");

    // make: Entering|Leaving directory `/Users/xaljox/GitHub/bash/bash-4.4/build_mac'
    RegEx regex_dir("^make(\\[[0-9]+\\])?: ((Entering)|(Leaving)) directory ['`](.*)'");
    
    // Line where a C/C++ compiler is called
    RegEx regex_com("^(clang|gcc|clang\\+\\+|g\\+\\+|c\\+\\+|CC|GCC)((( +-[a-zA-Z][a-zA-Z_0-9\\.\\/\\-]*)(=[^ ]+)?)*) +(.*)$");
        
    bool errorWarningMode = false;
    
    FixPath fixPath;
    
    string common;
    string prevCommon;
    regmatch_t match[10];
    const int maxLineLen = 4096;
    char line[maxLineLen];
    while (cin.getline(line, maxLineLen))
    {
        if (regexec(&regex_we, line, 6, match, 0) == 0)
        {
            errorWarningMode = true;
            
            line[match[1].rm_eo] = line[match[2].rm_eo] = line[match[3].rm_eo] = 
                line[match[4].rm_eo] = line[match[5].rm_eo] = '\0';

            string absPath = fixPath.ResolvePath(&line[match[1].rm_so]);
            cout << absPath << ':' << &line[match[2].rm_so] << ':' << &line[match[3].rm_so] << ": " 
                << &line[match[4].rm_so] << ": " << &line[match[5].rm_so] << endl;
        }
        else if (regexec(&regex_dir, line, 6, match, 0) == 0)
        {
            errorWarningMode = false;
            if (skipDirectoryLine == false)
            {
                cout << line << endl;
            }
            line[match[5].rm_eo] = '\0';
            if (match[3].rm_so != -1)
            {
                fixPath.EnterDirectory(&line[match[5].rm_so]);
            }
            else
            {
               fixPath.LeaveDirectory(&line[match[5].rm_so]);
            }
        }
        else if (regexec(&regex_com, line, 7, match, 0) == 0)
        {
            errorWarningMode = false;
            if (skipCompilerLine == false)
            {
                if (removeOptionsFromLine || removeSameOptionsFromLine)
                {
                    line[match[2].rm_eo] = '\0';
                    if (removeSameOptionsFromLine)
                    {
                        common = &line[match[2].rm_so];
                    }
            
                    if (removeOptionsFromLine || prevCommon == common)
                    {
                        line[match[1].rm_eo] = '\0';
                        cout << &line[match[1].rm_so];
                
                        if (match[6].rm_so != -1)
                        {
                            cout << " ... " << &line[match[6].rm_so];
                        }
                        cout << endl;
                    }
                    else
                    {
                        cout << line << endl;
                        prevCommon = common;
                    }
                }
                else
                {
                    cout << line << endl;
                }            
            }
        }
        else
        {
            if (errorWarningMode && line[0] != ' ')
            {
                errorWarningMode = false;
            }
        
            if (skipOtherLine == false || (errorWarningMode && line[0] == ' '))
            {
                cout << line << endl;            
            }
        }
        
        cout << flush;
    }
    if (appendReadyLine)
    {
        cout << "-------------------- Ready --------------------" << endl << flush;
    }
    
    return 0;
}

