#include <QLayout>
#include <QtGui>
#include "mainwindow.h"
#include <QLayout>
#include <QStackedLayout>
#include <QFrame>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QVBoxLayout>

Dialog::Dialog()
{
    layoututama = new QVBoxLayout;
    layouta = new QVBoxLayout;
    layoutb = new QVBoxLayout;
    framea = new QFrame;
    frameb = new QFrame;
    stackia = new QStackedLayout;
    labela = new QLabel("FRAME 1");
    labelb = new QLabel("FRAME 2");

    tombola = new QPushButton("1");
    tombola->setFixedSize(100,100);
    tombolb = new QPushButton("2");
    tombolb->setFixedSize(150,150);
    tombolpengatur = new QPushButton("SATU");
    tombolpengatur->setFixedSize(88,33);
    tombolpengutar = new QPushButton("DUA");
    tombolpengutar->setFixedSize(88,33);

    layouta->addWidget(labela);
    layouta->addWidget(tombola);
    framea->setLayout(layouta);
        framea->setFrameShape(QFrame::StyledPanel);
        framea->setFrameShadow(QFrame::Raised);

    layoutb->addWidget(labelb);
    layoutb->addWidget(tombolb);
        frameb->setLayout(layoutb);
        frameb->setFrameShape(QFrame::StyledPanel); //shape =

        frameb->setFrameShadow(QFrame::Raised); //shadow =
        stackia->addWidget(framea);
        stackia->addWidget(frameb);

    layoututama->addLayout(stackia); //bukan addWidget tetapi
        layoututama->addWidget(tombolpengatur);
        layoututama->addWidget(tombolpengutar);

        setLayout (layoututama);


        connect(tombolpengatur, SIGNAL(clicked()), this,SLOT(stacksatu()));
        connect(tombolpengutar, SIGNAL(clicked()), this, SLOT(stackdua()));


}
void Dialog::stacksatu()
{
    stackia->setCurrentIndex(0);
}
void Dialog::stackdua()
{
    stackia->setCurrentIndex(1);
}
