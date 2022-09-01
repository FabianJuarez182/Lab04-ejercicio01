/*
*------------------------------------------
* Laboratorio 4.cpp
* -----------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* FACULTAD DE INGENIERÍA
* DEPARTAMENTO DE CIENCIA DE LA COMPUTACIÓN
* CC3086 - Programacion de Microprocesadores
* Fabian Juárez 21440
*------------------------------------------
* Descripción: 
* 
* 
* 
* 
*------------------------------------------
*/ 
#include <iostream>
#include <stdio.h>
#include <pthread.h>
using namespace std;
//Creacion de variables que se utilizaran de manera global
void *process(void *ptr);
int totalVentas = 0;
int utilidadMes = 0;
int numThread = 8;
double precioUnit[] = {60, 32, 22, 24, 28, 24, 32, 60};
double costoFijoUnidad[] = {20, 19.20, 13.20, 17.20, 20.10, 17.20, 23, 20};
double unidadesVendidasJulio[] = {300, 400, 1590, 200, 390, 1455, 800, 60};
double unidadesVendidasAgosto[]= {250, 380, 800, 250, 600, 1200, 1540, 15};
double costosVariablesJulio = 45,640; 
int n = 0;
double costosVariablesAgosto = 40,590;

//Se creara el estructure para cada hilo
struct hilo{
  double precio, costo, unidadesVenta, ventasProducto, utilidadProdUnit;
  pthread_t Threadn;
};
//Funcion para calcular ventas por producto
double ventasProd(int unidades, int precio) {
    double ventas = unidades * precio;
    return ventas;
}

double utilidadProd(int ventas, int unidades, int costo){
  double utilidad  =  ventas - (unidades * costo);
  return utilidad
}

double utilidad(double totventas, double costoVariables){
    double utilidadMes = totventas - costoVariables;
    return utilidadMes;
}

// Funcion para el thread el cual se encarga de encontrar la venta total del productoy  utilidad  
// al final sumarlos y tener la utilidad del mes junto con sumarlo al total completo
void *process(void *ptr){
    hilo *soloHilo;
    soloHilo = (hilo *) ptr;

    printf("------------------------------------------\n");
    pthread_exit(nullptr);
}

int main()
{
    printf("------------------------------------------\n");
    pthread_exit(NULL);
    exit(0);
}