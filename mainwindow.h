#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initializeControls();

    void hideWindow();
    void closeEvent(QCloseEvent *event);

public slots:
     void trayClicked(QSystemTrayIcon::ActivationReason reason);
private:
    Ui::MainWindow *ui;
    QMenu *trayMenu;
    QSystemTrayIcon *trayIcon;


};

#endif // MAINWINDOW_H
