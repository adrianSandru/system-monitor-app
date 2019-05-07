#include "cpukernelmodewidget.h"
#include "systeminformation.h"

using namespace QtCharts;

CpuKernelModeWidget::CpuKernelModeWidget(QWidget *parent) : SysInfoWidget(parent,300,700)
{
    mSeriesValues = new QPieSeries(this);
    mSeriesValues->setHoleSize(0.35);

    QChart * fChart = chartView().chart();
    fChart->addSeries(mSeriesValues);
    fChart->setTitle("Cpu Kernel Load Graph");
}

void CpuKernelModeWidget::updateChartsValues()
{
    double cpuValue = SystemInformation::instance().cpuLoadInKernelMode();
    mSeriesValues->clear();
    mSeriesValues->append("load ", cpuValue);
    mSeriesValues->append("free", 100.0-cpuValue);
}
