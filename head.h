#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

double random(double min, double max);
double generate_x(double min, double max);
double generate_y(double x, double Q);

/** � ������ ������ � ���������� �� ������, � ������ ���� ���� �����, ������� ���������� �������������� � �������,
 ** ������� ��� ������� ������ ����� ������ Q+r(��� ��� ����� ������ �����  ������ �� ���������� ������� Q),
 ** � ���������� � ������� ����� ������� ����� ����� ������ Q+2*r (� ������, ��� ����� �������� ���� ��������� ������ ����������),
 ** ����� ��� �������� � ������� ����������� ��������, ������ R - ������ ������, r - ������ ������
**/
void middle(double Q, double R, double r, int total);

/** � ������ ������� ��� ���������� ����������� ���� ������� ����� �� ����, � ������ ��� ������� ����� �� ���������� ������� Q
**/
void edge(double Q, double R, double r, int total);

/** � ������ ������� ��� ���������� ����������� ���� ������� �� �������, � ������ ��� ������� ����� �� ���������� ������� Q-R
 ** �� ���� ���������� ������� R �������� ���������� ������� Q
**/
void contour(double Q, double R, double r, int total);

// ������� �����������
double f1(double x, double Q, double R, double r);
double f2(double x, double Q, double R, double r);
double f3(double x, double Q, double R, double r);
double f4(double x, double Q, double R, double r);
typedef double (*fnc_t)(double, double, double, double);
// ������� ��� ���������� �������������� ������� ��������
double trapezoidal_integration(double a, double b, int n, fnc_t f, double Q, double R, double r);

#endif // HEAD_H_INCLUDED
