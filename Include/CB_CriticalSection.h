#ifndef CB_CRITICAL_SECTION
#define CB_CRITICAL_SECTION

#ifdef _WIN32
// This is Windows specific, need to change this for other platforms.
#include <windows.h>
#include <process.h>

class CriticalSection
{
private:
    CRITICAL_SECTION _criticalSection;
	bool _init;

public:
    CriticalSection()
    {
        InitializeCriticalSectionAndSpinCount(&_criticalSection, 1000);
		_init = true;
    }
    ~CriticalSection()
    {
	    if (_init)
		{
		  _init = false;
          DeleteCriticalSection(&_criticalSection);
		}
    }

    void Enter()
    { 
		if (_init)
		{
			EnterCriticalSection(&_criticalSection); 
		}
    }
    void Leave()
    { 
		if (_init)
		{
            LeaveCriticalSection(&_criticalSection); 
		}
    }
};
#else
#ifdef xxxlinux

#include <pthread.h>
#include <assert.h>

class CriticalSection
{
private:
	// no members
	pthread_mutex_t _mutex;           // Mutex
	pthread_mutexattr_t _mutexattr;   // Mutex attribute variable
	
public:
    CriticalSection()
    {
    	int retVal = pthread_mutexattr_init( &_mutexattr );
    	assert( retVal == 0 );
		// Set the mutex as a recursive mutex
		retVal = pthread_mutexattr_settype(&_mutexattr, PTHREAD_MUTEX_RECURSIVE_NP);
//		retVal = pthread_mutexattr_settype(&_mutexattr, PTHREAD_MUTEX_ERRORCHECK_NP);
		assert( retVal == 0 );
		// create the mutex with the attributes set
		retVal = pthread_mutex_init(&_mutex, &_mutexattr);
		assert( retVal == 0 );
		
		//After initializing the mutex, the thread attribute can be destroyed
		pthread_mutexattr_destroy(&_mutexattr);
    }
    
    ~CriticalSection()
    {
    	pthread_mutex_destroy (&_mutex);
    }

    void Enter()
    {
    	int retVal = pthread_mutex_lock (&_mutex);
    	assert( retVal == 0 );
    }
    void Leave()
    { 
		int retVal = pthread_mutex_unlock (&_mutex);
		assert( retVal == 0 );
    }
};
#else
// Bogus implementation of this class. We won't use multithreading so critical sections are useless.
class CriticalSection
{
private:
	// no members

public:
    CriticalSection()
    {
    }
    ~CriticalSection()
    {
    }

    void Enter()
    { 
    }
    void Leave()
    { 
    }
};

#endif


#endif

class CriticalSectionLock
{
private:
    CriticalSection* _criticalSection;

public:
    CriticalSectionLock(CriticalSection& criticalSection)
        : _criticalSection(&criticalSection) 
    { 
        _criticalSection->Enter();
    }
    ~CriticalSectionLock()
    {
        _criticalSection->Leave();
    }
};

#endif
