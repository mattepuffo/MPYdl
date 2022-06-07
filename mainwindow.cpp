#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

#ifdef __linux__
    strFile = "./ydl";
    cmdDownYdl = "curl -L https://yt-dl.org/downloads/latest/youtube-dl -o ydl";
#else
    strFile = "ydl.exe";
    cmdDownYdl = "curl-win/bin/curl.exe -L https://yt-dl.org/downloads/latest/youtube-dl.exe -o ydl.exe";
#endif

    //QFile::remove(strFile);
    if(!QFileInfo::exists(strFile)) {
        execCmd(cmdDownYdl);
    }

    connect(ui->actionEsci, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionAggiorna, SIGNAL(triggered()), this, SLOT(aggiornaYdl()));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(onActionAbout()));
    connect(ui->txtUrl, SIGNAL(returnPressed()), ui->btnDownload, SIGNAL(clicked()));
}

void MainWindow::execCmd(QString cmd) {
    ui->txtRes->clear();
    ui->txtUrl->setEnabled(false);
    ui->btnDownload->setEnabled(false);

    process = new QProcess();
    if (process) {
        process->setEnvironment(QProcess::systemEnvironment());
        process->setProcessChannelMode(QProcess::MergedChannels);
        process->start(cmd);
        process->waitForStarted();
        connect(process, &QProcess::readyReadStandardOutput, this, &MainWindow::readOutput);
        connect(process, &QProcess::readyReadStandardError, this, &MainWindow::readError);
        connect(process, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(processFinished(int, QProcess::ExitStatus)));
    }
}

void MainWindow::processFinished(int code, QProcess::ExitStatus status) {
    process->kill();
    ui->txtRes->appendPlainText("\nTERMINATO");
    ui->txtRes->ensureCursorVisible();
    ui->txtRes->centerOnScroll();
    ui->txtUrl->setEnabled(true);
    ui->txtUrl->setText("");
    ui->btnDownload->setEnabled(true);
}

void MainWindow::readOutput() {
    QProcess *process = dynamic_cast<QProcess*>(sender());
    if (process) {
        ui->txtRes->appendPlainText(process->readAllStandardOutput());
    }
}

void MainWindow::readError() {
    QProcess *process = dynamic_cast<QProcess*>(sender());
    if (process) {
        QPalette p = ui->txtRes->palette();
        p.setColor(QPalette::Text, Qt::red);
        ui->txtRes->setPalette(p);
        ui->txtRes->appendPlainText(process->readAllStandardError());
    }
}

void MainWindow::aggiornaYdl() {
    if(QFileInfo::exists(strFile)) {
        QFile::remove(strFile);
    }
    execCmd(cmdDownYdl);
}

void MainWindow::on_btnDownload_clicked() {
    QString url = ui->txtUrl->text();

    if(url.isEmpty() || url.isNull()) {
        QMessageBox msgBox;
        msgBox.setText("Inserire un URL valido");
        msgBox.exec();
    } else {
        QString savePath = QFileDialog::getExistingDirectory(this, tr("Scegli cartella"), QDir::homePath(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
        QString ydl = "";
#ifdef __linux__
        QFile::setPermissions(strFile,
                              QFile::ReadUser | QFile::WriteUser | QFile::ExeUser |
                              QFile::ReadGroup | QFile::WriteGroup | QFile::ExeGroup |
                              QFile::ReadOther | QFile::WriteOther | QFile::ExeOther |
                              QFile::ReadOwner | QFile::WriteOwner | QFile::ExeOwner
                              );
        ydl = "./ydl -x --audio-format mp3 -o \"" + savePath + "/%(title)s.%(ext)s\" " + url;
#else
        ydl = "ydl.exe -x --audio-format mp3 -o \"" + savePath + "/%(title)s.%(ext)s\" " + url;
#endif

        execCmd(ydl);
    }
}

void MainWindow::onActionAbout() {
    MessageDialog *ms = new MessageDialog("About",
                                          qApp->applicationName() +
                                          "<br><br>"
                                          "Web site: https://www.mattepuffo.com"
                                          "<br><br>"
                                          "Licenza: https://www.mattepuffo.com/blog/copyright.html"
                                          "<br><br>"
                                          "Linguaggio: C++/Qt<br><br>"
                                          "Versione: " + qApp->applicationVersion() +
                                          "<br><br>"
                                          "Versione Qt: " + QT_VERSION_STR
                                          );
    ms->show();
}

MainWindow::~MainWindow() {
    delete ui;
}
