#include "else.h"

Else::Else()
{
}

bool Else::CargarTS()
{
    bool res=true;
    int i;

    TablaDeSimbolos *nTabla=new TablaDeSimbolos();
    nTabla->tablaArriba=tabla;
    tabla=nTabla;

    if(!this->SInstruccion.isEmpty())
    {
        for(i=0;i<this->SInstruccion.size()&&res;i++)
        {
            if(this->SInstruccion.takeAt(i)!=NULL)
            {
                this->SInstruccion.takeAt(i)->tabla=tabla;
                this->SInstruccion.takeAt(i)->Clase=Clase;
                this->SInstruccion.takeAt(i)->SimboloMetodo=SimboloMetodo;

                res=this->SInstruccion.takeAt(i)->CargarTS();
            }
        }

    }
    return res;
}
