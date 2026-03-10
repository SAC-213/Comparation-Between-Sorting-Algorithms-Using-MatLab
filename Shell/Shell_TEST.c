#include <stdio.h>
#include <stdlib.h>

/*
Entrada:
    int *A  -> arreglo de números enteros
    int n   -> tamaño del arreglo
Descripción:
    Ordena los elementos del arreglo utilizando el
    algoritmo ShellSort. Se comienza comparando
    elementos separados por un gap grande y se
    reduce progresivamente hasta llegar a 1.
*/
void shellsort(int *A, int n) {
    int gap = n / 2;	// Distancia inicial entre elementos a comparar
	// Mientras el gap sea mayor o igual a 1
    while (gap >= 1) {
        int cambios;	// Variable para verificar si hubo intercambios

        do {
            cambios = 0;
            int i;
			// Recorre el arreglo comparando elementos separados por gap
            for (i = gap; i < n; i++) {
				// Si el elemento anterior es mayor, se intercambian
                if (A[i-gap] > A[i]) {
                    int temp = A[i];
                    A[i] = A[i-gap];
                    A[i-gap] = temp;
                    cambios++;	// Se registra que hubo un cambio
                }
            }

        } while (cambios != 0);		// Se repite mientras existan cambios
		// Se reduce el gap a la mitad
        gap = gap / 2;
    }
}

/* Verificar si está ordenado */
int esta_ordenado(int *A, int n){
	int i;
	// Recorre el arreglo comparando cada elemento con el anterior
    for(i = 1; i < n; i++)
        if(A[i-1] > A[i])
            return 0;	 // Si encuentra un elemento mayor antes que otro, no está ordenado
    return 1;	// Si no encuentra errores, el arreglo está ordenado
}
/*
Función principal del programa
*/
int main(int argc, char *argv[]) {
	 // Verifica que el usuario haya ingresado el número correcto de argumentos
    if(argc != 2){
        printf("Uso: %s n\n", argv[0]);
        return 1;
    }
	// Convierte el argumento recibido a entero
    int n = atoi(argv[1]);
	// Reserva memoria dinámica para el arreglo
    int *A = malloc(n*sizeof(int));

    int i;
	// Lee los n números desde la entrada estándar
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
	// Llama al algoritmo de ordenamiento ShellSort
    shellsort(A,n);
	// Imprime el arreglo ordenado
    printf("\nArreglo ordenado:\n");
	for (int j = 0; j < n; j++)
	{
		printf("[%d]", A[j]);
	}
	// Libera la memoria reservada
	free(A);
	printf("\n");



    return 0;
}

