#include <iostream>
#include <string>
#include <fstream>
#include "funciones.h"
#include "ClaseTiempo.hpp"
#include <cmath>

int main(int argc, char* const* argv)
{
    if(argc!=5)
    {
        std::cout << std::endl;
        std::cout << "El método sofisticado utilizado es: QUICKSORT ITERATIVO" << std::endl << std::endl;
        std::cout << "Uso: " << argv[0] << " Minimo Maximo Incremento Algoritmo{0: InversaMatriz, 1:Fibonacci}" << std::endl;

        exit (-1);
    }

    int nMinimo = atoi(argv[1]);
    int nMaximo = atoi(argv[2]);
    int incremento = atoi(argv[3]);
    int algoritmo = atoi(argv[4]);


    if(nMinimo>nMaximo)
    {
        std::cout << "Error: El mínimo tamaño declarado no puede ser mayor que el máximo." << std::endl;
        exit(-1);
    }

    if(incremento == 0)
    {
        std::cout << "Error: El incremento mínimo permitido es 1. Un incremento de 0 provocaría un bucle infinito." << endl;
        exit(-1);
    }

    if(nMaximo-nMinimo == 0 || nMaximo-nMinimo <= incremento)
        std::cout << "Aviso: Se debe experimentar con varios tamaños para poder conseguir un buen ajuste. Realizar un ajuste con un tiempo obtenido para un solo tamaño es imposible." << endl << endl;

    //Inicializamos la semilla
    srand(time(NULL));

    std::vector <double> tReal, tEsperado, n, exp2, n3, n4;

    Clock time;

    if (algoritmo == 0){
        printf("Algoritmo en construccion");
    }
    else if(algoritmo == 1){


        for (int i = nMinimo; i <= nMaximo ; i+=incremento) {
            time.start();
            fibonacci_rev(i);
            time.stop();
            tReal.push_back(time.elapsed());
            n.push_back(i);
            n.push_back(pow(2,i));
        }

    }


    /*
    time.start();

    for(unsigned int i = 0; i <= 1000000000; i++)
    {
        a++;
        b++;
    }
    if (time.isStarted())
    {
        time.stop();
        std::cout << "Han pasado " << time.elapsed() << "microsegundos \n";
    }

    while (nFibo != 0) {
        std::cout << "Introduce el número de la serie de fibbonacci que quieres \n";
        std::cin >> nFibo;

        time.start();

        std::cout << fibonacci_simple(nFibo) << "\n";

        time.stop();
        std::cout << "Han pasado " << time.elapsed() << "microsegundos \n";
    }

     */

    return 0;
}
