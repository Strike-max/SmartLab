__declspec(dllexport)
int somme_tableau(int tab[], int n) {
    int s = 0;
    for(int i=0;i<n;i++) s += tab[i];
    return s;
}

__declspec(dllexport)
int recherche_lineaire(int tab[], int n, int x) {
    for(int i=0;i<n;i++)
        if(tab[i] == x) return i;
    return -1;
}