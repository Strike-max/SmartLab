#include <math.h>

__declspec(dllexport)
double concentration(double n, double v) {
    return n / v;
}

__declspec(dllexport)
double ph(double h) {
    return -log10(h);
}