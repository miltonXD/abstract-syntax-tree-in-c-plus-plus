#ifndef LOOP_H
#define LOOP_H
#include<exp.h>
#include<assignacion.h>
class Loop : public Instruccion
{

public:Assignacion *InicioF;
public:Assignacion *IncrementoF;

public:Exp *Condicion;

public:bool For;
public:bool While;


public:
    Loop();

public:bool CargarTS();

public:bool Ejecutar();

public:bool Traduccion();
};

#endif // LOOP_H
