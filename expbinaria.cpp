#include "expbinaria.h"

ExpBinaria::ExpBinaria()
{
}

bool ExpBinaria::CargarTS()
{
    bool res=true;

    this->Iz->tabla=tabla;
    this->Iz->Clase=Clase;
    this->Iz->SimboloMetodo=SimboloMetodo;

    res=this->Iz->CargarTS();

    if(res)
    {
        this->De->tabla=tabla;
        this->De->Clase=Clase;
        this->De->SimboloMetodo=SimboloMetodo;

        res=this->De->CargarTS();
    }

    //Verificar la operacion y los tipos de los operandos...

    return res;
}
