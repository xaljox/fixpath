/******************************************************************************\
*
* File:          FixPath.cpp
* Creation date: May 30, 2017 18:34
* Author:        ClassBuilder
*                XXXX
* Purpose:       Method implementations of class 'FixPath'
*
* Modifications: @INSERT_MODIFICATIONS(* )
* May 30, 2017 21:15 JV
*     Updated code of method 'ResolvePath'
* May 30, 2017 19:46 JV
*     Added method 'MergePaths'
*     Updated code of method 'ResolvePath'
* May 30, 2017 19:37 JV
*     Added method 'ResolvePath'
* May 30, 2017 18:44 JV
*     Updated interface of method 'FindDir'
*     Updated code of method '~FixPath'
*     Updated code of method 'FixPath'
*     Updated relation 'FixPath <>-->> Dir'
* May 30, 2017 18:34 JV
*     Added method 'DestructorInclude'
*     Added method 'ConstructorInclude'
*     Added method 'LeaveDirectory'
*     Added method 'FindPath'
*     Added method 'EnterDirectory'
*     Added method '~FixPath'
*     Added method 'FixPath'
*     Added relation 'FixPath <>-->> Path'
*
* Copyright 2017, XXXXX
* All rights are reserved. Reproduction in whole or part is prohibited
* without the written consent of the copyright owner.
*
\******************************************************************************/
//@START_USER1
//@END_USER1


// Master include file
#include "FixPathInclude.h"


//@START_USER2
#include <sys/stat.h>

inline bool FileExists(string filename) {
    struct stat fileInfo;
    return stat(filename.c_str(), &fileInfo) == 0;
}
//@END_USER2


// Static members


/*@NOTE_115
Constructor method.
*/
FixPath::FixPath() //@INIT_115
{//@CODE_115
    ConstructorInclude();

    // Put in your own code
}//@CODE_115


/*@NOTE_19
Destructor method.
*/
FixPath::~FixPath()
{//@CODE_19
    DestructorInclude();

    // Put in your own code
}//@CODE_19


void FixPath::EnterDirectory(char* path)
{//@CODE_118
    Dir* pDir = FindDir(path);
    
    if (!pDir)
    {
        pDir = new Dir(this, path);
    }

    pDir->Increment();
}//@CODE_118


Dir* FixPath::FindDir(const string& path)
{//@CODE_116
    DirIterator iDir(this);
    while (++iDir)
    {
        if (path == iDir->GetPath())
        {
            return iDir;
        }
    }

    return 0;
}//@CODE_116


void FixPath::LeaveDirectory(char* path)
{//@CODE_119
    Dir* pDir = FindDir(path);
    
    if (pDir)
    {
        pDir->Decrement();
        if (pDir->GetCnt() == 0)
        {
            delete pDir;
        }
    }
}//@CODE_119


string FixPath::MergePaths(const string& dir, const string& relPath)
{//@CODE_132
    size_t pos = 0;
    if (relPath.find("./") == 0)
    {
        pos = 2;
    }
   
    while (relPath.find("../", pos) == pos)
    {
        pos += 3;
    }
    
    string rPath = relPath.substr(pos);
    
    size_t rpos = dir.length();
    for (size_t i = 0; i < pos/3 && rpos != string::npos; i++)
    {
        rpos = dir.rfind('/', rpos-1);
    }

    if (rpos != string::npos)
    {
        return dir.substr(0, rpos) + '/' + rPath;
    }
    else
    {
        return relPath;
    }
}//@CODE_132



string FixPath::ResolvePath(char* path)
{//@CODE_130
    string str = path;
    
    if (path[0] != '/')
    {
        string lastFailedPath;
        
        DirIterator iDir(this);
        while (++iDir)
        {
            str = MergePaths(iDir->GetPath(), path);
            if (str != lastFailedPath)
            {
                if (FileExists(str))
                {
                    break;
                }
                else
                {
                    lastFailedPath = str;
                }
            }
        }
    }
    
    return str;
}//@CODE_130


//{{AFX DO NOT EDIT CODE BELOW THIS LINE !!!

/*@NOTE_20
Method which must be called first in a constructor.
*/
void FixPath::ConstructorInclude()
{
    INIT_MULTI_OWNED_ACTIVE(FixPath, FixPath, Dir, Dir)
}


/*@NOTE_21
Method which must be called first in a destructor.
*/
void FixPath::DestructorInclude()
{
    EXIT_MULTI_OWNED_ACTIVE(FixPath, FixPath, Dir, Dir)
}


// Methods for the relation(s) of the class
METHODS_MULTI_OWNED_ACTIVE(FixPath, FixPath, Dir, Dir)
METHODS_ITERATOR_MULTI_ACTIVE(FixPath, FixPath, Dir, Dir)

//}}AFX DO NOT EDIT CODE ABOVE THIS LINE !!!

//@START_USER3
