#include <QLayout>
#include "mainwindow.h"
#include <QtGui>
#include <QComboBox>
#include <QStackedLayout>

Dialog::Dialog()
{
    QVBoxLayout *mainlayout     =   new QVBoxLayout;
    QVBoxLayout *layouta        =   new QVBoxLayout;
    QVBoxLayout *layoutb        =   new QVBoxLayout;
    QVBoxLayout *layoutd        =   new QVBoxLayout;
    QPushButton *tombola        =   new QPushButton("A");
    QPushButton *tombolb        =   new QPushButton("B");
    QPushButton *tombolc        =   new QPushButton("C");
    QPushButton *tombold        =   new QPushButton("D");
    QFrame      *framea         =   new QFrame;
    QFrame      *frameb         =   new QFrame;
    QFrame      *framed         =   new QFrame;
    QStackedLayout *stackia     =   new QStackedLayout;
    QComboBox   *combo          =   new QComboBox;

    combo->addItem(tr("A"));
    combo->addItem(tr("B"));
    combo->addItem(tr("C"));
    combo->addItem(tr("D"));

    tombold->setFixedSize(55,55);

    layouta->addWidget(tombola);
    layoutb->addWidget(tombolb);
    layoutd->addWidget(tombold);

    framea->setLayout(layouta);
    frameb->setLayout(layoutb);
    framea->setMinimumSize(88,88);
    frameb->setMinimumSize(88,88);
    framed->setLayout(layoutd);

    //membentuk frame
    framea->setFrameShape(QFrame::StyledPanel);
    framea->setFrameShadow(QFrame::Raised);
    frameb->setFrameShape(QFrame::StyledPanel);
    frameb->setFrameShadow(QFrame::Raised);
    framed->setFrameShape(QFrame::StyledPanel);
    framed->setFrameShadow(QFrame::Raised);

    //mengecilkan ukuran tombol c
    tombolc->setMaximumWidth(33);

    stackia->addWidget(framea);
    stackia->addWidget(frameb);
    stackia->addWidget(tombolc);
    stackia->addWidget(framed);

    mainlayout->addLayout(stackia);

    mainlayout->addWidget(combo);
    setLayout(mainlayout);

    connect(combo, SIGNAL(activated(int)), stackia, SLOT(setCurrentIndex(int)));
}
