#ifndef SYSINFOWIDGET_H
#define SYSINFOWIDGET_H

#include <QWidget>
#include <QtCharts/QChartView>
#include <QTimer>

class SysInfoWidget : public QWidget
{
private:
    QTimer mTimer;
    QtCharts::QChartView mChartView;

    Q_OBJECT
public:
    explicit SysInfoWidget(QWidget *parent = nullptr,
                           int delayStart = 300,
                           int updateValuesDelay = 500);

    QtCharts::QChartView& chartView();
protected:


protected slots:
    virtual void updateChartsValues() = 0;
};

#endif // SYSINFOWIDGET_H
