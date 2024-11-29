#ifndef DISTFORM_H
#define DISTFORM_H

#include <QWidget>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QFileDialog>
#include <QTableView>
#include <QStandardItemModel>
#include "cars1.h"

namespace Ui {
class DistForm;
}

class DistForm : public QWidget
{
    Q_OBJECT

public:
    explicit DistForm(QWidget *parent = nullptr);
    ~DistForm();

private slots:
    void on_enterInput_clicked();

    void on_editSelected_clicked();

    void on_deleteSelected_clicked();

    void on_sortUp_clicked();

    void on_save_clicked();

    void on_load_clicked();

private:
    Ui::DistForm *ui;
    int newidx;
    Cars1* model;
};

#endif // DISTFORM_H
