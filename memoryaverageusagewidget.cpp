#include "memoryaverageusagewidget.h"
#include "systeminformation.h"

#include <QtCharts/QAreaSeries>
#include <QKeyEvent>

using namespace QtCharts;

MemoryAverageUsageWidget::
MemoryAverageUsageWidget(QWidget * parent):
                        SysInfoWidget(parent,300,500)
{
    this->setFocus();
    mXPoint = 0;
    mLineSeries = new QLineSeries(this);

    QAreaSeries * fArea = new QAreaSeries(mLineSeries);
    QChart * fChart = chartView().chart();
    fChart->addSeries(fArea);
    fChart->setTitle("Average memory usage");
    fChart->createDefaultAxes();
    fChart->axisX()->setVisible(false);
    fChart->axisX()->setRange(0, MAX_RANGE);
    fChart->axisY()->setRange(0,100);
}

void MemoryAverageUsageWidget::updateChartsValues()
{
    double fAverageMemoryValues = SystemInformation::instance().memoryUsage();
    mLineSeries->append(mXPoint++,fAverageMemoryValues);
    if(mLineSeries->count() > COUNT)
    {
        QChart * fChart = chartView().chart();
        fChart->scroll(fChart->plotArea().width() / MAX_RANGE,0);
    }
}

void MemoryAverageUsageWidget::keyPressEvent(QKeyEvent *event)
{
    qDebug("print key event");
    if(event->key() == Qt::Key_Left)
    {
        QChart * fChart = chartView().chart();
        fChart->scroll(-10,0);
        qDebug("print key event");
    }
    if(event->key() == Qt::Key_Right)
    {
        QChart * fChart = chartView().chart();
        fChart->scroll(10,0);
    }
}
