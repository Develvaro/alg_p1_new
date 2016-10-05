//
// Created by develvaro on 22/09/16.
//

#include <vector>
#include <ctime>
#include <cstdlib>

class Rand_Sqr_Matriz {

private:

    std::vector< std::vector <double> > _Matriz;

public:

        Rand_Sqr_Matriz(int orden){

            std::srand(std::time(0));

            //Reserva de memoria
            _Matriz = std::vector<std::vector <double >> (orden, std::vector <double > (orden));


            //Inicialización de la matriz con números aleatorios entre -10.000 y 10.0000
            for (int i = 0; i < orden ; i++) {
                for (int j = 0; j < orden; j++) {
                    _Matriz[i][j] = (10000 - (std::rand() % 20000)) / 1000;
                }
            }
        }

    const std::vector<std::vector<double>> &get_Matriz() const {
        return _Matriz;
    }


};