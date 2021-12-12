// Решаем уравнение, описывающее стационарные проецссы, вида:
//       Lu = F          <=>            -div(p(x) grad(u)) + q(x) u = F(x)

#include <iostream>
#include <array>
#include <vector>
#include <functional>
#include <cmath>
#include <D:/Informatics/CLionProjects/PTSB_zad1/Eigen/Eigen/Eigen.>

using namespace Eigen;
/*
double F(double x) { // Неоднородность
    return x;
}

double p(double x) { //
    return x;
}

double q(double x) { // Потенциал
    return x;
}

// Взятие первой производной функции
double diff(const function<double(double)> &function, double x, double h) {
    return ((function, x + h, h) - (function, x - h, h)) / 2.0 / h;
}

// Градиент функции
array<double, 2> grad(const function<double(double)> &function, array<double, 2> &u, double h) {
    return array<double, 2>{diff(function, u[0], h), diff(function, u[1], h)};
}

int main() {
    double h = 1e-3; // Шаг сетки
    double eps = 1e-3; // Погрешность
    double x = 0, y = 0; // Координаты
    array<double, 2> u = {x, y};

    // Начальные условия

    return 0;
};
*/

// Класс одного конечного элемента
class Elem {
    int num; // Номер элемента
    double u_k;  // Значение U_k на этом элементе
    double phi = 1; // Базисный вектор (всегда равен 1 на этом элементе: Phi_k(X_m) = Kroneker_km)

};


int main() {
    // Область определения Омега
    double x_start = 0, y_start = 0;
    double x_end = 1, y_end = 1;

    // Шаг сетки h (одинаков вдоль осей Ox и Oy)
    double h = 0.01;

    // Количество узлов n
    double n = ((x_end - x_start) / h) * ((y_end - y_start) / h);
    // Нумеровать узлы будем как: k = i + [(j-1) * (1/h)]

    //vector<>
    Matrix<float, 3, 3> m;


    return 0;
}