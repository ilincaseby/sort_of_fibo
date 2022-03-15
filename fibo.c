#include <stdio.h>
#define NMAX 100

int cmmdc(int a, int b){
    while (a != b) {
        if (a > b) {
            a -= b;
        }
        else {
            b -= a;
        }
    }
    return a;
}

void fibo(int n, int v1[NMAX], int v2[NMAX], int v3[NMAX]){
    int cif = 1;
    int transport = 0;
    while (n - 2 > 0) {
        for (int i = 0; i < cif; ++i) {
            v3[i] = v1[i] + v2[i] + transport;
            transport = v3[i] / 10;
            v3[i] %= 10;
            if (i == cif - 1 && transport != 0) {
                cif++;
            }
        }
        for (int i = 0; i < cif; ++i) {
            v1[i] = v2[i];
            v2[i] = v3[i];
            v3[i] = 0;
        }
        n--;
        transport = 0;
    }
    for (int i = cif - 1; i >= 0; --i) {
        printf("%d",v2[i]);
    }
    printf("\n");
}


int main(){
    int v1[NMAX], v2[NMAX], v3[NMAX], m, n, wow;
    for (int i = 0; i < NMAX; ++i) {
        v1[i] = 0;
        v2[i] = 0;
        v3[i] = 0;
    }
    v1[0] = 1;
    v2[0] = 1;
    scanf("%d%d", &m, &n);
    wow = cmmdc(m, n);
    fibo(wow, v1, v2, v3);
    return 0;
}