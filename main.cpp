#include <iostream>
#include "Productos.h"
#include "Proveedor.h"
#include "Orden.h"
#include "Clientes.h"
using namespace std;

int main()
{
    Productos p;
    Proveedor pr;
    Orden o;
    Clientes c;
    int opc,opc2;
    do
    {
        cout << "\n...Menu Principal...\n" << endl;
        cout << "\n[1]...Productos\n[2]...Proveedores\n[3]...Ordenes\n[4]...Clientes\n" << endl;
        cout<<"--->"; cin>>opc;
        switch(opc)
        {
        case 1: ///Productos / Delimitadores
            {
                do
                {
                    cout << "\n\n[1]...Capturar\n[2]...Imprimir\n[3]...Buscar\n[4]...Eliminar\n[5]...Regresar al Menu" << endl;
                    cout<<"--->"; cin>>opc2;
                    switch(opc2)
                    {
                    case 1:
                        {
                            p.capturar();
                            break;
                        }
                    case 2:
                        {
                            p.imprimir();
                            break;
                        }
                    case 3:
                        {
                            p.buscar();
                            break;
                        }
                    case 4:
                        {
                            p.eliminar();
                            break;
                        }

                    }

                }while(opc2!=5);

                break;
            }///FIN OPC 1 /PRODUCTOS
        case 2:
            {
                do
                {
                    cout << "\n\n[1]...Capturar\n[2]...Imprimir\n[3]...Buscar\n[4]...Modificar\n[5]...Eliminar\n[6]...Regresar al menu" << endl;
                    cout<<"--->"; cin>>opc2;
                    switch(opc2)
                    {
                    case 1:
                        {
                            pr.Capturar();
                            break;
                        }
                    case 2:
                        {
                            pr.imprimir();
                            break;
                        }
                    case 3:
                        {
                            pr.buscar();
                            break;
                        }
                    case 4:
                        {
                            pr.modificar();
                            break;
                        }
                    case 5:
                        {
                            pr.eliminar();
                            break;
                        }

                    }

                }while(opc2!=6);
            break;
            }///fin case 2/Proveedores
        case 3:
            {
              do
                {
                    cout << "\n\n[1]...Capturar\n[2]...Imprimir\n[3]...Buscar\n[4]...Modificar\n[5]...Eliminar\n[6]...Regresar al menu" << endl;
                    cout<<"--->"; cin>>opc2;
                    switch(opc2)
                    {
                    case 1:
                        {
                            o.capturar();
                            break;
                        }
                    case 2:
                        {
                            o.mostrar();
                            break;
                        }
                    case 3:
                        {
                            o.buscar();
                            break;
                        }
                    case 4:
                        {
                            o.modificar();
                            break;
                        }
                    case 5:
                        {
                            o.eliminar();
                            break;
                        }

                    }

                }while(opc2!=6);
            break;
            }///Fin case 3//Orden

        case 4:
            {
            do
                {
                    cout << "\n\n[1]...Capturar\n[2]...Imprimir\n[3]...Imprimir_Indice\n[4]...Buscar\n[5]...Modificar Cliente\n[6]...Regresar al menu" << endl;
                    cout<<"--->"; cin>>opc2;
                    switch(opc2)
                    {
                    case 1:
                        {
                            c.capturar();
                            break;
                        }
                    case 2:
                        {
                            c.mostrar();
                            break;
                        }
                    case 3:
                        {
                            c.Mostrar_Indice();
                            break;
                        }
                    case 4:
                        {
                            c.buscar();
                            break;
                        }
                    case 5:
                        {
                            c.Modificar();
                            break;
                        }

                    }

                }while(opc2!=6);
             break;
            }
        }
    }while(opc!=6);

    return 0;
}
