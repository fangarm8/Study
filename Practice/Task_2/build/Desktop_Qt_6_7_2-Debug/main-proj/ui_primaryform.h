/********************************************************************************
** Form generated from reading UI file 'primaryform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRIMARYFORM_H
#define UI_PRIMARYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrimaryForm
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *enterNum;
    QPushButton *enterButton;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *ans;

    void setupUi(QWidget *PrimaryForm)
    {
        if (PrimaryForm->objectName().isEmpty())
            PrimaryForm->setObjectName("PrimaryForm");
        PrimaryForm->resize(857, 572);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PrimaryForm->sizePolicy().hasHeightForWidth());
        PrimaryForm->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(PrimaryForm);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(PrimaryForm);
        label->setObjectName("label");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label);

        enterNum = new QLineEdit(PrimaryForm);
        enterNum->setObjectName("enterNum");

        horizontalLayout->addWidget(enterNum);


        verticalLayout_2->addLayout(horizontalLayout);

        enterButton = new QPushButton(PrimaryForm);
        enterButton->setObjectName("enterButton");

        verticalLayout_2->addWidget(enterButton);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_2 = new QLabel(PrimaryForm);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(label_2);

        ans = new QLabel(PrimaryForm);
        ans->setObjectName("ans");

        verticalLayout->addWidget(ans);


        verticalLayout_3->addLayout(verticalLayout);


        retranslateUi(PrimaryForm);

        QMetaObject::connectSlotsByName(PrimaryForm);
    } // setupUi

    void retranslateUi(QWidget *PrimaryForm)
    {
        PrimaryForm->setWindowTitle(QCoreApplication::translate("PrimaryForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("PrimaryForm", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\260\321\202\321\203\321\200\320\260\320\273\321\214\320\275\320\276\320\265 \321\207\320\270\321\201\320\273\320\276", nullptr));
        enterButton->setText(QCoreApplication::translate("PrimaryForm", "\320\222\320\262\320\276\320\264", nullptr));
        label_2->setText(QCoreApplication::translate("PrimaryForm", "\320\240\320\260\320\267\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \321\207\320\270\321\201\320\273\320\260:", nullptr));
        ans->setText(QCoreApplication::translate("PrimaryForm", "\320\236\321\202\320\262\320\265\321\202:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PrimaryForm: public Ui_PrimaryForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIMARYFORM_H
