#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
// ������� ��� ��������� ���������� ����� � ��������� [min, max]
double random(double min, double max) {
    return min + (double)rand() / RAND_MAX * (max - min);
}

// ������� ��� ��������� ���������� ����� � ��������� [min, max]
double generate_x(double min, double max) {
    return min + (double)rand() / RAND_MAX * (max - min);
}

// ������� ��� ���������� ����� ������� -sqrt(Q*Q-x*x) ��� +sqrt(Q*Q-x*x)
double generate_y(double x, double Q) {
    double sign = (rand() % 2 == 0) ? -1 : 1;
    return sign * sqrt(Q*Q - x*x);
}

// ������� ����� �� �������� ������
void middle(double Q, double R, double r, int total){
    int hits1 = 0; // ���������� ��������� ������ � ������
    int count1 = 0; // ���������� �������� ���������
    for (int i = 0; i < total; i++) {
        // ���������� ��������� ���������� ������, ������� ����� � ������ ������
        double personX = 0;
        double personY = 0;
        double appleX = random(-Q-r, Q+r);
        double appleY = random(-Q-r, Q+r);
        // ���������, ��������� �� ������ ������ ������
        if (sqrt(appleX*appleX + appleY*appleY) <= (Q+r)) {
            // ���������, �������� �� ������ � ������ ��������
            if (sqrt(pow(personX - appleX, 2) + pow(personY - appleY, 2)) <= (R + 2*r)) {
                hits1++;
            }
        }
        //���� ���, �� �� ��������� ��� ���������
        else if (sqrt(appleX*appleX + appleY*appleY) > Q+r){
            count1++;
        }
    }
    printf("%d\n", hits1);
    printf("%d\n", total-count1-hits1);
    // ��������� ����������� ��������� ������ � ������ ��������
    double probability1 = (double)hits1 / (total-count1);
    printf("����������� ��������� ������ � ������ ��������, �������� � �������� ������: %lf\n", probability1);
}

// ������� ����� �� ���� ������
void edge(double Q, double R, double r, int total){
    int hits2 = 0; // ���������� ��������� ������ � ������
    int count2 = 0; // ���������� �������� ���������
    for (int i = 0; i < total; i++) {
        // ���������� ���������� ������ �������� �� ���� � ��������� ���������� ������
        double personX = generate_x(-Q, Q);
        double personY = generate_y(personX, Q);
        double appleX = random(-Q-r, Q+r);
        double appleY = random(-Q-r, Q+r);
        // ���������, ��������� �� ������ ������ ������
        if (sqrt(appleX*appleX + appleY*appleY) <= Q+r){
            // ���������, �������� �� ������ � ������ ��������
            if (sqrt(pow(personX - appleX, 2) + pow(personY - appleY, 2)) <= (R + 2*r)) {
                hits2++;
            }
        }
        //���� ���, �� �� ��������� ��� ���������
        else if (sqrt(appleX*appleX + appleY*appleY) > Q+r){
            count2++;
        }
    }
    // ��������� ����������� ��������� ������ � ������ ��������
    double probability2 = (double)hits2 / (total-count2);
    printf("����������� ��������� ������ � ������ ��������, �������� �� ���� ������: %lf\n", probability2);
}

// ������� ����� �� ������� ������
void contour(double Q, double R, double r, int total){
    int hits3 = 0; // ���������� ��������� ������ � ������
    int count3 = 0; // ���������� �������� ���������
    for (int i = 0; i < total; i++) {
        // ���������� ���������� ������ �������� �� ���� � ��������� ���������� ������
        double personX = generate_x(-Q+R, Q-R);
        double personY = generate_y(personX, Q-R);
        double appleX = random(-Q-r, Q+r);
        double appleY = random(-Q-r, Q+r);
        // ���������, ��������� �� ������ ������ ������
        if (sqrt(appleX*appleX + appleY*appleY) <= Q+r){
            // ���������, �������� �� ������ � ������ ��������
            if (sqrt(pow(personX - appleX, 2) + pow(personY - appleY, 2)) <= (R + 2*r)) {
                hits3++;
            }
        }
        //���� ���, �� �� ��������� ��� ���������
        else if (sqrt(appleX*appleX + appleY*appleY) > Q+r){
            count3++;
        }
    }
    // ��������� ����������� ��������� ������ � ������ ��������
    double probability3 = (double)hits3 / (total-count3);
    printf("����������� ��������� ������ � ������ ��������, �������� �� ������� ������: %lf\n", probability3);
}

