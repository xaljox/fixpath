#ifndef CB_CRITICAL_MULTI_H
#define CB_CRITICAL_MULTI_H

#include "CB_CriticalSection.h"
#include "CB_Multi.h"

#define RELATION_TEMPLATE_CRITICAL_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
public:\
    CB_PTR(ClassTo) _first##NameTo;\
    CB_PTR(ClassTo) _last##NameTo;\
    int _count##NameTo;\
\
    static CriticalSection& CriticalSection##NameTo()\
    {\
        static CriticalSection criticalSection##NameTo;\
        return criticalSection##NameTo;\
    }\
\
public:\
    void Add##NameTo##First(ClassTo* item)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_ADDFIRST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Add##NameTo##Last(ClassTo* item)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_ADDLAST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Add##NameTo##After(ClassTo* item, ClassTo* pos)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_ADDAFTER(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Add##NameTo##Before(ClassTo* item, ClassTo* pos)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_ADDBEFORE(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Remove##NameTo(ClassTo* item)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_REMOVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Replace##NameTo(ClassTo* item, ClassTo* newItem)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_REPLACE(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void DeleteAll##NameTo()\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_DELETEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetFirst##NameTo() const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_GETFIRST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetLast##NameTo() const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_GETLAST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetNext##NameTo(ClassTo* pos) const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_GETNEXT(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetPrev##NameTo(ClassTo* pos) const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_GETPREV(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    int Get##NameTo##Count() const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_GETCOUNT(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Move##NameTo##First(ClassTo* item)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_MOVEFIRST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Move##NameTo##Last(ClassTo* item)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_MOVELAST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Move##NameTo##After(ClassTo* item, ClassTo* pos)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_MOVEAFTER(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Move##NameTo##Before(ClassTo* item, ClassTo* pos)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_MOVEBEFORE(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Sort##NameTo(int (*comp)(ClassTo*, ClassTo*))\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_SORT(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ITERATOR_TEMPLATE_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define RELATION_TEMPLATE_NOFILTER_CRITICAL_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
public:\
    CB_PTR(ClassTo) _first##NameTo;\
    CB_PTR(ClassTo) _last##NameTo;\
    int _count##NameTo;\
\
    static CriticalSection& CriticalSection##NameTo()\
    {\
        static CriticalSection criticalSection##NameTo;\
        return criticalSection##NameTo;\
    }\
\
public:\
    void Add##NameTo##First(ClassTo* item)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_ADDFIRST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Add##NameTo##Last(ClassTo* item)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_ADDLAST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Add##NameTo##After(ClassTo* item, ClassTo* pos)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_ADDAFTER(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Add##NameTo##Before(ClassTo* item, ClassTo* pos)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_ADDBEFORE(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Remove##NameTo(ClassTo* item)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_REMOVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Replace##NameTo(ClassTo* item, ClassTo* newItem)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_REPLACE(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void DeleteAll##NameTo()\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_DELETEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetFirst##NameTo() const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_GETFIRST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetLast##NameTo() const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_GETLAST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetNext##NameTo(ClassTo* pos) const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_GETNEXT(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetPrev##NameTo(ClassTo* pos) const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_GETPREV(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    int Get##NameTo##Count() const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_GETCOUNT(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Move##NameTo##First(ClassTo* item)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_MOVEFIRST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Move##NameTo##Last(ClassTo* item)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_MOVELAST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Move##NameTo##After(ClassTo* item, ClassTo* pos)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_MOVEAFTER(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Move##NameTo##Before(ClassTo* item, ClassTo* pos)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_MOVEBEFORE(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Sort##NameTo(int (*comp)(ClassTo*, ClassTo*))\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_MULTI_SORT(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ITERATOR_TEMPLATE_NOFILTER_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define RELATION_CRITICAL_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
public:\
    CB_PTR(ClassTo) _first##NameTo;\
    CB_PTR(ClassTo) _last##NameTo;\
    int _count##NameTo;\
\
public:\
    static CriticalSection _criticalSection##NameTo;\
\
    static CriticalSection& CriticalSection##NameTo() { return _criticalSection##NameTo; }\
\
    void Add##NameTo##First(ClassTo* item);\
    void Add##NameTo##Last(ClassTo* item);\
    void Add##NameTo##After(ClassTo* item, ClassTo* pos);\
    void Add##NameTo##Before(ClassTo* item, ClassTo* pos);\
    void Remove##NameTo(ClassTo* item);\
    void RemoveAll##NameTo();\
    void DeleteAll##NameTo();\
    void Replace##NameTo(ClassTo* item, ClassTo* newItem);\
    ClassTo* GetFirst##NameTo() const;\
    ClassTo* GetLast##NameTo() const;\
    ClassTo* GetNext##NameTo(ClassTo* pos) const;\
    ClassTo* GetPrev##NameTo(ClassTo* pos) const;\
    int Get##NameTo##Count() const;\
    void Move##NameTo##First(ClassTo* item);\
    void Move##NameTo##Last(ClassTo* item);\
    void Move##NameTo##After(ClassTo* item, ClassTo* pos);\
    void Move##NameTo##Before(ClassTo* item, ClassTo* pos);\
    void Sort##NameTo(int (*comp)(ClassTo*, ClassTo*));\
    ITERATOR_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define RELATION_NOFILTER_CRITICAL_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
public:\
    CB_PTR(ClassTo) _first##NameTo;\
    CB_PTR(ClassTo) _last##NameTo;\
    int _count##NameTo;\
\
public:\
    static CriticalSection _criticalSection##NameTo;\
\
    static CriticalSection& CriticalSection##NameTo() { return _criticalSection##NameTo; }\
\
    void Add##NameTo##First(ClassTo* item);\
    void Add##NameTo##Last(ClassTo* item);\
    void Add##NameTo##After(ClassTo* item, ClassTo* pos);\
    void Add##NameTo##Before(ClassTo* item, ClassTo* pos);\
    void Remove##NameTo(ClassTo* item);\
    void RemoveAll##NameTo();\
    void DeleteAll##NameTo();\
    void Replace##NameTo(ClassTo* item, ClassTo* newItem);\
    ClassTo* GetFirst##NameTo() const;\
    ClassTo* GetLast##NameTo() const;\
    ClassTo* GetNext##NameTo(ClassTo* pos) const;\
    ClassTo* GetPrev##NameTo(ClassTo* pos) const;\
    int Get##NameTo##Count() const;\
    void Move##NameTo##First(ClassTo* item);\
    void Move##NameTo##Last(ClassTo* item);\
    void Move##NameTo##After(ClassTo* item, ClassTo* pos);\
    void Move##NameTo##Before(ClassTo* item, ClassTo* pos);\
    void Sort##NameTo(int (*comp)(ClassTo*, ClassTo*));\
    ITERATOR_NOFILTER_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define RELATION_CRITICAL_MULTI_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
public:\
    CB_PTR(ClassFrom) _ref##NameFrom;\
    CB_PTR(ClassTo) _prev##NameFrom;\
    CB_PTR(ClassTo) _next##NameFrom;\
\
public:\
    ClassFrom* Get##NameFrom() const { return _ref##NameFrom; };

#define INIT_CRITICAL_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    INIT_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define EXIT_CRITICAL_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    EXIT_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define REPLACE_CRITICAL_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    REPLACE_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define INIT_CRITICAL_MULTI_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    INIT_MULTI_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define EXIT_CRITICAL_MULTI_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    EXIT_MULTI_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define REPLACE_CRITICAL_MULTI_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    REPLACE_MULTI_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define REMOVE_CRITICAL_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    REMOVE_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define SAVE_CRITICAL_MULTI_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    SAVE_MULTI_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define RESTORE_CRITICAL_MULTI_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    RESTORE_MULTI_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define REMOVE_CRITICAL_MULTI_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    REMOVE_MULTI_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define CLEANUP_CRITICAL_MULTI_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    CLEANUP_MULTI_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define METHODS_CRITICAL_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    CriticalSection ClassFrom::_criticalSection##NameTo;\
void ClassFrom::Add##NameTo##First(ClassTo* item)\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_MULTI_ADDFIRST(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::Add##NameTo##Last(ClassTo* item)\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_MULTI_ADDLAST(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::Add##NameTo##After(ClassTo* item, ClassTo* pos)\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_MULTI_ADDAFTER(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::Add##NameTo##Before(ClassTo* item, ClassTo* pos)\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_MULTI_ADDBEFORE(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::Remove##NameTo(ClassTo* item)\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_MULTI_REMOVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::RemoveAll##NameTo()\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_MULTI_REMOVEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::DeleteAll##NameTo()\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_MULTI_DELETEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::Replace##NameTo(ClassTo* item, ClassTo* newItem)\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_MULTI_REPLACE(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
ClassTo* ClassFrom::GetFirst##NameTo() const\
{\
    METHOD_MULTI_GETFIRST(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
ClassTo* ClassFrom::GetLast##NameTo() const\
{\
    METHOD_MULTI_GETLAST(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
ClassTo* ClassFrom::GetNext##NameTo(ClassTo* pos) const\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_MULTI_GETNEXT(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
ClassTo* ClassFrom::GetPrev##NameTo(ClassTo* pos) const\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_MULTI_GETPREV(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
int ClassFrom::Get##NameTo##Count() const\
{\
    METHOD_MULTI_GETCOUNT(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::Move##NameTo##First(ClassTo* item)\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_MULTI_MOVEFIRST(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::Move##NameTo##Last(ClassTo* item)\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_MULTI_MOVELAST(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::Move##NameTo##After(ClassTo* item, ClassTo* pos)\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_MULTI_MOVEAFTER(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::Move##NameTo##Before(ClassTo* item, ClassTo* pos)\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_MULTI_MOVEBEFORE(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::Sort##NameTo(int (*comp)(ClassTo*, ClassTo*))\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_MULTI_SORT(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define METHODS_CRITICAL_MULTI_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define WRITE_CRITICAL_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        WRITE_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    }

#define READ_CRITICAL_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
        {\
            CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
            READ_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
        }

#define DYNAMIC_READ_CRITICAL_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
        {\
            CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
            DYNAMIC_READ_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
        }

#endif
