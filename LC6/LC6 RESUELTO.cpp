// UNMSM – Facultad de Ing. Electrónica y Eléctrica 
// Escuela de Ingeniería Electrónica
// Curso: Lenguaje de Programación
// Docente: Avila López, B. Patricio 
// Estudiante: Tumbalobos Peralta, Cristopher Rigoberto
// Fecha: 24/07/2020 
// Laboratorio Calificado 06 
// Objetivo: Verificar si las posiciones (inicial y final) son válidas para un mismo alfil. 
// Datos de entrada: Abscisas (x1 y x2) y ordenadas (y1 y y2) de la posición inicial (x1, y1) y final (x2, y2).
// Restricciones: Al ingresar los valores de las abscisas (x1 y x2) y las ordenadas (y1 y y2) solo se tomará en cuenta el primer número escrito.

#include <iostream>
#include <locale.h>
#include <sstream>	// para usar istringstream
#include <conio.h>	// para usar el getch ()
#include <stdio.h>	// para usar el fflush
#include <string.h>	// para usar el strlen (), getline () y strcpy ()

using namespace std;
	
// Prototipo de la función "validacion_numero"
template <class TIPOD>	// Plantilla de Función: para trabajar con cualquier tipo de variable
double validacion_numero (TIPOD num, double numero, int& entero);	// Paso de parámetros por Referencia: para trabajar con la dirección
																	// de memoria donde están almacenadas las variables "numero" y "entero".
																	// Y así podemos intercambiar el valor de las variables,
																	// porque sabemos donde exactamente se están almacenando.

/*	
// Prototipo de la función "validacion_letra"
template <class TIPOD>
int validacion_letra (char cadena [100], int entero);
*/

int main () {
	setlocale(LC_ALL,"");
	
	string n1, n2, n3, n4;
	double x1, y1, x2, y2;
	int entero_x1, entero_y1, entero_x2, entero_y2;
	
	cout << "\n\tIngrese los valores para x1 y y1 respectivamente." << endl;
	
	validacion_numero (n1, x1, entero_x1);
	validacion_numero (n2, y1, entero_y1);
	
	cout << "\n\tPosición inicial (x1, y1): (" << entero_x1 << ", " << entero_y1 << ")\n" << endl;
	
	cout << "\n\tIngrese los valores para x2 y y2 respectivamente." << endl;
	
	validacion_numero (n3, x2, entero_x2);
	validacion_numero (n4, y2, entero_y2);
	
	cout << "\n\tPosición final (x2, y2): (" << entero_x2 << ", " << entero_y2 << ")\n" << endl;
	
	if ((entero_x2 == entero_x1) && (entero_y2 == entero_y1)) {
		cout << "\n\tLa posición inicial y final son iguales, el alfil no se ha movido." << endl;
	}
	
	else if ((entero_x2 > entero_x1) && (entero_y2 > entero_y1)) {
		
		if ((entero_x2 - entero_x1) == (entero_y2 - entero_y1)) {
			cout << "\n\tLas posiciones sí son válidas para un mismo alfil. Sí se puede puede ir de la posición inicial a la posición final con un solo movimiento." << endl;
		}
		
		else {
			cout << "\n\tLas posiciones NO son válidas para un mismo alfil." << endl;
		}
	}
	
	else if ((entero_x2 < entero_x1) && (entero_y2 > entero_y1)) {
		
		if ((entero_x1 - entero_x2) == (entero_y2 - entero_y1)) {
			cout << "\n\tLas posiciones sí son válidas para un mismo alfil. Sí se puede puede ir de la posición inicial a la posición final con un solo movimiento." << endl;
		}
		
		else {
			cout << "\n\tLas posicione NO son válidas para un mismo alfil." << endl;
		}
	}
	
	else if ((entero_x2 < entero_x1) && (entero_y2 < entero_y1)) {
		
		if ((entero_x1 - entero_x2) == (entero_y1 - entero_y2)) {
			cout << "\n\tLas posiciones sí son válidas para un mismo alfil.  Sí se puede puede ir de la posición inicial a la posición final con un solo movimiento." << endl;
		}
		
		else {
			cout << "\n\tLas posiciones NO son válidas para un mismo alfil." << endl;
		}
	}
	
	else if ((entero_x2 > entero_x1) && (entero_y2 < entero_y1)) {
		
		if ((entero_x2 - entero_x1) == (entero_y1 - entero_y2)) {
			cout << "\n\tLas posiciones sí son válidas para un mismo alfil. Sí se puede puede ir de la posición inicial a la posición final con un solo movimiento." << endl;
		}
		
		else {
			cout << "\n\tLas posiciones NO son válidas para un mismo alfil." << endl;
		}
	}
	
	else {
		cout << "\n\tNO se puede ir de la posición inicial a la posición final de un solo movimiento." << endl;
	}
	
	getch ();
	return 0;
}

// Definición de la función "validacion_numero"
template <class TIPOD>	// Plantilla de Función
double validacion_numero (TIPOD num, double numero, int& entero) {	// Paso de Parámetros por Referencia
	
	while (!((istringstream(num) >> numero) && ((numero >= 1) && (numero <= 8)) && (!(numero - entero)))) {
	// VALIDACIÓN:	Debe ser un número		&&	Debe estar en el rango [1-8]	&&	No (debe ser decimal)
		
		fflush (stdin);	// para limpiar la entrada de datos
		cout << "\n\tIngrese un número entre 1 y 8 (Solo se tomará en cuenta el primer número escrito): ";
		getline (cin, num);
		
		if	(istringstream (num) >> numero) {	// verificamos si el valor introducido es un número
			
			entero = numero;
			
			if (numero - entero) {	// verificamos si el número ingresado es un decimal
				cout << "\tUsted ingresó un número decimal, por favor ingrese un número entero entre 1 y 8." << endl;
			}
			
			else if (!((numero >= 1) && (numero <= 8))) {	// verificamos que esté en el rango [1-8]
				cout << "\tUsted ingresó un entero fuera del rango [1-8]" << endl;
			}
		}
			
		else {
			
			int longitud_caracteres, espacios_blanco = 0;
			char cadena [100] = "";
			
			strcpy (cadena, num.c_str());	// convierte el string "num" y lo copia en el char "cadena"
			
			longitud_caracteres = strlen (cadena);	// para contar los caracteres del char "cadena" 
			
			for (int i = 0; i <= longitud_caracteres; i++) {	// para saber cuantos espacios en blanco hay en el char "cadena"
				
				if (cadena [i] == ' ') {
					espacios_blanco++;
				}
			}
			
			if (espacios_blanco == 1) {	// verificamos si digitó un espacio en blanco
				cout << "\tUsted digitó un espacio en blanco, por favor ingrese un número entero entre 1 y 8." << endl;
			}
			
			else if (espacios_blanco > 1) {	// verificamos si digitó más de un espacio en blanco
				cout << "\tUsted digitó varios espacios en blanco, por favor ingrese un número entero entre 1 y 8." << endl;
			}
			
			else if (longitud_caracteres == 0){	// verificamos si no digitó ningún valor
				cout << "\tNo digitó ningun valor, por favor ingrese un número entero entre 1 y 8." << endl;
			}
			
			else if (longitud_caracteres == 1) {	// verificamos si ingresó un caracter
				cout << "\tUsted ingresó una caracter, por favor digite un número entero entre 1 y 8." << endl;
			}
			
			else if (longitud_caracteres > 1) {	// verificamos si ingreso más de un caracter
				cout << "\tUsted ingresó varios caracteres, por favor digite un número entero entre 1 y 8." << endl;
			}
		}
	}
	
	return numero;	// luego de pasar por la validación devuelve un número válido
}

// I N T E N T O   F A L L I D O   D E   L A   F U N C I O N   V A L I D A C I O N   D E   L E T R A S

/*
// Definición de la función "validacion_letra"
int validacion_letra (char cadena [100], int entero) {

	while ( && (letra == 'a') && (letra == 'b') && (letra == 'c') && (letra == 'd') && (letra == 'e') && (letra == 'f') && (letra == 'g') && (letra == 'h')) {
	// VALIDACIÓN:	Debe ser una letra			&&			Debe estar entre 'a' e 'h'		
		
		cout << "\n\tIngrese una letra entre 'a' e 'h' (en mayúscula o minúscula): ";
		getline (cin, num);
		fflush (stdin);	// para limpiar la entrada de datos
		
		if ((istringstream(num) >> numero)) {
		}
		
		else {
		
			int longitud_caracteres = 0;
			char letra_1 [100] = "", letra_2 [100] = "";
	
			strcpy (letra_1, num.c_str());
			longitud_caracteres = strlen (letra_1);
			
			for (int i = 0; i <= longitud_caracteres; i++) {
			
				switch (letra_1 [i]) {
					case 'a': entero = 1; break;
					case 'b': entero = 2; break;
					case 'c': entero = 3; break;
					case 'd': entero = 4; break;
					case 'e': entero = 5; break;
					case 'f': entero = 6; break;
					case 'g': entero = 7; break;
					case 'h': entero = 8; break;
				}
			}		
		}	

		if ((istringstream(num) >> numero)) {
		}

		else {
			int longitud_caracteres = 0;
			char letra_1 [100] = "", letra_2 [100] = "";
		
			strcpy (letra_1, num.c_str());
			longitud_caracteres = strlen (letra_1);
			
			if (longitud_caracteres == 0){	// verificamos si no digitó ningún valor
				cout << "\tNo digitó ningun valor, por favor ingrese una letra entre 'a' e 'h'." << endl;
			}
		
			else if (longitud_caracteres == 1) {	// verificamos si ingresó una letra
				cout << "\tUsted ingresó una caracter, por favor digite una letra entre 'a' e 'h'." << endl;
			}
		
			else if (longitud_caracteres > 1) {	// verificamos si ingreso más de una letra
				cout << "\tUsted ingresó varios caracteres, por favor digite una letra entre 'a' e 'h'." << endl;
			}		
		}
	
		for (int i = 0; i <= longitud_caracteres; i++) {	// para saber cuantos espacios en blanco hay en el char "cadena"
				
				if (cadena [i] == ' ') {
					espacios_blanco++;
				}
		}
		
	return entero;	// luego de pasar por la validación devuelve un número válido
	}
}
*/

