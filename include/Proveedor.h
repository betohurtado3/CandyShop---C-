#ifndef PROVEEDOR_H
#define PROVEEDOR_H
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Proveedor
{
    public:
        Proveedor();
        virtual ~Proveedor();
        char nombre[35],rfc[15],tel[15],saldo[15],linea[15];
        void Capturar();
        void imprimir();
        void buscar();
        void modificar();
        void eliminar();
};

#endif // PROVEEDOR_H
