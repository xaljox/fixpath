#ifndef _FIXPATHINCLUDE_H
#define _FIXPATHINCLUDE_H

// Date, Time & Version defines
#define FIXPATH_DATE    20170530
#define FIXPATH_TIME    194659
#define FIXPATH_VERSION 5

// Context define declarations

// Forward extern class declarations

//@START_USER1
#include <string>

using namespace std;
//@END_USER1

// Defines needed for relations between templated classes

// Forward class declarations
class FixPath;
class Dir;

// Needed ClassBuilder include files
#include "CB_MultiOwned.h"

// Make sure the inline implementations are skipped
#ifdef CB_INLINES
#undef CB_INLINES
#endif

// Include classes, for declarations
#include "Dir.h"
#include "FixPath.h"


// Include classes again, for inline implementation
#define CB_INLINES
#include "Dir.h"

//@START_USER2
//@END_USER2

#endif
