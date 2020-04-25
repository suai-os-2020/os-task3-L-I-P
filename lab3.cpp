#include <iostream>
#include <windows.h>
#include "lab3.h"
using namespace std;

#define THREADCOUNT 14
#define SEMAPHORECOUNT 10

HANDLE ghMutex;
HANDLE aThread[THREADCOUNT];
DWORD ThreadID;

HANDLE ghSemaphore[SEMAPHORECOUNT];
int max_sem_count = 3;

unsigned int lab3_thread_graph_id()
{
    return 2;
}

const char* lab3_unsynchronized_threads()
{
    return "bcde";
}

const char* lab3_sequential_threads()
{
    return "ikm";
}

DWORD WINAPI thread_b(LPVOID lpParam);
DWORD WINAPI thread_c(LPVOID lpParam);
DWORD WINAPI thread_d(LPVOID lpParam);
DWORD WINAPI thread_e(LPVOID lpParam);
DWORD WINAPI thread_e2(LPVOID lpParam);
DWORD WINAPI thread_f(LPVOID lpParam);
DWORD WINAPI thread_g(LPVOID lpParam);
DWORD WINAPI thread_h(LPVOID lpParam);
DWORD WINAPI thread_i(LPVOID lpParam);
DWORD WINAPI thread_i2(LPVOID lpParam);
DWORD WINAPI thread_k(LPVOID lpParam);
DWORD WINAPI thread_m(LPVOID lpParam);
DWORD WINAPI thread_n(LPVOID lpParam);

DWORD WINAPI thread_a(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);

    aThread[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) thread_b, 0,  0, &ThreadID);
    if( aThread[1] == NULL )
    {
        cout << "CreateThread 1 error: " << GetLastError();
        return 1;
    }

    ReleaseSemaphore(ghSemaphore[0], 1 ,NULL);

    bool bContinue = true;

    for(int i = 0; i < 3; i++)
    {
        bContinue = true;
        while(bContinue)
        {
            switch (WaitForSingleObject(ghSemaphore[0], INFINITE))
            {
                case WAIT_OBJECT_0:
                    WaitForSingleObject(ghMutex, INFINITE);
                    cout << "a" << flush;
                    ReleaseMutex(ghMutex);
                    computation();

                    bContinue=false;
                if(!ReleaseSemaphore(ghSemaphore[1], 1, NULL))
                {
                    cout << "ReleaseSemaphore 1 error: " << GetLastError();
                }
                break;
                }
        }
    }

    WaitForSingleObject(aThread[1], INFINITE);
    ExitThread(0);
}

DWORD WINAPI thread_b(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    bool bContinue = true;

    for(int i = 0; i < 3; i++)
    {
        bContinue = true;
        while(bContinue)
        {
            switch (WaitForSingleObject(ghSemaphore[1], INFINITE))
            {
                case WAIT_OBJECT_0:
                    WaitForSingleObject(ghMutex, INFINITE);
                    cout << "b" << flush;
                    ReleaseMutex(ghMutex);
                    computation();

                    bContinue=false;
                if(!ReleaseSemaphore(ghSemaphore[0], 1, NULL))
                {
                    cout << "ReleaseSemaphore 0 error: " << GetLastError();
                }
                break;
                }
        }
    }

    aThread[2] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) thread_c, 0,  0, &ThreadID);
    if( aThread[2] == NULL )
    {
        cout << "CreateThread 2 error: " << GetLastError();
        return 1;
    }
    aThread[3] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) thread_d, 0,  0, &ThreadID);
    if( aThread[3] == NULL )
    {
        cout << "CreateThread 3 error: " << GetLastError();
        return 1;
    }
    aThread[4] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) thread_e, 0,  0, &ThreadID);
    if( aThread[4] == NULL )
    {
        cout << "CreateThread 4 error: " << GetLastError();
        return 1;
    }
    for(int i = 0; i < 3; i++) {
        WaitForSingleObject(ghMutex, INFINITE);
        cout << "b" << flush;
        ReleaseMutex(ghMutex);
        computation();
    }

    WaitForSingleObject(aThread[2], INFINITE);
    WaitForSingleObject(aThread[3], INFINITE);
    WaitForSingleObject(aThread[4], INFINITE);
    ExitThread(0);
}

DWORD WINAPI thread_c(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    for(int i = 0; i < 3; i++) {
        WaitForSingleObject(ghMutex, INFINITE);
        cout << "c" << flush;
        ReleaseMutex(ghMutex);
        computation();
    }

    ExitThread(0);
}

DWORD WINAPI thread_d(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    for(int i = 0; i < 3; i++) {
        WaitForSingleObject(ghMutex, INFINITE);
        cout << "d" << flush;
        ReleaseMutex(ghMutex);
        computation();
    }

    ExitThread(0);
}

DWORD WINAPI thread_e(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    for(int i = 0; i < 3; i++) {
        WaitForSingleObject(ghMutex, INFINITE);
        cout << "e" << flush;
        ReleaseMutex(ghMutex);
        computation();
    }

    ExitThread(0);
}

DWORD WINAPI thread_e2(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);

    aThread[6] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) thread_f, 0,  0, &ThreadID);
    if( aThread[6] == NULL )
    {
        cout << "CreateThread 6 error: " << GetLastError();
        return 1;
    }
    aThread[7] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) thread_g, 0,  0, &ThreadID);
    if( aThread[7] == NULL )
    {
        cout << "CreateThread 7 error: " << GetLastError();
        return 1;
    }
    aThread[8] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) thread_h, 0,  0, &ThreadID);
    if( aThread[8] == NULL )
    {
        cout << "CreateThread 8 error: " << GetLastError();
        return 1;
    }
    aThread[9] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) thread_i, 0,  0, &ThreadID);
    if( aThread[9] == NULL )
    {
        cout << "CreateThread 9 error: " << GetLastError();
        return 1;
    }


    ReleaseSemaphore(ghSemaphore[2], 1 ,NULL);

    bool bContinue = true;

    for(int i = 0; i < 3; i++)
    {
        bContinue = true;
        while(bContinue)
        {
            switch (WaitForSingleObject(ghSemaphore[2], INFINITE))
            {
                case WAIT_OBJECT_0:
                    WaitForSingleObject(ghMutex, INFINITE);
                    cout << "e" << flush;
                    ReleaseMutex(ghMutex);
                    computation();

                    bContinue=false;
                if(!ReleaseSemaphore(ghSemaphore[3], 1, NULL))
                {
                    cout << "ReleaseSemaphore 3 error: " << GetLastError();
                }
                break;
                }
        }
    }

    WaitForSingleObject(aThread[6], INFINITE);
    WaitForSingleObject(aThread[7], INFINITE);
    WaitForSingleObject(aThread[8], INFINITE);
    WaitForSingleObject(aThread[9], INFINITE);
    ExitThread(0);
}

DWORD WINAPI thread_f(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    bool bContinue = true;

    for(int i = 0; i < 3; i++)
    {
        bContinue = true;
        while(bContinue)
        {
            switch (WaitForSingleObject(ghSemaphore[3], INFINITE))
            {
                case WAIT_OBJECT_0:
                    WaitForSingleObject(ghMutex, INFINITE);
                    cout << "f" << flush;
                    ReleaseMutex(ghMutex);
                    computation();

                    bContinue=false;
                if(!ReleaseSemaphore(ghSemaphore[4], 1, NULL))
                {
                    cout << "ReleaseSemaphore 4 error: " << GetLastError();
                }
                break;
                }
        }
    }

    ExitThread(0);
}

DWORD WINAPI thread_g(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    bool bContinue = true;

    for(int i = 0; i < 3; i++)
    {
        bContinue = true;
        while(bContinue)
        {
            switch (WaitForSingleObject(ghSemaphore[4], INFINITE))
            {
                case WAIT_OBJECT_0:
                    WaitForSingleObject(ghMutex, INFINITE);
                    cout << "g" << flush;
                    ReleaseMutex(ghMutex);
                    computation();

                    bContinue=false;
                if(!ReleaseSemaphore(ghSemaphore[5], 1, NULL))
                {
                    cout << "ReleaseSemaphore 5 error: " << GetLastError();
                }
                break;
                }
        }
    }

    ExitThread(0);
}

DWORD WINAPI thread_h(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    bool bContinue = true;

    for(int i = 0; i < 3; i++)
    {
        bContinue = true;
        while(bContinue)
        {
            switch (WaitForSingleObject(ghSemaphore[5], INFINITE))
            {
                case WAIT_OBJECT_0:
                    WaitForSingleObject(ghMutex, INFINITE);
                    cout << "h" << flush;
                    ReleaseMutex(ghMutex);
                    computation();

                    bContinue=false;
                if(!ReleaseSemaphore(ghSemaphore[6], 1, NULL))
                {
                    cout << "ReleaseSemaphore 6 error: " << GetLastError();
                }
                break;
                }
        }
    }

    ExitThread(0);
}

DWORD WINAPI thread_i(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    bool bContinue = true;

    for(int i = 0; i < 3; i++)
    {
        bContinue = true;
        while(bContinue)
        {
            switch (WaitForSingleObject(ghSemaphore[6], INFINITE))
            {
                case WAIT_OBJECT_0:
                    WaitForSingleObject(ghMutex, INFINITE);
                    cout << "i" << flush;
                    ReleaseMutex(ghMutex);
                    computation();

                    bContinue=false;
                if(!ReleaseSemaphore(ghSemaphore[2], 1, NULL))
                {
                    cout << "ReleaseSemaphore 2 error: " << GetLastError();
                }
                break;
                }
        }
    }

    ExitThread(0);
}

DWORD WINAPI thread_i2(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);

    aThread[11] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) thread_k, 0,  0, &ThreadID);
    if( aThread[11] == NULL )
    {
        cout << "CreateThread 11 error: " << GetLastError();
        return 1;
    }
    aThread[12] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) thread_m, 0,  0, &ThreadID);
    if( aThread[12] == NULL )
    {
        cout << "CreateThread 12 error: " << GetLastError();
        return 1;
    }


    ReleaseSemaphore(ghSemaphore[7], 1 ,NULL);

    bool bContinue = true;

    for(int i = 0; i < 3; i++)
    {
        bContinue = true;
        while(bContinue)
        {
            switch (WaitForSingleObject(ghSemaphore[7], INFINITE))
            {
                case WAIT_OBJECT_0:
                    WaitForSingleObject(ghMutex, INFINITE);
                    cout << "i" << flush;
                    ReleaseMutex(ghMutex);
                    computation();

                    bContinue=false;
                if(!ReleaseSemaphore(ghSemaphore[8], 1, NULL))
                {
                    cout << "ReleaseSemaphore 8 error: " << GetLastError();
                }
                break;
                }
        }
    }

    WaitForSingleObject(aThread[11], INFINITE);
    WaitForSingleObject(aThread[12], INFINITE);
    ExitThread(0);
}

DWORD WINAPI thread_k(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    bool bContinue = true;

    for(int i = 0; i < 3; i++)
    {
        bContinue = true;
        while(bContinue)
        {
            switch (WaitForSingleObject(ghSemaphore[8], INFINITE))
            {
                case WAIT_OBJECT_0:
                    WaitForSingleObject(ghMutex, INFINITE);
                    cout << "k" << flush;
                    ReleaseMutex(ghMutex);
                    computation();

                    bContinue=false;
                if(!ReleaseSemaphore(ghSemaphore[9], 1, NULL))
                {
                    cout << "ReleaseSemaphore 9 error: " << GetLastError();
                }
                break;
                }
        }
    }

    ExitThread(0);
}

DWORD WINAPI thread_m(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    bool bContinue = true;

    for(int i = 0; i < 3; i++)
    {
        bContinue = true;
        while(bContinue)
        {
            switch (WaitForSingleObject(ghSemaphore[9], INFINITE))
            {
                case WAIT_OBJECT_0:
                    WaitForSingleObject(ghMutex, INFINITE);
                    cout << "m" << flush;
                    ReleaseMutex(ghMutex);
                    computation();

                    bContinue=false;
                if(!ReleaseSemaphore(ghSemaphore[7], 1, NULL))
                {
                    cout << "ReleaseSemaphore 7 error: " << GetLastError();
                }
                break;
                }
        }
    }

    ExitThread(0);
}

DWORD WINAPI thread_n(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    for(int i = 0; i < 3; i++) {
        WaitForSingleObject(ghMutex, INFINITE);
        cout << "n" << flush;
        ReleaseMutex(ghMutex);
        computation();
    }

    ExitThread(0);
}

int lab3_init()
{
    ghMutex = CreateMutex(NULL, FALSE, NULL);
    if(ghMutex == NULL)
    {
        cout << "CreateMutex error: " << GetLastError();
        return 1;
    }

    for(int i = 0; i < SEMAPHORECOUNT; i++)
    {
        ghSemaphore[i] = CreateSemaphore(NULL, 0, max_sem_count, NULL);
        if (ghSemaphore[i] == NULL)
        {
            cout << "CreateSemaphore " << i << " error: " <<  GetLastError();
            return 1;
        }
    }

    aThread[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) thread_a, 0,  0, &ThreadID);
    if( aThread[0] == NULL )
    {
        cout << "CreateThread 0 error: " << GetLastError();
        return 1;
    }
    WaitForSingleObject(aThread[0], INFINITE);

    aThread[5] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) thread_e2, 0,  0, &ThreadID);
    if( aThread[5] == NULL )
    {
        cout << "CreateThread 5 error: " << GetLastError();
        return 1;
    }
    WaitForSingleObject(aThread[5], INFINITE);

    aThread[10] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) thread_i2, 0,  0, &ThreadID);
    if( aThread[10] == NULL )
    {
        cout << "CreateThread 10 error: " << GetLastError();
        return 1;
    }
    WaitForSingleObject(aThread[10], INFINITE);

    aThread[13] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) thread_n, 0,  0, &ThreadID);
    if( aThread[13] == NULL )
    {
        cout << "CreateThread 13 error: " << GetLastError();
        return 1;
    }
    WaitForSingleObject(aThread[13], INFINITE);

    for(int i = 0; i < THREADCOUNT; i++)
        CloseHandle(aThread[i]);

    for(int i = 0; i < SEMAPHORECOUNT; i++)
        CloseHandle(ghSemaphore[i]);

    CloseHandle(ghMutex);

    return 0;
}
