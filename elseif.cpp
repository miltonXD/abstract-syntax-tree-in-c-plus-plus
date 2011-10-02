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

    if(!this->SW)
    {
    this->Condicion->tabla=tabla;
    this->Condicion->Clase=Clase;
    this->Condicion->SimboloMetodo=SimboloMetodo;

    res=this->Condicion->CargarTS();
            //Falta ver si el Tipo de Condicion es Booleano
    if(res)
    {
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

    }
    }
    else
    {
     ExpBinaria *nC=new ExpBinaria();
        nC->Iz=this->ExpSwitch;
        nC->De=this->Condicion;
        nC->Operador="==";
        NC=nC;

        NC->tabla=tabla;
        NC->SimboloMetodo=this->SimboloMetodo;
        NC->Clase=Clase;
        res=NC->CargarTS();
                //Falta ver si el Tipo de NC es Booleano
        if(res)
        {
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

        }
    }
    return res;
}
