/********************************************************************************
** Form generated from reading UI file 'sqeqform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SQEQFORM_H
#define UI_SQEQFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SqEqform
{
public:

    void setupUi(QWidget *SqEqform)
    {
        if (SqEqform->objectName().isEmpty())
            SqEqform->setObjectName("SqEqform");
        SqEqform->resize(400, 300);

        retranslateUi(SqEqform);

        QMetaObject::connectSlotsByName(SqEqform);
    } // setupUi

    void retranslateUi(QWidget *SqEqform)
    {
        SqEqform->setWindowTitle(QCoreApplication::translate("SqEqform", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SqEqform: public Ui_SqEqform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQEQFORM_H
