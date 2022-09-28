// UNMSM � Facultad de Ing. Electr�nica y El�ctrica 
// Escuela de Ingenier�a Electr�nica
// Curso: Lenguaje de Programaci�n
// Docente: Avila L�pez, B. Patricio 
// Estudiante: Tumbalobos Peralta, Cristopher Rigoberto
// Fecha: 17/07/2020 
// Laboratorio Calificado 05 
// Objetivo: Monitorear a distancia a las personas con COVID 19. 
// Datos de entrada: Respuestas a las preguntas.
// Restricciones: Las opciones ingresadas deben ser v�lidas (debe ser un n�mero, debe ser o 1 o 2 y no debe ser decimal).

#include <iostream>
#include <locale.h>
#include <string>	// para usar getline
#include <sstream>	// para usar istringstream
#include <conio.h>	// para usar el getch()
#include <stdlib.h>	// para usar el exit(0)

using namespace std;

// Prototipo de la Funci�n "validaci�n"
template <class TIPOD>	// Plantilla de Funci�n: para trabajar con cualquier tipo de variable
int validacion(TIPOD num, double& respuesta, int& entero);	// Paso de par�metros por Referencia: para trabajar con la direcci�n
															// de memoria donde est�n almacenadas las variables "numero" y "entero".
															// Y as� podemos intercambiar el valor de las variables, 
															// porque sabemos donde exactamente se est�n almacenando.								
// Prototipo de la Funci�n "control"				
void control (double& respuesta);	// Funci�n de tipo void: no retorna a ning�n valor			
															
int main() {	// Funci�n principal
	setlocale(LC_ALL,"");
	
	string n1, n2, n3, n4, n5;
	double respuesta;
	int entero;
	
	cout << "\n\tC O N S U L T A   V I R T U A L   C O V I D - 1 9" << endl;
	cout << "\n\tOPCIONES:	Digitar 1 si la respuesta es SI y 2 si la respuesta es NO" << endl;
	
	cout << "\n\t1.�Tiene usted sensaci�n de falta de aire o dificultad para respirar en reposo?" << endl;
	validacion (n1, respuesta, entero);	// Realizando la validaci�n de la primera opci�n ingresada
	control (respuesta);	// Realizando el control de la primera respuesta
	
	cout << "\n\t2.�Presenta desorientaci�n o confusi�n?" << endl;
	validacion (n2, respuesta, entero);	// Realizando la validaci�n de la segunda opci�n ingresada
	control (respuesta);	// Realizando el control de la segunda respuesta

	cout << "\n\t3.�Tuvo usted fiebre mayor a 38�C persistente por m�s de dos d�as?" << endl;
	validacion (n3, respuesta, entero);	// Realizando la validaci�n de la tercera opci�n ingresada
	control (respuesta);	// Realizando el control de la tercera respuesta

	cout << "\n\t4.�Presenta dolor en el pecho?" << endl;
	validacion (n4, respuesta, entero);	// Realizando la validaci�n de la cuarta opci�n ingresada
	control (respuesta);	// Realizando el control de la cuarta respuesta
	
	cout << "\n\t5.�Tuvo usted coloraci�n azul en los labios, manos o pies?" << endl;
	validacion (n5, respuesta, entero);	// Realizando la validaci�n de la quinta opci�n ingresada
	control (respuesta);	// Realizando el control de la quinta respuesta
	
	cout << "\n\tPor el momento no tiene una emergencia, pero si tiene s�ntomas de alguna enfermedad, acuda a su Centro de Salud m�s cercano." << endl;
	
	cout << "\n\n";
	getch();	// Para evitar que se cierre el ejecutable
	return 0;
}

// Definici�n de la Funci�n "validacion"
template <class TIPOD>	// Para trabajar con cualquier tipo de variable
int validacion (TIPOD num, double& respuesta, int& entero) {	// Paso de par�metros por Referencia
	
	while (!((istringstream(num) >> respuesta) && ((respuesta == 1) || (respuesta == 2)) && (!(respuesta - entero)))) {	
	// VALIDACI�N: Debe ser un n�mero      	   &&  			Debe ser 1 o 2               &&   No (debe ser decimal)
		
		cout << "\n\tIngrese una opci�n:  ";
		getline(cin,num);
		
		if (istringstream(num) >> respuesta) {		// Con este if verificamos si es(son) una(s) letra(s)
			
			entero = respuesta;		// Artificio. Ej: 1.234 -> 1
		
			if (respuesta - entero) {	// Con este if verificamos si el n�mero ingresado es un decimal
				cout << "\tUsted ingres� un n�mero decimal, por favor ingrese el n�mero de una opci�n v�lida." << endl;
			}
			
			else if ((respuesta == 1) || (respuesta == 2)) {	// Con este if verificamos que sea una de las opciones v�lidas
			}
				
			else {
				cout << "\tUsted ingres� una opci�n inv�lida." << endl;
			}
		}
		
		else {
			cout << "\tUsted ingres� letra(s), debe digitar el n�mero de una opci�n v�lida." << endl;
		}
	}
	
	return entero;	// Luego de pasar por la validaci�n devuelve una opci�n v�lida
}

// Definici�n de la Funci�n "control"
void control (double& respuesta) {	// Funci�n de tipo void: no retorna a ning�n valor	
	
	if (respuesta == 1) {
		cout << "\n\tPronto llegar� una ambulancia para trasladarlo a un Centro de Salud." << endl;
		exit(0);	// Para salir del c�digo cuando tenga uno de los 5 s�ntomas
	}
}

