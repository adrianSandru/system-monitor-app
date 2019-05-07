#ifndef CPUUSERMODEWIDGET_H
#define CPUUSERMODEWIDGET_H
#include <QtCharts/QPieSeries>
#include "sysinfowidget.h"

class CpuUserModeWidget : public SysInfoWidget
{private:
    QtCharts::QPieSeries * mSeriesValues;

    Q_OBJECT
public:
    explicit CpuUserModeWidget(QWidget * parent = 0);

protected slots:
    void updateChartsValues() override;
};
#endif // CPUUSERMODEWIDGET_H
