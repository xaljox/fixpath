#ifndef CB_ITERATOR_MULTI_H
#define CB_ITERATOR_MULTI_H

#include <assert.h>
#include "CB_CriticalSection.h"

#ifdef _AFXEXT
#define CB_EXT_CLASS       AFX_CLASS_EXPORT
#else
#define CB_EXT_CLASS
#endif

#ifndef CB_PTR
#define CB_PTR(ClassName) ClassName*
#endif

#define ITERATOR_TEMPLATE_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    class CB_EXT_CLASS NameTo##Iterator\
    {\
    private:\
		static CriticalSection& CriticalSection##NameTo()\
		{\
			static CriticalSection criticalSection##NameTo;\
			return criticalSection##NameTo;\
		}\
	    \
        ClassTo* _ref##NameTo;\
        ClassTo* _prev##NameTo;\
        ClassTo* _next##NameTo;\
        const ClassFrom* _iter##NameFrom;\
        \
        NameTo##Iterator* _prev;\
        NameTo##Iterator* _next;\
        \
        int (ClassTo::*_method)() const;\
        \
        static NameTo##Iterator*& First()\
        {\
            static NameTo##Iterator* first = 0;\
            return first;\
        }\
        static NameTo##Iterator*& Last()\
        {\
            static NameTo##Iterator* last = 0;\
            return last;\
        }\
        \
    public:\
        NameTo##Iterator(const ClassFrom* iter##NameFrom,\
                         int (ClassTo::*method)() const = 0,\
                         ClassTo* ref##NameTo = 0)\
        {\
            assert(iter##NameFrom);\
            CriticalSectionLock lock(CriticalSection##NameTo());\
            \
            _iter##NameFrom = iter##NameFrom;\
            _ref##NameTo = _prev##NameTo = _next##NameTo = ref##NameTo;\
            _prev = (NameTo##Iterator*)0;\
            _next = (NameTo##Iterator*)0;\
            _method = method;\
            if (Last())\
            {\
                Last()->_next = this;\
                _prev = Last();\
                Last() = this;\
            }\
            else\
                First() = Last() = this;\
        }\
        NameTo##Iterator(const ClassFrom& iter##NameFrom,\
                         int (ClassTo::*method)() const = 0,\
                         ClassTo* ref##NameTo = 0)\
        {\
            assert(&iter##NameFrom);\
            CriticalSectionLock lock(CriticalSection##NameTo());\
            \
            _iter##NameFrom = &iter##NameFrom;\
            _ref##NameTo = _prev##NameTo = _next##NameTo = ref##NameTo;\
            _prev = (NameTo##Iterator*)0;\
            _next = (NameTo##Iterator*)0;\
            _method = method;\
            if (Last())\
            {\
                Last()->_next = this;\
                _prev = Last();\
                Last() = this;\
            }\
            else\
                First() = Last() = this;\
        }\
        NameTo##Iterator(const NameTo##Iterator& iterator__,\
                         int (ClassTo::*method)() const = 0)\
        {\
            CriticalSectionLock lock(CriticalSection##NameTo());\
            \
            _iter##NameFrom = iterator__._iter##NameFrom;\
            _ref##NameTo = iterator__._ref##NameTo;\
            _prev##NameTo = iterator__._prev##NameTo;\
            _next##NameTo = iterator__._next##NameTo;\
            _prev = (NameTo##Iterator*)0;\
            _next = (NameTo##Iterator*)0;\
            _method = method;\
            if (Last())\
            {\
                Last()->_next = this;\
                _prev = Last();\
                Last() = this;\
            }\
            else\
                First() = Last() = this;\
        }\
        ~NameTo##Iterator()\
        {\
            CriticalSectionLock lock(CriticalSection##NameTo());\
            \
            if (_next)\
                _next->_prev = _prev;\
            else\
                Last() = _prev;\
        \
            if (_prev)\
                _prev->_next = _next;\
            else\
                First() = _next;\
        }\
        \
        NameTo##Iterator& operator= (const NameTo##Iterator& iterator__)\
        {\
            _iter##NameFrom = iterator__._iter##NameFrom;\
            _ref##NameTo = iterator__._ref##NameTo;\
            _prev##NameTo = iterator__._prev##NameTo;\
            _next##NameTo = iterator__._next##NameTo;\
            _method = iterator__._method;\
            return *this;\
        }\
        ClassTo* operator++ ()\
        {\
            _next##NameTo = _iter##NameFrom->GetNext##NameTo(_next##NameTo);\
            if (_method != 0)\
            {\
                while (_next##NameTo && !(_next##NameTo->*_method)())\
                    _next##NameTo = _iter##NameFrom->GetNext##NameTo(_next##NameTo);\
            }\
            _ref##NameTo = _prev##NameTo = _next##NameTo;\
            return _ref##NameTo;\
        }\
        ClassTo* operator-- ()\
        {\
            _prev##NameTo = _iter##NameFrom->GetPrev##NameTo(_prev##NameTo);\
            if (_method != 0)\
            {\
                while (_prev##NameTo && !(_prev##NameTo->*_method)())\
                    _prev##NameTo = _iter##NameFrom->GetPrev##NameTo(_prev##NameTo);\
            }\
            _ref##NameTo = _next##NameTo = _prev##NameTo;\
            return _ref##NameTo;\
        }\
        operator ClassTo*() { return _ref##NameTo; }\
        ClassTo* operator-> () { return _ref##NameTo; }\
        ClassTo* Get() { return _ref##NameTo; }\
        void Reset() { _ref##NameTo = _prev##NameTo = _next##NameTo = (ClassTo*)0; }\
        \
        int IsLast() { return (_iter##NameFrom->GetLast##NameTo() == _ref##NameTo); }\
        int IsFirst() { return (_iter##NameFrom->GetFirst##NameTo() == _ref##NameTo); }\
        \
        static void Check(ClassTo* item##NameTo)\
        {\
            if (First())\
            {\
                CriticalSectionLock lock(CriticalSection##NameTo());\
                \
                for (NameTo##Iterator* item = First(); item; item = item->_next)\
                {\
                    if (item->_prev##NameTo == item##NameTo)\
                    {\
                        item->_prev##NameTo = item->_iter##NameFrom->GetNext##NameTo(item->_prev##NameTo);\
                        item->_ref##NameTo = 0;\
                    }\
                    if (item->_next##NameTo == item##NameTo)\
                    {\
                        item->_next##NameTo = item->_iter##NameFrom->GetPrev##NameTo(item->_next##NameTo);\
                        item->_ref##NameTo = 0;\
                    }\
                }\
            }\
        }\
        static void CheckAll(ClassFrom* item##NameFrom)\
        {\
            if (First())\
            {\
                CriticalSectionLock lock(CriticalSection##NameTo());\
                \
                for (NameTo##Iterator* item = First(); item; item = item->_next)\
                {\
                    if (item->_iter##NameFrom == item##NameFrom)\
                    {\
                        item->_prev##NameTo = 0;\
                        item->_ref##NameTo = 0;\
    					item->_next##NameTo = 0;\
                    }\
                }\
            }\
        }\
        static void ClearAll()\
        {\
            if (First())\
            {\
                CriticalSectionLock lock(CriticalSection##NameTo());\
            	\
                NameTo##Iterator* item = First();\
                while (item)\
                {\
                    NameTo##Iterator* nextItem = item->_next;\
                    item->_prev = 0;\
                    item->_next = 0;\
                    item->_prev##NameTo = 0;\
                    item->_ref##NameTo = 0;\
                    item->_next##NameTo = 0;\
                    item = nextItem;\
                }\
                First() = 0;\
                Last() = 0;\
            }\
        }\
        static void Check(ClassTo* item##NameTo, ClassTo* newItem##NameTo)\
        {\
            if (First())\
            {\
                CriticalSectionLock lock(CriticalSection##NameTo());\
                \
                for (NameTo##Iterator* item = First(); item; item = item->_next)\
                {\
                    if (item->_ref##NameTo == item##NameTo)\
                    {\
                        item->_ref##NameTo = item->_prev##NameTo = item->_next##NameTo = newItem##NameTo;\
                    }\
                    if (item->_prev##NameTo == item##NameTo)\
                    {\
                        item->_prev##NameTo = newItem##NameTo;\
                        item->_ref##NameTo = 0;\
                    }\
                    if (item->_next##NameTo == item##NameTo)\
                    {\
                        item->_next##NameTo = newItem##NameTo;\
                        item->_ref##NameTo = 0;\
                    }\
                }\
            }\
        }\
    };


#define ITERATOR_TEMPLATE_NOFILTER_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    class CB_EXT_CLASS NameTo##Iterator\
    {\
    private:\
		static CriticalSection& CriticalSection##NameTo()\
		{\
			static CriticalSection criticalSection##NameTo;\
			return criticalSection##NameTo;\
		}\
	    \
        ClassTo* _ref##NameTo;\
        ClassTo* _prev##NameTo;\
        ClassTo* _next##NameTo;\
        const ClassFrom* _iter##NameFrom;\
        \
        NameTo##Iterator* _prev;\
        NameTo##Iterator* _next;\
        \
        static NameTo##Iterator*& First()\
        {\
            static NameTo##Iterator* first = 0;\
            return first;\
        }\
        static NameTo##Iterator*& Last()\
        {\
            static NameTo##Iterator* last = 0;\
            return last;\
        }\
        \
    public:\
        NameTo##Iterator(const ClassFrom* iter##NameFrom,\
                         ClassTo* ref##NameTo = 0)\
        {\
            assert(iter##NameFrom);\
            CriticalSectionLock lock(CriticalSection##NameTo());\
            \
            _iter##NameFrom = iter##NameFrom;\
            _ref##NameTo = _prev##NameTo = _next##NameTo = ref##NameTo;\
            _prev = (NameTo##Iterator*)0;\
            _next = (NameTo##Iterator*)0;\
            if (Last())\
            {\
                Last()->_next = this;\
                _prev = Last();\
                Last() = this;\
            }\
            else\
                First() = Last() = this;\
        }\
        NameTo##Iterator(const ClassFrom& iter##NameFrom,\
                         ClassTo* ref##NameTo = 0)\
        {\
            assert(&iter##NameFrom);\
            CriticalSectionLock lock(CriticalSection##NameTo());\
            \
            _iter##NameFrom = &iter##NameFrom;\
            _ref##NameTo = _prev##NameTo = _next##NameTo = ref##NameTo;\
            _prev = (NameTo##Iterator*)0;\
            _next = (NameTo##Iterator*)0;\
            if (Last())\
            {\
                Last()->_next = this;\
                _prev = Last();\
                Last() = this;\
            }\
            else\
                First() = Last() = this;\
        }\
        NameTo##Iterator(const NameTo##Iterator& iterator__)\
        {\
            CriticalSectionLock lock(CriticalSection##NameTo());\
            \
            _iter##NameFrom = iterator__._iter##NameFrom;\
            _ref##NameTo = iterator__._ref##NameTo;\
            _prev##NameTo = iterator__._prev##NameTo;\
            _next##NameTo = iterator__._next##NameTo;\
            _prev = (NameTo##Iterator*)0;\
            _next = (NameTo##Iterator*)0;\
            if (Last())\
            {\
                Last()->_next = this;\
                _prev = Last();\
                Last() = this;\
            }\
            else\
                First() = Last() = this;\
        }\
        ~NameTo##Iterator()\
        {\
            CriticalSectionLock lock(CriticalSection##NameTo());\
            \
            if (_next)\
                _next->_prev = _prev;\
            else\
                Last() = _prev;\
        \
            if (_prev)\
                _prev->_next = _next;\
            else\
                First() = _next;\
        }\
        \
        NameTo##Iterator& operator= (const NameTo##Iterator& iterator__)\
        {\
            _iter##NameFrom = iterator__._iter##NameFrom;\
            _ref##NameTo = iterator__._ref##NameTo;\
            _prev##NameTo = iterator__._prev##NameTo;\
            _next##NameTo = iterator__._next##NameTo;\
            return *this;\
        }\
        ClassTo* operator++ ()\
        {\
            _next##NameTo = _iter##NameFrom->GetNext##NameTo(_next##NameTo);\
            _ref##NameTo = _prev##NameTo = _next##NameTo;\
            return _ref##NameTo;\
        }\
        ClassTo* operator-- ()\
        {\
            _prev##NameTo = _iter##NameFrom->GetPrev##NameTo(_prev##NameTo);\
            _ref##NameTo = _next##NameTo = _prev##NameTo;\
            return _ref##NameTo;\
        }\
        operator ClassTo*() { return _ref##NameTo; }\
        ClassTo* operator-> () { return _ref##NameTo; }\
        ClassTo* Get() { return _ref##NameTo; }\
        void Reset() { _ref##NameTo = _prev##NameTo = _next##NameTo = (ClassTo*)0; }\
        \
        int IsLast() { return (_iter##NameFrom->GetLast##NameTo() == _ref##NameTo); }\
        int IsFirst() { return (_iter##NameFrom->GetFirst##NameTo() == _ref##NameTo); }\
        \
        static void Check(ClassTo* item##NameTo)\
        {\
            if (First())\
            {\
                CriticalSectionLock lock(CriticalSection##NameTo());\
                \
                for (NameTo##Iterator* item = First(); item; item = item->_next)\
                {\
                    if (item->_prev##NameTo == item##NameTo)\
                    {\
                        item->_prev##NameTo = item->_iter##NameFrom->GetNext##NameTo(item->_prev##NameTo);\
                        item->_ref##NameTo = 0;\
                    }\
                    if (item->_next##NameTo == item##NameTo)\
                    {\
                        item->_next##NameTo = item->_iter##NameFrom->GetPrev##NameTo(item->_next##NameTo);\
                        item->_ref##NameTo = 0;\
                    }\
                }\
            }\
        }\
        static void CheckAll(ClassFrom* item##NameFrom)\
        {\
            if (First())\
            {\
                CriticalSectionLock lock(CriticalSection##NameTo());\
                \
                for (NameTo##Iterator* item = First(); item; item = item->_next)\
                {\
                    if (item->_iter##NameFrom == item##NameFrom)\
                    {\
                        item->_prev##NameTo = 0;\
                        item->_ref##NameTo = 0;\
    					item->_next##NameTo = 0;\
                    }\
                }\
            }\
        }\
        static void ClearAll()\
        {\
            if (First())\
            {\
                CriticalSectionLock lock(CriticalSection##NameTo());\
            	\
                NameTo##Iterator* item = First();\
                while (item)\
                {\
                    NameTo##Iterator* nextItem = item->_next;\
                    item->_prev = 0;\
                    item->_next = 0;\
                    item->_prev##NameTo = 0;\
                    item->_ref##NameTo = 0;\
                    item->_next##NameTo = 0;\
                    item = nextItem;\
                }\
                First() = 0;\
                Last() = 0;\
            }\
        }\
        static void Check(ClassTo* item##NameTo, ClassTo* newItem##NameTo)\
        {\
            if (First())\
            {\
                CriticalSectionLock lock(CriticalSection##NameTo());\
                \
                for (NameTo##Iterator* item = First(); item; item = item->_next)\
                {\
                    if (item->_ref##NameTo == item##NameTo)\
                    {\
                        item->_ref##NameTo = item->_prev##NameTo = item->_next##NameTo = newItem##NameTo;\
                    }\
                    if (item->_prev##NameTo == item##NameTo)\
                    {\
                        item->_prev##NameTo = newItem##NameTo;\
                        item->_ref##NameTo = 0;\
                    }\
                    if (item->_next##NameTo == item##NameTo)\
                    {\
                        item->_next##NameTo = newItem##NameTo;\
                        item->_ref##NameTo = 0;\
                    }\
                }\
            }\
        }\
    };

#define ITERATOR_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    class CB_EXT_CLASS NameTo##Iterator\
    {\
    private:\
        static CriticalSection& CriticalSection##NameTo()\
        {\
            static CriticalSection criticalSection##NameTo;\
            return criticalSection##NameTo;\
        }\
        ClassTo* _ref##NameTo;\
        ClassTo* _prev##NameTo;\
        ClassTo* _next##NameTo;\
        const ClassFrom* _iter##NameFrom;\
        \
        NameTo##Iterator* _prev;\
        NameTo##Iterator* _next;\
        \
        int (ClassTo::*_method)() const;\
        \
        static NameTo##Iterator* _first;\
        static NameTo##Iterator* _last;\
        \
    public:\
        NameTo##Iterator(const ClassFrom* iter##NameFrom,\
                         int (ClassTo::*method)() const = 0,\
                         ClassTo* ref##NameTo = 0);\
        NameTo##Iterator(const ClassFrom& iter##NameFrom,\
                         int (ClassTo::*method)() const = 0,\
                         ClassTo* ref##NameTo = 0);\
        NameTo##Iterator(const NameTo##Iterator& iterator__,\
                         int (ClassTo::*method)() const = 0);\
        ~NameTo##Iterator();\
        \
        NameTo##Iterator& operator= (const NameTo##Iterator& iterator__)\
        {\
            _iter##NameFrom = iterator__._iter##NameFrom;\
            _ref##NameTo = iterator__._ref##NameTo;\
            _prev##NameTo = iterator__._prev##NameTo;\
            _next##NameTo = iterator__._next##NameTo;\
            _method = iterator__._method;\
            return *this;\
        }\
        ClassTo* operator++ ()\
        {\
            _next##NameTo = _iter##NameFrom->GetNext##NameTo(_next##NameTo);\
            if (_method != 0)\
            {\
                while (_next##NameTo && !(_next##NameTo->*_method)())\
                    _next##NameTo = _iter##NameFrom->GetNext##NameTo(_next##NameTo);\
            }\
            _ref##NameTo = _prev##NameTo = _next##NameTo;\
            return _ref##NameTo;\
        }\
        ClassTo* operator-- ()\
        {\
            _prev##NameTo = _iter##NameFrom->GetPrev##NameTo(_prev##NameTo);\
            if (_method != 0)\
            {\
                while (_prev##NameTo && !(_prev##NameTo->*_method)())\
                    _prev##NameTo = _iter##NameFrom->GetPrev##NameTo(_prev##NameTo);\
            }\
            _ref##NameTo = _next##NameTo = _prev##NameTo;\
            return _ref##NameTo;\
        }\
        operator ClassTo*() { return _ref##NameTo; }\
        ClassTo* operator-> () { return _ref##NameTo; }\
        ClassTo* Get() { return _ref##NameTo; }\
        void Reset() { _ref##NameTo = _prev##NameTo = _next##NameTo = (ClassTo*)0; }\
        \
        int IsLast() { return (_iter##NameFrom->GetLast##NameTo() == _ref##NameTo); }\
        int IsFirst() { return (_iter##NameFrom->GetFirst##NameTo() == _ref##NameTo); }\
        \
        static void Check(ClassTo* item##NameTo);\
        static void CheckAll(ClassFrom* item##NameFrom);\
        static void Check(ClassTo* item##NameTo, ClassTo* newItem##NameTo);\
        static void ClearAll();\
    };

#define METHODS_ITERATOR_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
ClassFrom::NameTo##Iterator* ClassFrom::NameTo##Iterator::_first = 0;\
ClassFrom::NameTo##Iterator* ClassFrom::NameTo##Iterator::_last = 0;\
\
ClassFrom::NameTo##Iterator::NameTo##Iterator(\
    const ClassFrom* iter##NameFrom,\
    int (ClassTo::*method)() const,\
    ClassTo* ref##NameTo)\
{\
    assert(iter##NameFrom);\
    CriticalSectionLock lock(CriticalSection##NameTo());\
\
    _iter##NameFrom = iter##NameFrom;\
    _ref##NameTo = _prev##NameTo = _next##NameTo = ref##NameTo;\
    _prev = (NameTo##Iterator*)0;\
    _next = (NameTo##Iterator*)0;\
    _method = method;\
    if (_last)\
    {\
        _last->_next = this;\
        _prev = _last;\
        _last = this;\
    }\
    else\
        _first = _last = this;\
}\
\
ClassFrom::NameTo##Iterator::NameTo##Iterator(\
    const ClassFrom& iter##NameFrom,\
    int (ClassTo::*method)() const,\
    ClassTo* ref##NameTo)\
{\
    assert(&iter##NameFrom);\
    CriticalSectionLock lock(CriticalSection##NameTo());\
\
    _iter##NameFrom = &iter##NameFrom;\
    _ref##NameTo = _prev##NameTo = _next##NameTo = ref##NameTo;\
    _prev = (NameTo##Iterator*)0;\
    _next = (NameTo##Iterator*)0;\
    _method = method;\
    if (_last)\
    {\
        _last->_next = this;\
        _prev = _last;\
        _last = this;\
    }\
    else\
        _first = _last = this;\
}\
\
ClassFrom::NameTo##Iterator::NameTo##Iterator(\
    const NameTo##Iterator& iterator__,\
    int (ClassTo::*method)() const)\
{\
    CriticalSectionLock lock(CriticalSection##NameTo());\
	\
    _iter##NameFrom = iterator__._iter##NameFrom;\
    _ref##NameTo = iterator__._ref##NameTo;\
    _prev##NameTo = iterator__._prev##NameTo;\
    _next##NameTo = iterator__._next##NameTo;\
    _prev = (NameTo##Iterator*)0;\
    _next = (NameTo##Iterator*)0;\
    _method = method;\
    if (_last)\
    {\
        _last->_next = this;\
        _prev = _last;\
        _last = this;\
    }\
    else\
        _first = _last = this;\
}\
\
ClassFrom::NameTo##Iterator::~NameTo##Iterator()\
{\
    CriticalSectionLock lock(CriticalSection##NameTo());\
	\
    if (_next)\
        _next->_prev = _prev;\
    else\
        _last = _prev;\
\
    if (_prev)\
        _prev->_next = _next;\
    else\
        _first = _next;\
}\
\
void ClassFrom::NameTo##Iterator::Check(ClassTo* item##NameTo)\
{\
    if (_first)\
    {\
        CriticalSectionLock lock(CriticalSection##NameTo());\
    	\
        for (NameTo##Iterator* item = _first; item; item = item->_next)\
        {\
            if (item->_prev##NameTo == item##NameTo)\
            {\
                item->_prev##NameTo = item->_iter##NameFrom->GetNext##NameTo(item->_prev##NameTo);\
                item->_ref##NameTo = 0;\
            }\
            if (item->_next##NameTo == item##NameTo)\
            {\
                item->_next##NameTo = item->_iter##NameFrom->GetPrev##NameTo(item->_next##NameTo);\
                item->_ref##NameTo = 0;\
            }\
        }\
    }\
}\
\
void ClassFrom::NameTo##Iterator::CheckAll(ClassFrom* item##NameFrom)\
{\
    if (_first)\
    {\
        CriticalSectionLock lock(CriticalSection##NameTo());\
    	\
        for (NameTo##Iterator* item = _first; item; item = item->_next)\
        {\
            if (item->_iter##NameFrom == item##NameFrom)\
            {\
                item->_prev##NameTo = 0;\
                item->_ref##NameTo = 0;\
    			item->_next##NameTo = 0;\
            }\
        }\
    }\
}\
\
void ClassFrom::NameTo##Iterator::ClearAll()\
{\
    if (_first)\
    {\
        CriticalSectionLock lock(CriticalSection##NameTo());\
    	\
        NameTo##Iterator* item = _first;\
        while (item)\
        {\
            NameTo##Iterator* nextItem = item->_next;\
            item->_prev = 0;\
            item->_next = 0;\
            item->_prev##NameTo = 0;\
            item->_ref##NameTo = 0;\
            item->_next##NameTo = 0;\
            item = nextItem;\
        }\
        _first = 0;\
        _last = 0;\
    }\
}\
\
void ClassFrom::NameTo##Iterator::Check(ClassTo* item##NameTo, ClassTo* newItem##NameTo)\
{\
    if (_first)\
    {\
        CriticalSectionLock lock(CriticalSection##NameTo());\
    	\
        for (NameTo##Iterator* item = _first; item; item = item->_next)\
        {\
            if (item->_ref##NameTo == item##NameTo)\
            {\
                item->_ref##NameTo = item->_prev##NameTo = item->_next##NameTo = newItem##NameTo;\
            }\
            if (item->_prev##NameTo == item##NameTo)\
            {\
                item->_prev##NameTo = newItem##NameTo;\
                item->_ref##NameTo = 0;\
            }\
            if (item->_next##NameTo == item##NameTo)\
            {\
                item->_next##NameTo = newItem##NameTo;\
                item->_ref##NameTo = 0;\
            }\
        }\
    }\
}

#define ITERATOR_NOFILTER_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
    class CB_EXT_CLASS NameTo##Iterator\
    {\
    private:\
        static CriticalSection& CriticalSection##NameTo()\
        {\
            static CriticalSection criticalSection##NameTo;\
            return criticalSection##NameTo;\
        }\
        \
        ClassTo* _ref##NameTo;\
        ClassTo* _prev##NameTo;\
        ClassTo* _next##NameTo;\
        const ClassFrom* _iter##NameFrom;\
        \
        NameTo##Iterator* _prev;\
        NameTo##Iterator* _next;\
        \
        static NameTo##Iterator* _first;\
        static NameTo##Iterator* _last;\
        \
    public:\
        NameTo##Iterator(const ClassFrom* iter##NameFrom,\
                         ClassTo* ref##NameTo = 0);\
        NameTo##Iterator(const ClassFrom& iter##NameFrom,\
                         ClassTo* ref##NameTo = 0);\
        NameTo##Iterator(const NameTo##Iterator& iterator__);\
        ~NameTo##Iterator();\
        \
        NameTo##Iterator& operator= (const NameTo##Iterator& iterator__)\
        {\
            _iter##NameFrom = iterator__._iter##NameFrom;\
            _ref##NameTo = iterator__._ref##NameTo;\
            _prev##NameTo = iterator__._prev##NameTo;\
            _next##NameTo = iterator__._next##NameTo;\
            return *this;\
        }\
        ClassTo* operator++ ()\
        {\
            _next##NameTo = _iter##NameFrom->GetNext##NameTo(_next##NameTo);\
            _ref##NameTo = _prev##NameTo = _next##NameTo;\
            return _ref##NameTo;\
        }\
        ClassTo* operator-- ()\
        {\
            _prev##NameTo = _iter##NameFrom->GetPrev##NameTo(_prev##NameTo);\
            _ref##NameTo = _next##NameTo = _prev##NameTo;\
            return _ref##NameTo;\
        }\
        operator ClassTo*() { return _ref##NameTo; }\
        ClassTo* operator-> () { return _ref##NameTo; }\
        ClassTo* Get() { return _ref##NameTo; }\
        void Reset() { _ref##NameTo = _prev##NameTo = _next##NameTo = (ClassTo*)0; }\
        \
        int IsLast() { return (_iter##NameFrom->GetLast##NameTo() == _ref##NameTo); }\
        int IsFirst() { return (_iter##NameFrom->GetFirst##NameTo() == _ref##NameTo); }\
        \
        static void Check(ClassTo* item##NameTo);\
        static void CheckAll(ClassFrom* item##NameFrom);\
        static void Check(ClassTo* item##NameTo, ClassTo* newItem##NameTo);\
        static void ClearAll();\
    };

#define METHODS_ITERATOR_NOFILTER_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
ClassFrom::NameTo##Iterator* ClassFrom::NameTo##Iterator::_first = 0;\
ClassFrom::NameTo##Iterator* ClassFrom::NameTo##Iterator::_last = 0;\
\
ClassFrom::NameTo##Iterator::NameTo##Iterator(\
    const ClassFrom* iter##NameFrom, ClassTo* ref##NameTo)\
{\
    assert(iter##NameFrom);\
    CriticalSectionLock lock(CriticalSection##NameTo());\
	\
    _iter##NameFrom = iter##NameFrom;\
    _ref##NameTo = _prev##NameTo = _next##NameTo = ref##NameTo;\
    _prev = (NameTo##Iterator*)0;\
    _next = (NameTo##Iterator*)0;\
    if (_last)\
    {\
        _last->_next = this;\
        _prev = _last;\
        _last = this;\
    }\
    else\
        _first = _last = this;\
}\
\
ClassFrom::NameTo##Iterator::NameTo##Iterator(\
    const ClassFrom& iter##NameFrom, ClassTo* ref##NameTo)\
{\
    assert(&iter##NameFrom);\
    CriticalSectionLock lock(CriticalSection##NameTo());\
	\
    _iter##NameFrom = &iter##NameFrom;\
    _ref##NameTo = _prev##NameTo = _next##NameTo = ref##NameTo;\
    _prev = (NameTo##Iterator*)0;\
    _next = (NameTo##Iterator*)0;\
    if (_last)\
    {\
        _last->_next = this;\
        _prev = _last;\
        _last = this;\
    }\
    else\
        _first = _last = this;\
}\
\
ClassFrom::NameTo##Iterator::NameTo##Iterator(\
    const NameTo##Iterator& iterator__)\
{\
    CriticalSectionLock lock(CriticalSection##NameTo());\
	\
    _iter##NameFrom = iterator__._iter##NameFrom;\
    _ref##NameTo = iterator__._ref##NameTo;\
    _prev##NameTo = iterator__._prev##NameTo;\
    _next##NameTo = iterator__._next##NameTo;\
    _prev = (NameTo##Iterator*)0;\
    _next = (NameTo##Iterator*)0;\
    if (_last)\
    {\
        _last->_next = this;\
        _prev = _last;\
        _last = this;\
    }\
    else\
        _first = _last = this;\
}\
\
ClassFrom::NameTo##Iterator::~NameTo##Iterator()\
{\
    CriticalSectionLock lock(CriticalSection##NameTo());\
	\
    if (_next)\
        _next->_prev = _prev;\
    else\
        _last = _prev;\
\
    if (_prev)\
        _prev->_next = _next;\
    else\
        _first = _next;\
}\
\
void ClassFrom::NameTo##Iterator::Check(ClassTo* item##NameTo)\
{\
    if (_first)\
    {\
        CriticalSectionLock lock(CriticalSection##NameTo());\
    	\
        for (NameTo##Iterator* item = _first; item; item = item->_next)\
        {\
            if (item->_prev##NameTo == item##NameTo)\
            {\
                item->_prev##NameTo = item->_iter##NameFrom->GetNext##NameTo(item->_prev##NameTo);\
                item->_ref##NameTo = 0;\
            }\
            if (item->_next##NameTo == item##NameTo)\
            {\
                item->_next##NameTo = item->_iter##NameFrom->GetPrev##NameTo(item->_next##NameTo);\
                item->_ref##NameTo = 0;\
            }\
        }\
    }\
}\
\
void ClassFrom::NameTo##Iterator::CheckAll(ClassFrom* item##NameFrom)\
{\
    if (_first)\
    {\
        CriticalSectionLock lock(CriticalSection##NameTo());\
    	\
        for (NameTo##Iterator* item = _first; item; item = item->_next)\
        {\
            if (item->_iter##NameFrom == item##NameFrom)\
            {\
                item->_prev##NameTo = 0;\
                item->_ref##NameTo = 0;\
    			item->_next##NameTo = 0;\
            }\
        }\
    }\
}\
\
void ClassFrom::NameTo##Iterator::ClearAll()\
{\
    if (_first)\
    {\
        CriticalSectionLock lock(CriticalSection##NameTo());\
    	\
        NameTo##Iterator* item = _first;\
        while (item)\
        {\
            NameTo##Iterator* nextItem = item->_next;\
            item->_prev = 0;\
            item->_next = 0;\
            item->_prev##NameTo = 0;\
            item->_ref##NameTo = 0;\
            item->_next##NameTo = 0;\
            item = nextItem;\
        }\
        _first = 0;\
        _last = 0;\
    }\
}\
\
void ClassFrom::NameTo##Iterator::Check(ClassTo* item##NameTo, ClassTo* newItem##NameTo)\
{\
    if (_first)\
    {\
        CriticalSectionLock lock(CriticalSection##NameTo());\
    	\
        for (NameTo##Iterator* item = _first; item; item = item->_next)\
        {\
            if (item->_ref##NameTo == item##NameTo)\
            {\
                item->_ref##NameTo = item->_prev##NameTo = item->_next##NameTo = newItem##NameTo;\
            }\
            if (item->_prev##NameTo == item##NameTo)\
            {\
                item->_prev##NameTo = newItem##NameTo;\
                item->_ref##NameTo = 0;\
            }\
            if (item->_next##NameTo == item##NameTo)\
            {\
                item->_next##NameTo = newItem##NameTo;\
                item->_ref##NameTo = 0;\
            }\
        }\
    }\
}

#define METHODS_ITERATOR_BINARYBITTREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
        METHODS_ITERATOR_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo)

#define METHODS_ITERATOR_NOFILTER_BINARYBITTREE_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo) \
        METHODS_ITERATOR_NOFILTER_MULTI_ACTIVE(ClassFrom, NameFrom, ClassTo, NameTo)
#endif
