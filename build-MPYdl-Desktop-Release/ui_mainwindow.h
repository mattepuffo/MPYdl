/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAggiorna;
    QAction *actionEsci;
    QAction *actionAbout;
    QWidget *centralwidget;
    QPlainTextEdit *txtRes;
    QPushButton *btnDownload;
    QLineEdit *txtUrl;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 600);
        MainWindow->setMinimumSize(QSize(600, 600));
        MainWindow->setMaximumSize(QSize(600, 600));
        actionAggiorna = new QAction(MainWindow);
        actionAggiorna->setObjectName(QString::fromUtf8("actionAggiorna"));
        actionEsci = new QAction(MainWindow);
        actionEsci->setObjectName(QString::fromUtf8("actionEsci"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        txtRes = new QPlainTextEdit(centralwidget);
        txtRes->setObjectName(QString::fromUtf8("txtRes"));
        txtRes->setGeometry(QRect(10, 40, 581, 531));
        txtRes->setReadOnly(true);
        btnDownload = new QPushButton(centralwidget);
        btnDownload->setObjectName(QString::fromUtf8("btnDownload"));
        btnDownload->setGeometry(QRect(510, 10, 80, 23));
        txtUrl = new QLineEdit(centralwidget);
        txtUrl->setObjectName(QString::fromUtf8("txtUrl"));
        txtUrl->setGeometry(QRect(10, 10, 491, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 20));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menu->menuAction());
        menuFile->addAction(actionAggiorna);
        menuFile->addAction(actionEsci);
        menu->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MPYdl", nullptr));
        actionAggiorna->setText(QCoreApplication::translate("MainWindow", "Aggiorna YDL", nullptr));
#if QT_CONFIG(shortcut)
        actionAggiorna->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+U", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEsci->setText(QCoreApplication::translate("MainWindow", "Esci", nullptr));
#if QT_CONFIG(shortcut)
        actionEsci->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
#if QT_CONFIG(shortcut)
        actionAbout->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+'", nullptr));
#endif // QT_CONFIG(shortcut)
        btnDownload->setText(QCoreApplication::translate("MainWindow", "Download", nullptr));
        txtUrl->setText(QString());
        txtUrl->setPlaceholderText(QCoreApplication::translate("MainWindow", "Inserisci un URL", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
