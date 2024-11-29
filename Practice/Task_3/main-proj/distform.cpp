#include "distform.h"
#include "ui_distform.h"

DistForm::DistForm(QWidget *parent): QWidget(parent), ui(new Ui::DistForm)
{
    model = new Cars1;

    ui->setupUi(this);

}

DistForm::~DistForm()
{
    delete ui;
}

void DistForm::on_enterInput_clicked()
{
    QString mod_str = ui->enterModel->text();
    QString date_str = ui->enterDate->text();
    QString mileage_str = ui->enterMileage->text();
    uint date_ = date_str.toUInt();
    uint mileage_ = mileage_str.toUInt();

    model->append(distance(mod_str, date_, mileage_));
    this->ui->tableView->setModel(model);
}

void DistForm::on_editSelected_clicked()
{
    QString mod_str = ui->enterModel->text();
    QString date_str = ui->enterDate->text();
    QString mileage_str = ui->enterMileage->text();
    uint date_ = date_str.toUInt();
    uint mileage_ = mileage_str.toUInt();
    model->update(ui->tableView->currentIndex().row(), distance(mod_str, date_, mileage_));
}

void DistForm::on_deleteSelected_clicked()
{
    model->deleteRow(ui->tableView->currentIndex().row());
}


void DistForm::on_sortUp_clicked()
{
    model->SortUp();
}

void DistForm::on_save_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this);
    if (fileName.isEmpty()) {
        return;
    }

    model->save(fileName);
}


void DistForm::on_load_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if (fileName.isEmpty()) {
        return;
    }

    model->load(fileName);
    this->ui->tableView->setModel(model);
}

