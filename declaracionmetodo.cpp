#include "declaracionmetodo.h"

DeclaracionMetodo::DeclaracionMetodo()
{
}

bool DeclaracionMetodo::CargarTS()
{
    bool res=true;
    Simbolo *Sm;
    TablaDeSimbolos *nTabla=null;
    int i;
    QList<QString> tiposParametros;
    if(this->Parametros!=null)
    {

        for(i=0;i<this->Parametros.size();i++)
        {
            tiposParametros.append(this->Parametros.takeAt(i)->Tipo);
        }

    }
    res=tabla.InsertarMeotodo(this->Nombre,this->Tipo,this->Clase,tiposParametros);
    if(res)
    {
        Sm=tabla.BuscarMetodo(this->Nombre,tiposParametros,this->CargarTS());


        nTabla=new TablaDeSimbolos(); //Crear un nuevo ambito (nueva tabla para el metodo) ;)
        nTabla->tablaArriba=tabla;
        tabla=nTabla;

        if(this->Parametros!=null)
        {
        for(i=0;i<this->Parametros.size()&&res;i++)
        {
            if(this->Parametros.takeAt(i)!=null)
            {
            this->Parametros.takeAt(i)->tabla=tabla;
            this->Parametros.takeAt(i)->SimboloMetodo=Sm;
            this->Parametros.takeAt(i)->Clase=Clase;

            res=this->Parametros.takeAt(i)->CargarTS();

            }
        }
        }

        if(res)
        {
            if(this->SInstruccion!=null)
            {
                for(i=0;i<this->SInstruccion.size()&&res;i++)
                {
                    if(this->SInstruccion.takeAt(i)!=null)
                    {
                        this->SInstruccion.takeAt(i)->tabla=tabla;
                        this->SInstruccion.takeAt(i)->SimboloMetodo=Sm;
                        this->SInstruccion.takeAt(i)->Clase=Clase;

                        res=this->SInstruccion.takeAt(i)->CargarTS();
                    }
                }

            }

        }
    }
    return res;
}
