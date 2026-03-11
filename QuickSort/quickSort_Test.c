#include <stdio.h>
#include <stdlib.h>

void QuickSort(int A[], int p, int r);
int Pivot(int A[], int p, int r);
void Intercambio(int A[], int i, int j);

/*
Función principal del programa
*/
int main(int argc, char *argv[])
{
    // Convierte el argumento recibido a entero para definir el tamaño
    int n = atoi(argv[1]);
    // Reserva memoria dinámica para el arreglo
    int *A = malloc(sizeof(int) * n);
    
    // Verifica que la memoria se haya reservado correctamente
    if (A == NULL)
    {
        printf("\nError al reservar memoria para %d elementos\n", n);
        exit(EXIT_FAILURE);
    }

    // Lee los n números desde la entrada estándar
    for (int j = 0; j < n; j++)
    {
        scanf("%d", &A[j]);
    }

    // Llama al algoritmo de ordenamiento QuickSort indicando el inicio y el fin del arreglo
    QuickSort(A, 0, n - 1);

    // Imprime el arreglo ordenado
    printf("\nArreglo ordenado:\n");
    for (int j = 0; j < n; j++)
    {
        printf("[%d]", A[j]);
    }

    printf("\n");

    // Libera la memoria reservada (buena práctica, aunque falte en el original)
    free(A);

    return 0;
}

/*
Entrada:
    int A[] -> arreglo de números enteros
    int p   -> índice inicial a ordenar
    int r   -> índice final a ordenar
Descripción:
    Ordena los elementos del arreglo utilizando el
    algoritmo QuickSort. Es una función recursiva que 
    divide el arreglo en sublistas a partir de un pivote.
*/
void QuickSort(int A[], int p, int r){
    int j;
    // Condición base: verifica que la sublista tenga al menos dos elementos
    if (p < r)
    {
        // Obtiene la posición definitiva del pivote
        j = Pivot(A, p, r);
        // Ordena recursivamente la sublista izquierda (menores al pivote)
        QuickSort(A, p, j - 1);
        // Ordena recursivamente la sublista derecha (mayores al pivote)
        QuickSort(A, j + 1, r);
    }
}

/*
Entrada:
    int A[] -> arreglo de números enteros
    int p   -> índice inicial de la sublista
    int r   -> índice final de la sublista
Descripción:
    Selecciona un elemento como pivote (el primero de la sublista)
    y reubica los elementos: los menores o iguales al pivote
    quedan a su izquierda, y los mayores a su derecha.
*/
int Pivot(int A[], int p, int r){
    int piv = A[p];     // Se toma el primer elemento como pivote
    int i = p + 1;      // Índice que busca elementos mayores al pivote (de izquierda a derecha)
    int j = r;          // Índice que busca elementos menores al pivote (de derecha a izquierda)

    // Mientras los índices no se crucen
    while (i < j)
    {
        // Avanza 'i' mientras encuentre elementos menores o iguales al pivote
        while (A[i] <= piv && i <= r){
            i++;
        }
        
        // Retrocede 'j' mientras encuentre elementos mayores al pivote
        while (A[j] > piv && j >= p){
            j--;
        }

        // Si los índices no se han cruzado, se intercambian los elementos desubicados
        if (i < j)
        {
            Intercambio(A, i, j);
        }  
    }
    // Coloca el pivote en su posición final definitiva
    Intercambio(A, p, j);
    
    // Retorna la nueva posición del pivote
    return j;
}

/* Entrada:
    int A[] -> arreglo de números enteros
    int i   -> índice del primer elemento
    int j   -> índice del segundo elemento
Descripción:
    Intercambia de posición dos elementos dentro del arreglo.
*/
void Intercambio(int A[], int i, int j){
    int temp = A[j];    // Guarda temporalmente el valor de A[j]
    A[j] = A[i];        // Asigna a A[j] el valor de A[i]
    A[i] = temp;        // Asigna a A[i] el valor temporal guardado
}
