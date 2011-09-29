#include "expu.h"

ExpU::ExpU()
{
}

bool ExpU::CargarTS()
{
    bool res=true;

    this->Op->tabla=tabla;
    this->Op->Clase=Clase;
    this->Op->SimboloMetodo=SimboloMetodo;

    res=this->Op->CargarTS();

    if(res)
    {
        //Verifiar el tipo del operador y el operando

    }
    return res;
}
