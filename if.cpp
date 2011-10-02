#include "if.h"

IF::IF()
{
}

bool IF::CargarTS()
{
    bool res=true;
    int i;

    if(!this->SW)
    {
    TablaDeSimbolos *nTabla=new TablaDeSimbolos();  //Crear un nuevo ambito para el If (crea una nueva tabla)
    nTabla->tablaArriba=tabla;
    tabla=nTabla;

    this->Condicion->SimboloMetodo=SimboloMetodo;
    this->Condicion->tabla=tabla;
    this->Clase=Clase;

    res=this->Condicion->CargarTS();
    if(res)
    {
        if(!this->SInstruccion.isEmpty())
        {
            for(i=0;i<this->SInstruccion.size()&&res;i++)
            {
                if(this->SInstruccion.takeAt(i)!=NULL)
                {
                    this->SInstruccion.takeAt(i)->tabla=tabla;
                    this->SInstruccion.takeAt(i)->SimboloMetodo=SimboloMetodo;
                    this->SInstruccion.takeAt(i)->Clase=Clase;

                    res=this->SInstruccion.takeAt(i)->CargarTS();
                }
            }
        }
    }
    if(res)
    {
        if(!this->elseif.isEmpty())
        {
            for(i=0;i<this->elseif.size()&&res;i++)
            {
                if(this->elseif.takeAt(i)!=NULL)
                {
                    this->elseif.takeAt(i)->tabla=tabla;
                    this->elseif.takeAt(i)->SimboloMetodo=this->SimboloMetodo;
                    this->elseif.takeAt(i)->Clase=Clase;

                    res=this->elseif.takeAt(i)->CargarTS();
                }

            }
        }

    }
    if(res&&this->else1!=NULL)
    {
             this->else1->tabla=tabla;
             this->else1->SimboloMetodo=SimboloMetodo;
             this->else1->Clase=Clase;
             res=this->else1->CargarTS();
    }
    }
    else
    {
            if(!this->elseif.isEmpty())
            {
                for(i=0;this->elseif.size()&&res;i++)
                {
                    if(this->elseif.takeAt(i)!=NULL)
                    {
                        this->elseif.takeAt(i)->ExpSwitch=ExpSwitch;
                        this->elseif.takeAt(i)->tabla=tabla;
                        this->elseif.takeAt(i)->SimboloMetodo=this->SimboloMetodo;
                        this->elseif.takeAt(i)->Clase=Clase;

                        res=this->elseif.takeAt(i)->CargarTS();
                    }
                }

            }
            if(res&&this->else1!=NULL)
            {
                this->else1->tabla=tabla;
                this->else1->SimboloMetodo=SimboloMetodo;
                this->else1->Clase=Clase;
                res=this->else1->CargarTS();
            }
    }
    return res;
}
