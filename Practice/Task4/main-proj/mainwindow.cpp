#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new Paint();
    ui->graphicsView->setScene(scene);

    //connect(this->scene, &Paint::signalTargetCoordinate, rec, &Rectangle::slotTarget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SelectColor_triggered()
{
    selColor = QColorConstants::Red;
}


void MainWindow::on_selRectangle_triggered()
{
    /*rec = new Rectangle(scene->target);
    scene->addItem(rec);*/
}

