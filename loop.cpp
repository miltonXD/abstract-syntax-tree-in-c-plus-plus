#include "loop.h"

Loop::Loop()
{
}


bool Loop::CargarTS()
{
    bool res=true;
    int i;
    if(this->For)
    {
        if(this->InicioF!=null)
        {
            this->InicioF->tabla=tabla;
            this->InicioF->Clase=Clase;
            this->InicioF->SimboloMetodo=this->SimboloMetodo;

            res=this->InicioF->CargarTS();
        }
        if(this->IncrementoF!=null)
        {
            this->IncrementoF->tabla=tabla;
            this->IncrementoF->Clase=Clase;
            this->IncrementoF->SimboloMetodo=this->SimboloMetodo;

            res=this->IncrementoF->CargarTS();
        }
    }

    if(res)
    {
      this->Condicion->tabla=tabla;
      this->Condicion->Clase=Clase;
      this->Condicion->SimboloMetodo=this->SimboloMetodo;

      res=this->Condicion->CargarTS();

      //Revisar si la condicion es tipo bool o int
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
                     this->SInstruccion.takeAt(i)->SimboloMetodo=this->SimboloMetodo;

                     res=this->SInstruccion.takeAt(i)->CargarTS();
                 }
              }
         }
      }

    }
    return res;
}
