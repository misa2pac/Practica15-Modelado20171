#ifndef MAIN_H // Guarda para evitar include circulares
#define MAIN_H
/* ------ Se hacen todos los includes necesarios ------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* ------ Definición de tus estructuras ------ */

// Estructura para los caracteres.
typedef struct caracteres{
	int num_palabras;
	char *letra;
	}Caracteres;

// Estructura para manejar las palabras como listas, se hace
// como en la practica anterior.
struct elemento{
	struct elemento *siguiente;
	Caracteres *caracter;
	};

// Les ponemos los alias para tener control sobre ellas.
typedef struct elemento Elemento;
typedef Elemento** Lista;

/* ------ Definición de tus funciones ------ */

/*Imprime los elementos de la lista como enteros*/
void imprime_lista_int(Lista lista);

/*Crea una lista vacía*/
Lista crea_lista();

/*Inserta un elemento en la lista y se regresa el nuevo tamaño de la lista*/
void inserta_elemento(Lista lista, Caracteres *caracter);

/*Libera la memoria que se uso*/
void libera_memoria(Lista lista, int tam);

/*Busca las palabras mas repetidas en un documento*/
Caracteres *buscaPalabra(Lista lista);

/*Guarda el documento con las palabras mas repetidas*/
void guardar(Lista lista, FILE *documento);

/*Imprime las instrucciones de uso del programa*/
void imprime_instrucciones();

/*Regresa el número de elementos en la lista*/
size_t longitud(Lista lista);

/*Funcion principal*/
void inciar();
#endif //MAIN_H
