#include "declaracionvar.h"

DeclaracionVar::DeclaracionVar()
{
}

bool DeclaracionVar::CargarTS()
{
    //Simbolo *Sim=new Simbolo();
    bool res=true;

    if(this->Atributo)
    {
        if(this->SubDeclaracion!=NULL)
        {
            this->SubDeclaracion->tabla=tabla;

            this->SubDeclaracion->Tipo=Tipo;
            this->SubDeclaracion->Clase=Clase;
            this->SubDeclaracion->SimboloMetodo=SimboloMetodo;
            this->SubDeclaracion->Acceso=Acceso;
            res=SubDeclaracion->CargarTS();

        }
        if(res){
          res=tabla->InsertarAtributo(this->Nombre,this->Tipo,this->Clase,this->Dimenciones,this->Acceso);
        }

    }
    else
    {
        if(this->SubDeclaracion!=NULL)
        {
            this->SubDeclaracion->tabla=tabla;

            this->SubDeclaracion->Tipo=Tipo;
            this->SubDeclaracion->Clase=Clase;
            this->SubDeclaracion->SimboloMetodo=SimboloMetodo;
            res=SubDeclaracion->CargarTS();
        }
        if(res)
        {


          res=tabla->InsertarVariable(this->Nombre,this->Tipo,this->SimboloMetodo,this->Dimenciones);
        }

    }

    return res;
}
