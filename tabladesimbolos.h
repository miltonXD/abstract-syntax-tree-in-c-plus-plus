#ifndef TABLADESIMBOLOS_H
#define TABLADESIMBOLOS_H

#include<QHash>
#include<QLinkedList>
#include<QBool>
#include<simbolo.h>

class TablaDeSimbolos
{
public: QHash <QString,Simbolo*> Tabla;
public: TablaDeSimbolos *tablaArriba;

static const TablaDeSimbolos *tablaTemporales;


public:
    TablaDeSimbolos();

public: bool InsertarVariable(QString nombre,QString tipo,Simbolo *padre,QList<int>Dim);
public: bool BuscarVariable(QString nombre,Simbolo *padre);
public:Simbolo* GetVariable(QString nombre,Simbolo *padre);

public:bool InsertarAtributo(QString nombre,QString tipo,Simbolo *padre,QList<int>Dim,QString Acceso);
public:bool BuscarAtributo(QString nombre,Simbolo *padre);
public:Simbolo* GetAtributo(QString nombre,Simbolo *padre);

public:bool InsertarMeotodo(QString nombre,QString tipo,Simbolo *padre,QList<QString> parametros);
public:bool BuscarMetodo(QString nombre,QString tiposParametros,Simbolo *padre);
public:Simbolo* GetMetodo(QString nombre,QString tiposParametros,Simbolo *padre);

public:bool InsertarClase(QString nombre,QString clasePadre);
public:bool BuscarClase(QString nombre);
public:Simbolo* GetClase(QString nombre);


};

#endif // TABLADESIMBOLOS_H
