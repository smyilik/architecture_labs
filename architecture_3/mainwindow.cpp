#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "clientinterface.h"



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clientInt = ClientInterface::getInstance();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_getIDButton_clicked()
{
    const int id = ui->getIDSpinBox->value();
    clientInt->getNargile(id);
}


void MainWindow::on_getAllButton_clicked()
{
    clientInt->getNargile();
}

void MainWindow::on_createButton_clicked()
{
    //const QString name = ui->createLineEdit->textContent();
    const QString name = ui->createLineEdit->text();
    const QString bowl_type = ui->createComboBox1->currentText();
    const QString bowl_material = ui->createComboBox2->currentText();
    const QString tobacco = ui->createComboBox3->currentText();
    const int years_of_usage = ui->createSpinBox1->value();
    const int flask_volume = ui->createSpinBox2->value();
    clientInt->createNargile(name, bowl_type, bowl_material, tobacco, years_of_usage, flask_volume);
}


void MainWindow::on_updateButton_clicked()
{
    const int id = ui->updateSpinBox->value();
    const QString name = ui->updateLineEdit->text();
    const QString bowl_type = ui->updateComboBox1->currentText();
    const QString bowl_material = ui->updateComboBox2->currentText();
    const QString tobacco = ui->updateComboBox3->currentText();
    const int years_of_usage = ui->updateSpinBox1->value();
    const int flask_volume = ui->updateSpinBox2->value();
    clientInt->updateNargile(id, name, bowl_type, bowl_material, tobacco, years_of_usage, flask_volume);
}


void MainWindow::on_deleteButton_clicked()
{
    const int id = ui->deleteSpinBox->value();
    clientInt->deleteNargile(id);
}

