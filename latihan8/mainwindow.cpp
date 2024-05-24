#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QtGui>
#include <QApplication>
#include <QLayout>
#include <QPushButton>


Dialog :: Dialog()
{
    QVBoxLayout *layoututama = new QVBoxLayout;
    QPushButton *tombolsatu = new QPushButton("SATU");
    QPushButton *tomboldua = new QPushButton("DUA");
    QPushButton *tomboltiga = new QPushButton("TIGA");
    QPushButton *tombolempat = new QPushButton("EMPAT");

    tombolsatu->setFixedSize(55,55);
    tomboldua->setFixedSize(55,55);
    tomboltiga->setFixedSize(55,55);
    tombolempat->setFixedSize(55,55);

    layoututama->addWidget(tombolsatu);
    layoututama->addWidget(tomboldua);
    layoututama->addWidget(tomboltiga);
    layoututama->addWidget(tombolempat);

    setLayout(layoututama);
}
