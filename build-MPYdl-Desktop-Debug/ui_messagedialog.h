/********************************************************************************
** Form generated from reading UI file 'messagedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEDIALOG_H
#define UI_MESSAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_MessageDialog
{
public:
    QDialogButtonBox *buttonBox;
    QTextBrowser *txtMessage;

    void setupUi(QDialog *MessageDialog)
    {
        if (MessageDialog->objectName().isEmpty())
            MessageDialog->setObjectName(QString::fromUtf8("MessageDialog"));
        MessageDialog->setWindowModality(Qt::WindowModal);
        MessageDialog->resize(400, 400);
        MessageDialog->setMinimumSize(QSize(400, 400));
        MessageDialog->setMaximumSize(QSize(400, 400));
        MessageDialog->setBaseSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/logo.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MessageDialog->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(MessageDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 360, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        buttonBox->setCenterButtons(true);
        txtMessage = new QTextBrowser(MessageDialog);
        txtMessage->setObjectName(QString::fromUtf8("txtMessage"));
        txtMessage->setGeometry(QRect(5, 10, 391, 341));
        txtMessage->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        retranslateUi(MessageDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), MessageDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MessageDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(MessageDialog);
    } // setupUi

    void retranslateUi(QDialog *MessageDialog)
    {
        MessageDialog->setWindowTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class MessageDialog: public Ui_MessageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEDIALOG_H
