
#define T 3     

#include <stdio.h>

void calcularTS(int L[T][T], int x[T], int y[T]);
void imprimirVetor(int x[T]);

int main(){
    int L[T][T] = {{3,1,0}, {0,2,-1}, {0,0,3}};
    int x[T];
    int y[T] = {4,2,0};

    calcularTS(L, x, y);
    imprimirVetor(x);
    return 0;
}

void calcularTS(int L[T][T], int x[T], int y[T]){
    int soma;
    for(int i = T -1 ; i >=0 ; i--){
        soma = 0;
        for(int j = i+1 ; j < T ; j++){
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