#ifndef EXP_H
#define EXP_H

#include<instruccion.h>
class Exp : public Instruccion
{
public:QString Tipo;
public:QString Valor;
public:QString Direccion;

public:QString TempValor;
public:QString TempDireccion;

public:bool Heap;
public:bool Stack;



public:
    Exp();

public:bool CargarTS();

public:bool Ejecutar();

public:bool Traduccion();
};

#endif // EXP_H
