/******************************************************************************\
*
* File:          Dir.cpp
* Creation date: May 30, 2017 18:34
* Author:        ClassBuilder
*                XXXX
* Purpose:       Method implementations of class 'Dir'
*
* Modifications: @INSERT_MODIFICATIONS(* )
* May 30, 2017 18:44 JV
*     Added method 'GetPath'
*     Updated interface of method 'ConstructorInclude'
*     Updated code of method 'GetCnt'
*     Updated code of method '~Dir'
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
//@START_USER1
//@END_USER1


// Master include file
#include "FixPathInclude.h"


//@START_USER2
//@END_USER2


// Static members


/*@NOTE_112
Constructor method.
*/
Dir::Dir(FixPath* pFixPath, char* path) //@INIT_112
    : _path(path)
    , _cnt(0)
{//@CODE_112
    ConstructorInclude(pFixPath);

    // Put in your own code
}//@CODE_112


/*@NOTE_24
Destructor method.
*/
Dir::~Dir()
{//@CODE_24
    DestructorInclude();

    // Put in your own code
}//@CODE_24


void Dir::Decrement()
{//@CODE_122
    _cnt--;
}//@CODE_122


void Dir::Increment()
{//@CODE_121
    _cnt++;
}//@CODE_121


//{{AFX DO NOT EDIT CODE BELOW THIS LINE !!!

/*@NOTE_25
Method which must be called first in a constructor.
*/
void Dir::ConstructorInclude(FixPath* pFixPath)
{
    INIT_MULTI_OWNED_PASSIVE(FixPath, FixPath, Dir, Dir)
}


/*@NOTE_26
Method which must be called first in a destructor.
*/
void Dir::DestructorInclude()
{
    EXIT_MULTI_OWNED_PASSIVE(FixPath, FixPath, Dir, Dir)
}


// Methods for the relation(s) of the class
METHODS_MULTI_OWNED_PASSIVE(FixPath, FixPath, Dir, Dir)

//}}AFX DO NOT EDIT CODE ABOVE THIS LINE !!!

//@START_USER3
