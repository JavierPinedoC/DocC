#include <stdio.h>
#include <stdlib.h>

void menu(){
printf("\n				Elija una de las siguientes opciones: \n\n");
printf("|		1. Crear Lista				2. Insertar Nodo Cabeza 		\n");
printf("|	  3. Insertar Nodo Cola			    4. Insertar Nodo en una posicion 	\n");
printf("|		5. Buscar Nodo					6. Modificar				\n");
printf("|	 7. Eliminar Nodo 	 8. Desplegar Lista 			 9. Finalizar... \n");
}

typedef struct nodo{
	int dato;
	struct nodo *siguiente;
}nodo;

nodo *primero = NULL;
nodo *ultimo  = NULL;
nodo *aux     = NULL;

void agregarNodoCola();
void desplegarLista();
void buscarNodo();
void modificarNodo();
void eliminarNodo();
void crearLista();
void agregarNodoCabeza();
void agregarNodoPosicion();

int main(){
	int opcionmenu = 0;
	do
	{
		menu();
		scanf("%i", &opcionmenu);
		switch(opcionmenu){
			case 1:
				printf("\n\n Crear Lista\n\n");
				crearLista();
				break;
			case 2:
				printf("\n\n Insertar Nodo cabeza\n\n");
				agregarNodoCabeza();
				break;
			case 3:
				printf("\n\n Insertar Nodo cabeza Cola\n\n");
				agregarNodoCola();
				break;
			case 4:
				printf("\n\n Agregar Nodo en una posicion de la lista\n\n");
				agregarNodoPosicion();
				break;
			case 5:
				printf("\n\n Buscar Nodo en la listan\n");
				buscarNodo();
				break;
			case 6:
				printf("\n\n Modificar un Nodo\n\n");
				modificarNodo();
				break;
			case 7: 
				printf("\n\n Eliminar Nodo\n\n");
				eliminarNodo();
				break;
			case 8:
				printf("\n\n Desplegar Lista de Nodos \n\n");
				desplegarLista();
				break;
			case 9:
				printf("\n\n Programa finalizado...\n\n");
				break;			
			default:
				printf("\n\n Opcion no Valida \n\n");
		}
	} while (opcionmenu != 9);
	return 0;
}

void crearLista(){
	int crealis;
	printf("\n\n Cuantos datos quieres agregar: ");
	scanf("%i",&crealis);
	for (int i = 0; i < crealis; ++i){
		nodo *nuevo = (nodo*)malloc(sizeof(nodo));
		printf("\nIngrese el dato que contendra el nodo: \n");
		scanf("%d",&nuevo->dato);
		if (primero == NULL){
			primero             = nuevo;
			primero ->siguiente = NULL;
			ultimo              = nuevo;
		}
		else{
			ultimo->siguiente = nuevo;
			nuevo->siguiente  = NULL;
			ultimo            = nuevo;
		}
	printf("Nodo ingresado correctamente\n");
	}
}

void agregarNodoPosicion(){
	nodo *actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingresa el dato del nodo a buscar: \n");
	scanf("%d", &nodoBuscado);

	nodo *nuevo = (nodo*)malloc(sizeof(nodo));
	printf("Ingrese el dato que contendra el nodo: \n");
	scanf("%d",&nuevo->dato);

	if (primero != NULL){
		while (actual != NULL && encontrado != 1){
			if (actual->dato == nodoBuscado){
				printf("\n El nodo con el dato ( %d ) Encontrado", nodoBuscado );				
				aux              = actual;
				actual           = actual->siguiente;
				aux->siguiente   = nuevo;
				nuevo->siguiente = actual;
				encontrado       = 1;
			}
			actual = actual->siguiente;	
		}
		if (encontrado == 0){
			printf("\n Nodo no encontrado");
		}
	}
	else{
		printf("La lista esta vacia\n");
	}
}

void agregarNodoCola(){
	nodo *nuevo = (nodo*)malloc(sizeof(nodo));
	printf("Ingrese el dato que contendra el nodo al final: \n");
	scanf("%d",&nuevo->dato);
	if (primero == NULL){
		primero             = nuevo;
		primero ->siguiente = NULL;
		ultimo              = nuevo;
	}
	else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente  = NULL;
		ultimo            = nuevo;
	}
	printf("\n Nodo ingresado correctamente\n");
}
void agregarNodoCabeza(){
	nodo *nuevo = (nodo*)malloc(sizeof(nodo));
	printf("Ingrese el dato que contendra el nodo al inicio: \n");
	scanf("%d",&nuevo->dato);
	if (primero == NULL){
		primero             = nuevo;
		primero ->siguiente = NULL;
		ultimo              = nuevo;
	}
	else{
		nuevo->siguiente = primero;
		primero          = nuevo;
	}
	printf("Nodo ingresado correctamente\n");
}

void buscarNodo(){
nodo *actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingresa el dato del nodo a buscar: \n");
	scanf("%d", &nodoBuscado);

	if (primero != NULL){
		while (actual != NULL && encontrado != 1){
			if (actual->dato == nodoBuscado){
				printf("\n El nodo con el dato ( %d ) Encontrado", nodoBuscado );
				encontrado = 1;
			}
			actual = actual->siguiente;	
		}
		if (encontrado == 0){
			printf("\n Nodo no encontrado");
		}
	}
	else{
		printf("La lista esta vacia\n");
	}	
}

void eliminarNodo(){
	nodo *actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	nodo *anterior = (nodo*) malloc(sizeof(nodo));
	anterior = NULL;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingresa el dato del nodo a buscar para eliminar: \n");
	scanf("%d", &nodoBuscado);
	if (primero != NULL){
		while (actual != NULL && encontrado != 1){
			if (actual->dato == nodoBuscado){
				if (actual == primero){
					primero = primero->siguiente;
				}
				else if(actual == ultimo){
					anterior->siguiente = NULL;
					ultimo = anterior;
				}
				else{
					anterior->siguiente=actual->siguiente;
				}
				printf("\n Nodo eliminado con exito\n");
				encontrado = 1;
			}
			anterior = actual;
			actual   = actual->siguiente;	
		}
		if (encontrado == 0){
			printf("\n Nodo no encontrado\n");
		}
		else{
			free(anterior);
		}
	}
	else{
		printf("La lista esta vacia\n");
	}
}

void modificarNodo(){
	nodo *actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el dato del nodo a buscar para modificar: \n");
	scanf("%d", &nodoBuscado);

	if (primero != NULL){
		while (actual != NULL && encontrado != 1){
			if (actual->dato == nodoBuscado){
				printf("\n El nodo con el dato ( %d ) Encontrado\n", nodoBuscado );
				printf("\n Ingrese el nuevo dato del nodo: \n");
				scanf("%d", &actual->dato);
				printf("\n Nodo modificado con exito \n\n");
				encontrado = 1;
			}
			actual = actual->siguiente;	
		}
		if (encontrado == 0){
			printf("\n Nodo no encontrado\n");
		}
	}
	else{
		printf("La lista esta vacia\n");
	}	
}
void desplegarLista(){
	nodo *actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	if (primero != NULL){
		while (actual != NULL){
			printf("\n %d", actual->dato );
			actual = actual->siguiente;	
		}
	}
	else{
		printf("La lista esta vacia\n");
	}
}
