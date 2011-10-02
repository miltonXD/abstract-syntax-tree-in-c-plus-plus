#ifndef ELSEIF_H
#define ELSEIF_H
#include"expbinaria.h"
class ElseIF : public Instruccion
{
public: Exp *Condicion;

public: Exp *ExpSwitch;

public: bool SW;

public: Exp *NC;

public:
    ElseIF();
public:bool CargarTS();

public:bool Ejecutar();

public:bool Traduccion();
};

#endif // ELSEIF_H
