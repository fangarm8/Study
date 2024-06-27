#include "sqeqform.h"
#include "ui_sqeqform.h"

SqEqform::SqEqform(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SqEqform)
{
    ui->setupUi(this);
}

SqEqform::~SqEqform()
{
    delete ui;
}
