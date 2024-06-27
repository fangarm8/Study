#ifndef PRIMARYFORM_H
#define PRIMARYFORM_H

#include <QWidget>

namespace Ui {
class PrimaryForm;
}

class PrimaryForm : public QWidget
{
    Q_OBJECT

public:
    explicit PrimaryForm(QWidget *parent = nullptr);
    ~PrimaryForm();

private slots:
    void on_enterButton_clicked();

private:
    Ui::PrimaryForm *ui;
};

#endif // PRIMARYFORM_H
