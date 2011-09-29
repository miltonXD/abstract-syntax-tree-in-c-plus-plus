#include "elseif.h"

ElseIF::ElseIF()
{
}

bool ElseIF::CargarTS()
{
    bool res=true;
    int i;
    TablaDeSimbolos *nTabla=new TablaDeSimbolos();
    nTabla->tablaArriba=tabla;
    tabla=nTabla;

    this->Condicion->tabla=tabla;
    this->Condicion->Clase=Clase;
    this->Condicion->SimboloMetodo=SimboloMetodo;

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
                    this->SInstruccion.takeAt(i)->Clase=Clase;
                    this->SInstruccion.takeAt(i)->SimboloMetodo=SimboloMetodo;

                    res=this->SInstruccion.takeAt(i)->CargarTS();
                }

           }
       }

    }
    return res;
}
