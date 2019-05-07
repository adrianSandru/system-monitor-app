#include "cpuidlemodewidget.h"
#include "systeminformation.h"

using namespace QtCharts;

CpuIdleModeWidget::CpuIdleModeWidget(QWidget *parent) : SysInfoWidget(parent,300,600)
{
    mSeriesValues = new QPieSeries(this);
    mSeriesValues->setHoleSize(0.35);

    QChart * fChart = chartView().chart();
    fChart->addSeries(mSeriesValues);
    fChart->setTitle("Cpu Idle Load Graph");
}

void CpuIdleModeWidget::updateChartsValues()
{
    double cpuValue = SystemInformation::instance().cpuLoadIdleMode();
    mSeriesValues->clear();
    mSeriesValues->append("load ", cpuValue);
    mSeriesValues->append("free", 100.0-cpuValue);
}
