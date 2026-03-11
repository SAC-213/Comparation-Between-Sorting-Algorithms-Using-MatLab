#!/bin/bash

gcc -c tiempo.c -o tiempo.o
gcc tiempo.o selectionsort_time.c -o selectionsort_time

for N in { 1000 2000 3000 4000 5000 8000 10000 50000 100000 150000 200000 300000 400000 500000 600000 700000 800000 900000 1000000 1500000 2000000 }
do
    echo "Corriendo Merge-Sort con $N datos" 
    ./selectionsort_time $N < numeros10millones.txt >>selectionsort_time.txt
    echo "Terminado Merge-Sort con $N datos" 
done
