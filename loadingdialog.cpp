#include "loadingdialog.h"

void LoadingDialog::open(QWidget *parent, QString title, bool modal) {
    dialog = new QDialog(parent);
    dialog->setWindowTitle(title);
    dialog->setModal(modal);
    dialog->show();
}

void LoadingDialog::close() {
    dialog->hide();
}
