/*En el práctico de Estructuras, ejercicio 3, Ud. trabajó con una base de datos de
mediciones de diferentes sensores utilizando arreglos de estructuras en C.
Vamos a implementar lo mismo pero en C++ con orientación a objetos. Para
ello su programa debe tener:
- Una clase Sensor, con sus atributos (marca sensor, tipo, unidad de
medida) y funciones relativas a los sensores.
- Una clase Medición:
- La fecha y hora de la medición debe ser almacenada en una
variable tipo t_time (de la librería ctime)
- El sensor con el cual se realizó la medición, la clase Sensor antes
declarada.
- Valor de la medición.
- Comentarios.
- Una clase Lista que almacenará N mediciones en un arreglo de objetos
tipo Medicion. Con los métodos:
- Agregar Medición
- Eliminar medición
- Mostrar las mediciones
- Guardar las mediciones en un archivo.

Cada clase debe tener todos sus atributos privados y sus funciones get y set
para obtener y asignar valor respectivamente.*/

#include <iostream>
#include <ctime>
#include <string.h>
#define TAM 100
#define ESTRUC 5

using namespace std;

class Sensor{
	
	private:
		
		char m_marca[TAM];
		char m_tipo[TAM];
		char m_unidad[TAM];
		
	public:

		char *getmarca(void);
		char *gettipo(void);
		char *getunidad(void);
		void setmarca(char marca[TAM]); 
		void settipo(char tipo[TAM]);
		void setunidad(char unidad[TAM]);
};

class Medicion{
	
	private:
		
		time_t ahora;
		struct tm *reloj;
		float m_valor;
	
	public:
		Medicion(){};
		
		Medicion(int v)
		{
			m_valor = v;
			ahora = time(NULL);
			reloj = localtime(&ahora);
		};
		
		struct tm *getreloj(void);
		float getvalor(void);
		void setreloj(void);
		void setvalor(float valor);
};

class Base{
	private:
	
		Medicion EstructuraM[ESTRUC];
		Sensor TipodeSensor;
		
	public:
	
		FILE *fp;
	
		Base(void){
			char marca[]="000";
			char tipo[]="000";
			char unidad[]="000";
			float valor=0.0;
			int i;
			
			TipodeSensor.setmarca(marca);
			TipodeSensor.settipo(tipo);
			TipodeSensor.setunidad(unidad);
			
			for(i=0;i<ESTRUC;i++){
				EstructuraM[i] = Medicion(valor);
			}
		};
			
		Base(int){
			char marca[]="Fluke";
			char tipo[]="Sensor de temperatura en ambiente";
			char unidad[]="Grados celsius";
			float valor=34.23;
			int i;
			
			TipodeSensor.setmarca(marca);
			TipodeSensor.settipo(tipo);
			TipodeSensor.setunidad(unidad);
			
			for(i=0;i<ESTRUC;i++){
			EstructuraM[i] = Medicion(valor+i);
			}
			
		}
		
		void mostrarM(class Base objeto,int contMediciones);
		void guardarM(class Base objeto,int cont);
		
		Sensor getSensor(void){
			return TipodeSensor;
		}
			
		void setSensor(Sensor objeto){
			TipodeSensor=objeto;
		}	
		
		Medicion* getMediciones(int i){
			return &EstructuraM[i];
		}
			
		void setMedicion(Medicion objeto,int i){
			EstructuraM[i] = objeto;
		}
			
};

int main(int argc, char *argv[]) {
	
	int opcion;
	int cont=0;
	char marca[TAM],unidad[TAM],tipo[TAM];
	float valor;
	Base Objeto;
	Sensor Sensorcito;
	Medicion MedicionUno;

	do{
		printf("\n\nMenu de opciones");
		printf("\n1. Agregar nueva medicion");
		printf("\n2. Eliminar medicion");
		printf("\n3. Mostrar mediciones");
		printf("\n4. Guardar mediciones en un archivo");
		printf("\n5. Salir\n");
		scanf("%d",&opcion);
		
		switch(opcion){
			case 1:
					if(cont==0){
						
						printf("\nSe creó el objeto por primera vez.");
						
						printf("\nDesigne la marca del sensor: ");
						scanf("%s",marca);
						Sensorcito.setmarca(marca);
						
						printf("\nDesigne el tipo del sensor: ");
						scanf("%s",tipo);
						Sensorcito.settipo(tipo);
						
						printf("\nDesigne la unidad de medida del sensor: ");
						scanf("%s",unidad);
						Sensorcito.setunidad(unidad);
						
						printf("\nDesigne el valor de la medicion: ");
						scanf("%f",&valor);
						MedicionUno.setvalor(valor);
						
						printf("\nLa hora y fecha de la medición se guardarán según la actual.");
						MedicionUno.setreloj();
						
						Objeto.setSensor(Sensorcito);
						Objeto.setMedicion(MedicionUno,cont);
						cont++;
						
					}else{
						printf("\nDesigne el valor de la medicion: ");
						scanf("%f",&valor);
						MedicionUno.setvalor(valor);
						
						printf("\nLa hora y fecha de la medición se guardarán según la actual.");
						MedicionUno.setreloj();
						
						Objeto.setMedicion(MedicionUno,cont);
						cont++;
					}
					
				break;
			case 2:
				if(cont==0){
					printf("\nTodavia no has cargado ningun sensor");
				}else{
					cont--;
					printf("\nBorraste la ultima medicion");
				}
				break;
			case 3:
				if(cont==0){
					printf("\nTodavia no has cargado ningun sensor");
				}else{
					Objeto.mostrarM(Objeto,cont);
				}
				break;
			case 4:
				if(cont==0){
					printf("\nTodavia no has cargado ningun sensor");
				}else{
					Objeto.guardarM(Objeto,cont);
				}
				break;
		}
		
	}while(opcion!=5);
	
	
	
	return 0;
}

void Sensor::setmarca(char marca[]){
	strcpy(m_marca,marca);
}

void Sensor::settipo(char tipo[]){
	strcpy(m_tipo,tipo);
}

void Sensor::setunidad(char unidad[]){
	strcpy(m_unidad,unidad);
}

char* Sensor::getmarca(void){
	char *marca;
	marca=m_marca;
	return marca;
}

char* Sensor::gettipo(void){
	char *tipo;
	tipo=m_tipo;
	return tipo;
}

char* Sensor::getunidad(void){
	char *unidad;
	unidad=m_unidad;
	return unidad;
}


void Medicion::setreloj(void){
	
	ahora = time(NULL);
	reloj = localtime(&ahora);
}

void Medicion::setvalor(float valor){
	m_valor=valor;
}

struct tm* Medicion::getreloj(void){
	struct tm *horario;
	horario=reloj;
	return horario;
	
}

float Medicion::getvalor(void){

	return m_valor;
}


void Base::mostrarM(class Base objeto,int contMediciones){
	

	char *marca;
	char *tipo; 
	char *unidad;
	int i,cont=1;
	struct tm *horario;
	float valor;
	Medicion *MedicionActual;
	
	
	marca=objeto.TipodeSensor.getmarca();
	tipo=objeto.TipodeSensor.gettipo();
	unidad=objeto.TipodeSensor.getunidad();
	
	printf("\nMarca de la herramienta: %s",marca);

	printf("\nTipo de herramienta: %s",tipo);
	printf("\nUnidad de medida: %s",unidad);
	
	
	for(i=0;i<contMediciones;i++){
	
	printf("\nMedicion numero %d",cont);
	cont++;
	
	

	MedicionActual=objeto.getMediciones(i);
	horario=MedicionActual->getreloj();
	valor=MedicionActual->getvalor();
	
	printf("\nLa fecha y hora de la medicion: %04d-%02d-%02d %02d:%02d:%02d",horario->tm_year, horario->tm_mon, 
	horario->tm_mday, horario->tm_hour, horario->tm_min, horario->tm_sec);
	
	printf("\nValor medido: %.2f",valor);
	
	}
}

void Base::guardarM(class Base objeto,int cont){
	
	objeto.fp = fopen("Mediciones.txt","a");
	Medicion *MedEscribir;
	Sensor SenEscribir;
	char *marca,*tipo,*unidad;
	float valor;
	struct tm* reloj;
	char *cadenatime;
	int i=0;
	
	if(objeto.fp==NULL){
		printf("\nFalló al abrir el archivo");
	}
	else{
		printf("\nEl archivo se abrió correctamente");
		SenEscribir = objeto.getSensor();
		
		marca = SenEscribir.getmarca();
		tipo = SenEscribir.gettipo();
		unidad = SenEscribir.getunidad();
		
		fputs(marca,objeto.fp);
		fputs("-",objeto.fp);		
		fputs(tipo,objeto.fp);
		fputs("-",objeto.fp);
		fputs(unidad,objeto.fp);
		
		while(i<cont){
			
		fputs("\nMedicion\n",objeto.fp);
		
		MedEscribir = objeto.getMediciones(i);
		
		valor = MedEscribir->getvalor();
		reloj = MedEscribir->getreloj();
		cadenatime = asctime(reloj);  //convierte la struct tm reloj en una string "cadenatime"
		
		fputs(cadenatime,objeto.fp);
		fputs("-",objeto.fp);
		fprintf(objeto.fp,"valor: %.2f",valor);
		i++;
		
		}
	}
	
	fclose(objeto.fp);
}



