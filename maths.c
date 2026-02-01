#include <math.h>

__declspec(dllexport)
double addition(double a, double b) {
    return a + b;
}

__declspec(dllexport)
double moyenne(double a, double b, double c) {
    return (a + b + c) / 3.0;
}

__declspec(dllexport)
double suite_arithmetique(int u0, int r, int n) {
    return u0 + n * r;
}

__declspec(dllexport)
double equation_second_degre(double a, double b, double c) {
    double delta = b*b - 4*a*c;
    if (delta < 0) return -1;
    return (-b + sqrt(delta)) / (2*a);
}