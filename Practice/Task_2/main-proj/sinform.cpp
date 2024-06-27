#include "sinform.h"
#include "ui_sinform.h"
#include "num.h"

sinform::sinform(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::sinform)
{
    ui->setupUi(this);
}

sinform::~sinform()
{
    delete ui;
}



void sinform::on_enterButton_clicked()
{
    QString num_str = ui->enterNum->text();
    QString eps_str = ui->enterAccuracy->text();
    double num_ = static_cast<double>(num_str.toDouble());
    double eps_ = static_cast<double>(eps_str.toDouble());
    double res = num().sin(num_, eps_);
    QString tmp = QString::number(res);
    num_str = "sin(" + num_str + ")" + " = " + tmp;
    ui->ans->setText(num_str);
}

