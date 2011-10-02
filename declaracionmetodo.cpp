#include "declaracionmetodo.h"

DeclaracionMetodo::DeclaracionMetodo()
{
}

bool DeclaracionMetodo::CargarTS()
{

    bool res=true;
    Simbolo *Sm;
    TablaDeSimbolos *nTabla=NULL;
    int i;
    QList<QString> tiposParametros;
    QString tiposParametrosC="";
    if(!this->Parametros.isEmpty())
    {

        for(i=0;i<this->Parametros.size();i++)
        {
            tiposParametros.append(this->Parametros.takeAt(i)->Tipo);
            tiposParametrosC=tiposParametrosC+"_"+this->Parametros.takeAt(i)->Tipo;
        }

    }
    res=tabla->InsertarMeotodo(this->Nombre,this->Tipo,this->Clase,tiposParametros);
    if(res&&tabla->BuscarMetodo(this->Nombre,tiposParametrosC,this->Clase))
    {
        Sm=tabla->GetMetodo(this->Nombre,tiposParametrosC,this->Clase);
        //Sm->CMetodo=this;

        //Sm->LabelFin=TablaDeSimbolos::GenerarEtiqueta();//Genera una Etiqueta para el fin de un metodo

        nTabla=new TablaDeSimbolos(); //Crear un nuevo ambito (nueva tabla para el metodo) ;)
        nTabla->tablaArriba=tabla;
        tabla=nTabla;

        if(!this->Parametros.isEmpty())
        {
        for(i=0;i<this->Parametros.size()&&res;i++)
        {
            if(this->Parametros.takeAt(i)!=NULL)
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
            if(!this->SInstruccion.isEmpty())
            {
                for(i=0;i<this->SInstruccion.size()&&res;i++)
                {
                    if(this->SInstruccion.takeAt(i)!=NULL)
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
