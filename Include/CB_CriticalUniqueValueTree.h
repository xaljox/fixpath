#ifndef CB_CRITICAL_UNIQUEVALUETREE_H
#define CB_CRITICAL_UNIQUEVALUETREE_H

#include "CB_CriticalSection.h"
#include "CB_UniqueValueTree.h"

// defines for include files
#define RELATION_TEMPLATE_CRITICAL_UNIQUEVALUETREE_ACTIVE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
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
        METHOD_UNIQUEVALUETREE_ADD(member, ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Remove##NameTo(ClassTo* item)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_UNIQUEVALUETREE_REMOVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void RemoveAll##NameTo()\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_UNIQUEVALUETREE_REMOVEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void DeleteAll##NameTo()\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_UNIQUEVALUETREE_DELETEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Replace##NameTo(ClassTo* item, ClassTo* newItem)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_UNIQUEVALUETREE_REPLACE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetFirst##NameTo() const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_UNIQUEVALUETREE_GETFIRST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetLast##NameTo() const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_UNIQUEVALUETREE_GETLAST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetNext##NameTo(ClassTo* pos) const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_UNIQUEVALUETREE_GETNEXT(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetPrev##NameTo(ClassTo* pos) const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_UNIQUEVALUETREE_GETPREV(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    int Get##NameTo##Count() const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_UNIQUEVALUETREE_GETCOUNT(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ITERATOR_TEMPLATE_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define RELATION_TEMPLATE_NOFILTER_CRITICAL_UNIQUEVALUETREE_ACTIVE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
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
        METHOD_UNIQUEVALUETREE_ADD(member, ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Remove##NameTo(ClassTo* item)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_UNIQUEVALUETREE_REMOVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void RemoveAll##NameTo()\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_UNIQUEVALUETREE_REMOVEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void DeleteAll##NameTo()\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_UNIQUEVALUETREE_DELETEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Replace##NameTo(ClassTo* item, ClassTo* newItem)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_UNIQUEVALUETREE_REPLACE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetFirst##NameTo() const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_UNIQUEVALUETREE_GETFIRST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetLast##NameTo() const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_UNIQUEVALUETREE_GETLAST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetNext##NameTo(ClassTo* pos) const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_UNIQUEVALUETREE_GETNEXT(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetPrev##NameTo(ClassTo* pos) const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_UNIQUEVALUETREE_GETPREV(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    int Get##NameTo##Count() const\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_UNIQUEVALUETREE_GETCOUNT(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ITERATOR_TEMPLATE_NOFILTER_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define RELATION_CRITICAL_UNIQUEVALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
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

#define RELATION_NOFILTER_CRITICAL_UNIQUEVALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
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

#define RELATION_CRITICAL_UNIQUEVALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
public:\
    CB_PTR(ClassFrom) _ref##NameFrom;\
    CB_PTR(ClassTo) _parent##NameFrom;\
    CB_PTR(ClassTo) _left##NameFrom;\
    CB_PTR(ClassTo) _right##NameFrom;\
\
public:\
    ClassFrom* Get##NameFrom() const { return _ref##NameFrom; };

// defines implementation
#define INIT_CRITICAL_UNIQUEVALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    INIT_UNIQUEVALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define EXIT_CRITICAL_UNIQUEVALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    EXIT_UNIQUEVALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define REPLACE_CRITICAL_UNIQUEVALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    REPLACE_UNIQUEVALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define INIT_CRITICAL_UNIQUEVALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    INIT_UNIQUEVALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define EXIT_CRITICAL_UNIQUEVALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    EXIT_UNIQUEVALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define REPLACE_CRITICAL_UNIQUEVALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    REPLACE_UNIQUEVALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define REMOVE_CRITICAL_UNIQUEVALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    REMOVE_UNIQUEVALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define SAVE_CRITICAL_UNIQUEVALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    SAVE_UNIQUEVALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define RESTORE_CRITICAL_UNIQUEVALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    RESTORE_UNIQUEVALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define REMOVE_CRITICAL_UNIQUEVALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    REMOVE_UNIQUEVALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define CLEANUP_CRITICAL_UNIQUEVALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    CLEANUP_UNIQUEVALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define METHODS_CRITICAL_UNIQUEVALUETREE_ACTIVE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
    CriticalSection ClassFrom::_criticalSection##NameTo;\
void ClassFrom::Add##NameTo(ClassTo* item)\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_UNIQUEVALUETREE_ADD(member, ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::Remove##NameTo(ClassTo* item)\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_UNIQUEVALUETREE_REMOVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::RemoveAll##NameTo()\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_UNIQUEVALUETREE_REMOVEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::DeleteAll##NameTo()\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_UNIQUEVALUETREE_DELETEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::Replace##NameTo(ClassTo* item, ClassTo* newItem)\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_UNIQUEVALUETREE_REPLACE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
ClassTo* ClassFrom::GetFirst##NameTo() const\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_UNIQUEVALUETREE_GETFIRST(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
ClassTo* ClassFrom::GetLast##NameTo() const\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_UNIQUEVALUETREE_GETLAST(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
ClassTo* ClassFrom::GetNext##NameTo(ClassTo* pos) const\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_UNIQUEVALUETREE_GETNEXT(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
ClassTo* ClassFrom::GetPrev##NameTo(ClassTo* pos) const\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_UNIQUEVALUETREE_GETPREV(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
int ClassFrom::Get##NameTo##Count() const\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_UNIQUEVALUETREE_GETCOUNT(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define METHODS_CRITICAL_UNIQUEVALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define BODY_CRITICAL_UNIQUEVALUETREE_FIND(member, value, ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    BODY_UNIQUEVALUETREE_FIND(member, value, ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define BODY_CRITICAL_UNIQUEVALUETREE_FINDREVERSE(member, value, ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    BODY_UNIQUEVALUETREE_FINDREVERSE(member, value, ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define WRITE_CRITICAL_UNIQUEVALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    WRITE_UNIQUEVALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define READ_CRITICAL_UNIQUEVALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    READ_UNIQUEVALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define DYNAMIC_READ_CRITICAL_UNIQUEVALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    DYNAMIC_READ_UNIQUEVALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#endif
