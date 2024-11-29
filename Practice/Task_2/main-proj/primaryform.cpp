#include "primaryform.h"
#include "ui_primaryform.h"
#include "num.h"

PrimaryForm::PrimaryForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PrimaryForm)
{
    ui->setupUi(this);
}

PrimaryForm::~PrimaryForm()
{
    delete ui;
}

void PrimaryForm::on_enterButton_clicked()
{
    QString num_str = ui->enterNum->text();
    uint num_ = static_cast<uint>(num_str.toInt());
    QVector<uint> multiple = num().PrimaryMultiple(num_);
    QString tmp = QString::number(multiple[0]);
    num_str = num_str + " = " + tmp;
    for (qsizetype i = 1; i < multiple.size(); i++) {
        tmp = QString::number(multiple[i]);
        num_str+= " *" + tmp;
    }
    ui->ans->setText(num_str);
}
