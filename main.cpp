// Решаем уравнение, описывающее стационарные проецссы, вида:
//                                    -div(p(x) grad(u)) + q(x) u = F(x)
#include "iostream"
#include <array>
#include <functional>
#include "cmath"

using namespace std;

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