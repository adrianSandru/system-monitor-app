#ifndef CPUWIDGET_H
#define CPUWIDGET_H

#include <QtCharts/QPieSeries>
#include "sysinfowidget.h"

class CpuAverageWidget : public SysInfoWidget
{
private:
    QtCharts::QPieSeries * mSeriesValues;

    Q_OBJECT
public:
    explicit CpuAverageWidget(QWidget * parent = 0);

protected slots:
    void updateChartsValues() override;
};

#endif // CPUWIDGET_H
