#ifndef CB_AVLTREE_OWNED_H
#define CB_AVLTREE_OWNED_H

#include "CB_AvlTree.h"

// defines for include files
#define RELATION_TEMPLATE_AVLTREE_OWNED_ACTIVE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
private:\
    CB_PTR(ClassTo) _top##NameTo;\
    int _count##NameTo;\
\
public:\
    void Add##NameTo(ClassTo* item)\
    {\
        METHOD_AVLTREE_ADD(member, ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Remove##NameTo(ClassTo* item)\
    {\
        METHOD_AVLTREE_REMOVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void RemoveAll##NameTo()\
    {\
        METHOD_AVLTREE_REMOVEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void DeleteAll##NameTo()\
    {\
        METHOD_AVLTREE_DELETEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Replace##NameTo(ClassTo* item, ClassTo* newItem)\
    {\
        METHOD_AVLTREE_REPLACE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetFirst##NameTo() const\
    {\
        METHOD_AVLTREE_GETFIRST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetLast##NameTo() const\
    {\
        METHOD_AVLTREE_GETLAST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetNext##NameTo(ClassTo* pos) const\
    {\
        METHOD_AVLTREE_GETNEXT(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetPrev##NameTo(ClassTo* pos) const\
    {\
        METHOD_AVLTREE_GETPREV(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    int Get##NameTo##Count() const\
    {\
        METHOD_AVLTREE_GETCOUNT(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ITERATOR_TEMPLATE_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define RELATION_TEMPLATE_NOFILTER_AVLTREE_OWNED_ACTIVE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
private:\
    CB_PTR(ClassTo) _top##NameTo;\
    int _count##NameTo;\
\
public:\
    void Add##NameTo(ClassTo* item)\
    {\
        METHOD_AVLTREE_ADD(member, ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Remove##NameTo(ClassTo* item)\
    {\
        METHOD_AVLTREE_REMOVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void RemoveAll##NameTo()\
    {\
        METHOD_AVLTREE_REMOVEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void DeleteAll##NameTo()\
    {\
        METHOD_AVLTREE_DELETEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    void Replace##NameTo(ClassTo* item, ClassTo* newItem)\
    {\
        METHOD_AVLTREE_REPLACE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetFirst##NameTo() const\
    {\
        METHOD_AVLTREE_GETFIRST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetLast##NameTo() const\
    {\
        METHOD_AVLTREE_GETLAST(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetNext##NameTo(ClassTo* pos) const\
    {\
        METHOD_AVLTREE_GETNEXT(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ClassTo* GetPrev##NameTo(ClassTo* pos) const\
    {\
        METHOD_AVLTREE_GETPREV(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    int Get##NameTo##Count() const\
    {\
        METHOD_AVLTREE_GETCOUNT(ClassFrom, NameFrom, ClassTo, NameTo) \
    }\
    ITERATOR_TEMPLATE_NOFILTER_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define RELATION_AVLTREE_OWNED_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
private:\
    CB_PTR(ClassTo) _top##NameTo;\
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

#define RELATION_NOFILTER_AVLTREE_OWNED_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
private:\
    CB_PTR(ClassTo) _top##NameTo;\
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

#define RELATION_AVLTREE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    RELATION_AVLTREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo)

// defines implementation
#define INIT_AVLTREE_OWNED_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
   INIT_AVLTREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define EXIT_AVLTREE_OWNED_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    {\
        ClassTo* lastItem = GetLast##NameTo();\
		ClassTo* item = lastItem;\
		ClassTo* prevItem;\
		while (item)\
	    {\
			prevItem = GetPrev##NameTo(item);\
		    item->_bal##NameFrom = intptr_t(prevItem);\
		    item = prevItem;\
	    }\
\
	    ClassFrom::NameTo##Iterator::CheckAll(this);\
		item = lastItem;\
		while (item)\
		{\
			prevItem = (ClassTo*)item->_bal##NameFrom;\
            item->_ref##NameFrom = (ClassFrom*)0;\
            item->_parent##NameFrom = (ClassTo*)0;\
            item->_left##NameFrom = (ClassTo*)0;\
            item->_right##NameFrom = (ClassTo*)0;\
            item->_bal##NameFrom = 0;\
            delete item;\
			item = prevItem;\
		}\
		_top##NameTo = (ClassTo*)0;\
		_count##NameTo = 0;\
	}

#define REPLACE_AVLTREE_OWNED_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    REPLACE_AVLTREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define INIT_AVLTREE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    _ref##NameFrom = (ClassFrom*)0;\
    _parent##NameFrom = (ClassTo*)0;\
    _left##NameFrom = (ClassTo*)0;\
    _right##NameFrom = (ClassTo*)0;\
    _bal##NameFrom = 0;\
    assert(p##NameFrom);\
    p##NameFrom->Add##NameTo(this);

#define EXIT_AVLTREE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    EXIT_AVLTREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define REPLACE_AVLTREE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    _ref##NameFrom = (ClassFrom*)0;\
    _parent##NameFrom = (ClassTo*)0;\
    _left##NameFrom = (ClassTo*)0;\
    _right##NameFrom = (ClassTo*)0;\
    _bal##NameFrom = 0;\
    pOld->_ref##NameFrom->Replace##NameTo(pOld, this);

#define REMOVE_AVLTREE_OWNED_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    while (_top##NameTo)\
    {\
        (void)new UndoSubDelete(_top##NameTo);\
    }

#define SAVE_AVLTREE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    SAVE_AVLTREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define RESTORE_AVLTREE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    RESTORE_AVLTREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define REMOVE_AVLTREE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    REMOVE_AVLTREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define CLEANUP_AVLTREE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    CLEANUP_AVLTREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define METHODS_AVLTREE_OWNED_ACTIVE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
void ClassFrom::Add##NameTo(ClassTo* item)\
{\
    METHOD_AVLTREE_ADD(member, ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::Remove##NameTo(ClassTo* item)\
{\
    METHOD_AVLTREE_REMOVE(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::DeleteAll##NameTo()\
{\
    METHOD_AVLTREE_DELETEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
void ClassFrom::Replace##NameTo(ClassTo* item, ClassTo* newItem)\
{\
    METHOD_AVLTREE_REPLACE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
ClassTo* ClassFrom::GetFirst##NameTo() const\
{\
    METHOD_AVLTREE_GETFIRST(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
ClassTo* ClassFrom::GetLast##NameTo() const\
{\
    METHOD_AVLTREE_GETLAST(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
ClassTo* ClassFrom::GetNext##NameTo(ClassTo* pos) const\
{\
    METHOD_AVLTREE_GETNEXT(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
ClassTo* ClassFrom::GetPrev##NameTo(ClassTo* pos) const\
{\
    METHOD_AVLTREE_GETPREV(ClassFrom, NameFrom, ClassTo, NameTo) \
}\
\
int ClassFrom::Get##NameTo##Count() const\
{\
    METHOD_AVLTREE_GETCOUNT(ClassFrom, NameFrom, ClassTo, NameTo) \
}

#define METHODS_AVLTREE_OWNED_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#endif
