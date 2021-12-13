// Решаем уравнение, описывающее стационарные процессы, вида:
//       Lu = F          <=>            -div(p(x) grad(u)) + q(x) u = F(x)

#include <iostream>
#include <array>
#include <vector>
#include <functional>
#include <cmath>
#include <D:/Eigen/Eigen.>

using namespace Eigen;
/*
// Взятие первой производной функции
double diff(const function<double(double)> &function, double x, double h) {
    return ((function, x + h, h) - (function, x - h, h)) / 2.0 / h;
}

// Градиент функции
array<double, 2> grad(const function<double(double)> &function, array<double, 2> &u, double h) {
    return array<double, 2>{diff(function, u[0], h), diff(function, u[1], h)};
}
*/

// Некоторый малый параметр эпсилон для задания матрицы p(x) и потенциала q(x)
double eps = 0.001;

// Область определения Омега
double x_start = 0.0, y_start = 0.0;
double x_end = 1.0, y_end = 1.0;

// Шаг сетки h (одинаков вдоль осей Ox и Oy)
double h = 0.01;

// Количество узлов n.
// Нумеровать узлы будем как: k = i + [(j-1) * (1/h)], начиная с нуля.
// Где i - кол-во шагов вдоль оси Oy, j -- вдоль Ox.
int n = int((x_end - x_start) / h) * int((y_end - y_start) / h);
int nx = int((x_end - x_start) / h);
int ny = int((y_end - y_start) / h);

// Номера строки и столбца точки в центре области (для значений q(x))
double i_center = int(1.0 / 2.0 / h);
double j_center = int(1.0 / 2.0 / h);

// Матрица коэффициентов каппа или же p(x)
Matrix<double, 2, 2> kappa;

// Класс узла сетки
class Node {
private:
    // Номер узла
    int num{};

    // Номер по строке (номер столбца)
    int j;

    // Номер по столбцу (номер строки)
    int i;
/*
    // Значение U_k на этом узле
    double u_k{};

    // Базисный вектор (всегда равен 1 на этом узле: Phi_k(X_m) = Kroneker_km)
    double phi = 1;

    // Значение потенциала q(x) на данном узле
    double q; */

public:
    Node() {
        num = 0;
        i = 0;
        j = 0;
    }

    Node(int k) {
        num = k;
        i = int(k * h); // Целая часть с округлением вниз
        j = k - i;
        /*
        // Определение потенциала q(x)
        if (i <= i_center && j <= j_center) {
            q = 0.0;
        }
        if (i <= i_center && j > j_center) {
            q = eps;
        }
        if (i > i_center && j <= j_center) {
            q = 1.0;
        }
        if (i > i_center && j > j_center) {
            q = 0.0;
        }*/
    }
};

// Класс конечного элемента
class Elem {
private:
    // Массив, содержащий номера узлов, образующих данный элемент
    int nodesInds[3]{};

public:
    Elem(int i, int j, int k){
        nodesInds[0] = i;
        nodesInds[1] = j;
        nodesInds[2] = k;
    }
};

// Вектор элементов
std::vector<Elem> elements;


int main() {
    // Элементы матрицы p(x)
    *&kappa << eps, 0.0,
            0.0, 1.0;


//    for (int i = 0; i < (1 / h); i++) {
//        for (int j = 0; j < (1 / h); j++) {
//
//        }
//    }
    //std::cout << int(21.99) << std::endl;
    return 0;
}