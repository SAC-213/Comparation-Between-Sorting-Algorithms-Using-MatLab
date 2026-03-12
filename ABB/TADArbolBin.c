/*TAD Arbol Binario de Búsqueda ABB, dirigido a ordenar un arreglode números.
Autor: Saul Ascencion Cruz
Fecha: 25 de Febrero del 2026
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADArbolBin.h"

/*Reserva el espacio necesario para crear el ABB*/
void Inicializar(arbolBinario *a)
{
  *a = NULL;
}

/*Libera la memoria necesaria para crear el ABB*/
void Destruir(arbolBinario *a)
{
  if (*a != NULL)
  {
    if ((*a)->hijoIzq != NULL)
    {
      Destruir(&(*a)->hijoIzq);
    }
    if ((*a)->hijoDer != NULL)
    {
      Destruir(&(*a)->hijoDer);
    }
    free(*a);
    *a = NULL;
  }
}

/*Regresa el nodo raíz del subárbol*/
posicion Raiz(arbolBinario *a)
{
  return *a;
}

/*Regresa el hijo derecho del nodo actual*/
posicion HijoDerecho(arbolBinario *a, posicion p)
{
  posicion regreso = NULL;
  if (!NodoNulo(&(*a), p))
  {
    regreso = p->hijoDer;
  }
  else
  {
    printf("ERROR: La posicion dada no es valida (Hijo Derecho)");
  }
  return regreso;
}

/*Regresa el hijo izquierdo del nodo actual*/
posicion HijoIzquierdo(arbolBinario *a, posicion p)
{
  posicion regreso = NULL;
  if (!NodoNulo(&(*a), p))
  {
    regreso = p->hijoIzq;
  }
  else
  {
    printf("ERROR: La posicion dad no es valida (Hijo Izquierdo)");
  }
  return regreso;
}

/*Verifica si un nodo está vacío. Si el nodo está vacío regresa FALSE, por el contrario si el nodo NO
está vacío regresa TRUE*/
boolean Vacio(arbolBinario *a)
{
  return ((*a) == NULL);
}

/*Verifica si el nodo dado pertenece al ABB*/
boolean NodoNulo(arbolBinario *a, posicion p)
{
  boolean respuesta = TRUE;
  if (!(*a == NULL || p == NULL))
  {
    if (!(*a == p))
    {
      if ((*a)->hijoIzq != NULL)
        respuesta = NodoNulo(&((*a)->hijoIzq), p);
      if ((*a)->hijoDer != NULL && respuesta == TRUE)
        respuesta = NodoNulo(&((*a)->hijoDer), p);
    }
    else
    {
      respuesta = FALSE;
    }
  }
  return respuesta;
}

/*Regresa el elemento del nodo dado*/
elemento LeerNodo(arbolBinario *a, posicion p)
{
  if (!NodoNulo(&(*a), p))
  {
    return p->valor;
  }
  else
  {
    printf("ERROR: la posicion no es valida (Leer Nodo)");
    exit(1);
  }
}

/*Inserta un elemento en un árbol siguiendo las reglas del ABB*/
void Insert(arbolBinario *a, int number)
{
  if (Vacio(&(*a)))
  {
    *a = malloc(sizeof(nodo));
    if (*a == NULL)
    {
      printf("No se pudo reservar memoria");
      exit(1);
    }
    (*a)->hijoIzq = NULL;
    (*a)->hijoDer = NULL;
    (*a)->valor.numero = number;
  }
  else if (number < (*a)->valor.numero)
  {
    Insert(&((*a)->hijoIzq), number);
    return;
  }
  else if (number > (*a)->valor.numero)
  {
    Insert(&((*a)->hijoDer), number);
    return;
  }
}

/*Recorre el ABB y sobreescribe el arreglo dado*/
void InOrden(arbolBinario *a, posicion p, int array[], int *i)
{
  if (p == NULL)
    return;

  InOrden(a, HijoIzquierdo(a, p), array, i);
  array[*(i)] = LeerNodo(a, p).numero;
  (*i)++;
  InOrden(a, HijoDerecho(a, p), array, i);
}