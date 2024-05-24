#include <QApplication>
#include "mainwindow.h"
#include <QDialog>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Dialog w;
    w.show();

    return app.exec();
}
