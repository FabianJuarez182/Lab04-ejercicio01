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
#include <vector>
#include <stdio.h>
#include <pthread.h>
using namespace std;
//Creacion de variables que se utilizaran de manera global
void *process(void *ptr);
long totalVentas = 0;
int utilidadMes = 0;
int numThread = 8;
string names[] = {"Porcion pastel de chocolate", "White mocha", "Cafe americano 8onz", "Latte 8onz", "Toffee coffee", "Cappuccino 8onz", "S'mores Latte", "Café tostado molido"};
double precioUnit[] = {60, 32, 22, 24, 28, 24, 32, 60};
double costoFijoUnidad[] = {20, 19.20, 13.20, 17.20, 20.10, 17.20, 23, 20};
double unidadesVendidasJulio[] = {300, 400, 1590, 200, 390, 1455, 800, 60};
double unidadesVendidasAgosto[] = {250, 380, 800, 250, 600, 1200, 1540, 15};
double costosVariablesJulio = 45640; 
double ventasProducto[8];
double utilidadProducto[8];
int n = 0;
double costosVariablesAgosto = 40590;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

//Se creara el estructure para cada hilo
struct hilo{
  string name;
  double pos;
  double precio, costo, unidadesVenta, ventasProducto, utilidadProdUnit;
  pthread_t Threadn;
};

// Funcion para el thread el cual se encarga de encontrar la venta total del productoy  utilidad  
// al final sumarlos y tener la utilidad del mes junto con sumarlo al total completo
void *process(void *ptr){
    hilo *soloHilo;
    soloHilo = (hilo *) ptr;
    soloHilo -> ventasProducto = soloHilo -> unidadesVenta *soloHilo -> precio;
    ventasProducto[n] = soloHilo -> ventasProducto;
    pthread_mutex_lock(&lock);
    soloHilo -> utilidadProdUnit = soloHilo -> ventasProducto -  (soloHilo -> unidadesVenta*  soloHilo -> costo);
    utilidadProducto[n] = soloHilo -> utilidadProdUnit;
    totalVentas = totalVentas + soloHilo -> ventasProducto; 
    utilidadMes = utilidadMes + soloHilo -> utilidadProdUnit;
    pthread_mutex_unlock(&lock);
    pthread_exit(nullptr);
}


int main()
{
    hilo hilon[16];
    printf("------------------------------------------\n");
    printf("Repote del mes de Julio\n");
    printf("Ventas por Producto \n");
     for (int i = 0; i < 8; i++){
            hilon[i].name = names[i];
            hilon[i].precio = precioUnit[i];
            hilon[i].costo = costoFijoUnidad[i];
            hilon[i].unidadesVenta = unidadesVendidasJulio[i];
            hilon[i].pos = i;
            n=i;
        pthread_create(&hilon[i].Threadn,NULL, process, (void*) &hilon[i]);
     }
    for(int i = 0; i < 8;i++){
        pthread_join(hilon[i].Threadn, NULL);
     }
     for(int i = 0; i < 8;i++){
        cout << hilon[i].name << ": Q "<<hilon[i].ventasProducto << endl;
     }
    printf("\n\nUtilidad por Producto \n");
     for(int i = 0; i < 8;i++){
        cout << hilon[i].name << ": Q "<<hilon[i].utilidadProdUnit << endl;
     }
        utilidadMes = utilidadMes - costosVariablesJulio;
        cout << "\nTotal Ventas: Q" << totalVentas << endl;
        cout << "Costos Variables: Q" << costosVariablesJulio  << endl;
        cout << "Utilidad del mes: Q" << utilidadMes  << endl;
     totalVentas = 0;
     utilidadMes = 0;
    printf("------------------------------------------\n");
    printf("Repote del mes de Agosto\n");
    printf("Ventas por Producto\n");
     for (int i = 0; i < 8; i++){
        hilon[i].name = names[i];
        hilon[i].precio = precioUnit[i];
        hilon[i].costo = costoFijoUnidad[i];
        hilon[i].unidadesVenta = unidadesVendidasAgosto[i];
        hilon[i].pos = i;
        pthread_create(&hilon[i].Threadn,NULL, process, (void*) &hilon[i]);
    }
    for(int i = 0; i < 8;i++){
        pthread_join(hilon[i].Threadn, NULL);
     }
     
    for(int i = 0; i < 8;i++){
        cout << hilon[i].name << ": Q "<<hilon[i].ventasProducto << endl;
    }
    printf("\n\nUtilidad por Producto \n");
     for(int i = 0; i < 8;i++){
        cout << hilon[i].name << ": Q "<<hilon[i].utilidadProdUnit << endl;
     }
             utilidadMes = utilidadMes - costosVariablesAgosto;
     cout << "\nTotal Ventas: Q" << totalVentas << endl;
     cout << "Costos Variables: Q" << costosVariablesAgosto  << endl;
     cout << "Utilidad del mes: Q" << utilidadMes  << endl;
    pthread_exit(NULL);
    exit(0);
}