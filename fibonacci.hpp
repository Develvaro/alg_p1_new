//
// Created by develvaro on 22/09/16.
//

#ifndef P1_FIBONACCI_H
#define P1_FIBONACCI_H

#include "ClaseTiempo.cpp"
#include <string>
#include <fstream>
#include <math.h>

class Fibonacci{

private:

    long _sumaTiempo;

    long _suma;

    long _xixyi;

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

public:


    Fibonacci(){
        _sumaTiempo = 0;
        _suma = 0;
        _xixyi = 0;
    }

    bool run(int min, int max, int inc, std::string name_fichero){

        std::ofstream fichero(name_fichero);


        if (fichero.is_open()){
            std::cout << "Fichero abierto \n";
        }
        else{
            std::cout << "Fichero NO abierto \n";
        }


        Clock time;
        unsigned int a, b;
        a = 0;
        b = 0;

        int nMuestras = 0;

        for (int i = min; i <= max; i += inc) {
            time.start();
            fibonacci_rev(i);
            time.stop();

            fichero << i << "," << pow(2,i) << "," << time.elapsed() << "," << std::endl;
            std::cout << i << " , " << pow(2,i) << " , " << time.elapsed() << " , " << std::endl;

            _sumaTiempo += time.elapsed();
            _suma += pow(2,i);
            _xixyi += time.elapsed() * pow(2,i);
            nMuestras++;
        }

        fichero.close();

        std::string aux_name = "aux_"+name_fichero;
        std::ofstream outputFile(aux_name);
        std::ifstream inputFile(name_fichero);

        outputFile << nMuestras << "," << _suma << "," << _sumaTiempo << "," << _xixyi << std::endl;
        outputFile << inputFile.rdbuf();

        inputFile.close();
        outputFile.close();

        std::remove(name_fichero.c_str());
        std::rename(aux_name.c_str(), name_fichero.c_str());

        std::cout << "Suma Tiempo: " << _sumaTiempo << "\n";
        std::cout << "SumaN: " << _suma << "\n";
        std::cout << "Sum Prod x y: " << _xixyi  << "\n";
    }

};

#endif //P1_FIBONACCI_H
