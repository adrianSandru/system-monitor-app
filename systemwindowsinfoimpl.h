#ifndef SYSTEMWINDOWSINFOIMPL_H
#define SYSTEMWINDOWSINFOIMPL_H

#include "systeminformation.h"
#include <QVector>

class SystemWindowsInfoImpl : public SystemInformation
{

private:
    QVector<quint64> mCpuValues;
    QVector<quint64> cpuDataCalculator();

public:
    SystemWindowsInfoImpl();

    void initialize() override;
    double cpuLoad() override;
    double memoryUsage() override;
};

#endif // SYSTEMWINDOWSINFOIMPL_H
