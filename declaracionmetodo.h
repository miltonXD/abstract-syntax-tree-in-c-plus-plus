#ifndef DECLARACIONMETODO_H
#define DECLARACIONMETODO_H
#include<QList>
#include<declaracionvar.h>
#include<instruccion.h>

class DeclaracionMetodo:public Instruccion
{
public:QString Nombre;
public:QString Tipo;
public:QString Accesso;
public:QList <DeclaracionVar*> Parametros;

public:QList<Instruccion*> CuerpoMetodo;

public:
    DeclaracionMetodo();

public:bool CargarTS();

public:bool Ejecutar();

public:bool Traduccion();
};

#endif // DECLARACIONMETODO_H
