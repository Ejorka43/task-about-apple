#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
// Функция для генерации случайного числа в диапазоне [min, max]
double random(double min, double max) {
    return min + (double)rand() / RAND_MAX * (max - min);
}

// Функция для генерации случайного числа в диапазоне [min, max]
double generate_x(double min, double max) {
    return min + (double)rand() / RAND_MAX * (max - min);
}

// Функция для нахождения числа равного -sqrt(Q*Q-x*x) или +sqrt(Q*Q-x*x)
double generate_y(double x, double Q) {
    double sign = (rand() % 2 == 0) ? -1 : 1;
    return sign * sqrt(Q*Q - x*x);
}

// Человек стоит по середине яблони
void middle(double Q, double R, double r, int total){
    int hits1 = 0; // Количество попаданий яблока в голову
    int count1 = 0; // Количество неверных испытаний
    for (int i = 0; i < total; i++) {
        // Генерируем случайные координаты яблока, человек стоит в центре яблони
        double personX = 0;
        double personY = 0;
        double appleX = random(-Q-r, Q+r);
        double appleY = random(-Q-r, Q+r);
        // Проверяем, находится ли яблоко внутри яблони
        if (sqrt(appleX*appleX + appleY*appleY) <= (Q+r)) {
            // Проверяем, попадает ли яблоко в голову человека
            if (sqrt(pow(personX - appleX, 2) + pow(personY - appleY, 2)) <= (R + 2*r)) {
                hits1++;
            }
        }
        //Если нет, то не учитываем это испытание
        else if (sqrt(appleX*appleX + appleY*appleY) > Q+r){
            count1++;
        }
    }
    printf("%d\n", hits1);
    printf("%d\n", total-count1-hits1);
    // Вычисляем вероятность попадания яблока в голову человека
    double probability1 = (double)hits1 / (total-count1);
    printf("Вероятность попадания яблока в голову человека, стоящего в середине яблони: %lf\n", probability1);
}

// Человек стоит на краю яблони
void edge(double Q, double R, double r, int total){
    int hits2 = 0; // Количество попаданий яблока в голову
    int count2 = 0; // Количество неверных испытаний
    for (int i = 0; i < total; i++) {
        // Генерируем координаты центра человека по краю и случайные координаты яблока
        double personX = generate_x(-Q, Q);
        double personY = generate_y(personX, Q);
        double appleX = random(-Q-r, Q+r);
        double appleY = random(-Q-r, Q+r);
        // Проверяем, находится ли яблоко внутри яблони
        if (sqrt(appleX*appleX + appleY*appleY) <= Q+r){
            // Проверяем, попадает ли яблоко в голову человека
            if (sqrt(pow(personX - appleX, 2) + pow(personY - appleY, 2)) <= (R + 2*r)) {
                hits2++;
            }
        }
        //Если нет, то не учитываем это испытание
        else if (sqrt(appleX*appleX + appleY*appleY) > Q+r){
            count2++;
        }
    }
    // Вычисляем вероятность попадания яблока в голову человека
    double probability2 = (double)hits2 / (total-count2);
    printf("Вероятность попадания яблока в голову человека, стоящего на краю яблони: %lf\n", probability2);
}

// Человек стоит по контуру яблони
void contour(double Q, double R, double r, int total){
    int hits3 = 0; // Количество попаданий яблока в голову
    int count3 = 0; // Количество неверных испытаний
    for (int i = 0; i < total; i++) {
        // Генерируем координаты центра человека по краю и случайные координаты яблока
        double personX = generate_x(-Q+R, Q-R);
        double personY = generate_y(personX, Q-R);
        double appleX = random(-Q-r, Q+r);
        double appleY = random(-Q-r, Q+r);
        // Проверяем, находится ли яблоко внутри яблони
        if (sqrt(appleX*appleX + appleY*appleY) <= Q+r){
            // Проверяем, попадает ли яблоко в голову человека
            if (sqrt(pow(personX - appleX, 2) + pow(personY - appleY, 2)) <= (R + 2*r)) {
                hits3++;
            }
        }
        //Если нет, то не учитываем это испытание
        else if (sqrt(appleX*appleX + appleY*appleY) > Q+r){
            count3++;
        }
    }
    // Вычисляем вероятность попадания яблока в голову человека
    double probability3 = (double)hits3 / (total-count3);
    printf("Вероятность попадания яблока в голову человека, стоящего по контуру яблони: %lf\n", probability3);
}

