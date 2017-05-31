#ifndef CB_AVLTREE_H
#define CB_AVLTREE_H

#include "CB_IteratorMulti.h"

// defines for include files
#define RELATION_TEMPLATE_AVLTREE_ACTIVE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
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

#define RELATION_TEMPLATE_NOFILTER_AVLTREE_ACTIVE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
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

#define RELATION_AVLTREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
private:\
    CB_PTR(ClassTo) _top##NameTo;\
    int _count##NameTo;\
\
public:\
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

#define RELATION_NOFILTER_AVLTREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
private:\
    CB_PTR(ClassTo) _top##NameTo;\
    int _count##NameTo;\
\
public:\
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

#define RELATION_AVLTREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
public:\
    CB_PTR(ClassFrom) _ref##NameFrom;\
    CB_PTR(ClassTo) _parent##NameFrom;\
    CB_PTR(ClassTo) _left##NameFrom;\
    CB_PTR(ClassTo) _right##NameFrom;\
    intptr_t _bal##NameFrom;\
\
public:\
    ClassFrom* Get##NameFrom() const { return _ref##NameFrom; };

// defines implementation
#define INIT_AVLTREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    _top##NameTo = (ClassTo*)0;\
    _count##NameTo = 0;

#define EXIT_AVLTREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    {\
        ClassTo* firstItem = GetFirst##NameTo();\
		ClassTo* item = firstItem;\
		ClassTo* nextItem;\
		while (item)\
	    {\
			nextItem = GetNext##NameTo(item);\
		    item->_bal##NameFrom = intptr_t(nextItem);\
		    item = nextItem;\
	    }\
\
	    ClassFrom::NameTo##Iterator::CheckAll(this);\
		item = firstItem;\
		while (item)\
		{\
			nextItem = (ClassTo*)item->_bal##NameFrom;\
            item->_ref##NameFrom = (ClassFrom*)0;\
            item->_parent##NameFrom = (ClassTo*)0;\
            item->_left##NameFrom = (ClassTo*)0;\
            item->_right##NameFrom = (ClassTo*)0;\
            item->_bal##NameFrom = 0;\
			item = nextItem;\
		}\
		_top##NameTo = (ClassTo*)0;\
		_count##NameTo = 0;\
	}

#define REPLACE_AVLTREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    _top##NameTo = pOld->_top##NameTo;\
    _count##NameTo = pOld->_count##NameTo;\
    pOld->_top##NameTo = (ClassTo*)0;\
    { for (ClassTo* item = GetFirst##NameTo(); item; item = GetNext##NameTo(item))\
          item->_ref##NameFrom = this; }

#define INIT_AVLTREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    _ref##NameFrom = (ClassFrom*)0;\
    _parent##NameFrom = (ClassTo*)0;\
    _left##NameFrom = (ClassTo*)0;\
    _right##NameFrom = (ClassTo*)0;\
    _bal##NameFrom = 0;

#define EXIT_AVLTREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    if (_ref##NameFrom)\
        _ref##NameFrom->Remove##NameTo(this);

#define REPLACE_AVLTREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    _ref##NameFrom = (ClassFrom*)0;\
    _parent##NameFrom = (ClassTo*)0;\
    _left##NameFrom = (ClassTo*)0;\
    _right##NameFrom = (ClassTo*)0;\
    _bal##NameFrom = 0;\
    if (pOld->_ref##NameFrom)\
        pOld->_ref##NameFrom->Replace##NameTo(pOld, this);

#define REMOVE_AVLTREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    while (_top##NameTo)\
    {\
        (void)new UndoSubChange(_top##NameTo);\
        Remove##NameTo(_top##NameTo);\
    }

#define SAVE_AVLTREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    p##ClassTo->_ref##NameFrom = _ref##NameFrom;

#define RESTORE_AVLTREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    {\
        ClassFrom* p##ClassFrom = p##ClassTo->_ref##NameFrom;\
        _ref##NameFrom = (ClassFrom*)0;\
        _bal##NameFrom = 0;\
        p##ClassFrom->Add##NameTo(this);\
    }\

#define REMOVE_AVLTREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    if (_ref##NameFrom)\
    {\
        ClassFrom* p##ClassFrom = _ref##NameFrom;\
        _ref##NameFrom->Remove##NameTo(this);\
        _ref##NameFrom = p##ClassFrom;\
    }

#define CLEANUP_AVLTREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    _ref##NameFrom = (ClassFrom*)0;\
    _parent##NameFrom = (ClassTo*)0;\
    _left##NameFrom = (ClassTo*)0;\
    _right##NameFrom = (ClassTo*)0;\
    _bal##NameFrom = 0;

#define METHODS_AVLTREE_ACTIVE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
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
void ClassFrom::RemoveAll##NameTo()\
{\
    METHOD_AVLTREE_REMOVEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
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

#define METHOD_AVLTREE_ADD(member, ClassFrom, NameFrom, ClassTo, NameTo) \
    assert(this);\
\
    assert(item);\
    assert(item->_ref##NameFrom == (ClassFrom*)0);\
\
    _count##NameTo++;\
\
    item->_ref##NameFrom = this;\
\
    if (_top##NameTo)\
    {\
        ClassTo* current = _top##NameTo;\
        while (1)\
        {\
            if (item->member < current->member)\
            {\
                if (current->_left##NameFrom)\
                {\
                    current = current->_left##NameFrom;\
                }\
                else\
                {\
                    current->_left##NameFrom = item;\
                    item->_parent##NameFrom = current;\
                    current->_bal##NameFrom--;\
                    break;\
                }\
            }\
            else\
            {\
                if (current->_right##NameFrom)\
                {\
                    current = current->_right##NameFrom;\
                }\
                else\
                {\
                    current->_right##NameFrom = item;\
                    item->_parent##NameFrom = current;\
                    current->_bal##NameFrom++;\
                    break;\
                }\
            }\
        }\
\
        ClassTo* parent;\
        while (current && current->_bal##NameFrom)\
        {\
            parent = current->_parent##NameFrom;\
            if (parent)\
            {\
                if (parent->_left##NameFrom == current)\
                {\
                    parent->_bal##NameFrom--;\
                }\
                else\
                {\
                    parent->_bal##NameFrom++;\
                }\
\
                if (parent->_bal##NameFrom == 2)\
                {\
                    if (current->_bal##NameFrom == -1)\
                    {\
                        ClassTo* sub = current->_left##NameFrom;\
                        parent->_right##NameFrom = sub->_left##NameFrom;\
                        if (sub->_left##NameFrom)\
                        {\
                            sub->_left##NameFrom->_parent##NameFrom = parent;\
                        }\
                        current->_left##NameFrom = sub->_right##NameFrom;\
                        if (sub->_right##NameFrom)\
                        {\
                            sub->_right##NameFrom->_parent##NameFrom = current;\
                        }\
                        sub->_parent##NameFrom = parent->_parent##NameFrom;\
                        sub->_left##NameFrom = parent;\
                        parent->_parent##NameFrom = sub;\
                        sub->_right##NameFrom = current;\
                        current->_parent##NameFrom = sub;\
                        if (sub->_parent##NameFrom)\
                        {\
                            if (sub->_parent##NameFrom->_left##NameFrom == parent)\
                            {\
                                sub->_parent##NameFrom->_left##NameFrom = sub;\
                            }\
                            else\
                            {\
                                sub->_parent##NameFrom->_right##NameFrom = sub;\
                            }\
                        }\
                        else\
                        {\
                            _top##NameTo = sub;\
                        }\
                        parent->_bal##NameFrom = (sub->_bal##NameFrom == 1? -1: 0);\
                        current->_bal##NameFrom = (sub->_bal##NameFrom == -1? 1: 0);\
                        sub->_bal##NameFrom = 0;\
                        current = sub;\
                    }\
                    else\
                    {\
                        parent->_right##NameFrom = current->_left##NameFrom;\
                        if (current->_left##NameFrom)\
                        {\
                            current->_left##NameFrom->_parent##NameFrom = parent;\
                        }\
                        current->_left##NameFrom = parent;\
                        current->_parent##NameFrom = parent->_parent##NameFrom;\
                        parent->_parent##NameFrom = current;\
                        if (current->_parent##NameFrom)\
                        {\
                            if (current->_parent##NameFrom->_left##NameFrom == parent)\
                            {\
                                current->_parent##NameFrom->_left##NameFrom = current;\
                            }\
                            else\
                            {\
                                current->_parent##NameFrom->_right##NameFrom = current;\
                            }\
                        }\
                        else\
                        {\
                            _top##NameTo = current;\
                        }\
                        parent->_bal##NameFrom = 0;\
                        current->_bal##NameFrom = 0;\
                    }\
                }\
                else if (parent->_bal##NameFrom == -2)\
                {\
                    if (current->_bal##NameFrom == 1)\
                    {\
                        ClassTo* sub = current->_right##NameFrom;\
                        parent->_left##NameFrom = sub->_right##NameFrom;\
                        if (sub->_right##NameFrom)\
                        {\
                            sub->_right##NameFrom->_parent##NameFrom = parent;\
                        }\
                        current->_right##NameFrom = sub->_left##NameFrom;\
                        if (sub->_left##NameFrom)\
                        {\
                            sub->_left##NameFrom->_parent##NameFrom = current;\
                        }\
                        sub->_parent##NameFrom = parent->_parent##NameFrom;\
                        sub->_right##NameFrom = parent;\
                        parent->_parent##NameFrom = sub;\
                        sub->_left##NameFrom = current;\
                        current->_parent##NameFrom = sub;\
                        if (sub->_parent##NameFrom)\
                        {\
                            if (sub->_parent##NameFrom->_right##NameFrom == parent)\
                            {\
                                sub->_parent##NameFrom->_right##NameFrom = sub;\
                            }\
                            else\
                            {\
                                sub->_parent##NameFrom->_left##NameFrom = sub;\
                            }\
                        }\
                        else\
                        {\
                            _top##NameTo = sub;\
                        }\
                        parent->_bal##NameFrom = (sub->_bal##NameFrom == -1? 1: 0);\
                        current->_bal##NameFrom = (sub->_bal##NameFrom == 1? -1: 0);\
                        sub->_bal##NameFrom = 0;\
                        current = sub;\
                    }\
                    else\
                    {\
                        parent->_left##NameFrom = current->_right##NameFrom;\
                        if (current->_right##NameFrom)\
                        {\
                            current->_right##NameFrom->_parent##NameFrom = parent;\
                        }\
                        current->_right##NameFrom = parent;\
                        current->_parent##NameFrom = parent->_parent##NameFrom;\
                        parent->_parent##NameFrom = current;\
                        if (current->_parent##NameFrom)\
                        {\
                            if (current->_parent##NameFrom->_right##NameFrom == parent)\
                            {\
                                current->_parent##NameFrom->_right##NameFrom = current;\
                            }\
                            else\
                            {\
                                current->_parent##NameFrom->_left##NameFrom = current;\
                            }\
                        }\
                        else\
                        {\
                            _top##NameTo = current;\
                        }\
                        parent->_bal##NameFrom = 0;\
                        current->_bal##NameFrom = 0;\
                    }\
                }\
                else\
                {\
                    current = parent;\
                }\
            }\
            else\
            {\
                current = parent;\
            }\
        }\
    }\
    else\
    {\
        _top##NameTo = item;\
    }

#define METHOD_AVLTREE_REMOVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    assert(this);\
\
    assert(item);\
    assert(item->_ref##NameFrom == this);\
\
    ClassFrom::NameTo##Iterator::Check(item);\
\
    _count##NameTo--;\
\
    ClassTo* subParent = item->_parent##NameFrom;\
    ClassTo* sub = item;\
    /*     item               -                                   */\
    /*      ^        ==>                                          */\
    /*     - -                                                    */\
    if (!item->_left##NameFrom && !item->_right##NameFrom)\
    {\
        if (subParent)\
        {\
            if (subParent->_left##NameFrom == item)\
            {\
                subParent->_left##NameFrom = (ClassTo*)0;\
                subParent->_bal##NameFrom++;\
            }\
            else\
            {\
                subParent->_right##NameFrom = (ClassTo*)0;\
                subParent->_bal##NameFrom--;\
            }\
        }\
        else\
        {\
            _top##NameTo = (ClassTo*)0;\
        }\
    }\
    else\
    {\
        if (item->_bal##NameFrom > 0)\
        {\
            sub = item->_right##NameFrom;\
            while (sub->_left##NameFrom)\
            {\
                sub = sub->_left##NameFrom;\
            }\
            subParent = sub->_parent##NameFrom;\
            if (subParent != item)\
            {\
                subParent->_left##NameFrom = sub->_right##NameFrom;\
                if (subParent->_left##NameFrom)\
                {\
                    subParent->_left##NameFrom->_parent##NameFrom = subParent;\
                }\
                subParent->_bal##NameFrom++;\
            }\
            else\
            {\
                item->_bal##NameFrom--;\
            }\
        }\
        else\
        {\
            sub = item->_left##NameFrom;\
            while (sub->_right##NameFrom)\
            {\
                sub = sub->_right##NameFrom;\
            }\
            subParent = sub->_parent##NameFrom;\
            if (subParent != item)\
            {\
                subParent->_right##NameFrom = sub->_left##NameFrom;\
                if (subParent->_right##NameFrom)\
                {\
                    subParent->_right##NameFrom->_parent##NameFrom = subParent;\
                }\
                subParent->_bal##NameFrom--;\
            }\
            else\
            {\
                item->_bal##NameFrom++;\
            }\
        }\
        sub->_parent##NameFrom = item->_parent##NameFrom;\
        if (item->_parent##NameFrom)\
        {\
            if (item->_parent##NameFrom->_left##NameFrom == item)\
            {\
                item->_parent##NameFrom->_left##NameFrom = sub;\
            }\
            else\
            {\
                item->_parent##NameFrom->_right##NameFrom = sub;\
            }\
        }\
        else\
        {\
            _top##NameTo = sub;\
        }\
        if (item->_left##NameFrom != sub)\
        {\
            sub->_left##NameFrom = item->_left##NameFrom;\
            if (item->_left##NameFrom)\
            {\
                item->_left##NameFrom->_parent##NameFrom = sub;\
            }\
        }\
        if (item->_right##NameFrom != sub)\
        {\
            sub->_right##NameFrom = item->_right##NameFrom;\
            if (item->_right##NameFrom)\
            {\
                item->_right##NameFrom->_parent##NameFrom = sub;\
            }\
        }\
        sub->_bal##NameFrom = item->_bal##NameFrom;\
\
        if (subParent == item)\
        {\
            subParent = sub;\
        }\
    }\
\
    item->_ref##NameFrom = (ClassFrom*)0;\
    item->_parent##NameFrom = (ClassTo*)0;\
    item->_left##NameFrom = (ClassTo*)0;\
    item->_right##NameFrom = (ClassTo*)0;\
    item->_bal##NameFrom = 0;\
\
    ClassTo* parent = subParent;\
    while (parent && parent->_bal##NameFrom != -1 && parent->_bal##NameFrom != 1)\
    {\
        if (parent->_bal##NameFrom == 2)\
        {\
            ClassTo* current = parent->_right##NameFrom;\
            if (current->_bal##NameFrom == -1)\
            {\
                ClassTo* sub = current->_left##NameFrom;\
                parent->_right##NameFrom = sub->_left##NameFrom;\
                if (sub->_left##NameFrom)\
                {\
                    sub->_left##NameFrom->_parent##NameFrom = parent;\
                }\
                current->_left##NameFrom = sub->_right##NameFrom;\
                if (sub->_right##NameFrom)\
                {\
                    sub->_right##NameFrom->_parent##NameFrom = current;\
                }\
                sub->_parent##NameFrom = parent->_parent##NameFrom;\
                sub->_left##NameFrom = parent;\
                parent->_parent##NameFrom = sub;\
                sub->_right##NameFrom = current;\
                current->_parent##NameFrom = sub;\
                if (sub->_parent##NameFrom)\
                {\
                    if (sub->_parent##NameFrom->_left##NameFrom == parent)\
                    {\
                        sub->_parent##NameFrom->_left##NameFrom = sub;\
                    }\
                    else\
                    {\
                        sub->_parent##NameFrom->_right##NameFrom = sub;\
                    }\
                }\
                else\
                {\
                    _top##NameTo = sub;\
                }\
                parent->_bal##NameFrom = (sub->_bal##NameFrom == 1? -1: 0);\
                current->_bal##NameFrom = (sub->_bal##NameFrom == -1? 1: 0);\
                sub->_bal##NameFrom = 0;\
                parent = sub;\
            }\
            else if (current->_bal##NameFrom == 1)\
            {\
                parent->_right##NameFrom = current->_left##NameFrom;\
                if (current->_left##NameFrom)\
                {\
                    current->_left##NameFrom->_parent##NameFrom = parent;\
                }\
                current->_left##NameFrom = parent;\
                current->_parent##NameFrom = parent->_parent##NameFrom;\
                parent->_parent##NameFrom = current;\
                if (current->_parent##NameFrom)\
                {\
                    if (current->_parent##NameFrom->_left##NameFrom == parent)\
                    {\
                        current->_parent##NameFrom->_left##NameFrom = current;\
                    }\
                    else\
                    {\
                        current->_parent##NameFrom->_right##NameFrom = current;\
                    }\
                }\
                else\
                {\
                    _top##NameTo = current;\
                }\
                parent->_bal##NameFrom = 0;\
                current->_bal##NameFrom = 0;\
                parent = current;\
            }\
            else\
            {\
                parent->_right##NameFrom = current->_left##NameFrom;\
                if (current->_left##NameFrom)\
                {\
                    current->_left##NameFrom->_parent##NameFrom = parent;\
                }\
                current->_left##NameFrom = parent;\
                current->_parent##NameFrom = parent->_parent##NameFrom;\
                parent->_parent##NameFrom = current;\
                if (current->_parent##NameFrom)\
                {\
                    if (current->_parent##NameFrom->_left##NameFrom == parent)\
                    {\
                        current->_parent##NameFrom->_left##NameFrom = current;\
                    }\
                    else\
                    {\
                        current->_parent##NameFrom->_right##NameFrom = current;\
                    }\
                }\
                else\
                {\
                    _top##NameTo = current;\
                }\
                parent->_bal##NameFrom = 1;\
                current->_bal##NameFrom = -1;\
                break;\
            }\
        }\
        else if (parent->_bal##NameFrom == -2)\
        {\
            ClassTo* current = parent->_left##NameFrom;\
            if (current->_bal##NameFrom == 1)\
            {\
                ClassTo* sub = current->_right##NameFrom;\
                parent->_left##NameFrom = sub->_right##NameFrom;\
                if (sub->_right##NameFrom)\
                {\
                    sub->_right##NameFrom->_parent##NameFrom = parent;\
                }\
                current->_right##NameFrom = sub->_left##NameFrom;\
                if (sub->_left##NameFrom)\
                {\
                    sub->_left##NameFrom->_parent##NameFrom = current;\
                }\
                sub->_parent##NameFrom = parent->_parent##NameFrom;\
                sub->_right##NameFrom = parent;\
                parent->_parent##NameFrom = sub;\
                sub->_left##NameFrom = current;\
                current->_parent##NameFrom = sub;\
                if (sub->_parent##NameFrom)\
                {\
                    if (sub->_parent##NameFrom->_right##NameFrom == parent)\
                    {\
                        sub->_parent##NameFrom->_right##NameFrom = sub;\
                    }\
                    else\
                    {\
                        sub->_parent##NameFrom->_left##NameFrom = sub;\
                    }\
                }\
                else\
                {\
                    _top##NameTo = sub;\
                }\
                parent->_bal##NameFrom = (sub->_bal##NameFrom == -1? 1: 0);\
                current->_bal##NameFrom = (sub->_bal##NameFrom == 1? -1: 0);\
                sub->_bal##NameFrom = 0;\
                parent = sub;\
            }\
            else if (current->_bal##NameFrom == -1)\
            {\
                parent->_left##NameFrom = current->_right##NameFrom;\
                if (current->_right##NameFrom)\
                {\
                    current->_right##NameFrom->_parent##NameFrom = parent;\
                }\
                current->_right##NameFrom = parent;\
                current->_parent##NameFrom = parent->_parent##NameFrom;\
                parent->_parent##NameFrom = current;\
                if (current->_parent##NameFrom)\
                {\
                    if (current->_parent##NameFrom->_right##NameFrom == parent)\
                    {\
                        current->_parent##NameFrom->_right##NameFrom = current;\
                    }\
                    else\
                    {\
                        current->_parent##NameFrom->_left##NameFrom = current;\
                    }\
                }\
                else\
                {\
                    _top##NameTo = current;\
                }\
                parent->_bal##NameFrom = 0;\
                current->_bal##NameFrom = 0;\
                parent = current;\
            }\
            else\
            {\
                parent->_left##NameFrom = current->_right##NameFrom;\
                if (current->_right##NameFrom)\
                {\
                    current->_right##NameFrom->_parent##NameFrom = parent;\
                }\
                current->_right##NameFrom = parent;\
                current->_parent##NameFrom = parent->_parent##NameFrom;\
                parent->_parent##NameFrom = current;\
                if (current->_parent##NameFrom)\
                {\
                    if (current->_parent##NameFrom->_right##NameFrom == parent)\
                    {\
                        current->_parent##NameFrom->_right##NameFrom = current;\
                    }\
                    else\
                    {\
                        current->_parent##NameFrom->_left##NameFrom = current;\
                    }\
                }\
                else\
                {\
                    _top##NameTo = current;\
                }\
                parent->_bal##NameFrom = -1;\
                current->_bal##NameFrom = 1;\
                break;\
            }\
        }\
\
        if (parent->_parent##NameFrom)\
        {\
            if (parent->_parent##NameFrom->_left##NameFrom == parent)\
            {\
                parent->_parent##NameFrom->_bal##NameFrom++;\
            }\
            else\
            {\
                parent->_parent##NameFrom->_bal##NameFrom--;\
            }\
        }\
\
        parent = parent->_parent##NameFrom;\
    }\

#define METHOD_AVLTREE_REMOVEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
    assert(this);\
\
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
			item = prevItem;\
		}\
		_top##NameTo = (ClassTo*)0;\
		_count##NameTo = 0;\
	}

#define METHOD_AVLTREE_DELETEALL(ClassFrom, NameFrom, ClassTo, NameTo) \
    assert(this);\
\
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

#define METHOD_AVLTREE_REPLACE(member, ClassFrom, NameFrom, ClassTo, NameTo) \
    assert(this);\
\
    assert(item);\
    assert(item->_ref##NameFrom == this);\
\
    assert(newItem);\
    assert(newItem->_ref##NameFrom == (ClassFrom*)0);\
\
    if (item->member == newItem->member)\
    {\
        ClassFrom::NameTo##Iterator::Check(item, newItem);\
        if (_top##NameTo == item)\
        {\
            _top##NameTo = newItem;\
        }\
        if (item->_parent##NameFrom)\
        {\
            if (item->_parent##NameFrom->_left##NameFrom == item)\
            {\
                item->_parent##NameFrom->_left##NameFrom = newItem;\
            }\
            else if (item->_parent##NameFrom->_right##NameFrom == item)\
            {\
                item->_parent##NameFrom->_right##NameFrom = newItem;\
            }\
        }\
		if (item->_left##NameFrom)\
		{\
			item->_left##NameFrom->_parent##NameFrom = newItem;\
		}\
		if (item->_right##NameFrom)\
		{\
			item->_right##NameFrom->_parent##NameFrom = newItem;\
		}\
        newItem->_ref##NameFrom = this;\
        newItem->_parent##NameFrom = item->_parent##NameFrom;\
        newItem->_left##NameFrom = item->_left##NameFrom;\
        newItem->_right##NameFrom = item->_right##NameFrom;\
        newItem->_bal##NameFrom = item->_bal##NameFrom;\
        item->_ref##NameFrom = (ClassFrom*)0;\
        item->_parent##NameFrom = (ClassTo*)0;\
        item->_left##NameFrom = (ClassTo*)0;\
        item->_right##NameFrom = (ClassTo*)0;\
        item->_bal##NameFrom = 0;\
    }\
    else\
    {\
        ClassFrom::NameTo##Iterator::Check(item);\
        Remove##NameTo(item);\
        Add##NameTo(newItem);\
    }

#define METHOD_AVLTREE_GETFIRST(ClassFrom, NameFrom, ClassTo, NameTo) \
    assert(this);\
\
    ClassTo* result = _top##NameTo;\
    if (result)\
    {\
        while (result->_left##NameFrom)\
        {\
            result = result->_left##NameFrom;\
        }\
    }\
\
    return result;

#define METHOD_AVLTREE_GETLAST(ClassFrom, NameFrom, ClassTo, NameTo) \
    assert(this);\
\
    ClassTo* result = _top##NameTo;\
    if (result)\
    {\
        while (result->_right##NameFrom)\
        {\
            result = result->_right##NameFrom;\
        }\
    }\
\
    return result;

#define METHOD_AVLTREE_GETNEXT(ClassFrom, NameFrom, ClassTo, NameTo) \
    assert(this);\
\
    ClassTo* result = 0;\
    if (pos == (ClassTo*)0)\
    {\
        result = _top##NameTo;\
        if (result)\
        {\
            while (result->_left##NameFrom)\
            {\
                result = result->_left##NameFrom;\
            }\
        }\
    }\
    else\
    {\
        assert(pos->_ref##NameFrom == this);\
\
        if (pos->_right##NameFrom)\
        {\
            result = pos->_right##NameFrom;\
            while (result->_left##NameFrom)\
            {\
                result = result->_left##NameFrom;\
            }\
        }\
        else\
        {\
            result = pos->_parent##NameFrom;\
            while (result && result->_right##NameFrom == pos)\
            {\
                pos = result;\
                result = pos->_parent##NameFrom;\
            }\
        }\
    }\
\
    return result;

#define METHOD_AVLTREE_GETPREV(ClassFrom, NameFrom, ClassTo, NameTo) \
    assert(this);\
\
    ClassTo* result = 0;\
    if (pos == (ClassTo*)0)\
    {\
        result = _top##NameTo;\
        if (result)\
        {\
            while (result->_right##NameFrom)\
            {\
                result = result->_right##NameFrom;\
            }\
        }\
    }\
    else\
    {\
        assert(pos->_ref##NameFrom == this);\
\
        if (pos->_left##NameFrom)\
        {\
            result = pos->_left##NameFrom;\
            while (result->_right##NameFrom)\
            {\
                result = result->_right##NameFrom;\
            }\
        }\
        else\
        {\
            result = pos->_parent##NameFrom;\
            while (result && result->_left##NameFrom == pos)\
            {\
                pos = result;\
                result = pos->_parent##NameFrom;\
            }\
        }\
    }\
\
    return result;

#define METHOD_AVLTREE_GETCOUNT(ClassFrom, NameFrom, ClassTo, NameTo) \
    assert(this);\
    return _count##NameTo;

#define METHODS_AVLTREE_PASSIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#ifndef _BODY_AVLTREE_FIND
#define _BODY_AVLTREE_FIND(member, value, ClassFrom, NameFrom, ClassTo, NameTo) \
    ClassTo* result = 0;\
    if (_top##NameTo)\
    {\
        ClassTo* item = _top##NameTo;\
        while (1)\
        {\
            if (item->member == value)\
            {\
                result = item;\
                break;\
            }\
\
            if (value <= item->member)\
            {\
                if (item->_left##NameFrom)\
                {\
                    item = item->_left##NameFrom;\
                }\
                else\
                {\
                    break;\
                }\
            }\
            else\
            {\
                if (item->_right##NameFrom)\
                {\
                    item = item->_right##NameFrom;\
                }\
                else\
                {\
                    break;\
                }\
            }\
        }\
    }
#endif

#define BODY_AVLTREE_FIND(member, value, ClassFrom, NameFrom, ClassTo, NameTo) \
    _BODY_AVLTREE_FIND(member, value, ClassFrom, NameFrom, ClassTo, NameTo) \
    if (result)\
    {\
        ClassTo* prev##NameTo = GetPrev##NameTo(result);\
        while (prev##NameTo && prev##NameTo->member == value)\
        {\
            result = prev##NameTo;\
            prev##NameTo = GetPrev##NameTo(result);\
        }\
    }\
    return result;

#define BODY_AVLTREE_FINDREVERSE(member, value, ClassFrom, NameFrom, ClassTo, NameTo) \
    _BODY_AVLTREE_FIND(member, value, ClassFrom, NameFrom, ClassTo, NameTo) \
    if (result)\
    {\
        ClassTo* next##NameTo = GetNext##NameTo(result);\
        while (next##NameTo && next##NameTo->member == value)\
        {\
            result = next##NameTo;\
            next##NameTo = GetNext##NameTo(result);\
        }\
    }\
    return result;

#define BODY_AVLTREE_FINDEQUALORBIGGER(member, value, ClassFrom, NameFrom, ClassTo, NameTo) \
    ClassTo* result = 0;\
    if (_top##NameTo)\
    {\
        ClassTo* item = _top##NameTo;\
        while (1)\
        {\
            if (item->member == value)\
            {\
                result = item;\
                ClassTo* prev##NameTo = GetPrev##NameTo(result);\
                while (prev##NameTo && prev##NameTo->member == value)\
                {\
                    result = prev##NameTo;\
                    prev##NameTo = GetPrev##NameTo(result);\
                }\
                break;\
            }\
\
            if (value <= item->member)\
            {\
                if (item->_left##NameFrom)\
                {\
                    item = item->_left##NameFrom;\
                }\
                else\
                {\
                    result = item;\
                    break;\
                }\
            }\
            else\
            {\
                if (item->_right##NameFrom)\
                {\
                    item = item->_right##NameFrom;\
                }\
                else\
                {\
                    result = GetNext##NameTo(item);\
                    break;\
                }\
            }\
        }\
    }\
\
    return result;


#define BODY_AVLTREE_FINDEQUALORSMALLER(member, value, ClassFrom, NameFrom, ClassTo, NameTo) \
    ClassTo* result = 0;\
    if (_top##NameTo)\
    {\
        ClassTo* item = _top##NameTo;\
        while (1)\
        {\
            if (item->member == value)\
            {\
                result = item;\
                ClassTo* next##NameTo = GetNext##NameTo(result);\
                while (next##NameTo && next##NameTo->member == value)\
                {\
                    result = next##NameTo;\
                    next##NameTo = GetNext##NameTo(result);\
                }\
                break;\
            }\
\
            if (value <= item->member)\
            {\
                if (item->_left##NameFrom)\
                {\
                    item = item->_left##NameFrom;\
                }\
                else\
                {\
                    result = GetPrev##NameTo(item);\
                    break;\
                }\
            }\
            else\
            {\
                if (item->_right##NameFrom)\
                {\
                    item = item->_right##NameFrom;\
                }\
                else\
                {\
                    result = item;\
                    break;\
                }\
            }\
        }\
    }\
\
    return result;

#define WRITE_AVLTREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    archive << Get##NameTo##Count();\
    { for (ClassTo* item = GetFirst##NameTo(); item; item = GetNext##NameTo(item))\
          archive << item->_index; }

#define READ_AVLTREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    {\
        int count;\
        int index;\
\
        archive >> count;\
        for (int i = 0; i < count; i++)\
        {\
            archive >> index;\
            Add##NameTo(static_cast<ClassTo*>(pointerArray[index]));\
        }\
    }

#define DYNAMIC_READ_AVLTREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    {\
        int count;\
        int index;\
\
        archive >> count;\
        for (int i = 0; i < count; i++)\
        {\
            archive >> index;\
            Add##NameTo(dynamic_cast<ClassTo*>(pointerArray[index]));\
        }\
    }

#endif
