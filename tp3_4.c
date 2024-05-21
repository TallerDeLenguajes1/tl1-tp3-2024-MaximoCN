#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}typedef Producto;

struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos //El tamaño de este arreglo depende de la variable
                        // “CantidadProductosAPedir”
}typedef Cliente;

void cargarDatosCliente (Cliente *pCliente, int cantClientes,char tipoProducto[]);
void costoTotal(Cliente *pCliente);
void listarDatos(Cliente *pCliente, int cantClientes);

int main ()
{
    Cliente *pCliente;
    srand(time(NULL));
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    int clientes;

    printf("Ingrese la cantidad de clientes: \n");
    scanf("%d", &clientes);

    pCliente = (Cliente*)malloc(sizeof(Cliente)* clientes);

    cargarDatosCliente(pCliente,clientes, TiposProductos);
    listarDatos(pCliente, clientes);

    for (int i = 0; i < clientes; i++)
    {
        free(pCliente->Productos);
    }
    free(pCliente);

    return 0;
}

void cargarDatosCliente (Cliente *pCliente, int cantClientes, char tipoProducto[])
{
    int numProducto;
    for (int i = 0; i < cantClientes; i++)
    {
        pCliente->ClienteID = i + 1;

        printf("Ingrese el nombre del cliente: \n");
        pCliente->NombreCliente = (char *)malloc(100 * sizeof(char)); // reservo memoria para el nombre
        scanf("%s", pCliente->NombreCliente);

        pCliente->CantidadProductosAPedir = rand() % 5 + 1;

        pCliente->Productos = malloc(sizeof(Producto) * pCliente->CantidadProductosAPedir);

        for (int j = 0; j < pCliente->CantidadProductosAPedir; j++)
        {
            pCliente->Productos[j].ProductoID = j + 1;
            pCliente->Productos[j].Cantidad = rand() % 10 + 1;
            //numProducto = rand() % 4;
           // pCliente->Productos->TipoProducto = (char *)malloc(sizeof(char) * 12);
            //pCliente->Productos[j].TipoProducto = pCliente->Productos->TipoProducto[numProducto];//
            pCliente->Productos[j].PrecioUnitario = rand() % 100 + 10;

        }
        pCliente++;
    }
    
}

void costoTotal(Cliente *pCliente)
{
    float total;

    total = pCliente->Productos->PrecioUnitario * pCliente->Productos->Cantidad;

    return total;
    
}

void listarDatos(Cliente *pCliente, int cantClientes)
{
    for (int i = 0; i < cantClientes; i++)
    {
        printf("CLIENTE NRO %d", pCliente->ClienteID);
        printf("NOMBRE DEL CLIENTE: %s", pCliente->NombreCliente);
          
        for (int j = 0; j < pCliente->CantidadProductosAPedir; j++)
        {
            printf("\nNUMERO DE PRODUCTO: %d", pCliente->Productos[j].ProductoID);
            printf("\nCANTIDAD DEL PRODUCTO %d", pCliente->Productos[j].Cantidad);
            //printf("\nNOMBRE DEL PRODUCTO: %s", pCliente->Productos[j].TipoProducto);
            printf("\nPRECIO UNITARIO: %d", pCliente->Productos[j].PrecioUnitario);
        }
        pCliente++;
        
    }
    
}

