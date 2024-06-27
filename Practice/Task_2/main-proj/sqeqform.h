#ifndef SQEQFORM_H
#define SQEQFORM_H

#include <QWidget>

namespace Ui {
class SqEqform;
}

class SqEqform : public QWidget
{
    Q_OBJECT

public:
    explicit SqEqform(QWidget *parent = nullptr);
    ~SqEqform();

private:
    Ui::SqEqform *ui;
};

#endif // SQEQFORM_H
