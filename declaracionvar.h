#ifndef DECLARACIONVAR_H
#define DECLARACIONVAR_H
#include<exp.h>
class DeclaracionVar : public Instruccion
{
public: QString Nombre;
public:QString Tipo;
public :Exp *Inicializar;

public: QList<int> Dimenciones;

public:bool Atributo;
public:QString Acceso;

public: DeclaracionVar *SubDeclaracion;

public:
    DeclaracionVar(int l,int c,QString nombre,QString Tipo);
public:bool CargarTS();

public:bool Ejecutar();

public:bool Traduccion();
};

#endif // DECLARACIONVAR_H
