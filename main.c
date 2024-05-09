#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "head.h"
#define M_PI 3.14159265358979323846 // ќпределение константы числа ѕи
int main() {
    srand(time(0)); // »нициализаци€ генератора случайных чисел
    setlocale(LC_CTYPE, "Russian");
    int total = 10000000; // ќбщее количество испытаний
    //double Q = 100; // –адиус круга €блони
    //double R = 10; // –адиус круга головы человека
    //double r = 5; // –адиус круга €блока

    double Q, R, r;

    printf("¬ведите радиус круга €блони: \n");
    scanf("%lf", &Q);

    printf("¬ведите радиус круга головы: \n");
    scanf("%lf", &R);

    printf("¬ведите радиус круга €блока: \n");
    scanf("%lf", &r);

    middle(Q, R, r, total);
    edge(Q, R, r, total);
    contour(Q, R, r, total);

    int n = 1000000; //  оличество разбиений
    double b = (R*R + 4*R*r - 2*Q*r + 3*r*r)/(2*Q);
    double c = (2*R*R + 4*R*r + 3*r*r - 2*Q*r - 2*Q*R)/(2*(Q-R));

    // ќтношение площади подобласти ко всей площади
    double result1=(M_PI*(R+2*r)*(R+2*r))/(M_PI*(Q+r)*(Q+r));
    double result2=(trapezoidal_integration(-r, b, n, f1, Q, R, r)+trapezoidal_integration(b, R+2*r, n, f2, Q, R, r))/(M_PI*(Q+r)*(Q+r));
    double result3=(trapezoidal_integration(-r-R, c, n, f3, Q, R, r)+trapezoidal_integration(c, R+2*r, n, f4, Q, R, r))/(M_PI*(Q+r)*(Q+r));

    printf("¬еро€тность попадани€ €блока в голову человека, сто€щего в середине €блони, подсчитанна€ теоретически: %lf\n", result1);
    printf("¬еро€тность попадани€ €блока в голову человека, сто€щего на краю €блони, подсчитанна€ теоретически: %lf\n", result2);
    printf("¬еро€тность попадани€ €блока в голову человека, сто€щего по контуру €блони, подсчитанна€ теоретически: %lf\n", result3);

    return 0;
}
