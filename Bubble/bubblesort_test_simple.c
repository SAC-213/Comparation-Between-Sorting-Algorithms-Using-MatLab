#include <stdio.h>
#include <stdlib.h>
/*
---------------------------------------------------------
Programa: Ordenamiento Burbuja (Bubble Sort)
Descripción:
Este programa lee n números enteros desde la entrada
estándar, los almacena en un arreglo dinámico y los
ordena utilizando el algoritmo de la burbuja.

El algoritmo compara elementos adyacentes e intercambia
sus posiciones si están en el orden incorrecto.
Este proceso se repite hasta que el arreglo queda ordenado.
---------------------------------------------------------
*/
void bubble (int A[],int n);
// Convierte el argumento de entrada (n) a entero
int main(int argc, char const *argv[]){
	// Convierte el argumento de entrada (n) a entero
    int n = atoi(argv[1]);
    int *A;

    //Apartar memoria para n números  enteros
	A=malloc(n*sizeof(int));
	// Verifica si la memoria se reservó correctamente
	if(A==NULL)
	{
		printf("\nError al intentar reservar memoria para %d elementos\n",n);		
		exit(1);
	}	
	// Lectura de los n elementos desde la entrada estándar
    for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	
	//Llamar al algoritmo
    
	bubble(A,n);
	
	// Imprime el arreglo ordenado
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",A[i]);
    }

    return 0;
}
/*
---------------------------------------------------------
Entrada:
    int A[] -> arreglo de enteros
    int n   -> tamaño del arreglo
Descripción:
    Ordena el arreglo utilizando el algoritmo de
    la burbuja (Bubble Sort).

    En cada iteración:
    - Compara elementos adyacentes
    - Los intercambia si están en orden incorrecto
    - Repite el proceso hasta ordenar completamente
---------------------------------------------------------
*/
void bubble (int A[],int n){
    int i,j,aux;
	// Recorre el arreglo múltiples veces
    for(i=0;i<=n-2;i++){
		// Compara elementos adyacentes
        for(j=0;j<=n-2;j++){
			// Si están en orden incorrecto, se intercambian
            if(A[j] > A[j+1]){
                aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;
            }
        }
    }
}
