#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
#include <QTimer>
#include "paint.h"

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

private slots:

    void on_SelectColor_triggered();

    void on_selRectangle_triggered();

    void on_selEllipse_triggered();

    void on_selPolygon_triggered();

    void slotTimer();

    void on_selMouseLine_triggered();

private:
    Ui::MainWindow *ui;
    Paint* scene;
    QTimer *timer;
    void resizeEvent(QResizeEvent *event);
};
#endif // MAINWINDOW_H
