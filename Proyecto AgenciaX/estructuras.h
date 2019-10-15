#include "librerias.h"

struct Trabajador
{
    int nro;
    char dni[15];
    char nombre[50];                             
    char apellido[50];                           
    //std::string fullname = nombre + apellido;
    int edad;
    int annIngreso;                                     //ANNO DE INGRESO
    char email[70];
    float sueldo;
};

struct Vehiculo
{
    int nro;                                            //NUMERO DE VEHICULO
    char tipo[30];
    char placa[10];
    char marca[15];
    int capMaxM;                                        //CAPACIDAD DE MERCANCIA EN KILOS
    int nroAsientos;                                    //CAPACIDAD DE PASAJEROS
};

struct Cliente
{
    int nro;
    char dni[15];
    char nombre[40];
    char apellido[40];
    int preferencia;

};

/*
PREFERENCIA
1 >> PREMIUM
2 >> REGULAR
3 >> NUEVO
*/


struct Informacion
{
    char ruc[13];
    char razonSocial[50];                            //NOMBRE DE LA EMPRESA
    char ciudad[50];
    char direccion[100];
    int nVehiculos;
    int nEmpleados;
    int nClientes;
    char tipo[50];
    char telefono[14];
};


struct NodoV
{
    Vehiculo info;
    NodoV *sgte;
};
typedef NodoV *PNodov;

struct NodoE
{
    Trabajador info;
    NodoE *sgte;
};
typedef NodoE *PNodoe;

struct ColaV
{
    PNodov primero;
    PNodov ultimo;
};


struct ColaE
{
    PNodoe primero;
    PNodoe ultimo;
};