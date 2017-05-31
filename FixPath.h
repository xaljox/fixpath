/******************************************************************************\
*
* File:          FixPath.h
* Creation date: May 30, 2017 18:34
* Author:        ClassBuilder
*                XXXX
* Purpose:       Declaration of class 'FixPath'
*
* Modifications: @INSERT_MODIFICATIONS(* )
* May 30, 2017 19:46 JV
*     Added method 'MergePaths'
* May 30, 2017 19:37 JV
*     Added method 'ResolvePath'
* May 30, 2017 18:44 JV
*     Updated interface of method 'FindDir'
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
#ifndef _FIXPATH_H
#define _FIXPATH_H

//@START_USER1
//@END_USER1



class FixPath
{
    RELATION_MULTI_OWNED_ACTIVE(FixPath, FixPath, Dir, Dir)

//@START_USER2
//@END_USER2

// Members
private:

protected:

public:

// Methods
private:
    string MergePaths(const string& dir, const string& relPath);
    void ConstructorInclude();
    void DestructorInclude();

protected:

public:
    FixPath();
    ~FixPath();
    void EnterDirectory(char* path);
    Dir* FindDir(const string& path);
    void LeaveDirectory(char* path);
    string ResolvePath(char* path);
};

#endif


#ifdef CB_INLINES
#ifndef _FIXPATH_H_INLINES
#define _FIXPATH_H_INLINES

//@START_USER3
//@END_USER3

#endif
#endif
