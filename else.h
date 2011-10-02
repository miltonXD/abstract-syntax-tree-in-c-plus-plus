#ifndef ELSE_H
#define ELSE_H
#include"exp.h"
class Else : public Instruccion
{
public:Exp ExpSwitch;

public:
    Else();
public:bool CargarTS();

public:bool Ejecutar();

public:bool Traduccion();
};


#endif // ELSE_H
