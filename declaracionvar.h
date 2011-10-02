#ifndef DECLARACIONVAR_H
#define DECLARACIONVAR_H
#include"exp.h"
class DeclaracionVar : public Instruccion
{
public: QString Nombre;
public:QString Tipo;
public :Exp *Inicializar;

public: QList<long int> Dimenciones;

public:bool Atributo;
public:QString Acceso;

public: DeclaracionVar *SubDeclaracion;

public:
    DeclaracionVar();
public:bool CargarTS();

public:bool Ejecutar();

public:bool Traduccion();
};

#endif // DECLARACIONVAR_H
