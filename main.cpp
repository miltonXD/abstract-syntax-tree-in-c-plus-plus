#include <QtGui/QApplication>
#include <instruccion.h>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Instruccion  pru;

    return a.exec();
}
