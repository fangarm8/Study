/********************************************************************************
** Form generated from reading UI file 'tableviewform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEVIEWFORM_H
#define UI_TABLEVIEWFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TableViewForm
{
public:
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;

    void setupUi(QWidget *TableViewForm)
    {
        if (TableViewForm->objectName().isEmpty())
            TableViewForm->setObjectName("TableViewForm");
        TableViewForm->resize(747, 501);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TableViewForm->sizePolicy().hasHeightForWidth());
        TableViewForm->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(TableViewForm);
        horizontalLayout->setObjectName("horizontalLayout");
        tableView = new QTableView(TableViewForm);
        tableView->setObjectName("tableView");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(tableView);


        retranslateUi(TableViewForm);

        QMetaObject::connectSlotsByName(TableViewForm);
    } // setupUi

    void retranslateUi(QWidget *TableViewForm)
    {
        TableViewForm->setWindowTitle(QCoreApplication::translate("TableViewForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TableViewForm: public Ui_TableViewForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEVIEWFORM_H
