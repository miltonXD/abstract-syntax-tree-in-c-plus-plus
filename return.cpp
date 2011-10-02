#include "return.h"

Return::Return()
{
}

bool Return::CargarTS()
{
    bool res=true;
    if(this->exprecion!=NULL)
    {
        this->exprecion->tabla=tabla;
        this->exprecion->Clase=Clase;
        this->exprecion->SimboloMetodo=SimboloMetodo;

        res=this->exprecion->CargarTS();
		
/*                if(SimboloMetodo->Tipo.comare(this->exprecion->Tipo)==0)
		{
			res=false;
			//Error el Tipo devuelto no coincide con el tipo declarado...:/
                }
*/
        //Revisar si el tipo de  la exprecion  coincide con el tipo del metodo
    }
    return res;
}
