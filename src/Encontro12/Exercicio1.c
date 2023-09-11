#define T 3     

#include <stdio.h>

void calcularLU(int A[T][T], float L[T][T], float U[T][T]){
    float soma;
    for (int i =0; i<T; i++){
        L[i][i] = 1;
        for(int j = i; j< T; j++){
            soma = 0;
            for(int k = 0; k < i; k++)
                soma += L[i][k] * U[k][j];
            U[i][j] = A[i][j] - soma;
        }
        for(int j = i + 1 ; j < T ; j++){
            soma = 0;
            for(int k = 0; k < i; k++)
                soma += L[j][k]*U[k][i];
            L[j][i] =  (A[j][i] - soma) / U[i][i];
        }
    }
}

void calcularTI(float L[T][T], float x[T], float y[T]){
    float soma;
    for (int i = 0; i<T; i++){
        soma = 0;
        for (int j = 0; j<i; j++){
            soma += L[i][j] * x[j];
        }
        x[i] = (y[i] - soma) / L[i][i];
    }
}

void calcularTS(float L[T][T], float x[T], float y[T]){
    float soma;
    for(int i = T -1 ; i >=0 ; i--){
        soma = 0;
        for(int j = i+1 ; j < T ; j++){
            soma += L[i][j] * x[j];
        }
        x[i] = (y[i] - soma) / L[i][i];
    }

}

void imprimirVetor(float x[T]){
    for(int i = 0 ; i < T ; i++){
        printf("%.0f ", x[i]);
    }
    printf("\n");
}

void printMatriz(float A[T][T]){
    for(int i = 0 ; i < T ; i++){
        for(int j = 0 ; j < T ; j++){
            printf("%.0f ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    int A[T][T] = {{3,2,4},{1,1,2},{4,3,-2}};
    float L[T][T], U[T][T];
    float x[T], y[T];
    float b[T] = {1,2,3};
    calcularLU(A, L, U);
    printf("L:\n");
    printMatriz(L);
    printf("U:\n");
    printMatriz(U);
    calcularTI(L, y, b);
    calcularTS(U, x, y);
    imprimirVetor(x);
    return 0;
}

