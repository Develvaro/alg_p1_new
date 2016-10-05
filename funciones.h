//
// Created by develvaro on 5/10/16.
//

#ifndef ALG_P1_FUNCIONES_H
#define ALG_P1_FUNCIONES_H

#include <vector>
#include <iostream>
#include <ctime>
#include <fstream>


//Funciones estadísticas necesarias para realizar el ajuste
double calcularMedia(const std::vector<double> &v);
double calcularCovarianza(const std::vector<double> &x, const double &xMedia, const std::vector<double> &y, const double &yMedia);
double calcularVarianza(const std::vector<double> &v, const double &vMedia);

//Funciones Matrices

bool initRandMatriz(int orden, std::vector<std::vector<double>> & Matriz);

int fibonacci_rev(int n);

bool guardarFichero(std::vector<double> n, std::vector<double> tReal, std::vector<double> tEstimado, std::string fichero);

void calcularTiemposEstimados(const std::vector <double> &x, const double &a, const double &b, std::vector <double> &yEstimada);


#endif //ALG_P1_FUNCIONES_H
