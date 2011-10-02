#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "instruccion.h"
#include "tabladesimbolos.h"
int TablaDeSimbolos::Etiquetas=0;
int TablaDeSimbolos::Temporales=0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
