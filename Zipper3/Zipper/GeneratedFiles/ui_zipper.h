/********************************************************************************
** Form generated from reading UI file 'zipper.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZIPPER_H
#define UI_ZIPPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ZipperClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ZipperClass)
    {
        if (ZipperClass->objectName().isEmpty())
            ZipperClass->setObjectName(QStringLiteral("ZipperClass"));
        ZipperClass->resize(508, 211);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Zipper/Resources/Bandizip.png"), QSize(), QIcon::Normal, QIcon::Off);
        ZipperClass->setWindowIcon(icon);
        centralWidget = new QWidget(ZipperClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ZipperClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ZipperClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 508, 21));
        ZipperClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ZipperClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ZipperClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ZipperClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ZipperClass->setStatusBar(statusBar);

        retranslateUi(ZipperClass);

        QMetaObject::connectSlotsByName(ZipperClass);
    } // setupUi

    void retranslateUi(QMainWindow *ZipperClass)
    {
        ZipperClass->setWindowTitle(QApplication::translate("ZipperClass", "Zipper", 0));
    } // retranslateUi

};

namespace Ui {
    class ZipperClass: public Ui_ZipperClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZIPPER_H
