#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"
// Функции, которые будут интегрироваться

// Человек находится на краю яблони
double f1(double x, double Q, double R, double r) {
    return 2*sqrt((Q+r)*(Q+r)-((x-Q)*(x-Q)));
}
double f2(double x, double Q, double R, double r) {
    return 2*sqrt((R+2*r)*(R+2*r)-(x*x));
}

// Человек находится по контуру яблони
double f3(double x, double Q, double R, double r) {
    return 2*sqrt((Q+r)*(Q+r)-(x-(Q-R))*(x-(Q-R)));
}
double f4(double x, double Q, double R, double r) {
    return 2*sqrt((R+2*r)*(R+2*r)-x*x);
}
typedef double (*fnc_t)(double, double, double, double);
// Функция для численного интегрирования методом трапеций
double trapezoidal_integration(double a, double b, int n, fnc_t f, double Q, double R, double r) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a, Q, R, r) + f(b, Q, R, r));

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x, Q, R, r);
    }
    return h * sum;
}

