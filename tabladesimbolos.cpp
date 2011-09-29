#include "tabladesimbolos.h"

TablaDeSimbolos::TablaDeSimbolos()
{
}
// InsertarMetodo, BuscarMetodo GetMetodo
bool TablaDeSimbolos::InsertarMeotodo(QString nombre,QString tipo,Simbolo *padre,QList <QString> parametros)
{
    bool res=true;
    QString nombre2="";
    QString nombre1=nombre;
    Simbolo *sn1=new Simbolo();
    Simbolo *sn2=null;
    int i;
    if(parametros!=null)
    {
    for(i=0;i<parametros.size();i++)
    {
        nombre2=nombre2+"_"+parametros.takeAt(i);
    }
    }
    nombre1="M_"+nombre1+"_"+nombre2;

    sn1->Nombre=nombre1;
    sn1->Metodo=true;
    sn1->Parametros=new QList(Simbolo*);
    //sn1->Parametros=parametros;   por lo del Huevo o la Gallina es primero insertar el simbolo del metodo y luego los parametros que ta tiene que tener simbolo de metodo
    sn1->Tipo=tipo;
    sn1->Size=0;
    sn1->PosRel=0;
    sn1->PosAbs=0;
    sn1->simboloPadre=padre;

    if(!BuscarMetodo(nombre,nombre2,padre))
    {
        Tabla.insert(nombre1,sn1);
        res=true;
    }
    else
    {
        res=false;
        sn2=GetMetodo(nombre,nombre2,padre);
        //Error: el metodo con con Nombre1 y parametros nombre2 ya esta decalrado
    }
return res;
}

bool TablaDeSimbolos::BuscarMetodo(QString nombre,QString tiposParametros,Simbolo *padre)
{
    bool res=true;
    QString nombre1="M_"+nombre+"_"+tiposParametros;
    Simbolo *sn1;
    sn1=Tabla.take(nombre1);
    if(sn1!=null)
    {
        if(sn1->Nombre.compare(nombre)==0&&padre->Nombre.compare(sn1->simboloPadre->Nombre)&&sn1->Metodo)
        {
            res=true;
        }
        else
        {
            res=false;
            sn1=null;
        }

    }
    if(!res&&tablaArriba!=null)
    {
        res=tablaArriba->BuscarMetodo(nombre,tiposParametros,padre);
    }
    return res;
}

Simbolo* TablaDeSimbolos::GetMetodo(QString nombre,QString tiposParametros,Simbolo *padre)
{
    bool res=true;
    QString nombre1="M_"+nombre+tiposParametros;
    Simbolo *sn1=null;
    sn1=Tabla.take(nombre1);

    if(sn1!=null)
    {
        if(sn1->Nombre.compare(nombre)==0&&padre->Nombre.compare(sn1->simboloPadre->Nombre)==0&&sn1->Metodo)
        {
            res=true;}
        else
        {
            sn1=null;
            res=false;
        }
    }
    if(!res&&tablaArriba!=null)
    {
        sn1=tablaArriba->BuscarMetodo(nombre,tiposParametros,padre);
    }
    return sn1;
}


//InsertarAtributo BuscarAtributo GetAtributo

bool TablaDeSimbolos::InsertarAtributo(QString nombre,QString tipo,Simbolo *padre,QList<int>Dim,QString Acceso)
{
    bool res=true;
    QString nombre1=nombre;
    Simbolo *sn1=new Simbolo();
    Simbolo *sn2=null;
    Simbolo *sn2=null;
    int SizeM=1;
    sn1->Nombre=nombre;
    sn1->Tipo=tipo;
    sn1->Dimenciones=Dim;
    sn1->Atributo=true;
    if(Acceso.compare("")==0){sn1->Privado=true;}
    if(Acceso.compare("public")==0){sn1->Publico=true;}
    if(Acceso.compare("protected")==0){sn1->Protegido=true;}
    if(Acceso.compare("private")==0){sn1->Privado=true;}
    if(Dim!=null)
    {
        for(i=0;i<Dim.size();i++)
        {
            SizeM=SizeM*Dim.takeAt(i);
        }
    }
    if(!BuscarAtributo(nombre,padre))
    {
        if(tipo.compare("int")==0||tipo.compare("float")==0||tipo.compare("boolean")==0||tipo.compare("char")==0)
        {
            if(tipo.compare("int")==0){sn1->Size=4;}
            if(tipo.compare("float")==0){sn1->Size=8;}
            if(tipo.compare("boolean")==0){sn1->Size=1;}
            if(tipo.compare("char")==0){sn1->Size=1;}
            res=true;
        }
        else
        {
            if(BuscarClase(tipo))
            {
                sn1->Size=4;   //por que es un objeto
                res=true;
            }
            else{res=false;}//no existe el tipo;
        }
        if(res)
        {
            padre->PosRel=padre->Size;
            padre->Size=padre->Size+sn1->Size*SizeM;

            sn1->Size=sn1->Size*SizeM;
            sn1->PosRel=padre->PosRel;
            Tabla.insert(nombre1,sn1);
            res=true;
        }

    }

    else
    {
        sn2=GetAtributo(nombre,padre);
        //Error el atributo con nombre ya fue declarado antes sn2->tipo
    }

    return res;
}


bool TablaDeSimbolos::BuscarAtributo(QString nombre,Simbolo *padre)
{
    bool res=true;
    QString nombre1=nombre;
    Simbolo *sn1=null;
    sn1=Tabla.take(noombre1);
    if(sn1!=null)
    {
        if(sn1->Atributo&&padre->Nombre.compare(sn1->simboloPadre->Nombre)==0)
        {
            res=true;

        }
        else
        {
            res=false;
        }
    }
    if(!res&&tablaArriba!=null)
    {
        res=tablaArriba->BuscarAtributo(nombre,padre);
    }   //Falta Buscar en la Clase Padre si es que existe

    return res;
}

Simbolo* TablaDeSimbolos::GetAtributo(QString nombre,Simbolo *padre)
{
    Simbolo *sn1=null;
    bool res=true;
    QString nombre1=nombre;
    sn1=Tabla.take(nombre1);
    if(sn1!=null)
    {
        if(sn1->Atributo&&padre->Nombre.compare(sn1->simboloPadre->Nombre)==0)
        {
            res=true;
        }
        else
        {
            res=false;
            ns1=null;
        }
    }
    if(sn1==null&&tablaArriba!=null)
    {
        sn1=tablaArriba->GetAtributo(nombre,padre);
    }
      //Falta Buscar en la Clase Padre si es que existe

    return sn1;
}

// InsertaVariable Inserta una Simbolo tipo variable; BuscarVariable  Busca un simbolo tipoo Variable; GetVariable devuelve un simbolo tipo Variable
bool TablaDeSimbolos::InsertarVariable(QString nombre,QString tipo,Simbolo *padre,QList<int>Dim)
{
    bool res=true;
    Simbolo *sn1=new Simbolo();
    Simbolo *sv=null;
    Simbolo *sa=null;
    QString nombre1=nombre;
    int SizeM=1;
    int i;
    sn1->Variable=true;
    sn1->Nombre=nombre;
    sn1->Tipo=tipo;
    sn1->simboloPadre=padre;
    sn1->Dimenciones=Dim;
    if(!BuscarVariable(nombre1,padre))
    {
        if(Dim!=null)
        {
            for(i=0;i<Dim.size();i++)
            {
                SizeM=SizeM*Dim.takeAt(i);
            }
        }
        //El tamaño de los tipos de datos estan en esta en Bytes
        if(tipo.compare("int")==0||tipo.compare("float")==0||tipo.compare("boolean")==0||tipo.compare("char")==0)
        {
        if(tipo.compare("int")==0){sn1->Size=4;}
        if(tipo.compare("float")==0){sn1->Size=8;}
        if(tipo.compare("boolean")==0){sn1->Size=1;}
        if(tipo.compare("char")==0){sn1->Size=1;}
        res=true;
        }
        else
        {
                if(BuscarClase(tipo))
                {
                    sa=GetClase(tipo);
                    sn1->Size=4; //por que es un apuntador
                    res=true;
                }
                else
                {
                    res=false; //no se encuetra el tipo de Dato tipo
                }
         }

        if(res){
        padre->PosRel=padre->Size;
        padre->Size=padre->Size+sn1->Size*SizeM;
        sn1->Size=sn1->Size*SizeM;

        sn1->PosRel=padre->PosRel;
        Tabla.insert(nombre1,ns1);
        }
            //Sumarle el tamaño al size
    }
    else
    {
        sv=GetVariable(nombre,*padre);
        //Error la Variable nombre ya esta declarada como sv->Tipo
    }
    return res;
}

bool TablaDeSimbolos::BuscarVariable(QString nombre,Simbolo *padre)
{
    bool res=true;
    QString nombre1=nombre;
    Simbolo *s1=null;
    s1=Tabla.take(nombre1);
    if(s1!=null){
    if(s1->Variable&&padre->Nombre.compare(s1->simboloPadre->Nombre)==0){res=true;}
    else{res=false;}
    }

    if(!res&&tablaArriba!=null)
    {
        res=tablaArriba->BuscarVariable(nombre1);
    }
    return res;
}

Simbolo* TablaDeSimbolos::GetVariable(QString nombre,Simbolo *padre)
{
    Simbolo *s1=null;
    bool res=true;
    QString nombre1=nombre;
    s1=Tabla.take(nombre1);
    if(s1!=null)
    {
    if(s1->Variable&&padre->Nombre.compare(s1->simboloPadre->Nombre)==0)
    {
        res=true;
    }
    else
    {
        s1=null;
        res=false;
    }
    }
    if(res=false&&tablaArriba!=null)
    {
        s1=tablaArriba->BuscarVariable(nombre,padre);
    }

    return s1;
}


////////////////////////

// InsertarClase: Inserta un simbolo tipo clase  , BuscarClase: Busca un Simbolo tipo clase  , GetClase: devuelve el simbolo clase

bool TablaDeSimbolos::BuscarClase(QString nombre)
{
    bool res=true;
    QString nombre1="C_"+nombre;
    Simbolo s1=null;
    s1=Tabla.take(nombre);
    if(s1!=null)
    {
    if(s1.Clase)
    {res=true;}
    else{res=false;}
    }
    //res=Tabla.contains(nombre1);
    if(!res&&tablaArriba!=null)
    {
        res=tablaArriba->BuscarClase(nombre);
    }
    return res;
}

Simbolo* TablaDeSimbolos::GetClase(QString nombre)
{
    Simbolo *ns=null;
    QString nombre1="C_"+nombre;

    ns=this->Tabla.take(nombre1);
    if(ns!=null)
    {
    if(!ns->Clase)
    {ns=null;}
    }

    if(ns==null&&this->tablaArriba!=null)
    {
        ns=tablaArriba->GetClase(nombre);
    }
    return ns;

}



bool TablaDeSimbolos::InsertarClase(QString nombre,QString clasePadre)
{
    bool res=true;
    Simbolo *cp=null;
    Simbolo *In=new Simbolo();
    QString nClave;
    if(BuscarClase(clasePadre))
    {
        cp=GetClase(clasePadre);
        In->Size=cp->Size;
        In->PosRel=cp->PosRel;
        In->PosAbs=cp->PosAbs;
        In->Clase=true;

        In->simboloPadre=cp;
    }
    else
    {
        In->Size=0;
        In->PosRel=0;
        In->PosAbs=0;
    }

    In->Nombre=nombre;
    In->Clase=true;

    if(!this->BuscarClase(nombre))
    {
        res=true;
        nClave="C_"+nombre;
        Tabla.insert(nClave,In);
    }
    else
    {
        res=false;
        //Error ya existe la clase  .....
    }
    return res;
}


