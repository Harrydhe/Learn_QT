#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QtGui>


Dialog::Dialog()
{
    layoututama = new QVBoxLayout;
    tombolsatu = new QPushButton("cat > metamorfosa.txt");
    tomboldua = new QPushButton("ls -l >metamorfosa_ls.txt");

    tomboltiga = new QPushButton("mkdir metamorfosa");
    label = new QLabel;
    tombolsatu->setFixedSize(188,55);
    tomboldua->setFixedSize(188,55);
    tomboltiga->setFixedSize(188,55);

    layoututama->addWidget(tombolsatu);layoututama->addWidget(tomboldua);
    layoututama->addWidget(tomboltiga);
    layoututama->addWidget(label);

    setLayout(layoututama);
    connect(tombolsatu, SIGNAL(clicked()), this,SLOT(echo_metamorfosa()));
    connect(tomboldua, SIGNAL(clicked()), this,SLOT(ls_metamorfosa()));
    connect(tomboltiga, SIGNAL(clicked()), this,SLOT(mkdir_metamorfosa()));
}

void Dialog::echo_metamorfosa()
{
system("echo 'metamorfosa' > metamorfosa.txt");
}
void Dialog::ls_metamorfosa()
{
system("ls -l > metamorfosa_ls.txt");
}
void Dialog::mkdir_metamorfosa()
{
system("mkdir metamorfosa");
}
