//
// Created by develvaro on 5/10/16.
//

#include "funciones.h"

using namespace std;

//Función que calcula la media de un vector de elementos de tipo double
double calcularMedia(const vector<double> &v)
{
    double media = 0;
    double suma = 0;
    int tam = v.size();

    for(int i=0; i<tam; i++)
        suma = suma + v[i];

    media = suma / tam;
    return media;
}

//Función que calcula la covarianza de dos conjuntos de elementos de tipo double (x e y)
double calcularCovarianza(const vector<double> &x, const double &xMedia, const vector<double> &y, const double &yMedia)
{
    double covarianza = 0;
    double suma = 0;

    if(x.size() != y.size())
    {
        cout << "Error: Los tamaños de los vectores que contiene el tiempo real y el tamaño utilizado no coinciden." << endl;
        exit(-1);
    }

    int tam = x.size();

    for (int i=0; i<tam; i++)
    {
        suma = suma + (x[i]-xMedia)*(y[i]-yMedia);
    }

    covarianza = suma / tam;
    return covarianza;
}

//Función que calcula la varianza de los elementos de tipo double contenidos en un vector
double calcularVarianza(const vector<double> &v, const double &vMedia)
{
    double varianza = 0;
    double suma = 0;
    int tam = v.size();

    for(int i=0; i<tam; i++)
        suma = suma + (v[i]-vMedia)*(v[i]-vMedia);

    varianza = suma / tam;
    return varianza;
}


bool initRandMatriz(std::vector<std::vector<double>> & Matriz, int orden){


    std::srand(std::time(0));

    //Reserva de memoria
    Matriz = std::vector<std::vector <double >> (orden, std::vector <double > (orden));


    //Inicialización de la matriz con números aleatorios entre -10.000 y 10.0000
    for (int i = 0; i < orden ; i++) {
        for (int j = 0; j < orden; j++) {
            Matriz[i][j] = (10000 - (std::rand() % 20000)) / 1000;
        }
    }
}


int fibonacci_rev(int n){
    if (n>2) {
        return fibonacci_rev(n - 1) + fibonacci_rev(n - 2);
    }
    else if (n == 2){
        return 1;
    }
    else if(n == 1){
        return 1;
    }
    else if(n == 0){
        return 0;
    }
    else{
        return -1;
    }
}


bool guardarFichero(std::vector<double> n, std::vector<double> tReal, std::vector<double> tEstimado, std::string algoritmo){

    std::ofstream fichero(algoritmo + ".txt");

    if (fichero.is_open()){
        std::cout << "Fichero abierto \n";
    }
    else{
        std::cout << "Fichero NO abierto \n";
    }

    unsigned long int tam = n.size();


    fichero << "#Nº Elementos\tTiempo Real " << algoritmo << "\tTiempo Estimado "<< algoritmo << "\t" << endl;

    for(int i=0; i<tam; i++)
    {
        fichero << n[i] << "\t" << tReal[i] << "\t" << tEstimado[i] << "\t" << endl;
    }

    fichero.close();
}



//Función que calcula el conjunto de parámetros y estimados para una serie de valores de x dados, según los parámetros a y b obtenidos al realizar el ajuste lineal
void calcularTiemposEstimados(const std::vector <double> &x, const double &a, const double &b, std::vector <double> &yEstimada)
{
    int tam = x.size();

    for (int i = 0; i<tam; i++)
        yEstimada.push_back(a*x[i] + b);
}


