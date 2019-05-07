#include "cpuusermodewidget.h"
#include "systeminformation.h"

using namespace QtCharts;

CpuUserModeWidget::CpuUserModeWidget(QWidget *parent) : SysInfoWidget(parent,300,800)
{
    mSeriesValues = new QPieSeries(this);
    mSeriesValues->setHoleSize(0.35);

    QChart * fChart = chartView().chart();
    fChart->addSeries(mSeriesValues);
    fChart->setTitle("Cpu User Mode Load Graph");
}

void CpuUserModeWidget::updateChartsValues()
{
    double cpuValue = SystemInformation::instance().cpuLoadInUserMode();
    mSeriesValues->clear();
    mSeriesValues->append("load", cpuValue);
    mSeriesValues->append("free", 100.0-cpuValue);
}
