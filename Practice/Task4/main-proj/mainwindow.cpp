#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new Paint();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_saveFile_triggered()
{
    QString newPath = QFileDialog::getSaveFileName(this, "Save SVG", path, "SVG files (* .svg)");
    if (newPath.isEmpty())
        return;

    path = newPath;

    QSvgGenerator gen;
    gen.setFileName(path);
    gen.setSize(QSize(scene->width(), scene->height()));
    gen.setViewBox(QRect(0, 0, scene->width(), scene->height()));
    gen.setTitle("main-proj");
    gen.setDescription("File created by Qt-editor");

    QPainter save_painter;
    save_painter.begin(&gen);
    scene->render(&save_painter);
    save_painter.end();
}

void MainWindow::on_SelectColor_triggered()
{
    scene->selColor = QColorDialog::getColor(Qt::black, this);
}


void MainWindow::on_selRectangle_triggered()
{
    scene->obj_type = 0;
}


void MainWindow::on_selEllipse_triggered()
{
    scene->obj_type = 1;
}


void MainWindow::on_selPolygon_triggered()
{
    scene->obj_type = 2;
}

void MainWindow::slotTimer()
{
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QMainWindow::resizeEvent(event);
}


