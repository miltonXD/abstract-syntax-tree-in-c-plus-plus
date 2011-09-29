#include "return.h"

Return::Return()
{
}

bool Return::CargarTS()
{
    bool res=true;
    if(this->exprecion!=null)
    {
        this->exprecion->tabla=tabla;
        this->exprecion->Clase=Clase;
        this->exprecion->SimboloMetodo=SimboloMetodo;

        res=this->exprecion->CargarTS();

        //Revisar si el tipo de  la exprecion  coincide con el tipo del metodo
    }
    return res;
}
