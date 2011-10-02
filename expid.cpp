#include "expid.h"

ExpID::ExpID()
{
}

bool ExpID::CargarTS()
{
    bool res=true;
    int i;
    QList<QString> lp;

    if(this->subExpID!=NULL)
    {
        this->subExpID->tabla=tabla;
        this->subExpID->Clase=Clase;
        this->subExpID->SimboloMetodo=SimboloMetodo;
		
        res=this->subExpID->CargarTS();
		
    }
    if(res&&!this->Indices.isEmpty())
    {

           for(i=0;i<this->Indices.size()&&res;i++)

           {    this->Indices.takeAt(i)->tabla=tabla;
                this->Indices.takeAt(i)->Clase=Clase;
                this->Indices.takeAt(i)->SimboloMetodo=SimboloMetodo;

                res=this->Indices.takeAt(i)->CargarTS();
				
				//Revisar si los indices son enteros.
				if(res&&this->Indices.takeAt(i)->Tipo.compare("int")==0)
				{
					res=true;
				}
				else
				{
					//Error los Indices de Un arreglo tiene que se entroso
					res=false;
				}				
				
           }
		   
    }
    if(res&&!this->Parametros.isEmpty())
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
