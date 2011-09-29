#include "expid.h"

ExpID::ExpID()
{
}

bool ExpID::CargarTS()
{
    bool res=true;
    int i;
    QList<QString> lp=new QList(QString);

    if(this->subExpID!=null)
    {
        this->subExpID->tabla=tabla;
        this->subExpID->Clase=Clase;
        this->subExpID->SimboloMetodo=SimboloMetodo;
        res=this->subExpID->CargarTS();
    }
    if(res&&this->Indices!=null)
    {

           for(i=0;i<this->Indices.size()&&res;i++)

           {    this->Indices.takeAt(i)->tabla=tabla;
                this->Indices.takeAt(i)->Clase=Clase;
                this->Indices.takeAt(i)->SimboloMetodo=SimboloMetodo;

                res=this->Indices.takeAt(i)->CargarTS();
           }
    }
    if(res&&this->Parametros!=null)
    {
            for(i=0;i<this->Indices.size()&&res;i++)
            {
                this->Parametros.takeAt(i)->tabla=tabla;
                this->Parametros.takeAt(i)->Clase=Clase;
                this->Parametros.takeAt(i)->SimboloMetodo=SimboloMetodo;

                res=this->Parametros.takeAt(i)->CargarTS();
                if(res)
                {
                    lp.append(this->Parametros.takeAt(i)->Tipo);
                }
            }
    }

    //Fatla revisar si el metodo/variable existe


    return res;
}
