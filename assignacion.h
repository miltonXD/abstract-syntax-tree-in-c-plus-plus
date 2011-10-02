#ifndef ASSIGNACION_H
#define ASSIGNACION_H
#include"expid.h"

class Assignacion : public Instruccion
{
public: ExpID *Var;
public: Exp *Expre;




public:
    Assignacion();
public:bool CargarTS();

public:bool Ejecutar();

public:bool Traduccion();
};

#endif // ASSIGNACION_H
