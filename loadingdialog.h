#ifndef LOADINGDIALOG_H
#define LOADINGDIALOG_H

#include <QDialog>

class LoadingDialog {
public:
    void open(QWidget* parent, QString title, bool modal);
    void close();

private:
    QDialog* dialog;
};

#endif // LOADINGDIALOG_H
