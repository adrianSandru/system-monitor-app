#ifndef MEMORYAVERAGEUSAGE_H
#define MEMORYAVERAGEUSAGE_H

#define COUNT 50
#define MAX_RANGE COUNT - 1

#include<QtCharts/QLineSeries>
#include "sysinfowidget.h"

class MemoryAverageUsageWidget : public SysInfoWidget
{
private:
    QtCharts::QLineSeries * mLineSeries;

    /**
     * @brief mXPoint
     * Track the latest X position
     * to make sure that never overflows
     */
    quint64 mXPoint;

    Q_OBJECT
public:
    MemoryAverageUsageWidget(QWidget * parent = 0);

protected:
    void updateChartsValues() override;
};

#endif // MEMORYAVERAGEUSAGE_H
