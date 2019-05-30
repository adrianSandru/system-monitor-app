#ifndef SYSTEMLINUXINFOIMPL_H
#define SYSTEMLINUXINFOIMPL_H
#include "systeminformation.h"
#include <QVector>
#include <QtGlobal>

enum CPU_STATS
{
    AVERAGE,
    KERNEL_MODE,
    USER_MODE,
    NICE_USER_MODE,
    IDLE_MODE
};

class SystemLinuxInfoImpl : public SystemInformation
{
private:
    /**
     * @brief mCpuValues
     * stores a system timing at a given moment of time
     */
    QVector<quint64> mCpuValues;

    /**
     * @brief cpuDataColector
     * The method will perform linux api call to get
     * system timing values regarding:
     * - normal processes in User Mode
     * - processes in Kernel
     * - nice processes in User Mode
     * - idle
     */
    QVector<quint64> cpuDataColector();
    double getCpuValues(CPU_STATS cpuStats);

public:
    SystemLinuxInfoImpl();

    void initialize() override;
    double cpuLoad() override;
    double memoryUsage() override;
    double cpuLoadInKernelMode() override;
    double cpuLoadInUserMode() override;
    double cpuLoadIdleMode() override;
};

#endif // SYSTEMLINUXINFOIMPL_H
