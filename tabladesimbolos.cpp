#include "tabladesimbolos.h"

TablaDeSimbolos::TablaDeSimbolos()
{
}

//Funciones Globales para Generar Temporales y Etiquetas metodos estaticos
QString  TablaDeSimbolos::GenerarEtiqueta()
{
    QString res="";
    TablaDeSimbolos::Etiquetas++;
    return res;
}

QString TablaDeSimbolos::GenerarTemporal(QString tipo)
{
    QString res="";
    TablaDeSimbolos::Temporales++;
    return res;
}


// InsertarMetodo, BuscarMetodo GetMetodo
bool TablaDeSimbolos::InsertarMeotodo(QString nombre,QString tipo,Simbolo *padre,QList <QString> parametros)
{
    bool res=true;
    QString nombre2="";
    QString nombre1=nombre;
    QString nombre3="";
    Simbolo *sn1=new Simbolo();
    Simbolo *sn2=NULL;
    int i;
    if(parametros.isEmpty())
    {
    for(i=0;i<parametros.size();i++)
    {
        nombre2=nombre2+"_"+parametros.takeAt(i);
    }
    }

    if(padre!=NULL)
    {
        nombre3=padre->Nombre+"_";
    }

    nombre1=nombre3+"M_"+nombre1+"_"+nombre2;

    QList<Simbolo*> lS;
    sn1->Nombre=nombre1;
    sn1->Metodo=true;
    sn1->Parametros=lS;
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
    QString nombre3="";
    if(padre!=NULL)
    {
        nombre3=padre->Nombre+"_";
    }

    QString nombre1=nombre3+"M_"+nombre+"_"+tiposParametros;
    Simbolo *sn1;
    sn1=Tabla.take(nombre1);
    if(sn1!=NULL)
    {
        if(sn1->Nombre.compare(nombre)==0&&padre->Nombre.compare(sn1->simboloPadre->Nombre)&&sn1->Metodo)
        {
            res=true;
        }
        else
        {
            res=false;
            sn1=NULL;
        }

    }
    if(!res&&tablaArriba!=NULL)
    {
        res=tablaArriba->BuscarMetodo(nombre,tiposParametros,padre);
    }
    return res;
}

Simbolo* TablaDeSimbolos::GetMetodo(QString nombre,QString tiposParametros,Simbolo *padre)
{
    bool res=true;

    QString nombre3="";
    if(padre!=NULL)
    {
        nombre3=padre->Nombre+"_";
    }
    QString nombre1=nombre3+"M_"+nombre+tiposParametros;

    Simbolo *sn1=NULL;
    sn1=Tabla.take(nombre1);

    if(sn1!=NULL)
    {
        if(sn1->Nombre.compare(nombre)==0&&padre->Nombre.compare(sn1->simboloPadre->Nombre)==0&&sn1->Metodo)
        {
            res=true;}
        else
        {
            sn1=NULL;
            res=false;
        }
    }
    if(!res&&tablaArriba!=NULL)
    {
        sn1=tablaArriba->GetMetodo(nombre,tiposParametros,padre);
    }
    return sn1;
}


//InsertarAtributo BuscarAtributo GetAtributo

bool TablaDeSimbolos::InsertarAtributo(QString nombre,QString tipo,Simbolo *padre,QList<long int>Dim,QString Acceso)
{
    bool res=true;
    QString nombre3="";
    int i;
    if(padre!=NULL)
    {
        nombre3=padre->Nombre+"_";
    }
    QString nombre1=nombre3+"A_"+nombre;
    Simbolo *sn1=new Simbolo();
    Simbolo *sn2=NULL;
    int SizeM=1;
    sn1->Nombre=nombre;
    sn1->Tipo=tipo;
    sn1->Dimenciones=Dim;
    sn1->Atributo=true;
    if(Acceso.compare("")==0){sn1->Privado=true;}
    if(Acceso.compare("public")==0){sn1->Publico=true;}
    if(Acceso.compare("protected")==0){sn1->Protegido=true;}
    if(Acceso.compare("private")==0){sn1->Privado=true;}
    if(!Dim.isEmpty())
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
    QString nombre3="";
    if(padre!=NULL)
    {
        nombre3=padre->Nombre+"";
    }

    QString nombre1=nombre3+nombre;
    Simbolo *sn1=NULL;
    sn1=Tabla.take(nombre1);
    if(sn1!=NULL)
    {
        if(padre!=NULL)
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
    }
    if(!res&&tablaArriba!=NULL)
    {
        res=tablaArriba->BuscarAtributo(nombre,padre);
    }   //Falta Buscar en la Clase Padre si es que existe

    return res;
}

Simbolo* TablaDeSimbolos::GetAtributo(QString nombre,Simbolo *padre)
{
    Simbolo *sn1=NULL;
    bool res=true;
    QString nombre3="";
    if(padre!=NULL)
    {
        nombre3=padre->Nombre+"_";
    }
    QString nombre1=nombre3+nombre;
    sn1=Tabla.take(nombre1);
    if(sn1!=NULL)
    {
        if(padre!=NULL)
        {
        if(sn1->Atributo&&padre->Nombre.compare(sn1->simboloPadre->Nombre)==0)
        {
            res=true;
        }
        else
        {
            res=false;
            sn1=NULL;
        }
        }
    }
    if(sn1==NULL&&tablaArriba!=NULL)
    {
        sn1=tablaArriba->GetAtributo(nombre,padre);
    }
      //Falta Buscar en la Clase Padre si es que existe

    return sn1;
}

// InsertaVariable Inserta una Simbolo tipo variable; BuscarVariable  Busca un simbolo tipoo Variable; GetVariable devuelve un simbolo tipo Variable
bool TablaDeSimbolos::InsertarVariable(QString nombre,QString tipo,Simbolo *padre,QList<long int>Dim)
{
    bool res=true;
    Simbolo *sn1=new Simbolo();
    Simbolo *sv=NULL;
    Simbolo *sa=NULL;
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
        if(!Dim.isEmpty())
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
        Tabla.insert(nombre1,sn1);
        }
            //Sumarle el tamaño al size
    }
    else
    {
        sv=GetVariable(nombre,padre);
        //Error la Variable nombre ya esta declarada como sv->Tipo
    }
    return res;
}

bool TablaDeSimbolos::BuscarVariable(QString nombre,Simbolo *padre)
{
    bool res=true;
    QString nombre1=nombre;
    Simbolo *s1=NULL;
    s1=Tabla.take(nombre1);
    if(s1!=NULL&&padre!=NULL){
    if(s1->Variable&&padre->Nombre.compare(s1->simboloPadre->Nombre)==0){res=true;}
    else{res=false;}
    }

    if(!res&&tablaArriba!=NULL)
    {
        res=tablaArriba->BuscarVariable(nombre1,padre);
    }
    return res;
}

Simbolo* TablaDeSimbolos::GetVariable(QString nombre,Simbolo *padre)
{
    Simbolo *s1=NULL;
    bool res=true;
    QString nombre1=nombre;
    s1=Tabla.take(nombre1);
    if(s1!=NULL&&padre!=NULL)
    {
    if(s1->Variable&&padre->Nombre.compare(s1->simboloPadre->Nombre)==0)
    {
        res=true;
    }
    else
    {
        s1=NULL;
        res=false;
    }
    }
    if(res==false&&tablaArriba!=NULL)
    {
        s1=tablaArriba->GetVariable(nombre,padre);
    }

    return s1;
}


////////////////////////

// InsertarClase: Inserta un simbolo tipo clase  , BuscarClase: Busca un Simbolo tipo clase  , GetClase: devuelve el simbolo clase

bool TablaDeSimbolos::BuscarClase(QString nombre)
{
    bool res=true;
    QString nombre1="C_"+nombre;
    Simbolo *s1=NULL;
    s1=Tabla.take(nombre);
    if(s1!=NULL)
    {
    if(s1->Clase)
    {res=true;}
    else{res=false;}
    }
    //res=Tabla.contains(nombre1);
    if(!res&&tablaArriba!=NULL)
    {
        res=tablaArriba->BuscarClase(nombre);
    }
    return res;
}

Simbolo* TablaDeSimbolos::GetClase(QString nombre)
{
    Simbolo *ns=NULL;
    QString nombre1="C_"+nombre;

    ns=this->Tabla.take(nombre1);
    if(ns!=NULL)
    {
    if(!ns->Clase)
    {ns=NULL;}
    }

    if(ns==NULL&&this->tablaArriba!=NULL)
    {
        ns=tablaArriba->GetClase(nombre);
    }
    return ns;

}



bool TablaDeSimbolos::InsertarClase(QString nombre,QString clasePadre)
{
    bool res=true;
    Simbolo *cp=NULL;
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


