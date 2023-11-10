/*Ud. con este ejercicio aprenderá a utilizar el tiempo (fechas, horas, segundos).
	Debe desarrollar y aplicar una clase para el manejo de un temporizador o
	cronómetro. Es requisito utilizar la librería ctime.
#include <ctime>
Debe tener los siguientes métodos:
	- Constructor
	- Iniciar el temporizador
	- Detener el temporizador
	- Regresar la cantidad de tiempo transcurrido. Esto puede mostrarse
	en diversos formatos: cantidad de milisegundos, formato minutos y
	segundos por ejemplo hh:mm:ss.
	- Resetear el temporizador (volverlo a cero).
	- Tres métodos más que Ud. elija agregar referidos al uso del tiempo
	o fechas con la librería ctime
	
	Debe mostrar el funcionamiento de la clase Cronometro en un programa
	principal.*/
#include <ctime>
#include <iostream>
#define TAM 50
using namespace std;

class Cronometro{
	
	public:
	
	time_t inicio;
	time_t fin;
	
	Cronometro(){
		inicio=0;
		fin=0;
	}
	
	time_t iniciar(time_t inicio);
	time_t detener(time_t fin);
	void regresarT(time_t inicio, time_t fin);
	void reset(time_t inicio, time_t fin);
	void temporizador(void);
	void fechaactual(void);
	
};

time_t Cronometro::iniciar(time_t inicio){
	inicio=time(NULL);
	printf("\n\nEl cronometro empezó a correr. . .");
	//printf("\ninicio es %.2f",inicio);
	return inicio;
}

time_t Cronometro::detener(time_t fin){
	fin=time(NULL);
	printf("\n\nEl cronometro paro. . .");
	//printf("\nfin es %.2f",fin);
	return fin;
}

void Cronometro::regresarT(time_t inicio, time_t fin){
	float diferencia=0;
	diferencia = difftime(fin,inicio);
	//printf("\ndiferencia es %.2f",diferencia);
	printf("\nEl tiempo transcurrido es: %.2f segundos",diferencia);
}

void Cronometro::reset(time_t inicio, time_t fin){
	inicio = 0;
	fin = 0;
	printf("\nEl cronometro se reseteó correctamente");
}

void Cronometro::temporizador(void){
	
	bool estado=true;
	
	time_t inicio = time(NULL);
	time_t fin;
	int diff;
	int tiempo;
	
	printf("\n¿A cuanto tiempo desea setear el temporizador(segundos)?: ");
	scanf("%d",&tiempo);
	
	printf("\nEl temporizador comenzó . . .");
	
	while(estado == true){
		fin = time(NULL);
		diff = difftime(fin,inicio);
		if(diff == tiempo){
			printf("\nEl temporizador frenó . . .");
			estado = false;
		}
	}
	
}

void Cronometro::fechaactual(void){
	time_t fecha;
	fecha = time(NULL);
	
	char *tmfecha = ctime(&fecha);
	printf("Hoy es %s",tmfecha);
}

int main(int argc, char *argv[]) {
	Cronometro reloj;
	int opcion;
	do{
		printf("\n\nMenu de opciones");
		printf("\n1. Iniciar el cronometro");
		printf("\n2. Detener el cronometro");
		printf("\n3. Mostrar el tiempo transcurrido");
		printf("\n4. Resetear el cronometro");
		printf("\n5. Temporizador");
		printf("\n6. Fecha actual");
		printf("\n7. Salir");
		printf("\n");
		scanf("%d",&opcion);
		
		switch(opcion){
			
			case 1:
				reloj.inicio=reloj.iniciar(reloj.inicio);
				break;
			case 2:
				reloj.fin=reloj.detener(reloj.fin);
				break;
			case 3:
				reloj.regresarT(reloj.inicio,reloj.fin);
				break;
			case 4:
				reloj.reset(reloj.inicio,reloj.fin);
				break;
			case 5:
				reloj.temporizador();
			case 6:
				reloj.fechaactual();
		}
		
	}while(opcion!=7);
	return 0;
}

