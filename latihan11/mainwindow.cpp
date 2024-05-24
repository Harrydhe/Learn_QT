#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    vl = new QVBoxLayout;
    satu = new QPushButton("SATU");
    dua = new QPushButton("DUA");
    tiga = new QPushButton("TIGA");
    empat = new QPushButton("EMPAT");
    widget = new QWidget;

    satu->setMinimumSize(88, 55);
    dua->setMinimumSize(88, 55);
    tiga->setMinimumSize(88, 55);
    empat->setMinimumSize(88, 55);

    // Buat objek player
    player = new QMediaPlayer(this);

    // Hubungkan tombol dengan pemutaran
    connect(satu, &QPushButton::clicked, [=]() { playSound("suara_1.ogg"); });
    connect(dua, &QPushButton::clicked, [=]() { playSound("suara_2.ogg"); });
    connect(tiga, &QPushButton::clicked, [=]() { playSound("suara_3.ogg"); });
    connect(empat, &QPushButton::clicked, [=]() { playSound("suara_4.ogg"); });

    vl->addWidget(satu);
    vl->addWidget(dua);
    vl->addWidget(tiga);
    vl->addWidget(empat);
    widget->setLayout(vl);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete player;
}

void MainWindow::playSound(const QString &fileName)
{
    player->setMedia(QUrl::fromLocalFile(fileName)); // Ubah sesuai path berkas Anda
    player->play();
}
