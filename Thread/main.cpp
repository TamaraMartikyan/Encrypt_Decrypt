#include <iostream>
#include <Windows.h> // For Windows threading and synchronization
using namespace std;

// Windows-specific type definitions
typedef HANDLE THREADVAR;
typedef DWORD WINAPI THREADFUNCVAR;
typedef LPVOID THREADFUNCARGS;
typedef THREADFUNCVAR(*THREADFUNC)(THREADFUNCARGS);
typedef CRITICAL_SECTION THREAD_LOCK;

// Cross-platform-like function declarations (Windows only)
THREADVAR PrepareThread(THREADFUNC f, THREADFUNCARGS arg);
void StopThread(THREADVAR t);
void InitThreadLock(THREAD_LOCK& t);
void LockThread(THREAD_LOCK& t);
void UnlockThread(THREAD_LOCK& t);
void sleep(int ms);

// The thread function declaration
THREADFUNCVAR MyAsyncSimpleThread(THREADFUNCARGS lpParam);

// Globals
int globlint = 0;
bool quitnow = false;

int main() {
    THREAD_LOCK recv_lock;
    InitThreadLock(recv_lock);

    // Prepare parameter(s) for the async thread
    DWORD_PTR* svRecvThrArgs = new DWORD_PTR[1];
    svRecvThrArgs[0] = (DWORD_PTR)&recv_lock;

    // Start the thread with parameters
    THREADVAR recvThrHandle = PrepareThread(MyAsyncSimpleThread, (THREADFUNCARGS)svRecvThrArgs);

    // Loop increment and check for exit
    while (!quitnow) {
        LockThread(recv_lock);

        globlint++;
        if (globlint > 5000) {
            quitnow = true;
        }
        cout << "\n\tMain loop.\t" << globlint << '\n';

        UnlockThread(recv_lock);
        sleep(5); // Sleep for 5 milliseconds
    }

    StopThread(recvThrHandle);
    return 0;
}

THREADFUNCVAR MyAsyncSimpleThread(THREADFUNCARGS lpParam) {
    DWORD_PTR* arg = (DWORD_PTR*)lpParam;
    THREAD_LOCK& ref_recv_lock = *((THREAD_LOCK*)arg[0]);

    while (!quitnow) {
        LockThread(ref_recv_lock);
        globlint++;
        if (globlint > 100) {
            quitnow = true;
        }
        cout << "\nMyAsyncSimpleThread.\t" << globlint << endl;
        UnlockThread(ref_recv_lock);
        sleep(1); // Sleep for 1 millisecond
    }
    return NULL;
}

// Windows-only definitions
THREADVAR PrepareThread(THREADFUNC f, THREADFUNCARGS arg) {
    DWORD thrId;
    return CreateThread(
        NULL,          // Default security attributes
        0,             // Default stack size
        (LPTHREAD_START_ROUTINE)f, // Thread function name
        arg,           // Argument to thread function
        0,             // Default creation flags
        &thrId         // Returns the thread identifier
    );
}

void StopThread(THREADVAR t) {
    TerminateThread(t, 0);
    CloseHandle(t);
}

void InitThreadLock(THREAD_LOCK& t) {
    InitializeCriticalSection(&t);
}

void LockThread(THREAD_LOCK& t) {
    EnterCriticalSection(&t);
}

void UnlockThread(THREAD_LOCK& t) {
    LeaveCriticalSection(&t);
}

void sleep(int ms) {
    Sleep(ms);
}
