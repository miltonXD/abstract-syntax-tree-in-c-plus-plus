#ifndef CLASE_H
#define CLASE_H
//#include<QList>
//#include"declaracionvar.h"
#include"declaracionmetodo.h"
class Clase : public Instruccion
{
public:QString Nombre;
public:QString ClasePadre;

public:QList<DeclaracionVar*> Atributos;
public:QList<DeclaracionMetodo*> Metodos;

public:
    Clase(int l,int c,QString nombre,QString nombrePadre,QList<DeclaracionVar*> a,QList<DeclaracionMetodo*> m );
public: bool CargarTS();

//public:bool Ejecutar();

//public:bool Traduccion();
};

#endif // CLASE_H
