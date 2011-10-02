#ifndef INSTRUCCION_H
#define INSTRUCCION_H

#include"tabladesimbolos.h"
//#include<QList>


class Instruccion
{
public:TablaDeSimbolos *tabla;

public:QString T3Direcciones;

public:QString Labeltrue;
public:QString LabelFalse;
public:QString LableSig;

public:QString Temporal;

public:QList<Instruccion*> SInstruccion;

public:Simbolo *SimboloMetodo;
public:Simbolo *Clase;


public:bool Return;
public:bool Break;

public:long int Linea;

public:long int Columna;


public: bool BREAK;
public: bool RETURN;

public:
    Instruccion();

public:bool CargarTS();

public:bool Ejecutar();

public:bool Traduccion();


};

#endif // INSTRUCCION_H
