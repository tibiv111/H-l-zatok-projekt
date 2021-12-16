#include "SysThread.h"
#include "ClientThread.h"
#define INVALID_HANDLE_VALUE 0 

const unsigned int SysThread::INFINIT_WAIT = UINT_MAX;

DWORD WINAPI runStub(LPVOID mthread)
{
    SysThread* pThread = static_cast<SysThread*>(mthread);
    pThread->m_bRunning = true;
    pThread->run();
    pThread->m_bRunning = false;
    pThread->m_bExited = true;
    return 0;
}

SysThread::SysThread(void)
{
    m_bRunning = false;
    m_bExited = true;
    m_thread = INVALID_HANDLE_VALUE;
}

SysThread::~SysThread()
{
}

bool SysThread::start(void)
{
    if (m_bExited)
    {
        m_bExited = false;
        DWORD dw;
        if ((m_thread = CreateThread(NULL, 4096, runStub, this, 0,
            &dw)) == INVALID_HANDLE_VALUE)
        {
            m_bRunning = false;
            m_bExited = true;
            return false;
        }
    }
    return true;
}

bool SysThread::stop(unsigned int timeout)
{
    m_bRunning = false;
    if (!m_bExited)
    {
        for (unsigned int i = 0; (i <= timeout / 100) || (timeout ==
            INFINIT_WAIT); i++)
        {
            m_bRunning = false;
            if (m_bExited)
            {
                break;
            }
            Sleep(10);
        }
    }
    if (m_thread != INVALID_HANDLE_VALUE)
    {
        CloseHandle(m_thread);
        m_thread = INVALID_HANDLE_VALUE;
    }
    return m_bExited;
}

void SysThread::run(void)
{
    //Itt  megh�vom  a  lesz�rmaztatott  oszt�ly run f�ggv�nyt,  ami tartalmazza a sz�l 
    //utas�t�sait
}


