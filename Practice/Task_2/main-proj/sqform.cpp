#include "sqform.h"
#include "ui_sqform.h"
#include "num.h"
#include <QMessageBox>

Sqform::Sqform(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Sqform)
{
    ui->setupUi(this);
}

Sqform::~Sqform()
{
    delete ui;
}

void Sqform::on_enterButton_clicked()
{
    QString ax_str = ui->enterAX->text();
    QString bx_str = ui->enterBX->text();
    QString cx_str = ui->enterCX->text();

    double ax = static_cast<double>(ax_str.toDouble());
    double bx = static_cast<double>(bx_str.toDouble());
    double cx = static_cast<double>(cx_str.toDouble());
    QVector<double> res;
    try {
        res = num().SqEq(ax, bx, cx);
    }
    catch (QString error_message) {
        QMessageBox::warning(this, error_message, "У данного уравнения нет действительных корней");
    }
    QString tmp;
    for (qsizetype i = 0; i < res.size(); i++) {
        tmp+= "x" + QString::number(i+1) + " = " + QString::number(res[i]) + "\n";
    }
    ui->ans->setText(tmp);
}

