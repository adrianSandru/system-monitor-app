#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "systeminformation.h"

#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    mCpuWidget = new CpuAverageWidget(this);
    mCpuUserModeWidget = new CpuUserModeWidget(this);
    mCpuKernelModeWidget = new CpuKernelModeWidget(this);
    mCpuIdleModeWidget = new CpuIdleModeWidget(this);

    ui->setupUi(this);
    SystemInformation::instance().initialize();
    QGridLayout * layout = new QGridLayout;
    ui->centralWidget->setLayout(layout);
    layout->addWidget(mCpuWidget,0,0);
    layout->addWidget(mCpuUserModeWidget,0,1);
    layout->addWidget(mCpuKernelModeWidget,1,0);
    layout->addWidget(mCpuIdleModeWidget,1,1);
    //ui->centralWidget->layout()->addWidget(&mCpuWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
