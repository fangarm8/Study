#ifndef SINFORM_H
#define SINFORM_H

#include <QWidget>

namespace Ui {
class sinform;
}

class sinform : public QWidget
{
    Q_OBJECT

public:
    explicit sinform(QWidget *parent = nullptr);
    ~sinform();

private slots:
    void on_enterButton_clicked();

private:
    Ui::sinform *ui;
};

#endif // SINFORM_H
