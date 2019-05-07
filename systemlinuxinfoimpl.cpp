#include "systemlinuxinfoimpl.h"
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <QtGlobal>
#include <QFile>

SystemLinuxInfoImpl::SystemLinuxInfoImpl() : SystemInformation(), mCpuValues()
{
}

void SystemLinuxInfoImpl::initialize()
{
    mCpuValues = cpuDataColector();
}

QVector<quint64> SystemLinuxInfoImpl::cpuDataColector()
{
    quint64 fTotalUser = 0,
            fTotalUserNice = 0,
            fTotalSystem = 0,
            fTotalIdle = 0;
    QVector<quint64> cpuValues;
    QFile file("/proc/stat");
    file.open(QIODevice::ReadOnly);

    QByteArray fStats = file.readLine();
    file.close();
    sscanf(fStats.data(),"cpu %llu %llu %llu %llu",
           &fTotalUser, &fTotalUserNice, &fTotalSystem, &fTotalIdle);

    cpuValues.append(fTotalUser);
    cpuValues.append(fTotalUserNice);
    cpuValues.append(fTotalSystem);
    cpuValues.append(fTotalIdle);

    return cpuValues;
}

double SystemLinuxInfoImpl::getCpuValues(CPU_STATS cpuStats)
{
    QVector<quint64> fFirstValues = mCpuValues;
    QVector<quint64> fSecondValues = cpuDataColector();

    double retValue = 0.0;
    /*fStats = user + nice + kernel*/
    double fStats = (fSecondValues[0] - fFirstValues[0]) +
            (fSecondValues[1] - fFirstValues[1]) +
            (fSecondValues[2] - fFirstValues[2]);

   double fTotalValue = fStats + (fSecondValues[3] - fFirstValues[3]);

    switch (cpuStats)
    {
        case AVERAGE:
        {
            retValue = (fStats / fTotalValue) * 100.0;
            break;
        }
        case KERNEL_MODE:
        {
            fStats = (fSecondValues[2] - fFirstValues[2]);
            retValue = (fStats / fTotalValue) * 100.0;
            break;
        }
        case USER_MODE:
        {
            fStats = (fSecondValues[0] - fFirstValues[0]);
            retValue = (fStats / fTotalValue) * 100.0;
            break;
        }
        case NICE_USER_MODE:
        {
            fStats = (fSecondValues[1] - fFirstValues[1]);
            retValue = (fStats / fTotalValue) * 100.0;
            break;
        }
        case IDLE_MODE:
        {
            fStats = (fSecondValues[3] - fFirstValues[3]);
            retValue = (fStats / fTotalValue) * 100.0;
            break;
        }
    }

    mCpuValues = fSecondValues;
    return  retValue;
}

double SystemLinuxInfoImpl::cpuLoad()
{
    qDebug("cpuLoad Average called");
    return qBound(0.0, getCpuValues(AVERAGE), 100.0);
}

double SystemLinuxInfoImpl::cpuLoadInUserMode()
{
    qDebug("cpuLoad user mode called");
    return qBound(0.0, getCpuValues(USER_MODE), 100.0);
}

double SystemLinuxInfoImpl::cpuLoadInKernelMode()
{
    qDebug("cpuLoad kernel mode called");
    return qBound(0.0, getCpuValues(KERNEL_MODE), 100.0);
}

double SystemLinuxInfoImpl::cpuLoadIdleMode()
{
    qDebug("cpuLoad idle mode called");
    return qBound(0.0, getCpuValues(IDLE_MODE), 100.0);
}

double SystemLinuxInfoImpl::memoryUsage()
{
    struct sysinfo fSystemInfo;
    sysinfo(&fSystemInfo);

    quint64 fTotalMemory = fSystemInfo.totalram;
    fTotalMemory = fTotalMemory + fSystemInfo.totalswap;
    fTotalMemory = fTotalMemory * fSystemInfo.mem_unit;

    quint64 fFreeMemory = fSystemInfo.freeram + fSystemInfo.freeswap;
    quint64 fTotalMemoryUsed = (fTotalMemory - fFreeMemory) * fSystemInfo.mem_unit;

    double fValueInPercent = ((double) fTotalMemoryUsed / (double) fTotalMemory) * 100.0;
    return qBound(0.0, fValueInPercent, 100.0);
}
