// UNMSM – Facultad de Ing. Electrónica y Eléctrica 
// Escuela de Ingeniería Electrónica
// Curso: Lenguaje de Programación
// Docente: Avila López, B. Patricio 
// Estudiante: Tumbalobos Peralta, Cristopher Rigoberto
// Fecha: 05/07/2020 
// Laboratorio Calificado 04 
// Objetivo: JUEGO:"Bajar las escaleras a ciegas". 
// Datos de entrada: Dos números enteros entre 1 y 8.
// Restricciones: Los números no deben ser decimales.

#include <iostream>
#include <locale.h>
#include <string>	// para usar getline
#include <sstream>	// para usar istringstream
#include <conio.h>	// para usar el getch()

using namespace std;

// Prototipo de la Función
template <class TIPOD>	// Plantilla de Función: para trabajar con cualquier tipo de variable
int validacion(TIPOD num, double& numero, int& entero);	// Paso de parámetros por Referencia: para trabajar con la dirección
														// de memoria donde están almacenadas las variables "numero" y "entero".
														// Y así podemos intercambiar el valor de las variables, 
														// porque sabemos donde exactamente se están almacenando.
int main() {
	setlocale(LC_ALL,"");
	
	string n1, n2;
	double primer_numero, segundo_numero;
	int entero, escalon_actual = 0;
	
	validacion (n1, primer_numero, entero);	// Realizando la validación del 1er número ingresado
	
	switch (entero) {
		case 1: cout << "\n\t¡En hora buena!. SE ENCONTRÓ CON UN ESCALÓN RESBALADIZO, ahora se encuentra en el escalón 2.";
			escalon_actual = entero + 1;	// = 2
			break;
		case 2: cout << "\n\tUsted se encuentra ahora en el escalón 2.";
			escalon_actual = entero;	// = 2
			break;
		case 3: cout << "\n\tUsted se encuentra ahora en el escalón 3.";
			escalon_actual = entero;	// = 3
			break;
		case 4: cout << "\n\t¡En hora buena!. EL ESCALÓN SE ROMPIÓ, ahora se encuentra en el escalón 7.";
			escalon_actual = entero + 3;	// = 7
			break;
		case 5: cout << "\n\tUsted se encuentra ahora en el escalón 5.";
			escalon_actual = entero;	// = 5
			break;
		case 6: cout << "\n\tMala suerte. SE ENCONTRÓ CON UN ESCORPIÓN, ahora se encuentra en el escalón 2.";
			escalon_actual = entero - 4;	// = 2
			break;
		case 7: cout << "\n\tUsted se encuentra ahora en el escalón 7.";
			escalon_actual = entero;	// = 7
			break;
		case 8: cout << "\n\tMala suerte. SE ENCONTRÓ CON UNA TARÁNTULA, ahora se encuentra en el escalón 5.";
			escalon_actual = entero - 3;	// = 5
			break;
	}
	
	cout << "\n\n";
	
	validacion (n2, segundo_numero, entero);	// Realizando la validación del 2do número ingresado
	
	escalon_actual = escalon_actual + entero;	// "escalon_actual" : Escalón donde se quedó luego del primer movimiento
	
	switch (escalon_actual) {
		case 3: cout << "\n\tUsted se encuentra ahora en el escalón 3.";
			break;
		case 4: cout << "\n\t¡En hora buena!. EL ESCALÓN SE ROMPIÓ, ahora se encuentra en el escalón 7.";
			break;
		case 5: cout << "\n\tUsted se encuentra ahora en el escalón 5.";
			break;
		case 6: cout << "\n\tMala suerte. SE ENCONTRÓ CON UN ESCORPIÓN, ahora se encuentra en el escalón 2.";
			break;
		case 7: cout << "\n\tUsted se encuentra ahora en el escalón 7.";
			break;
		case 8: cout << "\n\tMala suerte. SE ENCONTRÓ CON UNA TARÁNTULA, ahora se encuentra en el escalón 5.";
			break;
	}
	
	cout << "\n\n";
	
	if (escalon_actual >= 9) {
		cout << "\n\t¡¡¡ CONGRATULATIONS. LLegó a la META (suelo) !!!" << endl;
	}
	
	else {
		cout << "\n\tG A M E   O V E R   ( No ha llegado al suelo )";
	}
	
	cout << "\n\n";
	getch();	// Para evitar que se cierre el ejecutable
	return 0;
}

// Definición de la Función
template <class TIPOD>	// Para trabajar con cualquier tipo de variable
int validacion (TIPOD num, double& numero, int& entero) {	// Paso de parámetros por Referencia
	
	while (!((istringstream(num) >> numero) && ((numero >= 1) && (numero <=8)) && (!(numero - entero)))) {	
	// VALIDACIÓN: Debe ser un número       &&  Debe estar en el rango [1-8]   &&  No debe ser decimal
		
		cout << "\n\tIngrese un número entero entre 1 y 8:  ";
		getline(cin,num);
		
		if (istringstream(num) >> numero) {		// Con este if verificamos si es una(s) letra(s)
			
			if ((numero >= 1) && (numero <=8)) {	// Con este if verificamos que esté en el rango [1-8]
				
				entero = numero;		// Artificio. Ej: 1.234 -> 1
				
				if (numero - entero) {	// Con este if verificamos si el número es un decimal
					cout << "\tUsted ingresó un número decimal, por favor ingrese un número entero entre 1 y 8." << endl;
				}
			}
			
			else {
				cout << "\tUsted ingresó un número fuera del rango [1-8]." << endl;
			}
		}
		
		else {
			cout << "\tUsted ingresó letra(s), debe digitar un número entero entre 1 y 8." << endl;
		}
	}
	
	return entero;	// luego de pasar por la validación devuelve un valor válido
}

