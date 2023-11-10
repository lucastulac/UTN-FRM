/*Desarrollar una clase “Cadena” para el manejo de cadenas de caracteres.
	Además del constructor debe implementar como mínimo 5 métodos con
	funcionalidades referidas a la manipulación de cadenas: longitud, Concatenar,
	Copiar, Buscar coincidencias por carácter o por subcadena, etc. Demostrar el
	funcionamiento de dicha Clase Cadena en el programa principal.*/	
#include <iostream>
#include <string.h>
#define TAM 200
using namespace std;

class Cadena{
	
	public:		
		char cadena[TAM];
		
		Cadena(){
			strcpy(cadena,"Hola mundo");
		}
		
		void longitud(char cadena[]);
		void concatenar(char cadena[],char cadenaextra[]);
		void buscar(char cadena[], char subcadena[]);
		void copiar(char cadena[], char cadenaacopiar[]);
		void invertir(char cadena[]);
		void mostrar(char cadena[]);
};

void Cadena::longitud(char cadena[]){
	int largo;
	largo=strlen(cadena);
	printf("\nLa longitud de la cadena es %d\n",largo);
}

void Cadena::concatenar(char cadena[],char cadenaextra[]){
	strcat(cadena,cadenaextra);
	printf("\nLa nueva cadena es: %s",cadena);
}

void Cadena::copiar(char cadena[], char cadenaacopiar[]){
	strcpy(cadena,cadenaacopiar);
	printf("\nLa nueva cadena es: %s",cadena);
}

void Cadena::buscar(char cadena[],char subcadena[]){
 char *band;
	
	band=strstr(cadena,subcadena);
	if(band!=NULL){
		printf("\nSe encontro la subcadena dentro de la cadena base");
	}else{
		printf("\nNo se encontró la subcadena dentro de la cadena");
	}
}

void Cadena::mostrar(char cadena[]){
	printf("\n%s",cadena);
}

void Cadena::invertir(char cadena[]){
	int larg,j=0,i;
	larg=strlen(cadena);
	char cadenaI[TAM];
	
	for(i=larg;i==0;i++){
		cadenaI[j]=cadena[i];
		j++;
	}
	
	printf("La cadena invertida es: %s",cadenaI);
}

int main(int argc, char *argv[]) {
	
	Cadena cc1;
	int opcion=0;
	int longa;
	
	do{
	printf("\n\nMenu de opciones");
	printf("\n1. Longitud de la cadena");
	printf("\n2. Concatenar cadenas");
	printf("\n3. Buscar por subcadena");
	printf("\n4. Copiar cadena");
	printf("\n5. Invertir cadena");
	printf("\n6. Mostrar cadena");
	printf("\n7. Salir\n");
	scanf("%d",&opcion);
		
		switch(opcion){
			
			case 1:
				cc1.longitud(cc1.cadena);
				break;
				
			case 2:
				char cadenaextra[TAM];
				printf("\nIntroduzca la cadena a concatenar: \n");
				scanf("%s",cadenaextra);	//arreglar, no deja poner espacios
				/*fgets(cadenaextra, sizeof(TAM), stdin);
				
				longa = strlen(cadenaextra);
				if (cadenaextra[longa - 1] == '\n') {
					cadenaextra[longa - 1] = '\0';
				}*/
				
				cc1.concatenar(cc1.cadena,cadenaextra);
				
				break;
				
			case 3:
				char subcadena[TAM];
				printf("\nIntroduzca la subcadena a buscar: \n");
				scanf("%s",subcadena);
				cc1.buscar(cc1.cadena,subcadena);
				break;
				
			case 4:
				char cadenaacopiar[TAM];
				printf("\nIntroduzca la cadena a copiar: \n");
				scanf("%s",cadenaacopiar);
				cc1.copiar(cc1.cadena,cadenaacopiar);
				break;
				
			case 5:
				cc1.invertir(cc1.cadena);
				break;
				
			case 6:
				cc1.mostrar(cc1.cadena);
				break;
				
		}
		
	}while(opcion!=7);
	return 0;
}

