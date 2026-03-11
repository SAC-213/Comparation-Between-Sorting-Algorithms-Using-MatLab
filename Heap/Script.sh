#!/bin/bash

gcc -c tiempo.c -o tiempo.o
gcc -c SortHeap.c -o SortHeap.o
gcc tiempo.o SortHeap.o Heap_TIME.c -o HEAP_TIME

for N in { 1000 2000 3000 4000 5000 8000 10000 50000 100000 150000 200000 300000 400000 500000 600000 700000 800000 900000 1000000 1500000 2000000 }
do
    echo "Corriendo Heap-Sort con $N datos" 
    ./HEAP_TIME $N <numeros10millones.txt >>HEAP_TIME.txt
    echo "Terminado Heap-Sort con $N datos" 
done
