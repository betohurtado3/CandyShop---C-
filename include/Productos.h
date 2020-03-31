#ifndef PRODUCTOS_H
#define PRODUCTOS_H
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Productos
{
    public:
        Productos();
        virtual ~Productos();
        char nombre[20],tipo[20],id[20],cantidad[20],precio[20];
        void capturar();
        void imprimir();
        void buscar();
        void eliminar();

    protected:

    private:
};

#endif // PRODUCTOS_H
