#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QtGui>
#include <QVBoxLayout>
#include <QFrame>
#include <QStackedLayout>
#include <QPushButton>
#include <QLabel>

class QGroupBox;
class QpushButton;
class QStackedLayout;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog();
    QVBoxLayout * layoututama;
    QVBoxLayout *layouta;
    QVBoxLayout *layoutb;
    QFrame *framea;
    QFrame *frameb;
    QStackedLayout *stackia;
    QPushButton *tombola;
    QPushButton *tombolb;
    QPushButton *tombolpengatur;
    QPushButton *tombolpengutar;
    QLabel *labela;QLabel *labelb;

public slots:
    void stacksatu();
    void stackdua();
private:
};
#endif // MAINWINDOW_H
