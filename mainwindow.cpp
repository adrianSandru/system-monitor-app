#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "systeminformation.h"

#include <QGridLayout>
#include <QBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    mCpuWidget = new CpuAverageWidget(this);
    mCpuUserModeWidget = new CpuUserModeWidget(this);
    mCpuKernelModeWidget = new CpuKernelModeWidget(this);
    mCpuIdleModeWidget = new CpuIdleModeWidget(this);
    mAverageMemoryUsage = new MemoryAverageUsageWidget(this);

    ui->setupUi(this);
    SystemInformation::instance().initialize();
    QGridLayout * layout = new QGridLayout;
    ui->centralWidget->setLayout(layout);
    ui->centralWidget->setStyleSheet("background-color:#015673");
    layout->addWidget(mCpuWidget,0,0);
    layout->addWidget(mCpuUserModeWidget,0,1);
    layout->addWidget(mCpuKernelModeWidget,1,0);
    layout->addWidget(mCpuIdleModeWidget,1,1);
    layout->addWidget(mAverageMemoryUsage,2,0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
