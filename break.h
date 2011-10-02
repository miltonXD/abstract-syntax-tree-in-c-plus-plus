#ifndef BREAK_H
#define BREAK_H

#include"instruccion.h"
class Break : public Instruccion
{

public:
    Break();
public:bool CargarTS();

public:bool Ejecutar();

public:bool Traduccion();
};

#endif // BREAK_H
