// UNMSM � Facultad de Ing. Electr�nica y El�ctrica 
// Escuela de Ingenier�a Electr�nica
// Curso: Lenguaje de Programaci�n
// Docente: Avila L�pez, B. Patricio 
// Estudiante: Tumbalobos Peralta, Cristopher Rigoberto
// Fecha: 05/07/2020 
// Laboratorio Calificado 04 
// Objetivo: JUEGO:"Bajar las escaleras a ciegas". 
// Datos de entrada: Dos n�meros enteros entre 1 y 8.
// Restricciones: Los n�meros no deben ser decimales.

#include <iostream>
#include <locale.h>
#include <string>	// para usar getline
#include <sstream>	// para usar istringstream
#include <conio.h>	// para usar el getch()

using namespace std;

// Prototipo de la Funci�n
template <class TIPOD>	// Plantilla de Funci�n: para trabajar con cualquier tipo de variable
int validacion(TIPOD num, double& numero, int& entero);	// Paso de par�metros por Referencia: para trabajar con la direcci�n
														// de memoria donde est�n almacenadas las variables "numero" y "entero".
														// Y as� podemos intercambiar el valor de las variables, 
														// porque sabemos donde exactamente se est�n almacenando.
int main() {
	setlocale(LC_ALL,"");
	
	string n1, n2;
	double primer_numero, segundo_numero;
	int entero, escalon_actual = 0;
	
	validacion (n1, primer_numero, entero);	// Realizando la validaci�n del 1er n�mero ingresado
	
	switch (entero) {
		case 1: cout << "\n\t�En hora buena!. SE ENCONTR� CON UN ESCAL�N RESBALADIZO, ahora se encuentra en el escal�n 2.";
			escalon_actual = entero + 1;	// = 2
			break;
		case 2: cout << "\n\tUsted se encuentra ahora en el escal�n 2.";
			escalon_actual = entero;	// = 2
			break;
		case 3: cout << "\n\tUsted se encuentra ahora en el escal�n 3.";
			escalon_actual = entero;	// = 3
			break;
		case 4: cout << "\n\t�En hora buena!. EL ESCAL�N SE ROMPI�, ahora se encuentra en el escal�n 7.";
			escalon_actual = entero + 3;	// = 7
			break;
		case 5: cout << "\n\tUsted se encuentra ahora en el escal�n 5.";
			escalon_actual = entero;	// = 5
			break;
		case 6: cout << "\n\tMala suerte. SE ENCONTR� CON UN ESCORPI�N, ahora se encuentra en el escal�n 2.";
			escalon_actual = entero - 4;	// = 2
			break;
		case 7: cout << "\n\tUsted se encuentra ahora en el escal�n 7.";
			escalon_actual = entero;	// = 7
			break;
		case 8: cout << "\n\tMala suerte. SE ENCONTR� CON UNA TAR�NTULA, ahora se encuentra en el escal�n 5.";
			escalon_actual = entero - 3;	// = 5
			break;
	}
	
	cout << "\n\n";
	
	validacion (n2, segundo_numero, entero);	// Realizando la validaci�n del 2do n�mero ingresado
	
	escalon_actual = escalon_actual + entero;	// "escalon_actual" : Escal�n donde se qued� luego del primer movimiento
	
	switch (escalon_actual) {
		case 3: cout << "\n\tUsted se encuentra ahora en el escal�n 3.";
			break;
		case 4: cout << "\n\t�En hora buena!. EL ESCAL�N SE ROMPI�, ahora se encuentra en el escal�n 7.";
			break;
		case 5: cout << "\n\tUsted se encuentra ahora en el escal�n 5.";
			break;
		case 6: cout << "\n\tMala suerte. SE ENCONTR� CON UN ESCORPI�N, ahora se encuentra en el escal�n 2.";
			break;
		case 7: cout << "\n\tUsted se encuentra ahora en el escal�n 7.";
			break;
		case 8: cout << "\n\tMala suerte. SE ENCONTR� CON UNA TAR�NTULA, ahora se encuentra en el escal�n 5.";
			break;
	}
	
	cout << "\n\n";
	
	if (escalon_actual >= 9) {
		cout << "\n\t��� CONGRATULATIONS. LLeg� a la META (suelo) !!!" << endl;
	}
	
	else {
		cout << "\n\tG A M E   O V E R   ( No ha llegado al suelo )";
	}
	
	cout << "\n\n";
	getch();	// Para evitar que se cierre el ejecutable
	return 0;
}

// Definici�n de la Funci�n
template <class TIPOD>	// Para trabajar con cualquier tipo de variable
int validacion (TIPOD num, double& numero, int& entero) {	// Paso de par�metros por Referencia
	
	while (!((istringstream(num) >> numero) && ((numero >= 1) && (numero <=8)) && (!(numero - entero)))) {	
	// VALIDACI�N: Debe ser un n�mero       &&  Debe estar en el rango [1-8]   &&  No debe ser decimal
		
		cout << "\n\tIngrese un n�mero entero entre 1 y 8:  ";
		getline(cin,num);
		
		if (istringstream(num) >> numero) {		// Con este if verificamos si es una(s) letra(s)
			
			if ((numero >= 1) && (numero <=8)) {	// Con este if verificamos que est� en el rango [1-8]
				
				entero = numero;		// Artificio. Ej: 1.234 -> 1
				
				if (numero - entero) {	// Con este if verificamos si el n�mero es un decimal
					cout << "\tUsted ingres� un n�mero decimal, por favor ingrese un n�mero entero entre 1 y 8." << endl;
				}
			}
			
			else {
				cout << "\tUsted ingres� un n�mero fuera del rango [1-8]." << endl;
			}
		}
		
		else {
			cout << "\tUsted ingres� letra(s), debe digitar un n�mero entero entre 1 y 8." << endl;
		}
	}
	
	return entero;	// luego de pasar por la validaci�n devuelve un valor v�lido
}

