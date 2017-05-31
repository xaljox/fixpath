#ifndef CB_CRITICAL_SINGLE_H
#define CB_CRITICAL_SINGLE_H

#include "CB_CriticalSection.h"
#include "CB_Single.h"

// defines for include files
#define RELATION_TEMPLATE_CRITICAL_SINGLE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
public:\
    CB_PTR(ClassTo) _ref##NameTo;\
\
    static CriticalSection& CriticalSection##NameTo()\
    {\
        static CriticalSection criticalSection##NameTo;\
        return criticalSection##NameTo;\
    }\
    \
public:\
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
    void Move##NameTo(ClassTo* item)\
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        METHOD_SINGLE_MOVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    \
    ClassTo* Get##NameTo() const {return _ref##NameTo;};

#define RELATION_CRITICAL_SINGLE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
public:\
    CB_PTR(ClassTo) _ref##NameTo;\
\
    static CriticalSection _criticalSection##NameTo;\
    static CriticalSection& CriticalSection##NameTo() { return _criticalSection##NameTo; }\
\
public:\
    void Add##NameTo(ClassTo* item);\
    void Remove##NameTo(ClassTo* item);\
    void Move##NameTo(ClassTo* item);\
    void Replace##NameTo(ClassTo* item, ClassTo* newItem);\
    ClassTo* Get##NameTo() const { return _ref##NameTo; };


#define RELATION_CRITICAL_SINGLE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
public:\
    CB_PTR(ClassFrom) _ref##NameFrom;\
\
public:\
    ClassFrom* Get##NameFrom() const { return _ref##NameFrom; };

// defines implementation

#define INIT_CRITICAL_SINGLE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    INIT_SINGLE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define EXIT_CRITICAL_SINGLE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    EXIT_SINGLE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define REPLACE_CRITICAL_SINGLE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    REPLACE_SINGLE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define INIT_CRITICAL_SINGLE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    INIT_SINGLE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) 

#define EXIT_CRITICAL_SINGLE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    EXIT_SINGLE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define REPLACE_CRITICAL_SINGLE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    REPLACE_SINGLE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define REMOVE_CRITICAL_SINGLE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    REMOVE_SINGLE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define SAVE_CRITICAL_SINGLE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    SAVE_SINGLE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define RESTORE_CRITICAL_SINGLE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    RESTORE_SINGLE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define REMOVE_CRITICAL_SINGLE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    REMOVE_SINGLE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define CLEANUP_CRITICAL_SINGLE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    CLEANUP_SINGLE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define METHODS_CRITICAL_SINGLE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    CriticalSection ClassFrom::_criticalSection##NameTo;\
void ClassFrom::Add##NameTo(ClassTo* item)\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_SINGLE_ADD(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::Remove##NameTo(ClassTo* item)\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_SINGLE_REMOVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::Move##NameTo(ClassTo* item)\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_SINGLE_MOVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::Replace##NameTo(ClassTo* item, ClassTo* newItem)\
{\
    CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
    METHOD_SINGLE_REPLACE(ClassFrom, NameFrom, ClassTo, NameTo) \
}


#define METHODS_CRITICAL_SINGLE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define WRITE_CRITICAL_SINGLE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    {\
        CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
        WRITE_SINGLE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    }

#define READ_CRITICAL_SINGLE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
        {\
            CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
            READ_SINGLE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
        }

#define DYNAMIC_READ_CRITICAL_SINGLE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
        {\
            CriticalSectionLock lock(ClassFrom::CriticalSection##NameTo());\
            DYNAMIC_READ_SINGLE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
        }

#endif