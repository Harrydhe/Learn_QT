#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QDialog>
#include <QLayout>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog();
    QVBoxLayout *layout;
    QPushButton *tombola;
    QPushButton *tombolb;
    QPushButton *tombolc;

public slots:
    void perintah_cat();
    void perintah_mkdir();
    void perintah_ls();

private:

};

#endif // MAINWINDOW_H
