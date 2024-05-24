#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
    namespace Ui {
    class MainWindow;
    }

    class MainWindow : public QMainWindow
        {
    Q_OBJECT

        public:
                  explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QGridLayout *vl;
    QVBoxLayout *sl;
    QVBoxLayout *dl;
    QWidget *widget;
    QPushButton *pb_kambing;
    QPushButton *pb_fossid;
    QPushButton *pb_ugm;
    QPushButton *pb_buaya;
    QPushButton *pb_baca;
    QTextEdit *te_baca;
    QLabel *lb_repo;

    public slots:
        void ganti_ke_kambing();
        void ganti_ke_fossid();
        void ganti_ke_ugm();
        void ganti_ke_buaya();
        void baca_sources_list();

    private:
        Ui::MainWindow *ui;
     };

    #endif // MAINWINDOW_H
