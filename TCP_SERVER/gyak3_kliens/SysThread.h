#pragma once
#include <limits.h> 
#include <windows.h>
using namespace std;

class SysThread
{
public:
    SysThread(void);
    virtual ~SysThread();
    virtual bool start(void);
    virtual bool stop(unsigned int timeout = 0);
    inline volatile bool& isRunning(void)
    {
        return m_bRunning;
    }
    inline volatile bool& isExited(void)
    {
        return m_bExited;
    }

protected:
    virtual void run(void); //Ezt a metodust a sz�rmaztatott 
                            //oszt�lyban fel�l kell �rni.Ide kell be�rni az utas�t�s szekvenci�t
                            //amit a sz�lunk v�gre kell hajtson

private:
    friend DWORD WINAPI runStub(LPVOID mthread);

public:
    static const unsigned int INFINIT_WAIT;

private:
    volatile bool m_bRunning;
    volatile bool m_bExited;
    HANDLE m_thread;
};