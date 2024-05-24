#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMultimedia>
#include <QMediaPlaylist>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void playSound(int index);

private:
    Ui::MainWindow *ui;
    QVBoxLayout *vl;
    QPushButton *satu;
    QPushButton *dua;
    QPushButton *tiga;
    QPushButton *empat;
    QWidget *widget;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
};

#endif // MAINWINDOW_H
