/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Car1button;
    QPushButton *Car2button;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        Car1button = new QPushButton(centralwidget);
        Car1button->setObjectName("Car1button");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Car1button->sizePolicy().hasHeightForWidth());
        Car1button->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(Car1button);

        Car2button = new QPushButton(centralwidget);
        Car2button->setObjectName("Car2button");
        sizePolicy.setHeightForWidth(Car2button->sizePolicy().hasHeightForWidth());
        Car2button->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(Car2button);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Car1button->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\210\320\270\320\275\321\213 \321\201 \320\277\321\200\320\276\320\261\320\265\320\263\320\276\320\274", nullptr));
        Car2button->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\210\320\270\320\275\321\213 \320\261\320\265\320\267 \320\277\321\200\320\276\320\261\320\265\320\263\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
