#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "primaryform.h"
#include "sinform.h"
#include "sqform.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    primaryWindow.show();
}


void MainWindow::on_pushButton_2_clicked()
{
    sinWindow.show();
}

void MainWindow::on_pushButton_3_clicked()
{
    SqWindow.show();
}

