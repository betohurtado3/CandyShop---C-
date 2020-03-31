#ifndef ORDEN_H_INCLUDED
#define ORDEN_H_INCLUDED

class Orden
{
    public:
    char folio[10],fecha[20],proveedor[20];

    void capturar();
    void mostrar();
    void buscar();
    void modificar();
    void eliminar();
}dato;


void Orden::capturar()
{
    fflush(stdin);
    cout<<"Da un nuevo folio: "<<endl;
    cin.getline(dato.folio,10);
    cout<<"Ingresa fecha: "<<endl;
    cin.getline(dato.fecha,20);
    cout<<"Ingresa Proveedor: "<<endl;
    cin.getline(dato.proveedor,20);
///-----------------------------------------------------
    ofstream Archivo("OrdenDeVenta.txt",ios::app);
    Archivo.write ((char*)&dato,sizeof(dato));
    Archivo.close();
}

void Orden::mostrar()
{
    ifstream leer("OrdenDeVenta.txt");
    if(!leer.good())
    {
        cout<<"Error"<<endl;
    }
    else
    {
        while(!leer.eof())
        {
            leer.read((char*)&dato,sizeof(dato));
            if(leer.eof())
                break;

            cout<<"Folio: "<<dato.folio<<endl;
            cout<<"Fecha: "<<dato.fecha<<endl;
            cout<<"Proveedor: "<<dato.proveedor<<endl;
            cout<<"-------------------------------------"<<endl;
        }
    }
    leer.close();
}

void Orden::buscar()
{
    char folio2[10];
    int val;
    fflush(stdin);
    cout<<"Ingrese Folio a buscar :";
    cin.getline(folio2,20);
    ifstream busc("OrdenDeVenta.txt");
    if(!busc.good())
    {
        cout<<"Error"<<endl;
    }
    else{
        while(!busc.eof())
        {
            busc.read((char*)&dato,sizeof(dato));
            if(busc.eof())
                break;
            if(strcmp(folio2,dato.folio)==0)
            {
                cout<<"Folio: "<<dato.folio<<endl;
                cout<<"Fecha: "<<dato.fecha<<endl;
                cout<<"Proveedor: "<<dato.proveedor<<endl;
                cout<<"-------------------------------------"<<endl;
                val=1;
            }
            if(busc.eof())
                break;
        }
        if(val!=1)
        {
            cout<<"No encontrado"<<endl;
        }
    }
    busc.close();
}

void Orden::modificar()
{
    char folio2[10];
    int val;
    cin.ignore();
    cout<<"Ingrese un Folio :";
    cin.getline(folio2,20);

    ifstream mod("OrdenDeVenta.txt");
    ofstream temp("Temporal.txt",ios::app);

    if(!mod.good())
    {
        cout<<"Error"<<endl;
    }
    else{
        while(!mod.eof())
        {
            mod.read((char*)&dato,sizeof(dato));
            if(strcmp(folio2,dato.folio)==0)
            {
                if(mod.eof())
                    break;
                fflush(stdin);
                cout<<"Da un nuevo folio: "<<endl;
                cin.getline(dato.folio,10);
                cout<<"Ingresa fecha: "<<endl;
                cin.getline(dato.fecha,20);
                cout<<"Ingresa Proveedor: "<<endl;
                cin.getline(dato.proveedor,20);
                val=1;
            }
            if(mod.eof())
                break;
            if(temp.eof())
                break;
            temp.write((char*)&dato, sizeof(dato));
            if(mod.eof())
                break;
            if(temp.eof())
                break;
        }
        if(val!=1)
            cout<<"No encontrado"<<endl;
    }
        mod.close();
        temp.close();
        remove("OrdenDeVenta.txt");
        rename("temporal.txt","OrdenDeVenta.txt");
}

void Orden::eliminar()
{
    char folio2[10];
    int val;
    cin.ignore();
    cout<<"Ingrese un Folio :";
    cin.getline(folio2,20);

    ifstream elim("OrdenDeVenta.txt");
    ofstream temp("Temporal.txt",ios::app);

    if(!elim.good())
    {
        cout<<"Error"<<endl;
    }
    else{
        while(!elim.eof())
        {
            elim.read((char*)&dato,sizeof(dato));
            if(elim.eof())
                break;
            if(strcmp(folio2,dato.folio)!=0)
            {
                temp.write((char*)&dato,sizeof(dato));
                val=1;
            }
            if(elim.eof())
                break;
            if(temp.eof())
                break;
        }
        if(val==1)
            cout<<"Usuario Eliminado"<<endl;
    }
    elim.close();
    temp.close();
    remove("OrdenDeVenta.txt");
    rename("temporal.txt","OrdenDeVenta.txt");
}


#endif // ORDEN_H_INCLUDED
