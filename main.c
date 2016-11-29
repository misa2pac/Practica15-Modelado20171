#include "main.h"
// No hagas #include aquí, hazlos en main.h

int main(int argc, char const *argv[])
{
    // Verifica si hay al menos de 3 parametros
    // sino entonces se imprimen las instrucciones
    // y se para la ejecución del programa
    if (argc < 3)
    {
        imprime_instrucciones();
        return 0;
    }
	int i = 0;
	printf("Nombre del archivo		Palabra mas repetida		Numero de repeticiones\n");
	FILE *documento;
	FILE *salida = fopen(argv[argc-1], "w");
	for(i = 1;i<argc-1; i++){
		Lista letters = crea_lista();
		documento = fopen(argv[i],"a+");
		guardar(letters,documento);
		Caracteres *rep = buscaPalabra(letters);
		printf("%s", argv[i]);
		printf("						 %s",rep->letra);
		printf("						 %d\n",rep->num_palabras);
		}
		printf("\nSe guardo el resultado en el archivo %s\n", argv[argc-1]);
		fprintf(salida,"Nombre del archivo		Palabra mas repetida		Numero de repeticiones\n");
	for(i = 1;i<argc-1; i++){
		Lista letters = crea_lista();
		documento = fopen(argv[i],"r");
		guardar(letters,documento);
		Caracteres *rep = buscaPalabra(letters);
		fprintf(salida,"%s", argv[i]);
		fprintf(salida,"						 %s",rep->letra);
		fprintf(salida,"						 %d\n",rep->num_palabras);
		}
		fclose(salida);
    return 0;
}

/* ------ Aquí va la implementación de tus funciones ------ */

/*Funcion principal*/
/*void inciar(){
	int i = 0;
	printf("Nombre del archivo		Palabra mas repetida		Numero de repeticiones\n");
	FILE *documento;
	FILE *salida = fopen(argv[argc-1], "w");
	for(i = 1;i<argc-1; i++){
		Lista letters = crea_lista();
		documento = fopen(argv[i],"a+");
		guardar(letters,documento);
		Caracteres *rep = buscaPalabra(letters);
		printf("%s", argc[i]);
		printf("						 %s",rep->letra);
		printf("						 %d\n",rep->num_palabras);
		}
		printf("\nSe guardo el resultado en el archivo %s\n", argv[argc-1]);
		fprintf(salida,"Nombre del archivo		Palabra mas repetida		Numero de repeticiones\n");
	for(i = 1;i<argc-1; i++){
		Lista letters = crea_lista();
		documento = fopen(argv[i],"r");
		guardar(letters,documento);
		Caracteres *rep = buscaPalabra(letters);
		fprintf(salida,"%s", argc[i]);
		fprintf(salida,"						 %s",rep->letra);
		fprintf(salida,"						 %d\n",rep->num_palabras);
		}
		fclose(salida);
	}*/
/*Imprime los elementos de la lista como enteros*/
void imprime_lista_int(Lista lista){
	int i = 0;
	Elemento *aux = *lista;
	for(i = 0; i < longitud(lista); i++){
		Caracteres *letras = aux->caracter;
		printf("La palabra en la seccion [%d] es: %s y aparece %d veces \n", i,letras->letra,letras->num_palabras); 
		aux = aux->siguiente;
		}
	}

/*Crea una lista vacía*/
Lista crea_lista(){
	Lista lista = NULL;
	lista = malloc(sizeof(Elemento));
	return lista;
	}

/*Inserta un elemento en la lista y se regresa el nuevo tamaño de la lista*/
void inserta_elemento(Lista lista, Caracteres *caracter){
	int i = 0;
	Elemento *aux = *lista;
	while(aux != NULL){
		if(strcmp(aux->caracter->letra, caracter->letra) == 0){
			aux->caracter->num_palabras++;
			i = 1;
			break;
			}
			aux=aux->siguiente;
		}
		if(!i){
			Elemento *aux2 = malloc(sizeof(Elemento));
			aux2->siguiente = *lista;
			aux2->caracter = caracter;
			*lista = aux2;
			}
	}

/*Libera la memoria que se uso*/
void libera_memoria(Lista lista, int tam){
	}

/*Busca las palabras mas repetidas en un documento*/
Caracteres *buscaPalabra(Lista lista){
	Elemento *aux = *lista;
	int num = 0;
	Caracteres *letra;
	while(aux != NULL){
		int total = aux->caracter->num_palabras;
		if(total >= num){
			letra = aux->caracter;
			//num = letra->caracter;
			num = total;
			}
			aux = aux->siguiente;
		}
		return letra;
	}

/*Guarda el documento con las palabras mas repetidas*/
void guardar(Lista lista, FILE *documento){
	char buffer[200];
	while(fgets(buffer,200,documento)){
		char *token = NULL;
		token = strtok(buffer," ,.-\n");
		while(token != NULL){
			Caracteres *Arreglo = malloc(sizeof(Caracteres));
			Arreglo->num_palabras = 1;
			Arreglo->letra = strndup(token,200);
			inserta_elemento(lista,Arreglo);
			token = strtok(NULL," ,.-\n");
			}
		}
	}

/*Imprime las instrucciones de uso del programa*/
void imprime_instrucciones(){
	printf("Error: El formato de entrada es incorrecto");
	printf("Uso: <nombre_programa> <archivo> [<archivo> [<archivo> ...]] <archivo>");
	}

/*Regresa el número de elementos en la lista*/
size_t longitud(Lista lista){
	Elemento *aux = *lista;
	size_t n;
	n = 0;
	while(aux !=  NULL){
		n++;
		aux = aux->siguiente;
	}
	return n;
	}
