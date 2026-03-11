#!/bin/bash

gcc -c tiempo.c -o tiempo.o
gcc tiempo.o bubblesort_time_op2.c -o bubblesort_time_op2

for N in { 1000 2000 3000 4000 5000 8000 10000 50000 100000 150000 200000 300000 400000 500000 600000 700000 800000 900000 1000000 1500000 2000000 }
do
    echo "Corriendo Bubble Sort Optimizado 1 con $N datos" 
    ./bubblesort_time_op2 n < numeros10millones.txt >>bubblesort_time_op2.txt
    echo "Terminado Bubble Sort Optimizado 1 con $N datos" 
done
