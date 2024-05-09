#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "head.h"
#define M_PI 3.14159265358979323846 // ����������� ��������� ����� ��
int main() {
    srand(time(0)); // ������������� ���������� ��������� �����
    setlocale(LC_CTYPE, "Russian");
    int total = 10000000; // ����� ���������� ���������
    //double Q = 100; // ������ ����� ������
    //double R = 10; // ������ ����� ������ ��������
    //double r = 5; // ������ ����� ������

    double Q, R, r;

    printf("������� ������ ����� ������: \n");
    scanf("%lf", &Q);

    printf("������� ������ ����� ������: \n");
    scanf("%lf", &R);

    printf("������� ������ ����� ������: \n");
    scanf("%lf", &r);

    middle(Q, R, r, total);
    edge(Q, R, r, total);
    contour(Q, R, r, total);

    int n = 1000000; // ���������� ���������
    double b = (R*R + 4*R*r - 2*Q*r + 3*r*r)/(2*Q);
    double c = (2*R*R + 4*R*r + 3*r*r - 2*Q*r - 2*Q*R)/(2*(Q-R));

    // ��������� ������� ���������� �� ���� �������
    double result1=(M_PI*(R+2*r)*(R+2*r))/(M_PI*(Q+r)*(Q+r));
    double result2=(trapezoidal_integration(-r, b, n, f1, Q, R, r)+trapezoidal_integration(b, R+2*r, n, f2, Q, R, r))/(M_PI*(Q+r)*(Q+r));
    double result3=(trapezoidal_integration(-r-R, c, n, f3, Q, R, r)+trapezoidal_integration(c, R+2*r, n, f4, Q, R, r))/(M_PI*(Q+r)*(Q+r));

    printf("����������� ��������� ������ � ������ ��������, �������� � �������� ������, ������������ ������������: %lf\n", result1);
    printf("����������� ��������� ������ � ������ ��������, �������� �� ���� ������, ������������ ������������: %lf\n", result2);
    printf("����������� ��������� ������ � ������ ��������, �������� �� ������� ������, ������������ ������������: %lf\n", result3);

    return 0;
}
