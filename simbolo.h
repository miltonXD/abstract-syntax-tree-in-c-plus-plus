#ifndef SIMBOLO_H
#define SIMBOLO_H

#include<QList>
#include<QString>
class Instruccion;
class Simbolo
{

public: QString Nombre;
public: QString Tipo;
public: QString TipoDato;

public:bool Objeto;
public:bool Primitivo;

public: QList<QString> TipoParametro;  //Metodo
public:QList<Simbolo*> Parametros; //Metodo

public:QList<long int> Dimenciones; //Arreglo
public: bool Privado;              //Accesos
public:bool Protegido;
public:bool Publico;

public:Instruccion *CMetodo;

public:bool Metodo;                 //Tipo de Simbolo
public:bool Clase;
public:bool Atributo;

public:bool Variable;
public:bool Parametro;

public: QString LabelFin;              //Etiueta del fin del metodo para traduccion a 3 direcciones


public:bool Temporal;
public:bool Etiqueta;

public:Simbolo *simboloPadre;        //A que simolo Pertenece


public: long int Size;              //Tamaño
public:long int PosRel;             //Posicion del Simbolo ya sea en stack o el el heap
public:long int PosAbs;


public:
    Simbolo();


     long int CalcSize();



};

#endif // SIMBOLO_H
