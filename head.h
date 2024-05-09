#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

double random(double min, double max);
double generate_x(double min, double max);
double generate_y(double x, double Q);

/** В данной задаче я избавляюсь от яблока, а вместо него беру точку, которая равномерно распределяется в области,
 ** поэтому вся область теперь имеет радиус Q+r(так как центр яблока может  лежать на окружности радиуса Q),
 ** а подобласть в которую может попасть точка имеет радиус Q+2*r (я считал, что точка попадает если находится внутри подобласти),
 ** также для удобства я заменил обозначения радиусов, теперь R - радиус головы, r - радиус яблока
**/
void middle(double Q, double R, double r, int total);

/** В данной функции для нахождения вероятности если человек стоит на краю, я считал что человек стоит на окружности радиуса Q
**/
void edge(double Q, double R, double r, int total);

/** В данной функции для нахождения вероятности если человек по контуру, я считал что человек стоит на окружности радиуса Q-R
 ** то есть окружность радиуса R касается окружности радиуса Q
**/
void contour(double Q, double R, double r, int total);

// Графики окружностей
double f1(double x, double Q, double R, double r);
double f2(double x, double Q, double R, double r);
double f3(double x, double Q, double R, double r);
double f4(double x, double Q, double R, double r);
typedef double (*fnc_t)(double, double, double, double);
// Функция для численного интегрирования методом трапеций
double trapezoidal_integration(double a, double b, int n, fnc_t f, double Q, double R, double r);

#endif // HEAD_H_INCLUDED
