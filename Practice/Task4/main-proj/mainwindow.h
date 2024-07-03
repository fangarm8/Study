#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rectangle.h"
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

private:
    Ui::MainWindow *ui;
    QColor selColor;
    Paint* scene;
    Rectangle* rec;
    //QVector<Rectangle*> figures;
    //uint obj_type;
};
#endif // MAINWINDOW_H
