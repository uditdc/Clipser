#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSystemTrayIcon"
#include <QDebug>
#include <QCloseEvent>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initializeControls();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeControls(){

    // System Tray initialization
    QAction *actionQuit = new QAction("Quit",this);
    connect(actionQuit, SIGNAL(triggered()), qApp, SLOT(quit()));

    trayMenu = new QMenu();
    trayMenu->addAction(actionQuit);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayMenu);
    trayIcon->setIcon(QIcon(":/GameInLinux.png"));
    trayIcon->show();

    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this,
            SLOT(trayClicked(QSystemTrayIcon::ActivationReason)));

    // hide on close
    //connect(MainWindow.centralWidget(), SIGNAL(destroyed()), this, SLOT(hide()));

}

void MainWindow::trayClicked(QSystemTrayIcon::ActivationReason reason){
    if(reason==QSystemTrayIcon::DoubleClick){
        this->showNormal();
        this->activateWindow();
    }
}

void MainWindow::hideWindow(){
    this->hide();
}

void MainWindow::closeEvent(QCloseEvent *e){
    hideWindow();
    e->ignore();
}
