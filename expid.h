#ifndef EXPID_H
#define EXPID_H
#include<exp.h>
class ExpID:public Exp
{
public:QString Nombre;

public: QList<Exp*> Indices;
public: QList<Exp*> Parametros;

public: ExpID *subExpID;




public:
    ExpID();
public:bool CargarTS();

public:bool Ejecutar();

public:bool Traduccion();
};

#endif // EXPID_H
