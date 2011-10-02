#include "clase.h"

Clase::Clase(int l,int c,QString nombre,QString nombrePadre,QList<DeclaracionVar*> a,QList<DeclaracionMetodo*> m)
{
Linea=l;
Columna=c;
Nombre=nombre;
ClasePadre=nombrePadre;
Atributos=a;
Metodos=m;

}


bool Clase::CargarTS()
{
    int i;
    bool res=true;
    Simbolo *cl;
    res=tabla->InsertarClase(Nombre,ClasePadre);
    if(res)
    {
        cl=tabla->GetClase(Nombre);
    for(i=0;i<Atributos.size()&&res;i++)
    {
        Atributos.takeAt(i)->Clase=cl;
        Atributos.takeAt(i)->tabla=tabla;
        res=Atributos.takeAt(i)->CargarTS();

    }
    for(i=0;i<Metodos.size()&&res;i++)
    {
        Metodos.takeAt(i)->Clase=cl;
        Metodos.takeAt(i)->tabla=tabla;
        res=Metodos.takeAt(i)->CargarTS();
    }
    }
    return res;
}
