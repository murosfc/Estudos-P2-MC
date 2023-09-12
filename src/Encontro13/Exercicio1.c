#define T 3

#include <stdio.h>
#include <math.h>

void calcularTI(float L[T][T], float x[T], float y[T])
{
    float soma;
    for (int i = 0; i < T; i++)
    {
        soma = 0;
        for (int j = 0; j < i; j++)
        {
            soma += L[i][j] * x[j];
        }
        x[i] = (y[i] - soma) / L[i][i];
    }
}

void calcularTS(float L[T][T], float x[T], float y[T])
{
    float soma;
    for (int i = T - 1; i >= 0; i--)
    {
        soma = 0;
        for (int j = i + 1; j < T; j++)
        {
            soma += L[i][j] * x[j];
        }
        x[i] = (y[i] - soma) / L[i][i];
    }
}

void imprimirVetor(float x[T])
{
    for (int i = 0; i < T; i++)
    {
        printf("%.0f ", x[i]);
    }
    printf("\n");
}

void calcularR(int A[T][T], float R[T][T])
{
    for (int i = 0; i < T; i++)
    {
        float sum = 0.0;
        for (int k = 0; k < T; k++)
        {
            sum += pow(R[k][i], 2);
        }
        R[i][i] = sqrt(A[i][i] - sum);
        for (int j = i + 1; j < T; j++)
        {
            sum = 0.0;
            for (int k = 0; k < i; k++)
            {
                sum += R[k][i] * R[k][j];
            }
            R[i][j] = 1 / R[i][i] * (A[i][j] - sum);
        }
    }
}

void calcularRT(float R[T][T], float Rt[T][T])
{
    for (int i = 0; i < T; i++)
    {
        for (int j = i; j < T; j++)
            Rt[j][i] = R[i][j];
    }
}

int main()
{
    int A[T][T] = {{1, 2, 4}, {2, 8, 10}, {4, 10, 26}};
    float R[T][T], Rt[T][T];
    float b[T] = {1, -4, 10};
    float x[T], y[T];
    calcularR(A, R);
    calcularRT(R, Rt);
    // decomportCholesky(A, R, Rt);
    calcularTI(Rt, y, b);
    calcularTS(R, x, y);
    imprimirVetor(x);
    return 0;
}
