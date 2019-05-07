#ifndef CPUKERNELMODEWIDGET_H
#define CPUKERNELMODEWIDGET_H

#include <QtCharts/QPieSeries>
#include "sysinfowidget.h"

class CpuKernelModeWidget : public SysInfoWidget
{
private:
    QtCharts::QPieSeries * mSeriesValues;

    Q_OBJECT
public:
    explicit CpuKernelModeWidget(QWidget * parent = 0);

protected slots:
    void updateChartsValues() override;
};

#endif // CPUKERNELMODEWIDGET_H
