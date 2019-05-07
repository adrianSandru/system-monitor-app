#include "sysinfowidget.h"
#include <QVBoxLayout>

using namespace QtCharts;

SysInfoWidget::SysInfoWidget(QWidget *parent,
                             int delayStart,
                             int updateValuesDelay) :
                            QWidget(parent),
                            mChartView(this)
{
    mTimer.setInterval(updateValuesDelay);
    connect(&mTimer, &QTimer::timeout, this, &SysInfoWidget::updateChartsValues);
    QTimer::singleShot(delayStart,
                       [this] {mTimer.start();});
    mChartView.setRenderHint(QPainter::Antialiasing);
    mChartView.chart()->legend()->setVisible(false);
    QVBoxLayout * fBoxLayout = new QVBoxLayout(this);
    fBoxLayout->addWidget(&mChartView);
    setLayout(fBoxLayout);
}

QChartView& SysInfoWidget::chartView()
{
    return mChartView;
}
