#ifndef TABLADESIMBOLOS_H
#define TABLADESIMBOLOS_H

#include<QHash>
#include"simbolo.h"

class TablaDeSimbolos
{
public: QHash <QString,Simbolo*> Tabla;
public: TablaDeSimbolos *tablaArriba;

public: static  TablaDeSimbolos *tablaTemporales;

 static int Temporales;

 static int Etiquetas;

public:
    TablaDeSimbolos();

public: bool InsertarVariable(QString nombre,QString tipo,Simbolo *padre,QList<long int>Dim);
public: bool BuscarVariable(QString nombre,Simbolo *padre);
public:Simbolo* GetVariable(QString nombre,Simbolo *padre);

public:bool InsertarAtributo(QString nombre,QString tipo,Simbolo *padre,QList<long int>Dim,QString Acceso);
public:bool BuscarAtributo(QString nombre,Simbolo *padre);
public:Simbolo* GetAtributo(QString nombre,Simbolo *padre);

public:bool InsertarMeotodo(QString nombre,QString tipo,Simbolo *padre,QList<QString> parametros);
public:bool BuscarMetodo(QString nombre,QString tiposParametros,Simbolo *padre);
public:Simbolo* GetMetodo(QString nombre,QString tiposParametros,Simbolo *padre);

public:bool InsertarClase(QString nombre,QString clasePadre);
public:bool BuscarClase(QString nombre);
public:Simbolo* GetClase(QString nombre);

public:static QString GenerarTemporal(QString tipo);
public:static QString GenerarEtiqueta();

};

#endif // TABLADESIMBOLOS_H
