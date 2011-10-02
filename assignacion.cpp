#include "assignacion.h"

Assignacion::Assignacion()
{
}


bool Assignacion::CargarTS()
{
    bool res=true;

    this->Var->tabla=tabla;
    this->Var->Clase=Clase;
    this->Var->SimboloMetodo=SimboloMetodo;

    res=this->Var->CargarTS();

    if(res)
    {
        this->Expre->tabla=tabla;
        this->Expre->Clase=Clase;
        this->Expre->SimboloMetodo=SimboloMetodo;

        res=this->Expre->CargarTS();
    }

    /*if(this->Var->Tipo.compare(this->Expre->Tipo))
    {
        res=true;
    }
    else
    {
        //Error el Tipo de Var y Expre  no conincide
        //res=false;
    }*/
    return res;
}
