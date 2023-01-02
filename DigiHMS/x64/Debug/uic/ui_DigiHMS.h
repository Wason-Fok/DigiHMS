/********************************************************************************
** Form generated from reading UI file 'DigiHMS.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIGIHMS_H
#define UI_DIGIHMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DigiHMSClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DigiHMSClass)
    {
        if (DigiHMSClass->objectName().isEmpty())
            DigiHMSClass->setObjectName(QString::fromUtf8("DigiHMSClass"));
        DigiHMSClass->resize(600, 400);
        menuBar = new QMenuBar(DigiHMSClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        DigiHMSClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DigiHMSClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        DigiHMSClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(DigiHMSClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        DigiHMSClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DigiHMSClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DigiHMSClass->setStatusBar(statusBar);

        retranslateUi(DigiHMSClass);

        QMetaObject::connectSlotsByName(DigiHMSClass);
    } // setupUi

    void retranslateUi(QMainWindow *DigiHMSClass)
    {
        DigiHMSClass->setWindowTitle(QCoreApplication::translate("DigiHMSClass", "DigiHMS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DigiHMSClass: public Ui_DigiHMSClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIGIHMS_H
