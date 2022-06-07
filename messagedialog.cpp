#include "messagedialog.h"
#include "ui_messagedialog.h"

MessageDialog::MessageDialog(QString title, QString message, QWidget *parent) : QDialog(parent), ui(new Ui::MessageDialog) {
    ui->setupUi(this);
    this->setWindowTitle(title);
    ui->txtMessage->setHtml(message);
}

MessageDialog::~MessageDialog() {
    delete ui;
}
