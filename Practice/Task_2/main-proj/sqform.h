#ifndef SQFORM_H
#define SQFORM_H

#include <QWidget>

namespace Ui {
class Sqform;
}

class Sqform : public QWidget
{
    Q_OBJECT

public:
    explicit Sqform(QWidget *parent = nullptr);
    ~Sqform();

private slots:
    void on_enterButton_clicked();

private:
    Ui::Sqform *ui;
};

#endif // SQFORM_H
