#include "if.h"

IF::IF()
{
}

bool IF::CargarTS()
{
    bool res=true;
    int i;

    TablaDeSimbolos *nTabla=TablaDeSimbolos();  //Crear un nuevo ambito para el If (crea una nueva tabla)
    nTabla->tablaArriba=tabla;
    tabla=nTabla;

    this->Condicion->SimboloMetodo=SimboloMetodo;
    this->Condicion->tabla=tabla;
    this->Clase=Clase;

    res=this->Condicion->CargarTS();
    if(res)
    {
        if(this->SInstruccion!=null)
        {
            for(i=0;i<this->SInstruccion.size()&&res;i++)
            {
                if(this->SInstruccion.takeAt(i)!=null)
                {
                    this->SInstruccion.takeAt(i)->tabla=tabla;
                    this->SInstruccion.takeAt(i)->SimboloMetodo=SimboloMetodo;
                    this->SInstruccion.takeAt(i)->Clase=Clase;

                    res=this->SInstruccion.takeAt(i)->CargarTS();
                }
            }
        }
    }

    return res;
}
