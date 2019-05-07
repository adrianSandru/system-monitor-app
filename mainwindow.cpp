#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "systeminformation.h"

#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mCpuWidget(this)
{
    ui->setupUi(this);
    SystemInformation::instance().initialize();
    QGridLayout * layout = new QGridLayout;
    ui->centralWidget->setLayout(layout);
    layout->addWidget(&mCpuWidget,0,0);
    //ui->centralWidget->layout()->addWidget(&mCpuWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
