#ifndef CB_CRITICAL_VALUETREE_H
#define CB_CRITICAL_VALUETREE_H

#include "CB_CriticalSection.h"
#include "CB_ValueTree.h"

// defines for include files
#define RELATION_TEMPLATE_CRITICAL_VALUETREE_ACTIVE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
private:\
    CB_PTR(ClassTo) _first##NameTo;\
    int _count##NameTo;\
\
public:\
    static CriticalSection& CriticalSection##NameTo()\
    {\
        static CriticalSection criticalSection##NameTo;\
        return criticalSection##NameTo;\
    }\
\
    void Add##NameTo(ClassTo* item)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_VALUETREE_ADD(member, ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Remove##NameTo(ClassTo* item)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_VALUETREE_REMOVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void RemoveAll##NameTo()\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_VALUETREE_REMOVEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void DeleteAll##NameTo()\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_VALUETREE_DELETEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Replace##NameTo(ClassTo* item, ClassTo* newItem)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_VALUETREE_REPLACE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetFirst##NameTo() const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_VALUETREE_GETFIRST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetLast##NameTo() const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_VALUETREE_GETLAST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetNext##NameTo(ClassTo* pos) const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_VALUETREE_GETNEXT(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetPrev##NameTo(ClassTo* pos) const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_VALUETREE_GETPREV(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    int Get##NameTo##Count() const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_VALUETREE_GETCOUNT(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ITERATOR_TEMPLATE_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define RELATION_TEMPLATE_NOFILTER_CRITICAL_VALUETREE_ACTIVE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
private:\
    CB_PTR(ClassTo) _first##NameTo;\
    int _count##NameTo;\
\
public:\
    static CriticalSection& CriticalSection##NameTo()\
    {\
        static CriticalSection criticalSection##NameTo;\
        return criticalSection##NameTo;\
    }\
\
    void Add##NameTo(ClassTo* item)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_VALUETREE_ADD(member, ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Remove##NameTo(ClassTo* item)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_VALUETREE_REMOVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void RemoveAll##NameTo()\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_VALUETREE_REMOVEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void DeleteAll##NameTo()\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_VALUETREE_DELETEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Replace##NameTo(ClassTo* item, ClassTo* newItem)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_VALUETREE_REPLACE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetFirst##NameTo() const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_VALUETREE_GETFIRST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetLast##NameTo() const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_VALUETREE_GETLAST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetNext##NameTo(ClassTo* pos) const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_VALUETREE_GETNEXT(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetPrev##NameTo(ClassTo* pos) const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_VALUETREE_GETPREV(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    int Get##NameTo##Count() const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_VALUETREE_GETCOUNT(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ITERATOR_TEMPLATE_NOFILTER_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define RELATION_CRITICAL_VALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
private:\
    CB_PTR(ClassTo) _first##NameTo;\
    int _count##NameTo;\
\
public:\
    static CriticalSection _criticalSection##NameTo;\
    static CriticalSection& CriticalSection##NameTo() { return _criticalSection##NameTo; }\
\
    void Add##NameTo(ClassTo* item);\
    void Remove##NameTo(ClassTo* item);\
    void RemoveAll##NameTo();\
    void DeleteAll##NameTo();\
    void Replace##NameTo(ClassTo* item, ClassTo* newItem);\
    ClassTo* GetFirst##NameTo() const;\
    ClassTo* GetLast##NameTo() const;\
    ClassTo* GetNext##NameTo(ClassTo* pos) const;\
    ClassTo* GetPrev##NameTo(ClassTo* pos) const;\
    int Get##NameTo##Count() const;\
    ITERATOR_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define RELATION_NOFILTER_CRITICAL_VALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
private:\
    CB_PTR(ClassTo) _first##NameTo;\
    int _count##NameTo;\
\
public:\
    static CriticalSection _criticalSection##NameTo;\
    static CriticalSection& CriticalSection##NameTo() { return _criticalSection##NameTo; }\
\
    void Add##NameTo(ClassTo* item);\
    void Remove##NameTo(ClassTo* item);\
    void RemoveAll##NameTo();\
    void DeleteAll##NameTo();\
    void Replace##NameTo(ClassTo* item, ClassTo* newItem);\
    ClassTo* GetFirst##NameTo() const;\
    ClassTo* GetLast##NameTo() const;\
    ClassTo* GetNext##NameTo(ClassTo* pos) const;\
    ClassTo* GetPrev##NameTo(ClassTo* pos) const;\
    int Get##NameTo##Count() const;\
    ITERATOR_NOFILTER_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define RELATION_CRITICAL_VALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
public:\
    CB_PTR(ClassFrom) _ref##NameFrom;\
    CB_PTR(ClassTo) _parent##NameFrom;\
    CB_PTR(ClassTo) _left##NameFrom;\
    CB_PTR(ClassTo) _right##NameFrom;\
    CB_PTR(ClassTo) _sibling##NameFrom;\
\
public:\
    ClassFrom* Get##NameFrom() const { return _ref##NameFrom; };

// defines implementation
#define INIT_CRITICAL_VALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    INIT_VALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define EXIT_CRITICAL_VALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    EXIT_VALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define REPLACE_CRITICAL_VALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    REPLACE_VALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define INIT_CRITICAL_VALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    INIT_VALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define EXIT_CRITICAL_VALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    EXIT_VALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define REPLACE_CRITICAL_VALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    REPLACE_VALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define REMOVE_CRITICAL_VALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    REMOVE_VALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define SAVE_CRITICAL_VALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    SAVE_VALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define RESTORE_CRITICAL_VALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    RESTORE_VALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define REMOVE_CRITICAL_VALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    REMOVE_VALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define CLEANUP_CRITICAL_VALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    CLEANUP_VALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define METHODS_CRITICAL_VALUETREE_ACTIVE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
    CriticalSection ClassFrom::_criticalSection##NameTo;\
void ClassFrom::Add##NameTo(ClassTo* item)\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_VALUETREE_ADD(member, ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::Remove##NameTo(ClassTo* item)\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_VALUETREE_REMOVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::RemoveAll##NameTo()\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_VALUETREE_REMOVEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::DeleteAll##NameTo()\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_VALUETREE_DELETEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::Replace##NameTo(ClassTo* item, ClassTo* newItem)\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_VALUETREE_REPLACE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
ClassTo* ClassFrom::GetFirst##NameTo() const\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_VALUETREE_GETFIRST(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
ClassTo* ClassFrom::GetLast##NameTo() const\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_VALUETREE_GETLAST(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
ClassTo* ClassFrom::GetNext##NameTo(ClassTo* pos) const\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_VALUETREE_GETNEXT(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
ClassTo* ClassFrom::GetPrev##NameTo(ClassTo* pos) const\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_VALUETREE_GETPREV(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
int ClassFrom::Get##NameTo##Count() const\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_VALUETREE_GETCOUNT(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define METHODS_CRITICAL_VALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define BODY_CRITICAL_VALUETREE_FIND(member, value, ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    BODY_VALUETREE_FIND(member, value, ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define BODY_CRITICAL_VALUETREE_FINDREVERSE(member, value, ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    BODY_VALUETREE_FINDREVERSE(member, value, ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define WRITE_CRITICAL_VALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    WRITE_VALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define READ_CRITICAL_VALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    READ_VALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define DYNAMIC_READ_CRITICAL_VALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    DYNAMIC_READ_VALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#endif
