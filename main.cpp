#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <regex.h>
#include <getopt.h>
#include "FixPathInclude.h"


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
    static const char* descr[64];
    static const char* argname[64];
    static int cnt;

    public:
    Option(const char* n, int ha, int* f, int v, const char* d = "", const char* an = "") 
    {
	    name = n;
        has_arg = ha;
        flag = f;
	    val = v;
        descr[cnt] = d;
        argname[cnt++] = an;
    }

    void PrintUsage(const char* d, const char* an) const
    {
        if (has_arg == 0)
            fprintf(stdout, "  --%-15s (-%c)               %s\n", name, val, d);
        else if (has_arg == 1)
            fprintf(stdout, "  --%-15s (-%c) %-12s  %s\n", name, val, an, d);
        else if (has_arg == 2)
            fprintf(stdout, "  --%-15s (-%c) [%-10s] %s\n", name, val, an, d);
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
        
        fprintf(stdout, "    %-20s %-13s %s\n", "long option", "arg", "description");
        for (int i = 0; i < cnt-1; i++)
        {
            options[i].PrintUsage(descr[i], argname[i]);
        }

        fprintf(stdout, 
        "\nfixpath processes the output of a make process. When nested projects are used\n"
        "the resolving of the file names in some IDE's fails. The reported error/warning\n"
        "location is relative to the build directory which varies. This is resolved by\n"
        "processing the Entering and Leaving directory statements (use make -w). With\n"
        "this information the paths are made absolute. Normally fixpath is used in the\n"
        "folowing manner: 'make -j4 -w 2>&1 | fixpath' It processes the stdin and puts\n"
        "the altered output to stdout. There are options to perform some filtering at the\n"
        "same time, these options are described above. Lines starting with: \n"
        "'clang', 'gcc', 'clang++', 'g++', 'c++', 'CC' and 'GCC' are classified as\n"
        "compiler lines.");
    }
};

int Option::cnt = 0;
const char* Option::descr[64];
const char* Option::argname[64];

int main(int argc, char** argv)
{
    bool compressLine = 0;
    bool skipOtherLine = 0;
    bool skipCompilerLine = 0;
    bool skipDirectoryLine = 0;
    bool appendReadyLine = 0;
    
    static Option options[] = { 
        Option("help",            no_argument,        0,  'h', "Print this help"), 
        Option("version",         no_argument,        0,  'v', "Shows the current version of fixpath"),
        Option("compress",        no_argument,        0,  'x', "Compresses recognized compiler line by\n    removing the options from the line."),
        Option("skip_other",      no_argument,        0,  'o', "Skip lines that are not recognized as\n    compiler or Entering/Leaving directory lines."),
        Option("skip_compiler",   no_argument,        0,  'c', "Skip lines that are recognized as\n    compiler lines."),
        Option("skip_directory",  no_argument,        0,  'd', "Skip lines that are recognized as\n    Entering/Leaving directory lines."),
        Option("skip_all",        no_argument,        0,  'a', "Skip all lines from output."),
        Option("skip_most",       no_argument,        0,  'm', "Skip all lines from output except those\n    recognized as compiler lines."),
        Option("append_ready",    no_argument,        0,  'r', "Append a line at ens, so its clear we are\n    ready,"),
//        Option("input",           required_argument,  0,  'f', "Use infile instead of stdin.", "infile"),
//        Option("output",          required_argument,  0,  'o', "Use outfile instead of stdout.", "infile"),
        Option(0,                 0,                  0,  0)
    };

    int long_index =0;
    int opt;
    while ((opt = getopt_long(argc, argv,"hvxocdamr", 
                   options, &long_index )) != -1) {
        switch (opt) 
        {
            case 'x' : 
                compressLine = true; 
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
                fprintf(stdout, "fixpath: version 0.9\n");
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
    cout << "compressLine: " << compressLine << endl;
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
            if (skipCompilerLine == 0)
            {
                if (compressLine)
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

