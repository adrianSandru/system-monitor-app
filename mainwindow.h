#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cpuaveragewidget.h"
#include "cpuusermodewidget.h"
#include "cpukernelmodewidget.h"
#include "cpuidlemodewidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    SysInfoWidget *mCpuWidget;
    SysInfoWidget *mCpuUserModeWidget;
    SysInfoWidget *mCpuKernelModeWidget;
    SysInfoWidget *mCpuIdleModeWidget;
};

#endif // MAINWINDOW_H
