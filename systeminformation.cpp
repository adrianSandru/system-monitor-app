#include "systeminformation.h"
#include<QtGlobal>

#ifdef Q_OS_LINUX
    #include "systemlinuxinfoimpl.h"
#elif defined(Q_OS_WIN)
    #include "systemwindowsinfoimpl.h"
#endif

SystemInformation& SystemInformation::instance()
{
    #ifdef Q_OS_LINUX
        static SystemLinuxInfoImpl fInstance;
    #elif defined(Q_OS_WIN)
        static SystemWindowSInfoImpl fInstance;
    #endif

    return fInstance;
}

SystemInformation::SystemInformation()
{

}

SystemInformation::~SystemInformation()
{

}
