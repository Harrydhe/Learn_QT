#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    vl = new QGridLayout();
    sl = new QVBoxLayout();
    dl = new QVBoxLayout();
    widget = new QWidget();
    pb_kambing = new QPushButton("KAMBING");
    pb_fossid = new QPushButton("FOSS-ID");
    pb_ugm = new QPushButton("UGM");
    pb_buaya = new QPushButton("BUAYA");
    pb_baca = new QPushButton("BACA");
    te_baca = new QTextEdit;
    lb_repo = new QLabel;

    vl->addWidget(pb_kambing, 1, 1);
    vl->addWidget(pb_fossid, 1, 2);
    vl->addWidget(pb_ugm, 1, 3);
    vl->addWidget(pb_buaya, 2, 1);
    vl->addWidget(pb_baca, 2, 2);
    vl->addWidget(lb_repo, 2, 3);
    vl->setHorizontalSpacing(3);
    vl->setVerticalSpacing(3);
    dl->addWidget(te_baca);

    pb_kambing->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pb_fossid->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pb_ugm->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pb_buaya->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pb_baca->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    te_baca->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    pb_kambing->setMinimumHeight(55);
    pb_fossid->setMinimumHeight(55);
    pb_ugm->setMinimumHeight(55);
    pb_buaya->setMinimumHeight(55);
    pb_baca->setMinimumHeight(55);
    te_baca->setMinimumSize(575, 199);

    sl->addLayout(vl);
    sl->addLayout(dl);

    widget->setLayout(sl);

    this->setCentralWidget(widget);

    connect(pb_kambing, SIGNAL(clicked()), this, SLOT(ganti_ke_kambing()));
    connect(pb_fossid, SIGNAL(clicked()), this, SLOT(ganti_ke_fossid()));
    connect(pb_ugm, SIGNAL(clicked()), this, SLOT(ganti_ke_ugm()));
    connect(pb_buaya, SIGNAL(clicked()), this, SLOT(ganti_ke_buaya()));
    connect(pb_baca, SIGNAL(clicked()), this, SLOT(baca_sources_list()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ganti_ke_kambing()
{
    QStringList argumen;
    argumen << "-c" <<
        "echo 'deb http://kambing.ui.ac.id/ubuntu precise main restricted multiverse universe\n"
        "deb http://kambing.ui.ac.id/ubuntu/ precise-update mainrestricted multiverse universe\n"
        "deb http://kambing.ui.ac.id/ubuntu/ precise-security main restricted universe multiverse\n"
        "deb http://kambing.ui.ac.id/ubuntu/ precise-backports main restricted universe multiverse' > sources";

    QProcess perintah;
    perintah.start("/bin/bash", argumen);
    perintah.waitForFinished(-1);

    this->lb_repo->setText("<b>Repo Sekarang: Kambing</b>");
}

void MainWindow::ganti_ke_fossid()
{
    QStringList argumen;
    argumen << "-c" <<
        "echo 'deb http://repo.ugm.ac.id/ubuntu/ precise main restricted universe multiverse\n"
        "deb http://repo.ugm.ac.id/ubuntu/ precise-updates mainrestricted universe multiverse\n"
        "deb http://repo.ugm.ac.id/ubuntu/ precise-securitymain restricted universe multiverse' > sources";

    QProcess perintah;
    perintah.start("/bin/bash", argumen);
    perintah.waitForFinished(-1);

    this->lb_repo->setText("<b>Repo Sekarang: FOSS-ID</b>");
}

void MainWindow::ganti_ke_ugm()
{
    QStringList argumen;
    argumen << "-c" <<
        "echo 'deb http://repo.ugm.ac.id/ubuntu/ precise main restricted universe multiverse\n"
        "deb http://repo.ugm.ac.id/ubuntu/ precise-updates main restricted universe multiverse\n"
        "deb http://repo.ugm.ac.id/ubuntu/ precise-security main restricted universe multiverse' > sources";

    QProcess perintah;
    perintah.start("/bin/bash", argumen);
    perintah.waitForFinished(-1);

    this->lb_repo->setText("<b>Repo Sekarang: UGM</b>");
}

void MainWindow::ganti_ke_buaya()
{
    QStringList argumen;
    argumen << "-c" <<
        "echo 'deb http://buaya.klas.or.id/ubuntu/ precise main restricted universe multiverse\n"
        "deb http://buaya.klas.or.id/ubuntu/ precise-updates main restricted universe multiverse\n"
        "deb http://buaya.klas.or.id/ubuntu/ precise-securitymain restricted universe multiverse' > sources";

    QProcess perintah;
    perintah.start("/bin/bash", argumen);
    perintah.waitForFinished(-1);

    this->lb_repo->setText("<b>Repo Sekarang: Buaya</b>");
}

void MainWindow::baca_sources_list()
{
    //kode ini saya buat dengan menebak saja
    QString isi_sources_list;
    QProcess perintah_baca_sources;
    perintah_baca_sources.start("cat sources");
    perintah_baca_sources.waitForFinished(-1);
    isi_sources_list = perintah_baca_sources.readAllStandardOutput();

    this->te_baca->setText(isi_sources_list);
    this->te_baca->setReadOnly(true);
}
