__declspec(dllexport)
double vitesse(double distance, double temps) {
    return distance / temps;
}

__declspec(dllexport)
double force(double masse, double acceleration) {
    return masse * acceleration;
}

__declspec(dllexport)
double energie_cinetique(double m, double v) {
    return 0.5 * m * v * v;
}