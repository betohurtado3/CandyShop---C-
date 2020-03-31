#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>  ///////////////ES DE CLIENTES
#include <conio.h>
#include <vector>
#include <sstream>

using namespace std;
int orden=0;
class Clientes
{
    public:
        char rfc[14],nombre[20];

        void capturar();
        void buscar();
        void mostrar();
        void Modificar();
        void Eliminar();
        void Mostrar_Indice();
        void Orden();

}x;

class Indice
{
    public:
    long int pos;
    char indi[4],rfc[14];
}y;

void Clientes::capturar()
{
    fflush(stdin);
    cout<<"RFC:"<<endl;
    cin.getline(x.rfc,14);
    cout<<"Dame el nombre del cliente"<<endl;
    cin.getline(x.nombre,35);

    ofstream a("Clientes.txt",ios::app);
    a.write((char*)&x,sizeof(x));

    ifstream c("indice.txt");
    if(!c.good())
        cout<<"...";
    else
    {
        while(!c.eof())
        {
            c.read((char*)&y,sizeof(y));
            if(c.eof())
                break;
            y.indi;
            stringstream s;
            s<<y.indi;
            s>>y.pos;
            y.pos++;

            stringstream ss;
            ss<<y.pos;
            ss>>y.indi;
        }
    }
    c.close();
    a.close();
    strcpy(y.rfc,x.rfc);
    ofstream b("indice.txt",ios::app);
    b.write((char*)&y,sizeof(y));
    b.close();
    orden++;
}

void Clientes::mostrar()
{
    ifstream a("Clientes.txt");
    if(!a.good())
    cout<<"No existe el archivo";
    else
    {
        while(!a.eof())
        {
            a.read((char*)&x,sizeof(x));
            if(a.eof())
                break;
            cout<<"RFC:"<<x.rfc<<"\n"<<"Nombre: "<<x.nombre<<"\n"<<endl;
        }
    }
    a.close();
}

void Clientes::Mostrar_Indice()
{
  ifstream a("indice.txt");
    if(!a.good())
    cout<<"No existe el archivo";
    else
    {
        while(!a.eof())
        {
            a.read((char*)&y,sizeof(y));
            if(a.eof())
                break;
            cout<<"\nIndice:"<<y.pos<<endl;
            cout<<"RFC:"<<y.rfc<<endl;
        }
    }
    a.close();
}

void Clientes::buscar()
{
    int band=0;
    char rfc2[14];
    ifstream a("Clientes.txt");
    fflush(stdin);
    cout<<"Ingrese un RFC a buscar: "<<endl;
    cin.getline(rfc2,14);

    if(!a.good())
    cout<<"No existe el archivo";
    else
    {
        while(!a.eof())
        {
            a.read((char*)&x,sizeof(x));
            if(a.eof())
                break;

                if(strcmp(rfc2,x.rfc)==0)
                {
                    cout<<"RFC:"<<x.rfc<<"\n"<<"Nombre: "<<x.nombre<<"\n"<<endl;
                    band=1;
                }
        }
                if(band==0)
                    cout<<"Rfc No encontrado"<<endl;
    }
    a.close();
}

void Clientes::Modificar()
{
    int band=0;
    char rfc2[14];
    ifstream a("Clientes.txt");
    fflush(stdin);
    cout<<"Ingrese un RFC a Modificar: "<<endl;
    cin.getline(rfc2,14);
    if(!a.good())
    cout<<"No existe el archivo";
    else
    {
        while(!a.eof())
        {
            a.read((char*)&x,sizeof(x));
            if(a.eof())
                break;

                if(strcmp(rfc2,x.rfc)==0)
                {
                    fflush(stdin);
                    cout<<"RFC:"<<endl;
                    cin.getline(x.rfc,14);
                    cout<<"Dame el nombre del cliente"<<endl;
                    cin.getline(x.nombre,35);

                    ofstream b("ClientesTemp.txt",ios::app);
                    b.write((char*)&x,sizeof(x));

                    ifstream c("indice.txt");
                        if(!c.good())
                            cout<<"...";
                        else
                        {
                            while(!c.eof())
                            {
                                c.read((char*)&y,sizeof(y));
                                if(c.eof())
                                    break;

                                y.indi;
                                stringstream s;
                                s<<y.indi;
                                s>>y.pos;


                                stringstream ss;
                                ss<<y.pos;
                                ss>>y.indi;
                            }
                        }
                        c.close();
                        a.close();
                        strcpy(y.rfc,x.rfc);
                        ofstream d("tempindice.txt",ios::app);
                        d.write((char*)&y,sizeof(y));
                        d.close();

                    band=1;
                }
        }
                if(band==0)
                    cout<<"Rfc No encontrado"<<endl;
    }
    a.close();

     remove("Clientes.txt");
    rename("ClientesTemp.txt","Clientes.txt");
    remove("indice.txt");
    rename("tempindice.txt","indice.txt");

}

#endif // CLIENTES_H_INCLUDED
