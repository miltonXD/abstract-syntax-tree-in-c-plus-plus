#ifndef RETURN_H
#define RETURN_H
#include"exp.h"
class Return : public Instruccion
{
public: Exp *exprecion;

public:
    Return();
public:bool CargarTS();

public:bool Ejecutar();

public:bool Traduccion();
};

#endif // RETURN_H
