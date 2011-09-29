#ifndef SIMBOLO_H
#define SIMBOLO_H
#include<QList>
#include<QString>

class Simbolo
{

public: QString Nombre;
public: QString Tipo;
public: QString TipoDato;

public:QBool Objeto;
public:QBool Primitivo;

public: QList<QString> TipoParametro;  //Metodo
public:QList<Simbolo*> Parametros; //Metodo

public:QList<long int> Dimenciones; //Arreglo

public: QBool Privado;              //Accesos
public:QBool Protegido;
public:QBool Publico;

public:bool Metodo;                 //Tipo de Simbolo
public:bool Clase;
public:bool Atributo;

public:bool Variable;
public:bool Parametro;



public:Simbolo *simboloPadre;        //A que simolo Pertenece


public: long int Size;              //Tamaño
public:long int PosRel;             //Posicion del Simbolo ya sea en stack o el el heap
public:long int PosAbs;


public:
    Simbolo();


     long int CalcSize();



};

#endif // SIMBOLO_H
