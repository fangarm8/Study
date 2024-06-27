/********************************************************************************
** Form generated from reading UI file 'sinform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINFORM_H
#define UI_SINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sinform
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *enterNum;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *enterAccuracy;
    QPushButton *enterButton;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *ans;

    void setupUi(QWidget *sinform)
    {
        if (sinform->objectName().isEmpty())
            sinform->setObjectName("sinform");
        sinform->resize(857, 572);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sinform->sizePolicy().hasHeightForWidth());
        sinform->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(sinform);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(sinform);
        label->setObjectName("label");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label);

        enterNum = new QLineEdit(sinform);
        enterNum->setObjectName("enterNum");

        horizontalLayout->addWidget(enterNum);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(sinform);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        enterAccuracy = new QLineEdit(sinform);
        enterAccuracy->setObjectName("enterAccuracy");

        horizontalLayout_2->addWidget(enterAccuracy);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);

        enterButton = new QPushButton(sinform);
        enterButton->setObjectName("enterButton");

        verticalLayout_3->addWidget(enterButton);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_2 = new QLabel(sinform);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(label_2);

        ans = new QLabel(sinform);
        ans->setObjectName("ans");

        verticalLayout->addWidget(ans);


        verticalLayout_3->addLayout(verticalLayout);


        retranslateUi(sinform);

        QMetaObject::connectSlotsByName(sinform);
    } // setupUi

    void retranslateUi(QWidget *sinform)
    {
        sinform->setWindowTitle(QCoreApplication::translate("sinform", "Form", nullptr));
        label->setText(QCoreApplication::translate("sinform", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\321\202\320\265\320\273\321\214\320\275\320\276\320\265 \321\207\320\270\321\201\320\273\320\276", nullptr));
        label_3->setText(QCoreApplication::translate("sinform", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\202\320\276\321\207\320\275\320\276\321\201\321\202\321\214 \320\277\320\276\320\264\321\201\321\207\320\265\321\202\320\260 \321\201\320\270\320\275\321\203\321\201\320\260", nullptr));
        enterButton->setText(QCoreApplication::translate("sinform", "\320\222\320\262\320\276\320\264", nullptr));
        label_2->setText(QCoreApplication::translate("sinform", "\320\241\320\270\320\275\321\203\321\201 \321\207\320\270\321\201\320\273\320\260:", nullptr));
        ans->setText(QCoreApplication::translate("sinform", "\320\236\321\202\320\262\320\265\321\202:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sinform: public Ui_sinform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINFORM_H
