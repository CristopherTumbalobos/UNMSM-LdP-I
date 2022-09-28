// UNMSM – Facultad de Ing. Electrónica y Eléctrica 
// Escuela de Ingeniería Electrónica
// Curso: Lenguaje de Programación
// Docente: Avila López, B. Patricio 
// Estudiante: Tumbalobos Peralta, Cristopher Rigoberto
// Fecha: 07/08/2020 
// Laboratorio Calificado 07
// Objetivo: JUEGO: "Llegar a la meta (mediante el uso de un dado virtual)" 
// Datos de entrada: El número de una opción.
// Restricciones: Solo puede digitar el número de una opción válida (o el 1 o el 2).

#include <iostream>		// Para el flujo (entrada y salida) de datos
#include <locale.h>		// Para la ortografía de las palabras
#include <string>		// Para usar getline (), strcpy () y strlen ()
#include <sstream>		// Para usar istringstream ()
#include <conio.h>		// Para usar el getch ()
#include <stdlib.h>		// Para usar srand (), rand () y atoi ()
#include <ctime>		// Para usar time ()
#include <stdio.h>		// Para usar fflush ()
#include <windows.h>	// Para usar SetConsoleTextAttribute ()

using namespace std;	// Para omitir el uso de (std::)

// Prototipo de la función "validacion_opcion"
template <class TIPOD>	// Plantilla de función
void validacion_opcion (TIPOD& num, double& numero, int& entero);	// Paso de parámetros por referencia

// Prototipo de la función "color"
int color (int n);		// Paso de parámetros por valor

// Prototipo de la función "mensaje_casilla"
void mensaje_casilla (int& casilla);	// Paso de parámetros por referencia

// Prototipo de la función "mensaje_meta"
void mensaje_meta (int& casilla);

// Prototipo de la función "movimiento_casilla"
void movimiento_casilla (int& casilla);		// Paso de parámetros por referencia

// Prototipo de la función "lanzar_dado"
void lanzar_dado (int& casilla);		// Paso de parámetros por referencia

int main () {	// Función principal
	setlocale (LC_ALL, "");
	
	string n1;
	double numero;
	int entero, casilla = 0, turno = 2;
	bool fin1 = false;
	
	srand (time (NULL));	// Definimos la semilla de los números pseudo aleatorios
	
	cout << "\t\t\t\tT U R N O   1\n" << endl;

	lanzar_dado (casilla);
		
	if ((casilla == 1) || (casilla == 3) || (casilla == 6)) {	// Para mostrar los mensajes de las casillas 1, 3 o 6
		
		mensaje_casilla (casilla);
	}

	switch (casilla) {
		case 1: cout << "\n\t¡En hora buena!. ADELANTA 4 ESPACIOS, ahora se encuentra en la casilla 5." << endl;
			casilla = casilla + 4;	// = 5
			break;
		case 2: cout << "\n\tUsted se encuentra ahora en la casilla 2." << endl;
			casilla = casilla;	// = 2
			break;
		case 3: cout << "\n\t¡En hora buena!. ADELANTA 4 ESPACIOS, ahora se encuentra en la casilla 7." << endl;
			casilla = casilla + 4;	// = 7
			break;
		case 4: cout << "\n\tUsted se encuentra ahora en la casilla 4." << endl;
			casilla = casilla;	// = 4
			break;
		case 5: cout << "\n\tUsted se encuentra ahora en la casilla 5." << endl;
			casilla = casilla;	// = 5
			break;
		case 6: cout << "\n\tMala suerte. RETROCEDE 2 ESPACIOS, ahora se encuentra en la casilla 4." << endl;
			casilla = casilla - 2;	// = 4
			break;
	}
	
	movimiento_casilla (casilla);
	
	cout << "\n\t\tOpciones: " << endl;
	cout << "\t\t1. Seguir jugando." << endl;
	cout << "\t\t2. Retirarse." << endl;
	
	while (!fin1) {
		
		validacion_opcion (n1, numero, entero);
		
		if (entero == 2) {
			
			cout << "\n\tG A M E   O V E R" << endl;
			fin1 = true;	
		}
		
		else {
			printf ("\n\n\t\t\t\tT U R N O   %d\n\n", turno);
			
			lanzar_dado (casilla);
			
			if (casilla == 11) {	// Retrocede un espacio (SINGULAR)
				
				cout << "\n\tSu casilla supera a la casilla 10, por lo tanto usted retrocede una casilla." << endl;
				casilla = 20 - casilla;
				cout << "\n\tSe encuentra en la casilla " << casilla << "." << endl;
			}
			
			else if (casilla > 11) {	// Retrocede varios espacios (PLURAL)
				
				cout << "\n\tSu casilla supera a la casilla 10, por lo tanto usted retrocede " << casilla - 10 << " casillas." << endl;
				casilla = 20 - casilla;
				cout << "\n\tSe encuentra en la casilla " << casilla << "." << endl;
			}
			
			if ((casilla == 1) || (casilla == 3) || (casilla == 6) || (casilla == 8) || (casilla == 9)) {	// Para mostrar los mensajes de las casillas 1, 3, 6, 8 o 9
		
				mensaje_casilla (casilla);
			}
			
			switch (casilla) {
				case 1: cout << "\n\t¡En hora buena!. ADELANTA 4 ESPACIOS, ahora se encuentra en la casilla 5." << endl;
					casilla = casilla + 4;	// = 5
					break;
				case 2: cout << "\n\tUsted se encuentra ahora en la casilla 2." << endl;
					casilla = casilla;	// = 2
					break;
				case 3: cout << "\n\t¡En hora buena!. ADELANTA 4 ESPACIOS, ahora se encuentra en la casilla 7." << endl;
					casilla = casilla + 4;	// = 7
					break;
				case 4: cout << "\n\tUsted se encuentra ahora en la casilla 4." << endl;
					casilla = casilla;	// = 4
					break;
				case 5: cout << "\n\tUsted se encuentra ahora en la casilla 5." << endl;
					casilla = casilla;	// = 5
					break;
				case 6: cout << "\n\tMala suerte. RETROCEDE 2 ESPACIOS, ahora se encuentra en la casilla 4." << endl;
					casilla = casilla - 2;	// = 4
					break;
				case 7: cout << "\n\tUsted se encuentra ahora en la casilla 7." << endl;
					casilla = casilla;	// = 7
					break;
				case 8: cout << "\n\tMala suerte. RETROCEDE 4 ESPACIOS, ahora se encuentra en la casilla 4." << endl;
					casilla = casilla - 4;	// = 4
					break;
				case 9: cout << "\n\tMala suerte. REGRESA A LA CASILLA 2, ahora se encuentra en la casilla 2." << endl;
					casilla = 2;
					break;
				case 10: mensaje_meta (casilla);	// Para mostrar el mensaje de la casilla 10
					cout << "\n\n\t¡ C O N G R A T U L A T I O N S !. LLegó a la META" << endl << endl;
					fin1 = true;
					break;
			}
			
			if (casilla != 10) {
				
				movimiento_casilla (casilla);
				
				cout << "\n\t\tOpciones: " << endl;
				cout << "\t\t1. Seguir jugando." << endl;
				cout << "\t\t2. Retirarse." << endl;
			}	
		}
		
		turno++;
	}

	return 0;
}

// Definición de la función "validacion_opcion"
template <class TIPOD>	// Plantilla de función
void validacion_opcion (TIPOD& num, double& numero, int& entero) {	// Paso de parámetros por Referencia
	
	int longitud_caracteres, espacios_blanco = 0;
	char cadena [100] = "";
	bool fin2 = false;
	
	while (!fin2) {	
		
		fflush (stdin);	 // para limpiar la entrada de datos
		cout<<"\n\t\tIngrese una opcion (solo se tomará en cuenta el primer número escrito): ";
		getline(cin,num);
		
		if (istringstream(num) >> numero) {		// Con este if verificamos si es un número
			
			entero = numero;
			entero = atoi (num.c_str());	// Conversión de char a entero
			
			if ((numero == 1) || (numero ==2)) {	// Con este if verificamos que sea el número 1 o 2
				fin2 = true;
			}
			
			else if (numero - entero) {	// Con este if verificamos si el número es un decimal
				cout << "\t\tUsted ingresó un número decimal, por favor ingrese el número 1 o 2." << endl;
			}
			
			else {
				cout << "\t\tUsted ingresó una opción no válida, por favor ingrese el número 1 o 2." << endl;	// Ej: -6, 0, 3, 4, ...
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
				cout << "\t\tUsted digitó un espacio en blanco, por favor ingrese el número 1 o 2." << endl;
			}
			
			else if (espacios_blanco > 1) {	// verificamos si digitó más de un espacio en blanco
				cout << "\t\tUsted digitó varios espacios en blanco, por favor ingrese el número 1 o 2." << endl;
			}
			
			else if (longitud_caracteres == 0){	// verificamos si no digitó ningún valor
				cout << "\t\tNo digitó ningun valor, por favor ingrese el número 1 o 2." << endl;
			}
			
			else if (longitud_caracteres == 1) {	// verificamos si ingresó un caracter
				cout << "\t\tUsted ingresó una caracter, por favor ingrese el número 1 o 2." << endl;
			}
			
			else if (longitud_caracteres > 1) {	// verificamos si ingreso más de un caracter
				cout << "\t\tUsted ingresó varios caracteres, por favor ingrese el número 1 o 2." << endl;
			}
			//cout << "\tUsted ingresó caracteres." << endl;
		}
	}
}

// Definición de la funcion "color"
int color (int n) {		// Paso de parámetros por valor
	
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), n);
}

// Definición de la función "mensaje_casilla"
void mensaje_casilla (int& casilla) {	// Paso de parámetros por Referencia
	
	int i, j;
	
	cout << "\n" << endl;
	
	for (i = 1; i <= 10; i++) {
		
		color (7);
		cout << "\t\t\t" << i << "\t";
		
		for (j = 0; j < 1; j++) {

			if (i == casilla) {
				
				if ((i+j) % 2 == 0) {
				
					switch (casilla) {
						
						case 6:
							color (57);
							cout << "   Retroceda 2 espacios  ";
							break;
						case 8:
							color (57);		
							cout << "   Retroceda 4 espacios  ";
							break;
						default:
							color (51);
							cout << "[\t\t\t" << "]";
							break;
					}
				}
			
				else {
					
					switch (casilla) {
								
						case 1: 
							color (18);
							cout << "   Adelante 4 espacios   ";
							break;
						case 3: 
							color (18);
							cout << "   Adelante 4 espacios   ";
							break;
						case 9: 
							color (18);
							cout << "  Regrese a la casilla 2 ";
							break;
						default: 
							color (17);
							cout << "[\t\t\t" << "]";
							break;
					}
				}
			}
			
			else if (((i+j) % 2 == 0) && (i != 10)) {
				color (51);
				cout << "[\t\t\t" << "]";
			}
			
			else if ((i+j) % 2 != 0) {
				color (17);
				cout << "[\t\t\t" << "]";
			}		
		}
		
		if (i == 10) {	// Para mostrar el mensaje " M E T A " (de color azul claro)
				
			color (59);
			cout << "\t M E T A         ";
		}
		
		color (00);
		cout << "[\t\t\t" << "]" << endl;
	}

	color (7);
}

// Definición de la función "mensaje_meta"
void mensaje_meta (int& casilla) {	// Paso de parámetros por Referencia
	
	int i, j;
	
	cout << "\n" << endl;
	
	for (i = 1; i <= 10; i++) {
		
		color (7);
		cout << "\t\t\t" << i << "\t";
		
		for (j = 0; j < 1; j++) {

			if (i == 10) {
				color (64);
				cout << "\t M E T A         ";
				
			}
			
			else if (((i+j) % 2 == 0) && (i != 10)) {
				color (51);
				cout << "[\t\t\t" << "]";
			}
			
			else if ((i+j) % 2 != 0) {
				color (17);
				cout << "[\t\t\t" << "]";
			}	
		}
		
		color (00);
		cout << "[\t\t\t" << "]" << endl;
	}

	color (7);
}

// Definición de la función "movimiento_casilla"
void movimiento_casilla (int& casilla) {	// Paso de parámetros por Referencia
	
	int i, j;
	
	cout << "\n" << endl;
	
	for (i = 1; i <= 10; i++) {
		
		color (7);
		cout << "\t\t\t" << i << "\t";
		
		for (j = 0; j < 1; j++) {
			
			if (i == 10) {	// Para mostrar el mensaje " M E T A " (de color azul claro)
				
				color (59);
				cout << "\t M E T A         ";	
			}
			
			else if (i == casilla) {
				color (68);		// Casilla de color rojo
				cout << "[\t\t\t" << "]";
			}
			
			else if ((i+j) % 2 == 0) {
				color (51);
				cout << "[\t\t\t" << "]";
			}
			
			else {
				color (17);
				cout << "[\t\t\t" << "]";
			}		
		}
		
		color (00);
		cout << "[\t\t\t" << "]" << endl;
	}
	
	color (7);
}

// Definición de la función "lanzar_dado"
void lanzar_dado (int& casilla) {	// Paso de parámetros por Referencia
	
	int dado = 0;
	
	dado = 1 + (rand () % 6);
	
	casilla += dado;	// casilla = casilla + dado
	
	cout << "\t\tDado: " << dado << "\t\t-------->\t" << "Casilla: "<< casilla << endl;
}

