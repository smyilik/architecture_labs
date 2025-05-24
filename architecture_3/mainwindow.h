#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include "clientinterface.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ClientInterface *clientInt = nullptr;

private slots:
    void on_getIDButton_clicked();
    void on_getAllButton_clicked();
    void on_createButton_clicked();
    void on_updateButton_clicked();
    void on_deleteButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
