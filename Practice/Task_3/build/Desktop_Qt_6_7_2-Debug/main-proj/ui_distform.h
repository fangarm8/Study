/********************************************************************************
** Form generated from reading UI file 'distform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISTFORM_H
#define UI_DISTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DistForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *load;
    QPushButton *save;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *enterModel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *enterDate;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *enterMileage;
    QVBoxLayout *verticalLayout_3;
    QPushButton *enterInput;
    QPushButton *editSelected;
    QPushButton *deleteSelected;
    QPushButton *sortUp;

    void setupUi(QWidget *DistForm)
    {
        if (DistForm->objectName().isEmpty())
            DistForm->setObjectName("DistForm");
        DistForm->resize(804, 563);
        verticalLayout_2 = new QVBoxLayout(DistForm);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        load = new QPushButton(DistForm);
        load->setObjectName("load");

        horizontalLayout_5->addWidget(load);

        save = new QPushButton(DistForm);
        save->setObjectName("save");

        horizontalLayout_5->addWidget(save);


        verticalLayout_2->addLayout(horizontalLayout_5);

        tableView = new QTableView(DistForm);
        tableView->setObjectName("tableView");

        verticalLayout_2->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(DistForm);
        label_3->setObjectName("label_3");

        horizontalLayout_4->addWidget(label_3);

        enterModel = new QLineEdit(DistForm);
        enterModel->setObjectName("enterModel");

        horizontalLayout_4->addWidget(enterModel);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(DistForm);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        enterDate = new QLineEdit(DistForm);
        enterDate->setObjectName("enterDate");

        horizontalLayout_2->addWidget(enterDate);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(DistForm);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        enterMileage = new QLineEdit(DistForm);
        enterMileage->setObjectName("enterMileage");

        horizontalLayout_3->addWidget(enterMileage);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        enterInput = new QPushButton(DistForm);
        enterInput->setObjectName("enterInput");

        verticalLayout_3->addWidget(enterInput);

        editSelected = new QPushButton(DistForm);
        editSelected->setObjectName("editSelected");

        verticalLayout_3->addWidget(editSelected);

        deleteSelected = new QPushButton(DistForm);
        deleteSelected->setObjectName("deleteSelected");

        verticalLayout_3->addWidget(deleteSelected);

        sortUp = new QPushButton(DistForm);
        sortUp->setObjectName("sortUp");

        verticalLayout_3->addWidget(sortUp);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(DistForm);

        QMetaObject::connectSlotsByName(DistForm);
    } // setupUi

    void retranslateUi(QWidget *DistForm)
    {
        DistForm->setWindowTitle(QCoreApplication::translate("DistForm", "Form", nullptr));
        load->setText(QCoreApplication::translate("DistForm", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        save->setText(QCoreApplication::translate("DistForm", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("DistForm", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\274\320\276\320\264\320\265\320\273\320\270 \320\260\320\262\321\202\320\276", nullptr));
        label->setText(QCoreApplication::translate("DistForm", "\320\223\320\276\320\264 \320\262\321\213\320\277\321\203\321\201\320\272\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("DistForm", "\320\237\321\200\320\276\320\261\320\265\320\263 \320\260\320\262\321\202\320\276 (\320\272\320\274)", nullptr));
        enterInput->setText(QCoreApplication::translate("DistForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\262\320\262\320\265\320\264\320\265\320\275\320\275\320\276\320\265", nullptr));
        editSelected->setText(QCoreApplication::translate("DistForm", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        deleteSelected->setText(QCoreApplication::translate("DistForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
        sortUp->setText(QCoreApplication::translate("DistForm", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\277\320\276 \320\277\321\200\320\276\320\261\320\265\320\263\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DistForm: public Ui_DistForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISTFORM_H
