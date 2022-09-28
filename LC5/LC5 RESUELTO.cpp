// UNMSM – Facultad de Ing. Electrónica y Eléctrica 
// Escuela de Ingeniería Electrónica
// Curso: Lenguaje de Programación
// Docente: Avila López, B. Patricio 
// Estudiante: Tumbalobos Peralta, Cristopher Rigoberto
// Fecha: 17/07/2020 
// Laboratorio Calificado 05 
// Objetivo: Monitorear a distancia a las personas con COVID 19. 
// Datos de entrada: Respuestas a las preguntas.
// Restricciones: Las opciones ingresadas deben ser válidas (debe ser un número, debe ser o 1 o 2 y no debe ser decimal).

#include <iostream>
#include <locale.h>
#include <string>	// para usar getline
#include <sstream>	// para usar istringstream
#include <conio.h>	// para usar el getch()
#include <stdlib.h>	// para usar el exit(0)

using namespace std;

// Prototipo de la Función "validación"
template <class TIPOD>	// Plantilla de Función: para trabajar con cualquier tipo de variable
int validacion(TIPOD num, double& respuesta, int& entero);	// Paso de parámetros por Referencia: para trabajar con la dirección
															// de memoria donde están almacenadas las variables "numero" y "entero".
															// Y así podemos intercambiar el valor de las variables, 
															// porque sabemos donde exactamente se están almacenando.								
// Prototipo de la Función "control"				
void control (double& respuesta);	// Función de tipo void: no retorna a ningún valor			
															
int main() {	// Función principal
	setlocale(LC_ALL,"");
	
	string n1, n2, n3, n4, n5;
	double respuesta;
	int entero;
	
	cout << "\n\tC O N S U L T A   V I R T U A L   C O V I D - 1 9" << endl;
	cout << "\n\tOPCIONES:	Digitar 1 si la respuesta es SI y 2 si la respuesta es NO" << endl;
	
	cout << "\n\t1.¿Tiene usted sensación de falta de aire o dificultad para respirar en reposo?" << endl;
	validacion (n1, respuesta, entero);	// Realizando la validación de la primera opción ingresada
	control (respuesta);	// Realizando el control de la primera respuesta
	
	cout << "\n\t2.¿Presenta desorientación o confusión?" << endl;
	validacion (n2, respuesta, entero);	// Realizando la validación de la segunda opción ingresada
	control (respuesta);	// Realizando el control de la segunda respuesta

	cout << "\n\t3.¿Tuvo usted fiebre mayor a 38°C persistente por más de dos días?" << endl;
	validacion (n3, respuesta, entero);	// Realizando la validación de la tercera opción ingresada
	control (respuesta);	// Realizando el control de la tercera respuesta

	cout << "\n\t4.¿Presenta dolor en el pecho?" << endl;
	validacion (n4, respuesta, entero);	// Realizando la validación de la cuarta opción ingresada
	control (respuesta);	// Realizando el control de la cuarta respuesta
	
	cout << "\n\t5.¿Tuvo usted coloración azul en los labios, manos o pies?" << endl;
	validacion (n5, respuesta, entero);	// Realizando la validación de la quinta opción ingresada
	control (respuesta);	// Realizando el control de la quinta respuesta
	
	cout << "\n\tPor el momento no tiene una emergencia, pero si tiene síntomas de alguna enfermedad, acuda a su Centro de Salud más cercano." << endl;
	
	cout << "\n\n";
	getch();	// Para evitar que se cierre el ejecutable
	return 0;
}

// Definición de la Función "validacion"
template <class TIPOD>	// Para trabajar con cualquier tipo de variable
int validacion (TIPOD num, double& respuesta, int& entero) {	// Paso de parámetros por Referencia
	
	while (!((istringstream(num) >> respuesta) && ((respuesta == 1) || (respuesta == 2)) && (!(respuesta - entero)))) {	
	// VALIDACIÓN: Debe ser un número      	   &&  			Debe ser 1 o 2               &&   No (debe ser decimal)
		
		cout << "\n\tIngrese una opción:  ";
		getline(cin,num);
		
		if (istringstream(num) >> respuesta) {		// Con este if verificamos si es(son) una(s) letra(s)
			
			entero = respuesta;		// Artificio. Ej: 1.234 -> 1
		
			if (respuesta - entero) {	// Con este if verificamos si el número ingresado es un decimal
				cout << "\tUsted ingresó un número decimal, por favor ingrese el número de una opción válida." << endl;
			}
			
			else if ((respuesta == 1) || (respuesta == 2)) {	// Con este if verificamos que sea una de las opciones válidas
			}
				
			else {
				cout << "\tUsted ingresó una opción inválida." << endl;
			}
		}
		
		else {
			cout << "\tUsted ingresó letra(s), debe digitar el número de una opción válida." << endl;
		}
	}
	
	return entero;	// Luego de pasar por la validación devuelve una opción válida
}

// Definición de la Función "control"
void control (double& respuesta) {	// Función de tipo void: no retorna a ningún valor	
	
	if (respuesta == 1) {
		cout << "\n\tPronto llegará una ambulancia para trasladarlo a un Centro de Salud." << endl;
		exit(0);	// Para salir del código cuando tenga uno de los 5 síntomas
	}
}

