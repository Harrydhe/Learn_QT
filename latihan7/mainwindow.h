#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QApplication>
#include <QDialog>
#include <QLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class Dialog : public QDialog
{
Q_OBJECT

public:
    Dialog();
    QVBoxLayout *layoututama;
    QPushButton *tombolsatu;
    QPushButton *tomboldua;
    QPushButton *tomboltiga;
    QLabel *label;

public slots:
    void echo_metamorfosa();
    void ls_metamorfosa();
    void mkdir_metamorfosa();

private:
};

#endif // MAINWINDOW_H
