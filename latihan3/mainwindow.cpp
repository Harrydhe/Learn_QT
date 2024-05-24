#include <QLayout>
#include "mainwindow.h"
#include <QtGui>

Dialog::Dialog()
{
    QVBoxLayout *layoutKontainerKanan  = new QVBoxLayout;
    QVBoxLayout *layoutKontainerKiri   = new QVBoxLayout;
    QVBoxLayout *layoutKontainerTengah = new QVBoxLayout;
    QVBoxLayout *layoutKontainerBawah  = new QVBoxLayout;
    QVBoxLayout *layoutKontainerPojok  = new QVBoxLayout;
    QGridLayout *layoutUtama           = new QGridLayout;

    QPushButton *tombolSatu          = new QPushButton("SATU");
    QPushButton *tombolDua           = new QPushButton("DUA");
    QPushButton *tombolTiga          = new QPushButton("TIGA");
    QPushButton *tombolEmpat         = new QPushButton("");

    layoutKontainerKanan->addWidget(tombolSatu);
    layoutKontainerKanan->addWidget(tombolDua);
    layoutKontainerKanan->addWidget(tombolTiga);
    layoutKontainerKanan->addWidget(tombolEmpat);

    QSize size(88,88);                                  //menentukan ukuran, bisa dipakai di mana-mana nanti

    tombolEmpat->setMinimumSize(100,100);               //objek size lalu dimasukkan ke dalam method setIconSize dalam tombolEmpat
    tombolEmpat->setIconSize(size);                     //nggak sangka, dasar OOP; sampai ukuran ikon pun disimpan sebagai objek
    tombolEmpat->setIcon(QIcon(":/px.jpg")); //logo ubuntu.png ini jadi seukuran 88x88 betulan dalam tombol [sebelumnya gagal]

    QPushButton *tombolLima          = new QPushButton("LIMA");
    QPushButton *tombolEnam          = new QPushButton("ENAM");
    QPushButton *tombolTujuh         = new QPushButton("TUJUH");
    QPushButton *tombolDelapan       = new QPushButton("DELAPAN");

    layoutKontainerKiri->addWidget(tombolLima);
    layoutKontainerKiri->addWidget(tombolEnam);
    layoutKontainerKiri->addWidget(tombolTujuh);
    layoutKontainerKiri->addWidget(tombolDelapan);

    //TOMBOL-TOMBOL DI BARISAN BAWAH
    QPushButton *tombolSembilan      = new QPushButton("SEMBILAN");

    layoutKontainerBawah->addWidget(tombolSembilan);

    QPushButton *tombolSepuluh       = new QPushButton("SEPULUH");

    layoutKontainerPojok->addWidget(tombolSepuluh);

    //FRAME-FRAME PEMUAT TOMBOL
    QFrame *frameKanan = new QFrame;
    frameKanan->setLayout(layoutKontainerKanan);

    QFrame *frameKiri  = new QFrame;
    frameKiri->setLayout(layoutKontainerKiri);

    QFrame *frameTengah = new QFrame;
    frameTengah->setFixedWidth(66);                     //berhasil mengatur ukuran lebar frame secara galak
    //    frameTengah->setFrameShadow(QFrame::Raised);      //setFrameShadow dan setFrameStyle
    //    frameTengah->setFrameShape(QFrame::StyledPanel);  //kalau dimatikan, maka semua shadow hilang dan hanya tampak spasi kosong
    frameTengah->setLayout(layoutKontainerTengah);      //jangan lupa masukkan layout ke dalam frame

    QFrame *frameBawah = new QFrame;
    frameBawah->setLayout(layoutKontainerBawah);

    QFrame *frameSangga = new QFrame;
    frameSangga->setFixedHeight(88);

    QFrame *framePojok  = new QFrame;
    framePojok->setFixedHeight(50);
    framePojok->setLayout(layoutKontainerPojok);

    layoutUtama->addWidget(frameKanan, 1, 3);
    layoutUtama->addWidget(frameTengah, 1, 2);
    layoutUtama->addWidget(frameKiri, 1, 1);
    layoutUtama->addWidget(frameBawah, 3, 1);
    layoutUtama->addWidget(frameSangga, 2, 1);
    layoutUtama->addWidget(framePojok, 3, 3);
    layoutUtama->setColumnMinimumWidth(3, 100);     //menentukan jumlah kolom dan lebar masing-masingnya
    layoutUtama->setRowMinimumHeight(3, 10);       //menentukan jumlah baris dan tinggi masing-masingnya
    setLayout(layoutUtama);
}
