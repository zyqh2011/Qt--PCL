/********************************************************************************
** Form generated from reading UI file 'Myshow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYSHOW_H
#define UI_MYSHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyshowClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pcdshowButton;
    QPushButton *objtopcd;
    QPushButton *HarrisButton;
    QPushButton *SiftButton;
    QPushButton *IcpButton;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyshowClass)
    {
        if (MyshowClass->objectName().isEmpty())
            MyshowClass->setObjectName(QStringLiteral("MyshowClass"));
        MyshowClass->resize(600, 400);
        MyshowClass->setStyleSheet(QStringLiteral("background-color: rgb(45, 130, 32);"));
        centralWidget = new QWidget(MyshowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 30, 54, 12));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 20, 75, 23));
        pushButton->setStyleSheet(QStringLiteral("QPushButton { background-color: rgb(0, 100, 115); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(85,170,0); }"));
        pcdshowButton = new QPushButton(centralWidget);
        pcdshowButton->setObjectName(QStringLiteral("pcdshowButton"));
        pcdshowButton->setGeometry(QRect(20, 60, 75, 23));
        pcdshowButton->setStyleSheet(QStringLiteral("QPushButton { background-color: rgb(0, 100, 115); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(85,170,0); }"));
        objtopcd = new QPushButton(centralWidget);
        objtopcd->setObjectName(QStringLiteral("objtopcd"));
        objtopcd->setGeometry(QRect(30, 130, 75, 23));
        objtopcd->setStyleSheet(QStringLiteral("QPushButton { background-color: rgb(0, 100, 115); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(85,170,0); }"));
        HarrisButton = new QPushButton(centralWidget);
        HarrisButton->setObjectName(QStringLiteral("HarrisButton"));
        HarrisButton->setGeometry(QRect(30, 190, 81, 31));
        HarrisButton->setStyleSheet(QStringLiteral("QPushButton { background-color: rgb(0, 100, 115); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(85,170,0); }"));
        SiftButton = new QPushButton(centralWidget);
        SiftButton->setObjectName(QStringLiteral("SiftButton"));
        SiftButton->setGeometry(QRect(30, 240, 75, 23));
        SiftButton->setStyleSheet(QStringLiteral("QPushButton { background-color: rgb(0, 100, 115); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(85,170,0); }"));
        IcpButton = new QPushButton(centralWidget);
        IcpButton->setObjectName(QStringLiteral("IcpButton"));
        IcpButton->setGeometry(QRect(30, 280, 75, 23));
        IcpButton->setStyleSheet(QStringLiteral("QPushButton { background-color: rgb(0, 100, 115); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(85,170,0); }"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(260, 180, 75, 23));
        pushButton_2->setStyleSheet(QStringLiteral("color:rgb(0, 99, 0)"));
        MyshowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MyshowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        MyshowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyshowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MyshowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MyshowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyshowClass->setStatusBar(statusBar);

        retranslateUi(MyshowClass);

        QMetaObject::connectSlotsByName(MyshowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyshowClass)
    {
        MyshowClass->setWindowTitle(QApplication::translate("MyshowClass", "Myshow", Q_NULLPTR));
        label->setText(QApplication::translate("MyshowClass", "TextLabel", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MyshowClass", "PushButton", Q_NULLPTR));
        pcdshowButton->setText(QApplication::translate("MyshowClass", "\347\202\271\344\272\221\346\230\276\347\244\272", Q_NULLPTR));
        objtopcd->setText(QApplication::translate("MyshowClass", "obj2pcd", Q_NULLPTR));
        HarrisButton->setText(QApplication::translate("MyshowClass", "Harris\345\205\263\351\224\256\347\202\271", Q_NULLPTR));
        SiftButton->setText(QApplication::translate("MyshowClass", "Sift\345\205\263\351\224\256\347\202\271", Q_NULLPTR));
        IcpButton->setText(QApplication::translate("MyshowClass", "ICP\351\205\215\345\207\206", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MyshowClass", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyshowClass: public Ui_MyshowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYSHOW_H
