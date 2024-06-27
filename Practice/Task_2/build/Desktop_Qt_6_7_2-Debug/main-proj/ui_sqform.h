/********************************************************************************
** Form generated from reading UI file 'sqform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SQFORM_H
#define UI_SQFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sqform
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *enterAX;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *enterBX;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLineEdit *enterCX;
    QPushButton *enterButton;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *ans;

    void setupUi(QWidget *Sqform)
    {
        if (Sqform->objectName().isEmpty())
            Sqform->setObjectName("Sqform");
        Sqform->resize(759, 567);
        verticalLayout_3 = new QVBoxLayout(Sqform);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(Sqform);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        enterAX = new QLineEdit(Sqform);
        enterAX->setObjectName("enterAX");

        horizontalLayout_3->addWidget(enterAX);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_4 = new QLabel(Sqform);
        label_4->setObjectName("label_4");

        horizontalLayout_2->addWidget(label_4);

        enterBX = new QLineEdit(Sqform);
        enterBX->setObjectName("enterBX");

        horizontalLayout_2->addWidget(enterBX);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_5 = new QLabel(Sqform);
        label_5->setObjectName("label_5");

        horizontalLayout->addWidget(label_5);

        enterCX = new QLineEdit(Sqform);
        enterCX->setObjectName("enterCX");

        horizontalLayout->addWidget(enterCX);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout);

        enterButton = new QPushButton(Sqform);
        enterButton->setObjectName("enterButton");

        verticalLayout_3->addWidget(enterButton);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(Sqform);
        label->setObjectName("label");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(label);

        ans = new QLabel(Sqform);
        ans->setObjectName("ans");

        verticalLayout_2->addWidget(ans);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(Sqform);

        QMetaObject::connectSlotsByName(Sqform);
    } // setupUi

    void retranslateUi(QWidget *Sqform)
    {
        Sqform->setWindowTitle(QCoreApplication::translate("Sqform", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("Sqform", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\321\202\320\265\320\273\321\214\320\275\320\276\320\265 \321\207\320\270\321\201\320\273\320\276, \320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 \320\277\321\200\320\270 x^2", nullptr));
        label_4->setText(QCoreApplication::translate("Sqform", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\321\202\320\265\320\273\321\214\320\275\320\276\320\265 \321\207\320\270\321\201\320\273\320\276, \320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 \320\277\321\200\320\270 x", nullptr));
        label_5->setText(QCoreApplication::translate("Sqform", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\321\202\320\265\320\273\321\214\320\275\320\276\320\265 \321\207\320\270\321\201\320\273\320\276, \321\201\320\262\320\276\320\261\320\276\320\264\320\275\321\213\320\271 \321\207\320\273\320\265\320\275", nullptr));
        enterButton->setText(QCoreApplication::translate("Sqform", "\320\222\320\262\320\276\320\264", nullptr));
        label->setText(QCoreApplication::translate("Sqform", "\320\240\320\265\321\210\320\265\320\275\320\270\320\265 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\321\217:", nullptr));
        ans->setText(QCoreApplication::translate("Sqform", "\320\236\321\202\320\262\320\265\321\202:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sqform: public Ui_Sqform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQFORM_H
