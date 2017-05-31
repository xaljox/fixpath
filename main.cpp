#include <stdlib.h>
#include <iostream>
#include <regex.h>
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

int main(int argc, char** argv)
{
    // Recognize the warning/error line
    RegEx regex_we("^(.*):([0-9]+):([0-9]+): +(warning|error): +(.*)$");

    // make: Entering|Leaving directory `/Users/xaljox/GitHub/bash/bash-4.4/build_mac'
    RegEx regex_dir("^make(\\[[0-9]+\\])?: ((Entering)|(Leaving)) directory ['`](.*)'");
    
    // Line where a C/C++ compiler is called
    RegEx regex_com("^(clang|gcc|clang\\+\\+|g\\+\\+|c\\+\\+|CC|GCC)((( +-[a-zA-Z][a-zA-Z_0-9\\.\\/\\-]*)(=[^ ]+)?)*) +(.*)$");
        
    bool filterCompilerLine = true;
    bool dropNonCompilerLine = true;
    bool dropCompilerLine = false;
    bool dropDirectoryLine = true;
    
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
            if (dropDirectoryLine == false)
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
            if (dropCompilerLine == false)
            {
                if (filterCompilerLine)
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
        
            if (dropNonCompilerLine == false || (errorWarningMode && line[0] == ' '))
            {
                cout << line << endl;            
            }
        }
        
        cout << flush;
    }
    
    return 0;
}

