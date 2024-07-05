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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *saveFile;
    QAction *openFile;
    QAction *SelectColor;
    QAction *selLine;
    QAction *selRectangle;
    QAction *selEllipse;
    QAction *selPolygon;
    QAction *selMouseLine;
    QAction *action;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        saveFile = new QAction(MainWindow);
        saveFile->setObjectName("saveFile");
        openFile = new QAction(MainWindow);
        openFile->setObjectName("openFile");
        SelectColor = new QAction(MainWindow);
        SelectColor->setObjectName("SelectColor");
        selLine = new QAction(MainWindow);
        selLine->setObjectName("selLine");
        selRectangle = new QAction(MainWindow);
        selRectangle->setObjectName("selRectangle");
        selEllipse = new QAction(MainWindow);
        selEllipse->setObjectName("selEllipse");
        selPolygon = new QAction(MainWindow);
        selPolygon->setObjectName("selPolygon");
        selMouseLine = new QAction(MainWindow);
        selMouseLine->setObjectName("selMouseLine");
        action = new QAction(MainWindow);
        action->setObjectName("action");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        verticalLayout->addWidget(graphicsView);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(saveFile);
        menu->addAction(openFile);
        menu_2->addAction(SelectColor);
        menu_3->addAction(selLine);
        menu_3->addAction(selRectangle);
        menu_3->addAction(selEllipse);
        menu_3->addAction(selPolygon);
        menu_3->addAction(selMouseLine);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        saveFile->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        openFile->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        SelectColor->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202 \320\276\320\261\321\212\320\265\320\272\321\202\320\260", nullptr));
        selLine->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\321\217\320\274\320\260\321\217", nullptr));
        selRectangle->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        selEllipse->setText(QCoreApplication::translate("MainWindow", "\320\255\320\273\320\273\320\270\320\277\321\201", nullptr));
        selPolygon->setText(QCoreApplication::translate("MainWindow", "\320\240\320\276\320\274\320\261", nullptr));
        selMouseLine->setText(QCoreApplication::translate("MainWindow", "\320\241\320\262\320\276\320\261\320\276\320\264\320\275\320\276\320\265 \321\200\320\270\321\201\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\221\320\265\320\267 \320\267\320\260\320\273\320\270\320\262\320\272\320\270", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\276\320\261\321\212\320\272\321\202\320\260", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\276\321\200\320\274\320\260 \320\276\320\261\321\212\320\265\320\272\321\202\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
