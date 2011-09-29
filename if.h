#ifndef IF_H
#define IF_H
#include<exp.h>
#include<elseif.h>
#include<else.h>
class IF : public Instruccion
{
public: Exp *Condicion;

public:bool Switch;                //Exculsivo para traduccir switch
public:Exp *ExpSwitch;

public:QList <ElseIF> elseif;

public: Else else1;


public:
    IF();

public:bool CargarTS();

public:bool Ejecutar();

public:bool Traduccion();
};

#endif // IF_H
