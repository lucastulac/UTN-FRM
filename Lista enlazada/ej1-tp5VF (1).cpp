/*Basándose en su código fuente de su ejercicio 4 del TP4 de archivos, va a trabajar con
listas enlazadas para una base de datos de imágenes.
Puede tener pre-cargada algunos nodos a su lista. La lista debe ser simplemente
enlazada.
Debe crear funciones que permitan al usuario:
? añadir un nodo a la lista,
? eliminarlo de la lista,
? guardar la lista completa en un archivo ( modo append y binario),
? recuperar/leer esa lista del archivo,
? realizar búsquedas: por cualquiera de los miembros de la estructura imagen (tipo
archivo, nombre, etc). En el caso del tamaño del archivo, especificar si se busca
mayor a X tamaño (ingresado por teclado) o menor a X o un valor exacto de
tamaño.
? Mostrar la lista para visualizar todos sus elementos.
? Mostrar la lista ordenada alfabéticamente según el nombre del archivo.
Comente su código fuente para aclarar la funcionalidad de su
	programa.
	Recuerde que puede visualizar los archivos binarios usando diversas herramientas, ver
	apunte unidad Archivos, pdf “¿Cómo visualizamos los archivos binarios?”*/

#include <iostream>
#include <string.h> //<>
#define TAM 20
using namespace std;

struct nodoIM{
	int codigo;
	char nombre[TAM];
	char extension[TAM];
	int tamaniobytes;
	float precio;
	struct nodoIM *sig;
};


struct nodoIM *agregarnuevonodo(struct nodoIM*);
struct nodoIM *eliminarnodo(struct nodoIM*);
void cargararchivo(struct nodoIM*);
struct nodoIM *leerarchivo(struct nodoIM*);
void mostrarlista(struct nodoIM*);
void realizarbusqueda(struct nodoIM*);
void mostrarlistaordenada(struct nodoIM*);

int main(int argc, char *argv[]) {
	
	struct nodoIM *PRIMERO,*ULTIMO;
	PRIMERO=(struct nodoIM*)malloc(sizeof(struct nodoIM));
	ULTIMO=(struct nodoIM*)malloc(sizeof(struct nodoIM));
	
	PRIMERO->codigo=3423;
	strcpy(PRIMERO->nombre,"Holanda");
	strcpy(PRIMERO->extension,"png");		//precargamos el primer nodo
	PRIMERO->tamaniobytes=230;
	PRIMERO->precio=23.0;
	PRIMERO->sig=ULTIMO;
	
	ULTIMO->codigo=3424;
	strcpy(ULTIMO->nombre,"Noruega");
	strcpy(ULTIMO->extension,"png");		//precargamos el ultimo nodo
	ULTIMO->tamaniobytes=260;
	ULTIMO->precio=67.0;
	ULTIMO->sig=NULL;
	
	int opcion;
		
		do{
			printf("\n\nMenu de opciones");
			printf("\n1. Agregar nuevo nodo/imagen (AL FINAL)");
			printf("\n2. Eliminar un nodo/imagen (LA PRIMERA)");
			printf("\n3. Cargar lista en un archivo binario");
			printf("\n4. Leer archivo binario");
			printf("\n5. Realizar busqueda por miembro");
			printf("\n6. Mostrar lista completa");
			printf("\n7. Mostrar lista ordenada alfabeticamente");
			printf("\n8. Salir\n");
			scanf("%d",&opcion);
			switch(opcion){
				case 1:
					ULTIMO=agregarnuevonodo(ULTIMO);
					break;
				case 2:
					PRIMERO=eliminarnodo(PRIMERO);
					break;
				case 3:
					cargararchivo(PRIMERO);
					break;
				case 4:
					ULTIMO=leerarchivo(ULTIMO);
					break;
				case 5:
					realizarbusqueda(PRIMERO);
					break;
				case 6:
					mostrarlista(PRIMERO);
					break;
				case 7:
					mostrarlistaordenada(PRIMERO);
					break;
				default:
					printf("\nEsa opcion no es correcta");
			
			}
		} while(opcion!=8);
	
	return 0;
}

struct nodoIM *agregarnuevonodo(struct nodoIM *actual){
	
	struct nodoIM *nuevo;
	nuevo=(struct nodoIM*)malloc(sizeof(struct nodoIM));		//reservamos memoria para el nodo nuevo
	actual->sig=nuevo; //lo mismo pero al revez
	nuevo->sig=NULL;	//le asignamos NULL al sig del ultimo nodo
	
	printf("\nIngrese el codigo de la nueva imagen: ");
	scanf("%d",&nuevo->codigo);
	printf("\nIngrese el nombre de la nueva imagen: ");
	scanf("%s", nuevo->nombre);
	printf("\nIngrese la extension de la nueva imagen: ");
	scanf("%s", nuevo->extension);
	printf("\nIngrese el peso en bytes de la nueva imagen: ");
	scanf("%d",&nuevo->tamaniobytes);
	printf("\nIngrese el precio de la nueva imagen: ");
	scanf("%f",&nuevo->precio);
	nuevo->sig=NULL;
	printf("\nImagen/nodo cargado al final con éxito");
	
return nuevo;
}
	
struct nodoIM *eliminarnodo(struct nodoIM *PRIMERO){
	
	PRIMERO=PRIMERO->sig;
	printf("\nPrimer imagen/nodo eliminado con éxito");

return PRIMERO;
}
	
void cargararchivo(struct nodoIM *PRIMERO){
	FILE *fp;
	fp=fopen("Listas.bin","ab");
	struct nodoIM *actual;
	actual=PRIMERO;
	if(fp!=NULL){
		printf("\nLa apertura del archivo fue exitosa");  
		
		while(actual!=NULL){
		fwrite(actual, sizeof(struct nodoIM), 1, fp);
		
		/*printf("\n\n\nEsto se esta imprimiendo");
		printf("\nCodigo: %d",actual->codigo);					//Corroborar que se esta imprimiendo en el archivo
		printf("\nNombre: %s",actual->nombre);
		printf("\nExtension: %s",actual->extension);
		printf("\nTamaño en bytes: %d",actual->tamaniobytes);
		printf("\nPrecio: %f",actual->precio);*/
		
		actual=actual->sig;
		}
		if(actual==NULL){
			printf("\nSe realizó con exito la escritura del archivo");
		}
		
	}
	else{
		printf("\nFalló la apertura del archivo");
	}
	fclose(fp);
	
}
	
struct nodoIM* leerarchivo(struct nodoIM* ULTIMO) {
		FILE *archivolectura;		//ultraedit
		archivolectura = fopen("Listas.bin", "rb");
		
		if (archivolectura != NULL) {
			struct nodoIM *temp;
			temp = (struct nodoIM*)malloc(sizeof(struct nodoIM));
			
			while (fread(temp, sizeof(struct nodoIM), 1, archivolectura) == 1) {
				
				struct nodoIM *nuevo;
				nuevo = (struct nodoIM*)malloc(sizeof(struct nodoIM));
				ULTIMO->sig = temp;
				temp->sig = nuevo;
				/*printf("\n\n\nEsto se esta leyendo");
				printf("\nCodigo: %d",temp->codigo);
				printf("\nNombre: %s",temp->nombre);
				printf("\nExtension: %s",temp->extension);				//Corroborar que se está leyendo del archivo
				printf("\nTamaño en bytes: %d",temp->tamaniobytes);
				printf("\nPrecio: %f",temp->precio);*/
				
				temp = nuevo;
			}
			
			fclose(archivolectura);
		} else {
			printf("Falló la apertura del archivo.\n");
		}
	return ULTIMO;
	}
void mostrarlista(struct nodoIM *actual){
	
	int cont=1;
	
	while(actual!=NULL){
		
		printf("\n\n\nLista numero %d\n",cont);
		printf("\nCodigo: %d",actual->codigo);
		printf("\nNombre: %s",actual->nombre);
		printf("\nExtension: %s",actual->extension);
		printf("\nTamaño en bytes: %d",actual->tamaniobytes);
		printf("\nPrecio: %f",actual->precio);
		cont++;
		actual=actual->sig;
		
	}
}

void realizarbusqueda(struct nodoIM *actual){
	
	int opcion=0;
	
	struct nodoIM *NodoPatron;

	NodoPatron=actual;
	
	do{
	printf("\n\n\nElija el parametro a realizar la busqueda:");
	printf("\n1. Codigo");
	printf("\n2. Nombre");
	printf("\n3. Extension");
	printf("\n4. Tamaño en bytes");
	printf("\n5. Precio");
	printf("\n6. Salir\n");
	scanf("%d",&opcion);
		
		switch(opcion){
			
			case 1:
				int codigoP;
				printf("\nIngrese el codigo a buscar: ");
				scanf("%i",&codigoP);
				
				actual=NodoPatron;
				
				while(actual!=NULL){
					if(actual->codigo==codigoP){
						printf("\nSe encontró una coincidencia\n\n");
						printf("\nCodigo: %d",actual->codigo);
						printf("\nNombre: %s",actual->nombre);
						printf("\nExtension: %s",actual->extension);
						printf("\nTamaño en bytes: %d",actual->tamaniobytes);
						printf("\nPrecio: %f",actual->precio);
					}
					actual=actual->sig;
				}
				break;
				
			case 2:
				char nombreP[TAM];
				printf("\nIngrese el nombre a buscar: ");
				scanf("%s",nombreP);
				
				actual=NodoPatron;
				
				while(actual!=NULL){
					if(strcmp(nombreP,actual->nombre)==0){
						printf("\nSe encontró una coincidencia\n\n");
						printf("\nCodigo: %d",actual->codigo);
						printf("\nNombre: %s",actual->nombre);
						printf("\nExtension: %s",actual->extension);
						printf("\nTamaño en bytes: %d",actual->tamaniobytes);
						printf("\nPrecio: %f",actual->precio);
					}
					actual=actual->sig;
				}
				break;
			
			case 3:
				char extensionP[TAM];
				printf("\nIngrese la extension a buscar: ");
				scanf("%s",extensionP);
			
				actual=NodoPatron;
				
				while(actual!=NULL){
					if(strcmp(extensionP,actual->extension)==0){
						printf("\nSe encontró una coincidencia\n\n");
						printf("\nCodigo: %d",actual->codigo);
						printf("\nNombre: %s",actual->nombre);
						printf("\nExtension: %s",actual->extension);
						printf("\nTamaño en bytes: %d",actual->tamaniobytes);
						printf("\nPrecio: %f",actual->precio);
					}	
						 actual=actual->sig;
				}
				break;
				
			case 4:
				/*int tamaniobytesP;
				printf("\nIngrese el tamaño en bytes a buscar: ");
				scanf("%i",tamaniobytesP);
			
				actual=NodoPatron;
				
				while(actual!=NULL){
					if(actual->tamaniobytes==tamaniobytesP){
						printf("\nSe encontró una coincidencia\n\n");
						printf("\nCodigo: %d",actual->codigo);
						printf("\nNombre: %s",actual->nombre);
						printf("\nExtension: %s",actual->extension);
						printf("\nTamaño en bytes: %d",actual->tamaniobytes);
						printf("\nPrecio: %f",actual->precio);
					}
					actual=actual->sig;
				}*/
				printf("\n¿Desea buscar por un rango o por valor especifico?\n1.Rango\n2.Valor especifico");
				int desea;
				scanf("%d",&desea);
				switch(desea){
					
					case 2:
						int tamaniobytesP;
						printf("\nIngrese el tamaño en bytes a buscar: \n");
						scanf("%i",tamaniobytesP);
						
						actual=NodoPatron;
						
						while(actual!=NULL){
							if(actual->tamaniobytes==tamaniobytesP){
								printf("\nSe encontró una coincidencia\n\n");
								printf("\nCodigo: %d",actual->codigo);
								printf("\nNombre: %s",actual->nombre);
								printf("\nExtension: %s",actual->extension);
								printf("\nTamaño en bytes: %d",actual->tamaniobytes);
								printf("\nPrecio: %f",actual->precio);
							}
							actual=actual->sig;
						}
						break;
						
					case 1:
						printf("\n1.Mayor a\n2.Menor a\n");
						int desicion;
						scanf("%d",&desicion);
							if(desicion==1){
								
								int tamaniobytesPP;
								printf("\nBuscar mayor a : \n");
								scanf("%i",tamaniobytesPP);
								
								actual=NodoPatron;
								
								while(actual!=NULL){
									if(actual->tamaniobytes>tamaniobytesPP){
										printf("\n\nSe encontró una coincidencia\n\n");
										printf("\nCodigo: %d",actual->codigo);
										printf("\nNombre: %s",actual->nombre);
										printf("\nExtension: %s",actual->extension);
										printf("\nTamaño en bytes: %d",actual->tamaniobytes);
										printf("\nPrecio: %f",actual->precio);
									}
									actual=actual->sig;
								}
								
							}else{
								printf("\nOpcion no valida");
							}
							if(desicion==2){
								
								int tamaniobytesPPP;
								printf("\nBuscar menor a : \n");
								scanf("%i",tamaniobytesPPP);
								
								actual=NodoPatron;
								
								while(actual!=NULL){
									if(actual->tamaniobytes<tamaniobytesPPP){
										printf("\n\nSe encontró una coincidencia\n\n");
										printf("\nCodigo: %d",actual->codigo);
										printf("\nNombre: %s",actual->nombre);
										printf("\nExtension: %s",actual->extension);
										printf("\nTamaño en bytes: %d",actual->tamaniobytes);
										printf("\nPrecio: %f",actual->precio);
									}
									actual=actual->sig;
								}
								
							}else{
								printf("\nOpcion no valida");
							}
				}
				break;

			case 5:
				int precioP;
				printf("\nIngrese el precio a buscar: ");
				scanf("%i",precioP);
			
				actual=NodoPatron;
			
				while(actual!=NULL){
					if(actual->precio==precioP){
						printf("\nSe encontró una coincidencia\n\n");
						printf("\nCodigo: %d",actual->codigo);
						printf("\nNombre: %s",actual->nombre);
						printf("\nExtension: %s",actual->extension);
						printf("\nTamaño en bytes: %d",actual->tamaniobytes);
						printf("\nPrecio: %f",actual->precio);
					}
					actual=actual->sig;
				}
				break;
				
			default:
				printf("\nOpcion invalida");
		}
	}while(opcion!=6);
}

void mostrarlistaordenada(struct nodoIM *actual){
	
	struct nodoIM *actual_i,*actual_j,*temp;
	
	actual_i=actual;
	while(actual_i!=NULL){
		
		actual_j=actual_i->sig;
		printf("\nO a este?");
		while(actual_j!=NULL){
			printf("\nY a este?");
			printf("\nactual_i->nombre es: %s",actual_i->nombre);
			printf("\nactual_j->nombre es: %s",actual_j->nombre);
			if(strcmp(actual_i->nombre,actual_j->nombre)<0){ //actual i es mayor que actual j
				
				temp=(struct nodoIM*)malloc(sizeof(struct nodoIM));
				//creamos una copia de actual i en temp para no perder la info
				temp->codigo=actual_i->codigo;
				strcpy(temp->nombre,actual_i->nombre);
				strcpy(temp->extension,actual_i->extension);
				temp->tamaniobytes=actual_i->tamaniobytes;
				temp->precio=actual_i->precio;
				printf("\nOficialmente entró al bucle");
				//cambiamos a i por j, estamos cambiando el lugar
				actual_i->codigo=actual_j->codigo;
				strcpy(actual_i->nombre,actual_j->nombre);
				strcpy(actual_i->extension,actual_j->extension);
				actual_i->tamaniobytes=actual_j->tamaniobytes;
				actual_i->precio=actual_j->precio;
				//lo mismo de arriba pero al revez, con la copia de i, osea temp
				actual_j->codigo=temp->codigo;
				strcpy(actual_j->nombre,temp->nombre);
				strcpy(actual_j->extension,temp->extension);
				actual_j->tamaniobytes=temp->tamaniobytes;
				actual_j->precio=temp->precio;
			}
			actual_j=actual_j->sig;
		}
		actual_i=actual_i->sig;
	}
	int conta=1;
	while(actual_i!=NULL){
		
		printf("\n\n\nLista numero %d\n",conta);
		printf("\nCodigo: %d",actual_i->codigo);
		printf("\nNombre: %s",actual_i->nombre);
		printf("\nExtension: %s",actual_i->extension);
		printf("\nTamaño en bytes: %d",actual_i->tamaniobytes);
		printf("\nPrecio: %f",actual_i->precio);
		conta++;
		actual_i=actual_i->sig;
		
	}
}
