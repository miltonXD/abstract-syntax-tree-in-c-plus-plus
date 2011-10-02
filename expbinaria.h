#ifndef EXPBINARIA_H
#define EXPBINARIA_H
#include "exp.h"
class ExpBinaria : public Exp
{
public:
    ExpBinaria();

public:Exp *Iz;
public:Exp *De;
public:QString Operador;

public:bool CargarTS();

public:bool Ejecutar();

public:bool Traduccion();
};

#endif // EXPBINARIA_H
