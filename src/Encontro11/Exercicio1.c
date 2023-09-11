#define T 3     

#include <stdio.h>

void calcularTI(int L[T][T], int x[T], int y[T]);
void imprimirVetor(int x[T]);

int main(){
    int L[T][T] = {{2,0,0}, {1,4,0}, {1,1,1}};
    int x[T];
    int y[T] = {2,-3,1};

    calcularTI(L, x, y);
    imprimirVetor(x);
    return 0;
}

void calcularTI(int L[T][T], int x[T], int y[T]){
    int soma;
    for (int i = 0; i<T; i++){
        soma = 0;
        for (int j = 0; j<i; j++){
            soma += L[i][j] * x[j];
        }
        x[i] = (y[i] - soma) / L[i][i];
    }
}

void imprimirVetor(int x[T]){
    for(int i = 0 ; i < T ; i++){
        printf("%d ", x[i]);
    }
    printf("\n");
}