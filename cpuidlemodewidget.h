#ifndef CPUIDLEMODEWIDGET_H
#define CPUIDLEMODEWIDGET_H

#include <QtCharts/QPieSeries>
#include "sysinfowidget.h"

class CpuIdleModeWidget : public SysInfoWidget
{
private:
    QtCharts::QPieSeries * mSeriesValues;

    Q_OBJECT
public:
    explicit CpuIdleModeWidget(QWidget * parent = 0);

protected slots:
    void updateChartsValues() override;
};

#endif // CPUIDLEMODEWIDGET_H
