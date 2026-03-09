#include <stdio.h>
#include <stdlib.h>
#include "SortHeap.h"
//**************************************************
//Libreria necesaria para medir rendimiento en Linux
//#include "tiempo.h"
//**************************************************
int main(int argc, char *argv[])
{
//********************************************************
//Variables necesarias para poder medir el tiempo en Linux
//	double utime0, stime0, wtime0,utime1, stime1, wtime1;
//********************************************************
    int i;
    int n = atoi(argv[1]);
    int *A = malloc(sizeof(int) * n);
    if (A == NULL)
    {
        printf("\nError al reservar memoria para %d elementos\n", n);
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    Heap H;
    Initialize_Heap(&H, n);
    element e;
//******************************************************************	
//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
//uswtime(&utime0, &stime0, &wtime0);
//******************************************************************
    for (i = 0; i < n; i++)
    {
        e.number = A[i];
        Insert_Heap(&H, e);
    }
    for (i = 0; i < n; i++)
    {
        A[i] = Remove_Heap(&H).number;
    }
//******************************************************************	
//Evaluar los tiempos de ejecución 
//uswtime(&utime1, &stime1, &wtime1);
//******************************************************************
    Destroy_Heap(&H);
    free(A);
//***************************************************************************************************	
//Cálculo del tiempo de ejecución del programa
//	printf("\n");
//	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
//	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
//	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
//	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
//	printf("\n");
//***************************************************************************************************		
//***************************************************************************************************	
//Mostrar los tiempos en formato exponecial
//	printf("\n");
//	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
//	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
//	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
//	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
//	printf("\n");
//***************************************************************************************************	
}
