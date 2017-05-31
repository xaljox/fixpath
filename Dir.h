/******************************************************************************\
*
* File:          Dir.h
* Creation date: May 30, 2017 18:34
* Author:        ClassBuilder
*                XXXX
* Purpose:       Declaration of class 'Dir'
*
* Modifications: @INSERT_MODIFICATIONS(* )
* May 30, 2017 19:03 JV
*     Added inheritance 'string'
* May 30, 2017 18:44 JV
*     Added method 'GetPath'
*     Updated interface of method 'ConstructorInclude'
*     Updated interface of method 'Dir'
*     Updated relation 'FixPath <>-->> Dir'
*     Updated member '_cnt'
*     Updated member '_path'
* May 30, 2017 18:34 JV
*     Added method 'DestructorInclude'
*     Added method 'ConstructorInclude'
*     Added method 'GetCnt'
*     Added method 'Increment'
*     Added method 'Decrement'
*     Added method '~Dir'
*     Added method 'Dir'
*     Added relation 'Paths <>-->> Dir'
*     Added member '_cnt'
*     Added member '_path'
*
* Copyright 2017, XXXXX
* All rights are reserved. Reproduction in whole or part is prohibited
* without the written consent of the copyright owner.
*
\******************************************************************************/
#ifndef _DIR_H
#define _DIR_H

//@START_USER1
//@END_USER1



class Dir
{
    RELATION_MULTI_OWNED_PASSIVE(FixPath, FixPath, Dir, Dir)

//@START_USER2
//@END_USER2

// Members
private:
    string _path;
    int _cnt;

protected:

public:

// Methods
private:
    void ConstructorInclude(FixPath* pFixPath);
    void DestructorInclude();

protected:

public:
    Dir(FixPath* pFixPath, char* path);
    ~Dir();
    void Decrement();
    void Increment();
    int GetCnt() const;
    const string& GetPath() const;
};

#endif


#ifdef CB_INLINES
#ifndef _DIR_H_INLINES
#define _DIR_H_INLINES

/*@NOTE_120
Returns the value of member '_cnt'.
*/
inline int Dir::GetCnt() const
{//@CODE_120
    return _cnt;
}//@CODE_120



/*@NOTE_128
Returns the value of member '_path'.
*/
inline const string& Dir::GetPath() const
{//@CODE_128
    return _path;
}//@CODE_128



//@START_USER3
//@END_USER3

#endif
#endif
