#ifndef EXPU_H
#define EXPU_H
#include<exp.h>
class ExpU : public Exp
{
public: QString Operador;
public: Exp *Op;

public:
    ExpU();

public:bool CargarTS();

public:bool Ejecutar();

public:bool Traduccion();
};

#endif // EXPU_H
