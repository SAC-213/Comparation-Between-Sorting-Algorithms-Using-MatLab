#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//**************************************************
// Librería utilizada para medir el tiempo de ejecución
// del algoritmo utilizando la función clock()
//**************************************************

/* Ordenamiento por Inserción */
void insercion(int *A, int n) {
    int i;
    for (i = 1; i < n; i++) {
        int clave = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > clave) {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = clave;
    }
}

int main(int argc, char *argv[]) {
//********************************************************
// Variables necesarias para medir el tiempo de ejecución
//********************************************************

    if (argc != 2) {
        printf("Uso: %s n\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int *A = malloc(n * sizeof(int));

    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

//******************************************************************	
// Iniciar el conteo del tiempo antes de ejecutar el algoritmo
//******************************************************************
    clock_t inicio = clock();

    insercion(A, n);

//******************************************************************	
// Finalizar la medición del tiempo de ejecución
//******************************************************************
    clock_t fin = clock();

//***************************************************************************************************	
// Cálculo del tiempo total de ejecución del algoritmo
//***************************************************************************************************
    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    printf("Insercion n=%d tiempo=%.6f segundos\n", n, tiempo);

    free(A);
    return 0;
}

