#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>
#include "messagedialog.h"

//#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

private slots:
    void execCmd(QString cmd);
    void processFinished(int code, QProcess::ExitStatus status);
    void readOutput();
    void readError();
    void aggiornaYdl();
    void on_btnDownload_clicked();
    void onActionAbout();

private:
    Ui::MainWindow *ui;
    QString strFile;
    QString cmdDownYdl;
    QProcess *process;
};
#endif // MAINWINDOW_H
