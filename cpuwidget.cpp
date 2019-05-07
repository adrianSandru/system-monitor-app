#include "cpuwidget.h"
#include "systeminformation.h"

using namespace QtCharts;

CpuWidget::CpuWidget(QWidget *parent) : SysInfoWidget(parent)
{
    mSeriesValues = new QPieSeries(this);
    mSeriesValues->setHoleSize(0.35);
    mSeriesValues->append("cpu load", 30);
    mSeriesValues->append("cpu free", 70);

    QChart * fChart = chartView().chart();
    fChart->addSeries(mSeriesValues);
    fChart->setTitle("cpu load");
}

void CpuWidget::updateChartsValues()
{
    double cpuValue = SystemInformation::instance().cpuLoad();
    mSeriesValues->clear();
    mSeriesValues->append("load ", cpuValue);
    mSeriesValues->append("free", 100.0-cpuValue);
}
