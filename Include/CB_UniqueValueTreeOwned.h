#ifndef CB_UNIQUEVALUETREE_OWNED_H
#define CB_UNIQUEVALUETREE_OWNED_H

#include "CB_UniqueValueTree.h"

// defines for include files
#define RELATION_TEMPLATE_UNIQUEVALUETREE_OWNED_ACTIVE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
private:\
    CB_PTR(ClassTo) _first##NameTo;\
    int _count##NameTo;\
\
public:\
    void Add##NameTo(ClassTo* item)\
    {\
        METHOD_UNIQUEVALUETREE_ADD(member, ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Remove##NameTo(ClassTo* item)\
    {\
        METHOD_UNIQUEVALUETREE_REMOVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void RemoveAll##NameTo()\
    {\
        METHOD_UNIQUEVALUETREE_REMOVEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void DeleteAll##NameTo()\
    {\
        METHOD_UNIQUEVALUETREE_DELETEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Replace##NameTo(ClassTo* item, ClassTo* newItem)\
    {\
        METHOD_UNIQUEVALUETREE_REPLACE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetFirst##NameTo() const\
    {\
        METHOD_UNIQUEVALUETREE_GETFIRST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetLast##NameTo() const\
    {\
        METHOD_UNIQUEVALUETREE_GETLAST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetNext##NameTo(ClassTo* pos) const\
    {\
        METHOD_UNIQUEVALUETREE_GETNEXT(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetPrev##NameTo(ClassTo* pos) const\
    {\
        METHOD_UNIQUEVALUETREE_GETPREV(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    int Get##NameTo##Count() const\
    {\
        METHOD_UNIQUEVALUETREE_GETCOUNT(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ITERATOR_TEMPLATE_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define RELATION_TEMPLATE_NOFILTER_UNIQUEVALUETREE_OWNED_ACTIVE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
private:\
    CB_PTR(ClassTo) _first##NameTo;\
    int _count##NameTo;\
\
public:\
    void Add##NameTo(ClassTo* item)\
    {\
        METHOD_UNIQUEVALUETREE_ADD(member, ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Remove##NameTo(ClassTo* item)\
    {\
        METHOD_UNIQUEVALUETREE_REMOVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void RemoveAll##NameTo()\
    {\
        METHOD_UNIQUEVALUETREE_REMOVEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void DeleteAll##NameTo()\
    {\
        METHOD_UNIQUEVALUETREE_DELETEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Replace##NameTo(ClassTo* item, ClassTo* newItem)\
    {\
        METHOD_UNIQUEVALUETREE_REPLACE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetFirst##NameTo() const\
    {\
        METHOD_UNIQUEVALUETREE_GETFIRST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetLast##NameTo() const\
    {\
        METHOD_UNIQUEVALUETREE_GETLAST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetNext##NameTo(ClassTo* pos) const\
    {\
        METHOD_UNIQUEVALUETREE_GETNEXT(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetPrev##NameTo(ClassTo* pos) const\
    {\
        METHOD_UNIQUEVALUETREE_GETPREV(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    int Get##NameTo##Count() const\
    {\
        METHOD_UNIQUEVALUETREE_GETCOUNT(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ITERATOR_TEMPLATE_NOFILTER_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define RELATION_UNIQUEVALUETREE_OWNED_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
private:\
    CB_PTR(ClassTo) _first##NameTo;\
    int _count##NameTo;\
\
protected:\
\
public:\
    void Add##NameTo(ClassTo* item);\
    void Remove##NameTo(ClassTo* item);\
    void DeleteAll##NameTo();\
    void Replace##NameTo(ClassTo* item, ClassTo* newItem);\
    ClassTo* GetFirst##NameTo() const;\
    ClassTo* GetLast##NameTo() const;\
    ClassTo* GetNext##NameTo(ClassTo* pos) const;\
    ClassTo* GetPrev##NameTo(ClassTo* pos) const;\
    int Get##NameTo##Count() const;\
    ITERATOR_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define RELATION_NOFILTER_UNIQUEVALUETREE_OWNED_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
private:\
    CB_PTR(ClassTo) _first##NameTo;\
    int _count##NameTo;\
\
protected:\
\
public:\
    void Add##NameTo(ClassTo* item);\
    void Remove##NameTo(ClassTo* item);\
    void DeleteAll##NameTo();\
    void Replace##NameTo(ClassTo* item, ClassTo* newItem);\
    ClassTo* GetFirst##NameTo() const;\
    ClassTo* GetLast##NameTo() const;\
    ClassTo* GetNext##NameTo(ClassTo* pos) const;\
    ClassTo* GetPrev##NameTo(ClassTo* pos) const;\
    int Get##NameTo##Count() const;\
    ITERATOR_NOFILTER_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define RELATION_UNIQUEVALUETREE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    RELATION_UNIQUEVALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo)

// defines implementation
#define INIT_UNIQUEVALUETREE_OWNED_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
   INIT_UNIQUEVALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define EXIT_UNIQUEVALUETREE_OWNED_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    { for (ClassTo* item = GetFirst##NameTo(); item; item = GetFirst##NameTo())\
          delete item; }

#define REPLACE_UNIQUEVALUETREE_OWNED_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    REPLACE_UNIQUEVALUETREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define INIT_UNIQUEVALUETREE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    _ref##NameFrom = (ClassFrom*)0;\
    _parent##NameFrom = (ClassTo*)0;\
    _left##NameFrom = (ClassTo*)0;\
    _right##NameFrom = (ClassTo*)0;\
    assert(p##NameFrom);\
    p##NameFrom->Add##NameTo(this);

#define EXIT_UNIQUEVALUETREE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    EXIT_UNIQUEVALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define REPLACE_UNIQUEVALUETREE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    _ref##NameFrom = (ClassFrom*)0;\
    _parent##NameFrom = (ClassTo*)0;\
    _left##NameFrom = (ClassTo*)0;\
    _right##NameFrom = (ClassTo*)0;\
    pOld->_ref##NameFrom->Replace##NameTo(pOld, this);

#define REMOVE_UNIQUEVALUETREE_OWNED_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    { for (ClassTo* item = GetFirst##NameTo(); item; item = GetFirst##NameTo())\
          (void)new UndoSubDelete(item); }

#define SAVE_UNIQUEVALUETREE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    SAVE_UNIQUEVALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define RESTORE_UNIQUEVALUETREE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    RESTORE_UNIQUEVALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define REMOVE_UNIQUEVALUETREE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    REMOVE_UNIQUEVALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define CLEANUP_UNIQUEVALUETREE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    CLEANUP_UNIQUEVALUETREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define METHODS_UNIQUEVALUETREE_OWNED_ACTIVE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
void ClassFrom::Add##NameTo(ClassTo* item)\
{\
    METHOD_UNIQUEVALUETREE_ADD(member, ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::Remove##NameTo(ClassTo* item)\
{\
    METHOD_UNIQUEVALUETREE_REMOVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::DeleteAll##NameTo()\
{\
    METHOD_UNIQUEVALUETREE_DELETEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::Replace##NameTo(ClassTo* item, ClassTo* newItem)\
{\
    METHOD_UNIQUEVALUETREE_REPLACE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
ClassTo* ClassFrom::GetFirst##NameTo() const\
{\
    METHOD_UNIQUEVALUETREE_GETFIRST(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
ClassTo* ClassFrom::GetLast##NameTo() const\
{\
    METHOD_UNIQUEVALUETREE_GETLAST(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
ClassTo* ClassFrom::GetNext##NameTo(ClassTo* pos) const\
{\
    METHOD_UNIQUEVALUETREE_GETNEXT(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
ClassTo* ClassFrom::GetPrev##NameTo(ClassTo* pos) const\
{\
    METHOD_UNIQUEVALUETREE_GETPREV(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
int ClassFrom::Get##NameTo##Count() const\
{\
    METHOD_UNIQUEVALUETREE_GETCOUNT(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define METHODS_UNIQUEVALUETREE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#endif
