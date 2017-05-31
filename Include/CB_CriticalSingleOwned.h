#ifndef CB_CRITICAL_SINGLE_OWNED_H
#define CB_CRITICAL_SINGLE_OWNED_H

#include "CB_CriticalSingle.h"
#include "CB_SingleOwned.h"

// defines for include files
#define RELATION_TEMPLATE_CRITICAL_SINGLE_OWNED_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
public:\
    CB_PTR(ClassTo) _ref##NameTo;\
\
    static CriticalSection& CriticalSection##NameTo()\
    {\
        static CriticalSection criticalSection##NameTo;\
        return criticalSection##NameTo;\
    }\
\
protected:\
    void Add##NameTo(ClassTo* item)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_SINGLE_ADD(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    \
    void Remove##NameTo(ClassTo* item)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_SINGLE_REMOVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    \
    void Replace##NameTo(ClassTo* item, ClassTo* newItem)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_SINGLE_REPLACE(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    \
public:\
    void Move##NameTo(ClassTo* item)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_SINGLE_MOVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    \
    ClassTo* Get##NameTo() const {return _ref##NameTo;};

#define RELATION_CRITICAL_SINGLE_OWNED_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
public:\
    CB_PTR(ClassTo) _ref##NameTo;\
\
    static CriticalSection _criticalSection##NameTo;\
    static CriticalSection& CriticalSection##NameTo() { return _criticalSection##NameTo; }\
\
protected:\
    void Add##NameTo(ClassTo* item);\
    void Remove##NameTo(ClassTo* item);\
    void Move##NameTo(ClassTo* item);\
    void Replace##NameTo(ClassTo* item, ClassTo* newItem);\
\
public:\
    ClassTo* Get##NameTo() const {return _ref##NameTo;};

#define RELATION_CRITICAL_SINGLE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    RELATION_CRITICAL_SINGLE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo)

// defines implementation
#define INIT_CRITICAL_SINGLE_OWNED_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
   INIT_SINGLE_OWNED_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define EXIT_CRITICAL_SINGLE_OWNED_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    EXIT_SINGLE_OWNED_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define REPLACE_CRITICAL_SINGLE_OWNED_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    REPLACE_SINGLE_OWNED_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define INIT_CRITICAL_SINGLE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    INIT_SINGLE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define EXIT_CRITICAL_SINGLE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    EXIT_SINGLE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define REPLACE_CRITICAL_SINGLE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    REPLACE_SINGLE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define REMOVE_CRITICAL_SINGLE_OWNED_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    REMOVE_SINGLE_OWNED_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define SAVE_CRITICAL_SINGLE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    SAVE_SINGLE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define RESTORE_CRITICAL_SINGLE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    RESTORE_SINGLE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define REMOVE_CRITICAL_SINGLE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    REMOVE_SINGLE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define CLEANUP_CRITICAL_SINGLE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    CLEANUP_SINGLE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define METHODS_CRITICAL_SINGLE_OWNED_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    METHODS_CRITICAL_SINGLE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) 

#define METHODS_CRITICAL_SINGLE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#endif