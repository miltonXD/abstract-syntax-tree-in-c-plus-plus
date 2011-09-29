#ifndef ELSEIF_H
#define ELSEIF_H
#include<exp.h>
class ElseIF : public Instruccion
{
public: Exp *Condicion;

public: Exp *ExpSwitch;



public:
    ElseIF();
public:bool CargarTS();

public:bool Ejecutar();

public:bool Traduccion();
};

#endif // ELSEIF_H
