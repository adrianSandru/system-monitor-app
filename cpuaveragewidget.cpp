#include "cpuaveragewidget.h"
#include "systeminformation.h"

using namespace QtCharts;

CpuAverageWidget::CpuAverageWidget(QWidget *parent) : SysInfoWidget(parent)
{
    mSeriesValues = new QPieSeries(this);
    mSeriesValues->setHoleSize(0.35);

    QChart * fChart = chartView().chart();
    fChart->addSeries(mSeriesValues);
    fChart->setTitle("Cpu Average Load Graph");
}

void CpuAverageWidget::updateChartsValues()
{
    double cpuValue = SystemInformation::instance().cpuLoad();
    mSeriesValues->clear();
    mSeriesValues->append("load ", cpuValue);
    mSeriesValues->append("free", 100.0-cpuValue);
}
