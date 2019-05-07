#include "systemwindowsinfoimpl.h"

#ifdef Q_OS_WIN
#include <windows.h>
#endif

SystemWindowsInfoImpl::SystemWindowsInfoImpl() : SystemInformation()
{
}

double SystemWindowsInfoImpl::memoryUsage()
{
    return 0.0;
}

double SystemWindowsInfoImpl::cpuLoad()
{
    return 0.0;
}

void SystemWindowsInfoImpl::initialize()
{

}
