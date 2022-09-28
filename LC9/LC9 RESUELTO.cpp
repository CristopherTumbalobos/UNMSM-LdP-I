// UNMSM – Facultad de Ing. Electrónica y Eléctrica 
// Escuela de Ingeniería Electrónica
// Curso: Lenguaje de Programación
// Docente: Avila López, B. Patricio 
// Estudiante: Tumbalobos Peralta, Cristopher Rigoberto
// Fecha: 21/08/2020 
// Laboratorio Calificado 09
// Objetivo: Realizar un simulador de depósito a plazo.
// Datos de entrada: La opción de una moneda, cantidad a depositar, el plazo elegido y la fecha de inicio del depósito.
// Restricciones: En cada uno de los datos de entrada, solo se tomará en cuenta el primer número escrito.

#include <iostream>		// Para el flujo (entrada y salida) de datos
#include <locale.h>		// Para la ortografía de las palabras
#include <string>		// Para usar getline (), strcpy () y strlen ()
#include <sstream>		// Para usar istringstream ()
#include <stdlib.h>		// Para usar atoi ()
#include <conio.h>		// Para usar getch ()
#include <stdio.h>		// Para usar fflush ()
#include <windows.h>	// Para usar SetConsoleTextAttribute ()
#include <iomanip>		// Para usar setprecision ()
#include <math.h>		// Para usar pow ()

using namespace std;

// Prototipo de la función "validar_moneda"
template <class TIPOD>
void validar_moneda (TIPOD num, double numero, int &entero);

// Prototipo de la función "validar_cantidad_a_depositar"
template <class TIPOD>
void validar_cantidad_a_depositar (TIPOD num, double numero, int &entero);

// Prototipo de la función "color"
int color (int n);

// Prototipo de la función "tabla_plazo"
void tabla_plazo (int moneda);

// Prototipo de la función "validar_plazo"
template <class TIPOD>
void validar_plazo (TIPOD num, double numero, int &entero);

// Prototipo de la función "validar_anio"
template <class TIPOD>
void validar_anio (TIPOD num, double numero, int &entero);

// Prototipo de la función "validar_bisiesto"
void validar_bisiesto (int anio, char &bisiesto);

// Prototipo de la función "tabla_mes"
void tabla_mes ();

// Prototipo de la función "validar_mes"
template <class TIPOD>
void validar_mes (TIPOD num, double numero, int &entero);

// Prototipo de la función "validar_dia"
template <class TIPOD>
void validar_dia (TIPOD num, double numero, int &entero);

// Prototipo de la función "validar_fecha"
void validar_fecha (int dia, int mes, char bisiesto, bool &fin);

// Prototipo de la función "ganacia_x_interes"
void ganancia_x_interes (int moneda, int plazo, int cantidad_a_depositar, double &interes_ganado);

// Prototipo de la función "calcular_vencimiento"
void calcular_vencimiento (int dia, int mes, int anio, char bisiesto, int plazo);

int main () {
	setlocale (LC_ALL, "");
	
	string n1;
	double numero;
	int entero;
	
	int moneda;
	int cantidad_a_depositar;
	int plazo;
	int anio;
	char bisiesto;
	int mes;
	int dia;
	bool fin1 = false;
	double interes_ganado;
	
	cout << "NOTA: En cada uno de los datos requeridos, solo se tomará en cuenta el primer número escrito." << endl;
	
	cout << "\n\t\tS I M U L A D O R   D E   D E P Ó S I T O   A   P L A Z O" << endl;
	cout << "\n\tM O N E D A" << endl;
	cout << "\n\t\tIngrese la moneda: " << endl;
	cout << "\t\t1. Soles" << endl;
	cout << "\t\t2. US$" << endl;
	
	validar_moneda (n1, numero, moneda);	// Escoger Moneda
	
	cout << "\n\tC A N T I D A D   A   D E P O S I T A R" << endl;
	
	validar_cantidad_a_depositar (n1, numero, cantidad_a_depositar);	// Ingresa cantidad a depositar
	
	tabla_plazo (moneda);	// Muestra la tabla de los plazos de acuerdo a la moneda escogida
	
	cout << "\n\tP L A Z O   D E L   D E P Ó S I T O" << endl;
	
	validar_plazo (n1, numero, plazo);		// Elegir plazo
	
	cout << "\n\tF E C H A   D E   I N I C I O   D E L   D E P Ó S I T O" << endl;
	
	validar_anio (n1, numero, anio);		// Ingresar año
	
	validar_bisiesto (anio, bisiesto);		// Valida si el año es bisiesto
	
	tabla_mes ();	// Muestra el cuadro de los meses con su respectivo valor numérico 
	
	validar_mes (n1, numero, mes);		// Ingresar mes
	
	while (!fin1) {
		
		validar_dia (n1, numero, dia);		// Ingresar día
		
		validar_fecha (dia, mes, bisiesto, fin1);	// Valida si la fecha es correcta
	}
	
	cout << "\n\tG A N A N C I A   P O R   I N T E R É S" << endl;
	
	ganancia_x_interes (moneda, plazo, cantidad_a_depositar, interes_ganado);	// Calcula la ganancia por interés
	
	if (moneda == 1) {
		cout << "\n\t\tInterés ganado: " << fixed << setprecision (2) << interes_ganado << " Soles" << endl;
	}
	else if (moneda == 2) {
		cout << "\n\t\tInterés ganado: " << fixed << setprecision (2) << interes_ganado << " US$" << endl;
	}
	
	cout << "\n\tF E C H A   D E   V E N C I M I E N T O   D E L   P L A Z O"	<< endl;
	
	calcular_vencimiento (dia, mes, anio, bisiesto, plazo);		// Calcula y muestra la fecha de vencimiento

	getch ();
	return 0;
}

// Definición de la función "validar_moneda"
template <class TIPOD>
void validar_moneda (TIPOD num, double numero, int &entero) {
	
	int longitud_caracteres, espacios_blanco = 0;
	char cadena [100] = "";
	bool fin2 = false;
	
	while (!fin2) {	
		
		fflush (stdin);	 // Para limpiar la entrada de datos
		cout<<"\n\t\tIngrese una opción: ";
		getline(cin,num);
		
		if (istringstream(num) >> numero) {		// Con este if verificamos si es un número
			
			entero = numero;
			entero = atoi (num.c_str());	// Conversión de char a entero
			
			if (numero - entero) {	// Con este if verificamos si el número es un decimal
				cout << "\t\tUsted ingresó un número decimal, por favor ingrese el número 1 o 2." << endl;
			}
			
			else if ((numero == 1) || (numero ==2)) {	// Con este if verificamos que sea el número 1 o 2
				fin2 = true;
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
		}
	}
}

// Definición de la función "validar_cantidad_a_depositar"
template <class TIPOD>
void validar_cantidad_a_depositar (TIPOD num, double numero, int &entero) {
	
	int longitud_caracteres, espacios_blanco = 0;
	char cadena [100] = "";
	bool fin2 = false;
	
	while (!fin2) {	
		
		fflush (stdin);	 // Para limpiar la entrada de datos
		cout<<"\n\t\tDigite la cantidad a depositar: ";
		getline(cin,num);
		
		if (istringstream(num) >> numero) {		// Con este if verificamos si es un número
			
			entero = numero;
			entero = atoi (num.c_str());	// Conversión de char a entero
			
			if (numero - entero) {	// Con este if verificamos si el número es un decimal
				cout << "\t\tUsted ingresó un número decimal, por favor ingrese un número entero positivo." << endl;
			}
			
			else if (numero > 0) {	// Con este if verificamos que sea el número 1 o 2
				fin2 = true;
			}
			
			else {
				cout << "\t\tUsted ingresó una cantidad no válida, por favor ingrese un número entero positivo." << endl;	// Ej: -6, 0, 3, 4, ...
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
				cout << "\t\tUsted digitó un espacio en blanco, por favor ingrese un número entero positivo." << endl;
			}
			
			else if (espacios_blanco > 1) {	// verificamos si digitó más de un espacio en blanco
				cout << "\t\tUsted digitó varios espacios en blanco, por favor ingrese un número entero positivo." << endl;
			}
			
			else if (longitud_caracteres == 0){	// verificamos si no digitó ningún valor
				cout << "\t\tNo digitó ningun valor, por favor ingrese un número entero positivo." << endl;
			}
			
			else if (longitud_caracteres == 1) {	// verificamos si ingresó un caracter
				cout << "\t\tUsted ingresó una caracter, por favor ingrese un número entero positivo." << endl;
			}
			
			else if (longitud_caracteres > 1) {	// verificamos si ingreso más de un caracter
				cout << "\t\tUsted ingresó varios caracteres, por favor ingrese un número entero positivo." << endl;
			}
		}
	}
}

// Definición de la funcion "color"
int color (int n) {
	
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), n);
}

// Definición de la función "tabla_plazo"
void tabla_plazo (int moneda) {
	
	cout << "\n\t\t\t\t\t\tTABLA DE PLAZOS\n" << endl;
	
	for (int i = 1; i <= 5; i++) {
		
		color (7);
		cout << "\t\t\t\t";
		
		for (int j = 1; j <= 2; j++) {

			if (j == 1) {
				
				switch (i) {
					case 1:
						color (18);
						cout << "      PLAZO      ";
						break;
					case 2:
						color (57);
						cout << "     360 días    ";
						break;
					case 3:
						color (18);
						cout << "     270 días    ";
						break;
					case 4:
						color (57);
						cout << "     180 días    ";
						break;
					case 5:
						color (18);
						cout << "     90 días     ";
						break;
				}	
			}

			else if (j == 2) {
				
				if (moneda == 1) {
					
					switch (i) {
						
						case 1:
							color (18);
							cout << "  TASA DE INTERÉS (SOLES)  ";
							break;
						case 2:
							color (57);
							cout << "           0.34 %          ";
							break;
						case 3:
							color (18);
							cout << "           0.27 %          ";
							break;
						case 4:
							color (57);
							cout << "           0.22 %          ";
							break;
						case 5:
							color (18);
							cout << "           0.05 %          ";
							break;
					}
				}
				
				if (moneda == 2) {
					
					switch (i) {
						
						case 1:
							color (18);
							cout << "   TASA DE INTERÉS (US$)   ";
							break;
						case 2:
							color (57);
							cout << "           0.28 %          ";
							break;
						case 3:
							color (18);
							cout << "           0.25 %          ";
							break;
						case 4:
							color (57);
							cout << "           0.20 %          ";
							break;
						case 5:
							color (18);
							cout << "           0.02 %          ";
							break;	
					}	
				}			
			}

			else if (((i+j) % 2 == 0) && (i != 5)) {
				color (51);
				cout << "[\t\t" << "]";
			}
			
			else if ((i+j) % 2 != 0) {
				color (17);
				cout << "[\t\t" << "]";
			}		
		}
		
		color (00);
		cout << "[\t\t" << "]" << endl;
	}
	
	color (7);
}

// Definición de la función "validar_plazo"
template <class TIPOD>
void validar_plazo (TIPOD num, double numero, int &entero) {
	
	int longitud_caracteres, espacios_blanco = 0;
	char cadena [100] = "";
	bool fin2 = false;
	
	while (!fin2) {	
		
		fflush (stdin);	 // Para limpiar la entrada de datos
		cout<<"\n\t\tIngrese el plazo: ";
		getline(cin,num);
		
		if (istringstream(num) >> numero) {		// Con este if verificamos si es un número
			
			entero = numero;
			entero = atoi (num.c_str());	// Conversión de char a entero
			
			if (numero - entero) {	// Con este if verificamos si el número es un decimal
				cout << "\t\tUsted ingresó un número decimal, por favor ingrese uno de los plazos indicados en la tabla." << endl;
			}
			
			else if ((numero == 90) || (numero == 180) || (numero == 270) || (numero == 360)) {	// Con este if verificamos que sea el número 1 o 2
				fin2 = true;
			}
			
			else {
				cout << "\t\tUsted ingresó un plazo no válido, por favor ingrese uno de los plazos indicados en la tabla." << endl;	// Ej: -6, 0, 3, 4, ...
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
				cout << "\t\tUsted digitó un espacio en blanco, por favor ingrese uno de los plazos indicados en la tabla." << endl;
			}
			
			else if (espacios_blanco > 1) {	// verificamos si digitó más de un espacio en blanco
				cout << "\t\tUsted digitó varios espacios en blanco, por favor ingrese uno de los plazos indicados en la tabla." << endl;
			}
			
			else if (longitud_caracteres == 0){	// verificamos si no digitó ningún valor
				cout << "\t\tNo digitó ningun valor, por favor ingrese uno de los plazos indicados en la tabla." << endl;
			}
			
			else if (longitud_caracteres == 1) {	// verificamos si ingresó un caracter
				cout << "\t\tUsted ingresó una caracter, por favor ingrese uno de los plazos indicados en la tabla." << endl;
			}
			
			else if (longitud_caracteres > 1) {	// verificamos si ingreso más de un caracter
				cout << "\t\tUsted ingresó varios caracteres, por favor ingrese uno de los plazos indicados en la tabla." << endl;
			}
		}
	}
}

// Definición de la función "validar_anio"
template <class TIPOD>
void validar_anio (TIPOD num, double numero, int &entero) {
	
	int longitud_caracteres, espacios_blanco = 0;
	char cadena [100] = "";
	bool fin2 = false;
	
	while (!fin2) {	
		
		fflush (stdin);	 // Para limpiar la entrada de datos
		cout<<"\n\t\tIngrese el año: ";
		getline(cin,num);
		
		if (istringstream(num) >> numero) {		// Con este if verificamos si es un número
			
			entero = numero;
			entero = atoi (num.c_str());	// Conversión de char a entero
			
			if (numero - entero) {	// Con este if verificamos si el número es un decimal
				cout << "\t\tUsted ingresó un número decimal, por favor ingrese un número entero positivo." << endl;
			}
			
			else if (numero > 0) {	// Con este if verificamos que sea el número 1 o 2
				fin2 = true;
			}
			
			else {
				cout << "\t\tUsted ingresó un año no válido, por favor ingrese un número entero positivo." << endl;	// Ej: -6, 0, 3, 4, ...
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
				cout << "\t\tUsted digitó un espacio en blanco, por favor ingrese un número entero positivo." << endl;
			}
			
			else if (espacios_blanco > 1) {	// verificamos si digitó más de un espacio en blanco
				cout << "\t\tUsted digitó varios espacios en blanco, por favor ingrese un número entero positivo." << endl;
			}
			
			else if (longitud_caracteres == 0){	// verificamos si no digitó ningún valor
				cout << "\t\tNo digitó ningun valor, por favor ingrese un número entero positivo." << endl;
			}
			
			else if (longitud_caracteres == 1) {	// verificamos si ingresó un caracter
				cout << "\t\tUsted ingresó una caracter, por favor ingrese un número entero positivo." << endl;
			}
			
			else if (longitud_caracteres > 1) {	// verificamos si ingreso más de un caracter
				cout << "\t\tUsted ingresó varios caracteres, por favor ingrese un número entero positivo." << endl;
			}
		}
	}
}

// Definición de la función "validar_bisiesto"
void validar_bisiesto (int anio, char &bisiesto) {
	
	if (anio % 400 == 0) {
		bisiesto = 'S';
	}
	
	else {
		if (anio % 100 == 0) {
			bisiesto = 'N';
		}
		
		else {
			if (anio % 4 == 0) {
				bisiesto = 'S';
			}
			
			else {
				bisiesto = 'N';
			}	
		}	
	}
}

// Definición de la función "tabla_mes"
void tabla_mes () {
	
	cout << "\n\t\t\t\t\t   TABLA DE MESES\n" << endl;
	
	for (int i = 1; i <= 13; i++) {
		
		color (7);
		cout << "\t\t\t\t";
		
		for (int j = 1; j <= 2; j++) {

			if (j == 1) {
				
				switch (i) {
					case 1:
						color (18);
						cout << "      M E S      ";
						break;
					case 2:
						color (57);
						cout << "      Enero      ";
						break;
					case 3:
						color (18);
						cout << "     Febrero     ";
						break;
					case 4:
						color (57);
						cout << "      Marzo      ";
						break;
					case 5:
						color (18);
						cout << "      Abril      ";
						break;
					case 6:
						color (57);
						cout << "       Mayo      ";
						break;
					case 7:
						color (18);
						cout << "      Junio      ";
						break;
					case 8:
						color (57);
						cout << "      Julio      ";
						break;
					case 9:
						color (18);
						cout << "      Agosto     ";
						break;
					case 10:
						color (57);
						cout << "    Septiembre   ";
						break;
					case 11:
						color (18);
						cout << "     Octubre     ";
						break;
					case 12:
						color (57);
						cout << "    Noviembre    ";
						break;
					case 13:
						color (18);
						cout << "    Diciembre    ";
						break;
				}	
			}

			else if (j == 2) {

				switch (i) {
					
					case 1:
						color (18);
						cout << "    V A L O R    ";
						break;
					case 2:
						color (57);
						cout << "       1         ";
						break;
					case 3:
						color (18);
						cout << "       2         ";
						break;
					case 4:
						color (57);
						cout << "       3         ";
						break;
					case 5:
						color (18);
						cout << "       4         ";
						break;
					case 6:
						color (57);
						cout << "       5         ";
						break;
					case 7:
						color (18);
						cout << "       6         ";
						break;
					case 8:
						color (57);
						cout << "       7         ";
						break;
					case 9:
						color (18);
						cout << "       8         ";
						break;	
					case 10:
						color (57);
						cout << "       9         ";
						break;
					case 11:
						color (18);
						cout << "       10        ";
						break;
					case 12:
						color (57);
						cout << "       11        ";
						break;
					case 13:
						color (18);
						cout << "       12        ";
						break;		
				}
			}
			
			else if (((i+j) % 2 == 0) && (i != 5)) {
				color (51);
				cout << "[\t\t" << "]";
			}
			
			else if ((i+j) % 2 != 0) {
				color (17);
				cout << "[\t\t" << "]";
			}		
		}
		
		color (00);
		cout << "[\t\t" << "]" << endl;
	}
	
	color (7);
}

// Definición de la función "validar_mes"
template <class TIPOD>
void validar_mes (TIPOD num, double numero, int &entero) {
	
	int longitud_caracteres, espacios_blanco = 0;
	char cadena [100] = "";
	bool fin2 = false;
	
	while (!fin2) {	
		
		fflush (stdin);	 // Para limpiar la entrada de datos
		cout<<"\n\t\tIngrese el valor numérico de un mes: ";
		getline(cin,num);
		
		if (istringstream(num) >> numero) {		// Con este if verificamos si es un número
			
			entero = numero;
			entero = atoi (num.c_str());	// Conversión de char a entero
			
			if (numero - entero) {	// Con este if verificamos si el número es un decimal
				cout << "\t\tUsted ingresó un número decimal, por favor ingrese el valor numérico de un mes según la tabla." << endl;
			}
			
			else if ((numero >= 1) && (numero <= 12)) {	// Con este if verificamos que sea el número 1 o 2
				fin2 = true;
			}
			
			else {
				cout << "\t\tUsted ingresó un mes no válido, por favor ingrese el valor numérico de un mes según la tabla." << endl;	// Ej: -6, 0, 3, 4, ...
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
				cout << "\t\tUsted digitó un espacio en blanco, por favor ingrese el valor numérico de un mes según la tabla." << endl;
			}
			
			else if (espacios_blanco > 1) {	// verificamos si digitó más de un espacio en blanco
				cout << "\t\tUsted digitó varios espacios en blanco, por favor ingrese el valor numérico de un mes según la tabla." << endl;
			}
			
			else if (longitud_caracteres == 0){	// verificamos si no digitó ningún valor
				cout << "\t\tNo digitó ningun valor, por favor ingrese el valor numérico de un mes según la tabla." << endl;
			}
			
			else if (longitud_caracteres == 1) {	// verificamos si ingresó un caracter
				cout << "\t\tUsted ingresó una caracter, por favor ingrese el valor numérico de un mes según la tabla." << endl;
			}
			
			else if (longitud_caracteres > 1) {	// verificamos si ingreso más de un caracter
				cout << "\t\tUsted ingresó varios caracteres, por favor ingrese el valor numérico de un mes según la tabla." << endl;
			}
		}
	}
}

// Definición de la función "validar_dia"
template <class TIPOD>
void validar_dia (TIPOD num, double numero, int &entero) {
	
	int longitud_caracteres, espacios_blanco = 0;
	char cadena [100] = "";
	bool fin2 = false;
	
	while (!fin2) {	
		
		fflush (stdin);	 // Para limpiar la entrada de datos
		cout<<"\n\t\tIngrese el dia: ";
		getline(cin,num);
		
		if (istringstream(num) >> numero) {		// Con este if verificamos si es un número
			
			entero = numero;
			entero = atoi (num.c_str());	// Conversión de char a entero
			
			if (numero - entero) {	// Con este if verificamos si el número es un decimal
				cout << "\t\tUsted ingresó un número decimal, por favor ingrese el número de un día válido." << endl;
			}
			
			else if (numero >= 1) {	// Con este if verificamos que sea el número 1 o 2
				fin2 = true;
			}
			
			else {
				cout << "\t\tUsted ingresó un dia no válido, por favor ingrese el número de un día válido." << endl;	// Ej: -6, 0, 3, 4, ...
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
				cout << "\t\tUsted digitó un espacio en blanco, por favor ingrese el número de un día válido." << endl;
			}
			
			else if (espacios_blanco > 1) {	// verificamos si digitó más de un espacio en blanco
				cout << "\t\tUsted digitó varios espacios en blanco, por favor ingrese el número de un día válido." << endl;
			}
			
			else if (longitud_caracteres == 0){	// verificamos si no digitó ningún valor
				cout << "\t\tNo digitó ningun valor, por favor ingrese el número de un día válido." << endl;
			}
			
			else if (longitud_caracteres == 1) {	// verificamos si ingresó un caracter
				cout << "\t\tUsted ingresó una caracter, por favor ingrese el número de un día válido." << endl;
			}
			
			else if (longitud_caracteres > 1) {	// verificamos si ingreso más de un caracter
				cout << "\t\tUsted ingresó varios caracteres, por favor ingrese el número de un día válido." << endl;
			}
		}
	}
}

// Definición de la función "validar_fecha"
void validar_fecha (int dia, int mes, char bisiesto, bool &fin) {
	
	if ((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12)) {
		
		if (dia <= 31) {
			cout << "Fecha válida" << endl;
			fin = true;
		}
		
		else {
			cout << "Fecha inválida" << endl;
		}
	}

	else if ((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11)) {
		
		if (dia <= 30) {
			cout << "Fecha válida" << endl;
			fin = true;
		}
		
		else {
			cout << "Fecha inválida" << endl;
		}
	}

	else if (mes == 2) {
		
		if (bisiesto == 'S') {
			
			if (dia <= 29) {
				cout << "Fecha válida" << endl;
				fin = true;
			}
			
			else {
				cout << "Fecha inválida" << endl;
			}
		}
		
		else if (bisiesto == 'N') {
			
			if (dia <= 28) {
				cout << "Fecha válida" << endl;
				fin = true;
			}
			
			else {
				cout << "Fecha inválida" << endl;
			}
		}	
	}
}

// Definición de la función "ganancia_x_interes"
void ganancia_x_interes (int moneda, int plazo, int cantidad_a_depositar, double &interes_ganado) {
	
	if (moneda == 1) {
		
		if (plazo == 90) {
			interes_ganado = cantidad_a_depositar * (pow(1 + 0.0005, 90.0/360)-1);
		}
		else if (plazo == 180) {
			interes_ganado = cantidad_a_depositar * (pow(1 + 0.0022, 180.0/360)-1);
		}
		else if (plazo == 270) {
			interes_ganado = cantidad_a_depositar * (pow(1 + 0.0027, 270.0/360)-1);
		}
		else if (plazo == 360) {
			interes_ganado = cantidad_a_depositar * (pow(1 + 0.0034, 360.0/360)-1);
		}	
	}
	
	if (moneda == 2) {
		
		if (plazo == 90) {
			interes_ganado = cantidad_a_depositar * (pow(1 + 0.0002, 90.0/360)-1);
		}
		else if (plazo == 180) {
			interes_ganado = cantidad_a_depositar * (pow(1 + 0.0020, 180.0/360)-1);
		}
		else if (plazo == 270) {
			interes_ganado = cantidad_a_depositar * (pow(1 + 0.0025, 270.0/360)-1);
		}
		else if (plazo == 360) {
			interes_ganado = cantidad_a_depositar * (pow(1 + 0.0028, 360.0/360)-1);
		}	
	}
}

// Definición de la función "calcular_vencimiento" 
void calcular_vencimiento (int dia, int mes, int anio, char bisiesto, int plazo) {
	
	char bisiesto2;
	
	cout << "\n\t\t";
	
	if (plazo == 90) {
		
		if ((anio % 4 == 0) && (bisiesto == 'S')) {
			
			if (mes == 1) {
				
				if (dia == 1) {
					cout << dia + 30 << " de Marzo del " << anio << endl;				
				}
				
				else if ((dia >= 2) && (dia <= 31)) {
					cout << dia - 1 << " de Abril del " << anio << endl;
				}
			}
			
			else if (mes == 2) {
				
				if ((dia >= 1) && (dia <= 29)) {
					cout << dia << " de Mayo del " << anio << endl;
				}	
			}
			
			else if (mes == 3) {
				
				if ((dia == 1) || (dia == 2)) {
					cout << dia + 29 << " de Mayo del " << anio << endl;
				}
				
				else if ((dia >= 3) && (dia <= 31)) {
					cout << dia - 2 << " de Junio del " << anio << endl;
				}
			}
			
			else if (mes == 4) {
				
				if (dia == 1) {
					cout << dia + 29 << " de Junio del " << anio << endl;
				}
				
				else if ((dia >= 2) && (dia <= 30)) {
					cout << dia - 1 << " de Julio del " << anio << endl;
				}
			}
			
			else if (mes == 5) {
				
				if ((dia == 1) || (dia == 2)) {
					cout << dia + 29 << " de Julio del " << anio << endl;
				}
				
				else if ((dia >= 3) && (dia <= 31)) {
					cout << dia - 2 << " de Agosto del " << anio << endl;
				}
			}
			
			else if (mes == 6) {
				
				if ((dia == 1) || (dia == 2)) {
					cout << dia + 29 << " de Agosto del " << anio << endl;
				}
				
				else if ((dia >= 3) && (dia <= 30)) {
					cout << dia - 2 << " de Septiembre del " << anio << endl;
				}
			}
			
			else if (mes == 7) {
				
				if ((dia == 1) || (dia == 2)) {
					cout << dia + 28 << " de Septiembre del " << anio << endl;
				}
				
				else if ((dia >= 3) && (dia <= 31)) {
					cout << dia - 2 << " de Octubre del " << anio << endl;
				}
			}
			
			else if (mes == 8) {
				
				if ((dia == 1) || (dia == 2)) {
					cout << dia + 29 << " de Octubre del " << anio << endl;
				}
				
				else if ((dia >= 3) && (dia <= 31)) {
					cout << dia - 2 << " de Noviembre del " << anio << endl;
				}
			}
			
			else if (mes == 9) {
				
				if (dia == 1) {
					cout << dia + 29 << " de Noviembre del " << anio << endl;
				}
				
				else if ((dia >= 2) && (dia <= 30)) {
					cout << dia - 1 << " de Diciembre del " << anio << endl;
				}
			}
			
			else if (mes == 10) {
				
				if ((dia == 1) || (dia == 2)) {
					cout << dia + 29 << " de Diciembre del " << anio << endl;
				}
				
				else if ((dia >= 3) && (dia <= 31)) {
					cout << dia - 2 << " de Enero del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 11) {
				
				if ((dia == 1) || (dia == 2)) {
					cout << dia + 29 << " de Enero del " << anio + 1 << endl;
				}
				
				else if ((dia >= 3) && (dia <= 30)) {
					cout << dia - 2 << " de Febrero del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 12) {
				
				if ((dia >= 1) && (dia <= 31)) {
					cout << dia << " de Marzo del " << anio + 1 << endl;
				}
			}
		}
		
		else if ((anio % 4 == 1) || (anio % 4 == 2) || ((anio % 4 == 0) && (bisiesto = 'N'))) {
			
			if (mes == 1) {
				
				if ((dia >= 1) && (dia <= 30)) {
					cout << dia << " de Abril del " << anio << endl;
				}
				
				else if (dia == 31) {
					cout << dia - 30 << " de Mayo del " << anio << endl;
				}
			}
			
			else if (mes == 2) {
				
				if ((dia >= 1) && (dia <= 28)) {
					cout << dia + 1 << " de Mayo del " << anio << endl;	
				}
			}
			
			else if (mes == 3) {
				
				if ((dia == 1) || (dia == 2)) {
					cout << dia + 29 << " de Mayo del " << anio << endl;
				}
				
				else if ((dia >= 3) && (dia <= 31)) {
					cout << dia - 2 << " de Junio del " << anio << endl;
				}
			}
			
			else if (mes == 4) {
				
				if (dia == 1) {
					cout << dia + 29 << " de Junio del " << anio << endl;
				}
				
				else if ((dia >= 2) && (dia <= 30)) {
					cout << dia - 1 << " de Julio del " << anio << endl;
				}
			}
			
			else if (mes == 5) {
				
				if ((dia == 1) || (dia == 2)) {
					cout << dia + 29 << " de Julio del " << anio << endl;
				}
				
				else if ((dia >= 3) && (dia <= 31)) {
					cout << dia - 2 << " de Agosto del " << anio << endl;
				}
			}
			
			else if (mes == 6) {
				
				if ((dia == 1) || (dia == 2)) {
					cout << dia + 29 << " de Agosto del " << anio << endl;
				}
				
				else if ((dia >= 3) && (dia <= 30)) {
					cout << dia - 2 << " de Septiembre del " << anio << endl;
				}
			}
			
			else if (mes == 7) {
				
				if ((dia == 1) || (dia == 2)) {
					cout << dia + 28 << " de Septiembre del " << anio << endl;
				}
				
				else if ((dia >= 3) && (dia <= 31)) {
					cout << dia - 2 << " de Octubre del " << anio << endl;
				}
			}
			
			else if (mes == 8) {
				
				if ((dia == 1) || (dia == 2)) {
					cout << dia + 29 << " de Octubre del " << anio << endl;
				}
				
				else if ((dia >= 3) && (dia <= 31)) {
					cout << dia - 2 << " de Noviembre del " << anio << endl;
				}
			}
			
			else if (mes == 9) {
				
				if (dia == 1) {
					cout << dia + 29 << " de Noviembre del " << anio << endl;
				}
				
				else if ((dia >= 2) && (dia <= 30)) {
					cout << dia - 1 << " de Diciembre del " << anio << endl;
				}
			}
			
			else if (mes == 10) {
				
				if ((dia == 1) || (dia == 2)) {
					cout << dia + 29 << " de Diciembre del " << anio << endl;
				}
				
				else if ((dia >= 3) && (dia <= 31)) {
					cout << dia - 2 << " de Enero del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 11) {
				
				if ((dia == 1) || (dia == 2)) {
					cout << dia + 29 << " de Enero del " << anio + 1 << endl;
				}
				
				else if ((dia >= 3) && (dia <= 30)) {
					cout << dia - 2 << " de Febrero del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 12) {
				
				if ((dia >= 1) && (dia <= 31)) {
					cout << dia << " de Marzo del " << anio + 1 << endl;
				}	
			}
		}
		
		else if (anio % 4 == 3) {
			
			if (mes == 1) {
				
				if ((dia >= 1) && (dia <= 30)) {
					cout << dia << " de Abril del " << anio << endl;
				}
				
				else if (dia == 31) {
					cout << dia - 30 << " de Mayo del " << anio << endl;
				}
			}
			
			else if (mes == 2) {
				
				if ((dia >= 1) && (dia <= 28)) {
					cout << dia + 1 << " de Mayo del " << anio << endl;	
				}
			}
			
			else if (mes == 3) {
				
				if ((dia == 1) || (dia == 2)) {
					cout << dia + 29 << " de Mayo del " << anio << endl;
				}
				
				else if ((dia >= 3) && (dia <= 31)) {
					cout << dia - 2 << " de Junio del " << anio << endl;
				}
			}
			
			else if (mes == 4) {
				
				if (dia == 1) {
					cout << dia + 29 << " de Junio del " << anio << endl;
				}
				
				else if ((dia >= 2) && (dia <= 30)) {
					cout << dia - 1 << " de Julio del " << anio << endl;
				}
			}
			
			else if (mes == 5) {
				
				if ((dia == 1) || (dia == 2)) {
					cout << dia + 29 << " de Julio del " << anio << endl;
				}
				
				else if ((dia >= 3) && (dia <= 31)) {
					cout << dia - 2 << " de Agosto del " << anio << endl;
				}
			}
			
			else if (mes == 6) {
				
				if ((dia == 1) || (dia == 2)) {
					cout << dia + 29 << " de Agosto del " << anio << endl;
				}
				
				else if ((dia >= 3) && (dia <= 30)) {
					cout << dia - 2 << " de Septiembre del " << anio << endl;
				}
			}
			
			else if (mes == 7) {
				
				if ((dia == 1) || (dia == 2)) {
					cout << dia + 28 << " de Septiembre del " << anio << endl;
				}
				
				else if ((dia >= 3) && (dia <= 31)) {
					cout << dia - 2 << " de Octubre del " << anio << endl;
				}
			}
			
			else if (mes == 8) {
				
				if ((dia == 1) || (dia == 2)) {
					cout << dia + 29 << " de Octubre del " << anio << endl;
				}
				
				else if ((dia >= 3) && (dia <= 31)) {
					cout << dia - 2 << " de Noviembre del " << anio << endl;
				}
			}
			
			else if (mes == 9) {
				
				if (dia == 1) {
					cout << dia + 29 << " de Noviembre del " << anio << endl;
				}
				
				else if ((dia >= 2) && (dia <= 30)) {
					cout << dia - 1 << " de Diciembre del " << anio << endl;
				}
			}
			
			else if (mes == 10) {
				
				if ((dia == 1) || (dia == 2)) {
					cout << dia + 29 << " de Diciembre del " << anio << endl;
				}
				
				else if ((dia >= 3) && (dia <= 31)) {
					cout << dia - 2 << " de Enero del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 11) {
				
				if ((dia == 1) || (dia == 2)) {
					cout << dia + 29 << " de Enero del " << anio + 1 << endl;
				}
				
				else if ((dia >= 3) && (dia <= 30)) {
					cout << dia - 2 << " de Febrero del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 12) {
				
				validar_bisiesto (anio + 1, bisiesto2);
				
				if (((anio + 1) % 4 == 0) && (bisiesto2 == 'S')) {
				
					if (dia == 1) {
						cout << dia + 28 << " de Febrero del " << anio + 1 << endl;
					}
				
					else if ((dia >= 2) && (dia <= 31)) {
						cout << dia - 1 << " de Marzo del " << anio + 1 << endl;
					}
				}
				
				else if (((anio + 1) % 4 == 0) && (bisiesto2 = 'N')) {
					
					if ((dia >= 1) && (dia <= 31)) {
						cout << dia << " de Marzo del " << anio + 1 << endl;
					}
				}	
			}
		}
	}
	
	else if (plazo == 180) {
		
		if ((anio % 4 == 0) && (bisiesto == 'S')) {
			
			if (mes == 1) {
				
				if ((dia == 1) || (dia == 2)) {
					cout << dia + 28 << " de Junio del " << anio << endl;
				}
				
				else if ((dia >= 3) && (dia <= 31)) {
					cout << dia - 2 << " de Julio del " << anio << endl;
				}
			}
			
			else if (mes == 2) {
				
				if ((dia == 1) || (dia == 2)) {
					cout << dia + 29 << " de Julio del " << anio << endl;
				}
				
				else if ((dia >= 3) && (dia <= 29)) {
					cout << dia - 2 << " de Agosto del " << anio << endl;
				}
			}
			
			else if (mes == 3) {
				
				if ((dia >= 1) && (dia <= 4)) {
					cout << dia + 27 << " de Agosto del " << anio << endl;
				}
				
				else if ((dia >= 5) && (dia <= 31)) {
					cout << dia - 4 << " de Septiembre del " << anio << endl;
				}
			}
			
			else if (mes == 4) {
				
				if ((dia >= 1) && (dia <= 3)) {
					cout << dia + 27 << " de Septiembre del " << anio << endl;
				}
				
				else if ((dia >= 4) && (dia <= 30)) {
					cout << dia - 3 << " de Octubre del " << anio << endl;
				}	
			}
			
			else if (mes == 5) {
				
				if ((dia >= 1) && (dia <= 4)) {
					cout << dia + 27 << " de Octubre del " << anio << endl;
				}
				
				else if ((dia >= 5) && (dia <= 31)) {
					cout << dia - 4 << " de Noviembre del " << anio << endl;
				}
			}
			
			else if (mes == 6) {
				
				if ((dia >= 1) && (dia <= 3)) {
					cout << dia + 27 << " de Noviembre del " << anio << endl;
				}
				
				else if ((dia >= 4) && (dia <= 30)) {
					cout << dia - 3 << " de Diciembre del " << anio << endl;
				}
			}
			
			else if (mes == 7) {
				
				if ((dia >= 1) && (dia <= 4)) {
					cout << dia + 27 << " de Diciembre del " << anio << endl;
				}
				
				else if ((dia >= 5) && (dia <= 31)) {
					cout << dia - 4 << " de Enero del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 8) {
				
				if ((dia >= 1) && (dia <= 4)) {
					cout << dia + 27 << " de Enero del " << anio + 1 << endl;	
				}
				
				else if ((dia >= 5) && (dia <= 31)) {
					cout << dia - 4 << " de Febrero del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 9) {
				
				if (dia == 1) {
					cout << dia + 27 << " de Febrero del " << anio + 1 << endl;
				}
				
				else if ((dia >= 2) && (dia <= 30)) {
					cout << dia - 1 << " de Marzo del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 10) {
				
				if ((dia == 1) || (dia == 2)) {
					cout << dia + 29 << " de Marzo del " << anio + 1 << endl;
				}
				
				else if ((dia >= 3) && (dia <= 31)) {
					cout << dia - 2 << " de Abril del" << anio + 1 << endl;
				}
			}
			
			else if (mes == 11) {
				
				if (dia == 1) {
					cout << dia + 29 << " de Abril del " << anio + 1 << endl;
				}
				
				else if ((dia >= 2) && (dia <= 30)) {
					cout << dia - 1 << " de Mayo del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 12) {
				
				if ((dia == 1) || (dia == 2)) {
					cout << dia + 29 << " de Mayo del " << anio + 1 << endl;
				}
				
				else if ((dia >= 3) && (dia <= 31)) {
					cout << dia - 2 << " de Junio del " << anio + 1 << endl;
				}
			}	
		}
		
		else if ((anio % 4 == 1) || (anio % 4 == 2) || ((anio % 4 == 0) && (bisiesto = 'N'))) {
			
			if (mes == 1) {
				
				if (dia == 1) {
					cout << dia + 29 << " de Junio del " << anio << endl;
				}
				
				else if ((dia >= 2) && (dia <= 31)) {
					cout << dia - 1 << " de Julio del " << anio << endl;
				}
			}
			
			else if (mes == 2) {
				
				if (dia == 1) {
					cout << dia + 30 << " de Julio del " << anio << endl;
				}
				
				else if ((dia >= 2) && (dia <= 28)) {
					cout << dia - 1 << " de Agosto del " << anio << endl;
				}
			}
			
			else if (mes == 3) {
				
				if ((dia >= 1) && (dia <= 4)) {
					cout << dia + 27 << " de Agosto del " << anio << endl;
				}
				
				else if ((dia >= 5) && (dia <= 31)) {
					cout << dia - 4 << " de Septiembre del " << anio << endl;
				}
			}
			
			else if (mes == 4) {
				
				if ((dia >= 1) && (dia <= 3)) {
					cout << dia + 27 << " de Septiembre del " << anio << endl;
				}
				
				else if ((dia >= 4) && (dia <= 30)) {
					cout << dia - 3 << " de Octubre del " << anio << endl;
				}	
			}
			
			else if (mes == 5) {
				
				if ((dia >= 1) && (dia <= 4)) {
					cout << dia + 27 << " de Octubre del " << anio << endl;
				}
				
				else if ((dia >= 5) && (dia <= 31)) {
					cout << dia - 4 << " de Noviembre del " << anio << endl;
				}
			}
			
			else if (mes == 6) {
				
				if ((dia >= 1) && (dia <= 3)) {
					cout << dia + 27 << " de Noviembre del " << anio << endl;
				}
				
				else if ((dia >= 4) && (dia <= 30)) {
					cout << dia - 3 << " de Diciembre del " << anio << endl;
				}
			}
			
			else if (mes == 7) {
				
				if ((dia >= 1) && (dia <= 4)) {
					cout << dia + 27 << " de Diciembre del " << anio << endl;
				}
				
				else if ((dia >= 5) && (dia <= 31)) {
					cout << dia - 4 << " de Enero del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 8) {
				
				if ((dia >= 1) && (dia <= 4)) {
					cout << dia + 27 << " de Enero del " << anio + 1 << endl;	
				}
				
				else if ((dia >= 5) && (dia <= 31)) {
					cout << dia - 4 << " de Febrero del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 9) {
				
				if (dia == 1) {
					cout << dia + 27 << " de Febrero del " << anio + 1 << endl;
				}
				
				else if ((dia >= 2) && (dia <= 30)) {
					cout << dia - 1 << " de Marzo del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 10) {
				
				if ((dia == 1) || (dia == 2)) {
					cout << dia + 29 << " de Marzo del " << anio + 1 << endl;
				}
				
				else if ((dia >= 3) && (dia <= 31)) {
					cout << dia - 2 << " de Abril del" << anio + 1 << endl;
				}
			}
			
			else if (mes == 11) {
				
				if (dia == 1) {
					cout << dia + 29 << " de Abril del " << anio + 1 << endl;
				}
				
				else if ((dia >= 2) && (dia <= 30)) {
					cout << dia - 1 << " de Mayo del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 12) {
				
				if ((dia == 1) || (dia == 2)) {
					cout << dia + 29 << " de Mayo del " << anio + 1 << endl;
				}
				
				else if ((dia >= 3) && (dia <= 31)) {
					cout << dia - 2 << " de Junio del " << anio + 1 << endl;
				}
			}
		}
		
		else if (anio % 4 == 3) {
			
			if (mes == 1) {
				
				if (dia == 1) {
					cout << dia + 29 << " de Junio del " << anio << endl;
				}
				
				else if ((dia >= 2) && (dia <= 31)) {
					cout << dia - 1 << " de Julio del " << anio << endl;
				}
			}
			
			else if (mes == 2) {
				
				if (dia == 1) {
					cout << dia + 30 << " de Julio del " << anio << endl;
				}
				
				else if ((dia >= 2) && (dia <= 28)) {
					cout << dia - 1 << " de Agosto del " << anio << endl;
				}
			}
			
			else if (mes == 3) {
				
				if ((dia >= 1) && (dia <= 4)) {
					cout << dia + 27 << " de Agosto del " << anio << endl;
				}
				
				else if ((dia >= 5) && (dia <= 31)) {
					cout << dia - 4 << " de Septiembre del " << anio << endl;
				}
			}
			
			else if (mes == 4) {
				
				if ((dia >= 1) && (dia <= 3)) {
					cout << dia + 27 << " de Septiembre del " << anio << endl;
				}
				
				else if ((dia >= 4) && (dia <= 30)) {
					cout << dia - 3 << " de Octubre del " << anio << endl;
				}	
			}
			
			else if (mes == 5) {
				
				if ((dia >= 1) && (dia <= 4)) {
					cout << dia + 27 << " de Octubre del " << anio << endl;
				}
				
				else if ((dia >= 5) && (dia <= 31)) {
					cout << dia - 4 << " de Noviembre del " << anio << endl;
				}
			}
			
			else if (mes == 6) {
				
				if ((dia >= 1) && (dia <= 3)) {
					cout << dia + 27 << " de Noviembre del " << anio << endl;
				}
				
				else if ((dia >= 4) && (dia <= 30)) {
					cout << dia - 3 << " de Diciembre del " << anio << endl;
				}
			}
			
			else if (mes == 7) {
				
				if ((dia >= 1) && (dia <= 4)) {
					cout << dia + 27 << " de Diciembre del " << anio << endl;
				}
				
				else if ((dia >= 5) && (dia <= 31)) {
					cout << dia - 4 << " de Enero del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 8) {
				
				if ((dia >= 1) && (dia <= 4)) {
					cout << dia + 27 << " de Enero del " << anio + 1 << endl;	
				}
				
				else if ((dia >= 5) && (dia <= 31)) {
					cout << dia - 4 << " de Febrero del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 9) {
				
				validar_bisiesto (anio + 1, bisiesto2);
				
				if (dia == 1) {
					cout << dia + 27 << " de Febrero del " << anio + 1 << endl;
				}
				
				if (((anio + 1) % 4 == 0) && (bisiesto2 == 'S')) {
					
					if (dia == 2) {
						cout << dia + 27 << " de Febrero del " << anio + 1 << endl;
					}
					
					else if ((dia >= 3) && (dia <= 30)) {
						cout << dia - 2 << " de Marzo del " << anio + 1 << endl;
					}
				}
				
				else if (((anio + 1) % 4 == 0) && (bisiesto2 == 'N')) {
					
					if ((dia >= 2) && (dia <= 30)) {
						cout << dia - 1 << " de Marzo del " << anio + 1 << endl;
					}
				}
			}
			
			else if (mes == 10) {
				
				validar_bisiesto (anio + 1, bisiesto2);
				
				if (((anio + 1) % 4 == 0) && (bisiesto2 == 'S')) {
				
					if ((dia >= 1) && (dia <= 3)) {
						cout << dia + 28 << " de Marzo del " << anio + 1 << endl;
					}
				
					else if ((dia >= 4) && (dia <= 31)) {
						cout << dia - 3 << " de Abril del " << anio + 1 << endl;
					}
				}
				
				else if (((anio + 1) % 4 == 0) && (bisiesto2 == 'N')) {
				
					if ((dia == 1) || (dia == 2)) {
						cout << dia + 29 << " de Marzo del " << anio + 1 << endl;
					}
				
					else if ((dia >= 3) && (dia <= 31)) {
						cout << dia - 2 << " de Abril del " << anio + 1 << endl;
					}
				}
			}
			
			else if (mes == 11) {
				
				validar_bisiesto (anio + 1, bisiesto2);
				
				if (((anio + 1) % 4 == 0) && (bisiesto2 == 'S')) {
				
					if ((dia == 1) || (dia == 2)) {
						cout << dia + 28 << " de Abril del " << anio + 1 << endl;
					}
					
					else if ((dia >= 3) && (dia <= 30)) {
						cout << dia - 2 << " de Mayo del " << anio + 1 << endl;
					}
				}
				
				else if (((anio + 1) % 4 == 0) && (bisiesto2 == 'N')) {
				
					if (dia == 1) {
						cout << dia + 29 << " de Abril del " << anio + 1 << endl;
					}
					
					else if ((dia >= 2) && (dia <= 30)) {
						cout << dia - 1 << " de Mayo del " << anio + 1 << endl;
					}
				}
			}
			
			else if (mes == 12) {
				
				validar_bisiesto (anio + 1, bisiesto2);
				
				if (((anio + 1) % 4 == 0) && (bisiesto2 == 'S')) {
				
					if ((dia >= 1) && (dia <= 3)) {
						cout << dia + 28 << " de Mayo del " << anio + 1 << endl;
					}
					
					else if ((dia >= 4) && (dia <= 31)) {
						cout << dia - 3 << " de Junio del " << anio + 1 << endl;
					}
				}
				
				else if (((anio + 1) % 4 == 0) && (bisiesto2 == 'N')) {
				
					if ((dia == 1) || (dia == 2)) {
						cout << dia + 29 << " de Mayo del " << anio + 1 << endl;
					}
					
					else if ((dia >= 3) && (dia <= 31)) {
						cout << dia - 2 << " de Junio del " << anio + 1 << endl;
					}
				}
			}
		}
	}
	
	else if (plazo == 270) {
		
		if ((anio % 4 == 0) && (bisiesto == 'S')) {
			
			if (mes == 1) {
				
				if ((dia >= 1) && (dia <= 4)) {
					cout << dia + 26 << " de Septiembre del " << anio << endl;
				}
				
				else if ((dia >= 5) && (dia <= 31)) {
					cout << dia - 4 << " de Octubre del " << anio << endl;
				}
			}
			
			else if (mes == 2) {
				
				if ((dia >= 1) && (dia <= 4)) {
					cout << dia + 27 << " de Octubre del " << anio << endl;
				}
				
				else if ((dia >= 5) && (dia <= 29)) {
					cout << dia - 4 << " de Noviembre del " << anio << endl;
				}
			}
			
			else if (mes == 3) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 25 << " de Noviembre del " << anio << endl; 
				}
				
				else if ((dia >= 6) && (dia <= 31)) {
					cout << dia - 5 << " de Diciembre del " << anio << endl;
				}
			}
			
			else if (mes == 4) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 26 << " de Diciembre del " << anio << endl;
				}
				
				else if ((dia >= 6) && (dia <= 30)) {
					cout << dia - 5 << " de Enero del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 5) {
				
				if ((dia >= 1) && (dia <= 6)) {
					cout << dia + 25 << " de Enero del " << anio + 1 << endl;
				}
				
				else if ((dia >= 7) && (dia <= 31)) {
					cout << dia - 6 << " de Febrero del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 6) {
				
				if ((dia >= 1) && (dia <= 3)) {
					cout << dia + 25 << " de Febrero del " << anio + 1 << endl;
				}
				
				if ((dia >= 4) && (dia <= 30)) {
					cout << dia - 3 << " de Marzo del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 7) {
				
				if ((dia >= 1) && (dia <= 4)) {
					cout << dia + 27 << " de Marzo del " << anio + 1 << endl;
				}
				
				else if ((dia >= 5) && (dia <= 31)) {
					cout << dia - 4 << " de Abril del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 8) {
				
				if ((dia >= 1) && (dia <= 3)) {
					cout << dia + 27 << " de Abril del " << anio + 1 << endl;
				}
				
				else if ((dia >= 4) & (dia <= 31)) {
					cout << dia - 3 << " de Mayo del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 9) {
				
				if ((dia >= 1) && (dia <= 3)) {
					cout << dia + 28 << " de Mayo del " << anio + 1 << endl;
				}
				
				else if ((dia >= 4) && (dia <= 30)) {
					cout << dia - 3 << " de Junio del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 10) {
				
				if ((dia >= 1) && (dia <= 3)) {
					cout << dia + 27 << " de Junio del " << anio + 1 << endl;
				}
				
				else if ((dia >= 4) && (dia <= 31)) {
					cout << dia - 3 << " de Julio del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 11) {
				
				if ((dia >= 1) && (dia <= 3)) {
					cout << dia + 28 << " de Julio del " << anio + 1 << endl;
				}
				
				else if ((dia >= 4) && (dia <= 30)) {
					cout << dia - 3 << " de Agosto del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 12) {
				
				if ((dia >= 1) && (dia <= 4)) {
					cout << dia + 27 << " de Agosto del " << anio + 1 << endl;
				}
				
				else if ((dia >= 5) && (dia <= 31)) {
					cout << dia - 4 << " de Septiembre del " << anio + 1 << endl;
				}
			}
		}
		
		else if ((anio % 4 == 1) || (anio % 4 == 2) || ((anio % 4 == 0) && (bisiesto = 'N'))) {
			
			if (mes == 1) {
				
				if ((dia >= 1) && (dia <= 3)) {
					cout << dia + 27 << " de Septiembre del " << anio << endl;
				}
				
				else if ((dia >= 4) && (dia <= 31)) {
					cout << dia - 3 << " de Octubre del " << anio << endl;
				}
			}
			
			else if (mes == 2) {
				
				if ((dia >= 1) && (dia <= 3)) {
					cout << dia + 28 << " de Octubre del " << anio << endl;
				}
				
				else if ((dia >= 4) && (dia <= 28)) {
					cout << dia - 3 << " de Noviembre del " << anio << endl;
				}
			}
			
			else if (mes == 3) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 25 << " de Noviembre del " << anio << endl; 
				}
				
				else if ((dia >= 6) && (dia <= 31)) {
					cout << dia - 5 << " de Diciembre del " << anio << endl;
				}
			}
			
			else if (mes == 4) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 26 << " de Diciembre del " << anio << endl;
				}
				
				else if ((dia >= 6) && (dia <= 30)) {
					cout << dia - 5 << " de Enero del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 5) {
				
				if ((dia >= 1) && (dia <= 6)) {
					cout << dia + 25 << " de Enero del " << anio + 1 << endl;
				}
				
				else if ((dia >= 7) && (dia <= 31)) {
					cout << dia - 6 << " de Febrero del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 6) {
				
				if ((dia >= 1) && (dia <= 3)) {
					cout << dia + 25 << " de Febrero del " << anio + 1 << endl;
				}
				
				if ((dia >= 4) && (dia <= 30)) {
					cout << dia - 3 << " de Marzo del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 7) {
				
				if ((dia >= 1) && (dia <= 4)) {
					cout << dia + 27 << " de Marzo del " << anio + 1 << endl;
				}
				
				else if ((dia >= 5) && (dia <= 31)) {
					cout << dia - 4 << " de Abril del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 8) {
				
				if ((dia >= 1) && (dia <= 3)) {
					cout << dia + 27 << " de Abril del " << anio + 1 << endl;
				}
				
				else if ((dia >= 4) & (dia <= 31)) {
					cout << dia - 3 << " de Mayo del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 9) {
				
				if ((dia >= 1) && (dia <= 3)) {
					cout << dia + 28 << " de Mayo del " << anio + 1 << endl;
				}
				
				else if ((dia >= 4) && (dia <= 30)) {
					cout << dia - 3 << " de Junio del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 10) {
				
				if ((dia >= 1) && (dia <= 3)) {
					cout << dia + 27 << " de Junio del " << anio + 1 << endl;
				}
				
				else if ((dia >= 4) && (dia <= 31)) {
					cout << dia - 3 << " de Julio del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 11) {
				
				if ((dia >= 1) && (dia <= 3)) {
					cout << dia + 28 << " de Julio del " << anio + 1 << endl;
				}
				
				else if ((dia >= 4) && (dia <= 30)) {
					cout << dia - 3 << " de Agosto del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 12) {
				
				if ((dia >= 1) && (dia <= 4)) {
					cout << dia + 27 << " de Agosto del " << anio + 1 << endl;
				}
				
				else if ((dia >= 5) && (dia <= 31)) {
					cout << dia - 4 << " de Septiembre del " << anio + 1 << endl;
				}
			}
		}
		
		else if (anio % 4 == 3) {
			
			if (mes == 1) {
				
				if ((dia >= 1) && (dia <= 3)) {
					cout << dia + 27 << " de Septiembre del " << anio << endl;
				}
				
				else if ((dia >= 4) && (dia <= 31)) {
					cout << dia - 3 << " de Octubre del " << anio << endl;
				}
			}
			
			else if (mes == 2) {
				
				if ((dia >= 1) && (dia <= 3)) {
					cout << dia + 28 << " de Octubre del " << anio << endl;
				}
				
				else if ((dia >= 4) && (dia <= 28)) {
					cout << dia - 3 << " de Noviembre del " << anio << endl;
				}
			}
			
			else if (mes == 3) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 25 << " de Noviembre del " << anio << endl; 
				}
				
				else if ((dia >= 6) && (dia <= 31)) {
					cout << dia - 5 << " de Diciembre del " << anio << endl;
				}
			}
			
			else if (mes == 4) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 26 << " de Diciembre del " << anio << endl;
				}
				
				else if ((dia >= 6) && (dia <= 30)) {
					cout << dia - 5 << " de Enero del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 5) {
				
				if ((dia >= 1) && (dia <= 6)) {
					cout << dia + 25 << " de Enero del " << anio + 1 << endl;
				}
				
				else if ((dia >= 7) && (dia <= 31)) {
					cout << dia - 6 << " de Febrero del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 6) {
				
				validar_bisiesto (anio + 1, bisiesto2);
				
				if ((dia >= 1) && (dia <= 3)) {
					cout << dia + 25 << " de Febrero del " << anio + 1 << endl;
				}
				
				if (((anio + 1) % 4 == 0) && (bisiesto2 == 'S')) {
					
					if (dia == 4) {
						cout << dia + 25 << " de Febrero del " << anio + 1 << endl;
					}
					
					else if ((dia >= 5) && (dia <= 30)) {
						cout << dia - 4 << " de Marzo del " << anio + 1 << endl;
					}
				}
				
				else if (((anio + 1) % 4 == 0) && (bisiesto2 == 'N')) {
					
					if ((dia >= 4) && (dia <= 30)) {
						cout << dia - 3 << " de Marzo del " << anio + 1 << endl;
					}
				}
			}
			
			else if (mes == 7) {
				
				validar_bisiesto (anio + 1, bisiesto2);
				
				if (((anio + 1) % 4 == 0) && (bisiesto2 == 'S')) {
				
					if ((dia >= 1) && (dia <= 5)) {
						cout << dia + 26 << " de Marzo del " << anio + 1 << endl;
					}
					
					else if ((dia >= 6) && (dia <= 31)) {
						cout << dia - 5 << " de Abril del " << anio + 1 << endl;
					}
				}
				
				else if (((anio + 1) % 4 == 0) && (bisiesto2 == 'N')) {
				
					if ((dia >= 1) && (dia <= 4)) {
						cout << dia + 27 << " de Marzo del " << anio + 1 << endl;
					}
					
					else if ((dia >= 5) && (dia <= 31)) {
						cout << dia - 4 << " de Abril del " << anio + 1 << endl;
					}
				}
			}
			
			else if (mes == 8) {
				
				validar_bisiesto (anio + 1, bisiesto2);
				
				if (((anio + 1) % 4 == 0) && (bisiesto2 == 'S')) {
				
					if ((dia >= 1) && (dia <= 4)) {
						cout << dia + 26 << " de Abril del " << anio + 1 << endl;
					}
					
					else if ((dia >= 5) && (dia <= 31)) {
						cout << dia - 4 << " de Mayo del " << anio + 1 << endl;
					}
				}
				
				else if (((anio + 1) % 4 == 0) && (bisiesto2 == 'N')) {
				
					if ((dia >= 1) && (dia <= 3)) {
						cout << dia + 27 << " de Abril del " << anio + 1 << endl;
					}
					
					else if ((dia >= 4) && (dia <= 31)) {
						cout << dia - 3 << " de Mayo del " << anio + 1 << endl;
					}
				}
			}
			
			else if (mes == 9) {
				
				validar_bisiesto (anio + 1, bisiesto2);
				
				if (((anio + 1) % 4 == 0) && (bisiesto2 == 'S')) {
				
					if ((dia >= 1) && (dia <= 4)) {
						cout << dia + 27 << " de Mayo del " << anio + 1 << endl;
					}
					
					else if ((dia >= 5) && (dia <= 30)) {
						cout << dia - 4 << " de Junio del " << anio + 1 << endl;
					}
				}
				
				else if (((anio + 1) % 4 == 0) && (bisiesto2 == 'N')) {
				
					if ((dia >= 1) && (dia <= 3)) {
						cout << dia + 28 << " de Mayo del " << anio + 1 << endl;
					}
					
					else if ((dia >= 4) && (dia <= 30)) {
						cout << dia - 3 << " de Junio del " << anio + 1 << endl;
					}
				}
			}
			
			else if (mes == 10) {
				
				validar_bisiesto (anio + 1, bisiesto2);
				
				if (((anio + 1) % 4 == 0) && (bisiesto2 == 'S')) {
				
					if ((dia >= 1) && (dia <= 4)) {
						cout << dia + 26 << " de Junio del " << anio + 1 << endl;
					}
					
					else if ((dia >= 5) && (dia <= 31)) {
						cout << dia - 4 << " de Julio del " << anio + 1 << endl;
					}
				}
				
				else if (((anio + 1) % 4 == 0) && (bisiesto2 == 'N')) {
				
					if ((dia >= 1) && (dia <= 3)) {
						cout << dia + 27 << " de Junio del " << anio + 1 << endl;
					}
					
					else if ((dia >= 4) && (dia <= 31)) {
						cout << dia - 3 << " de Julio del " << anio + 1 << endl;
					}
				}
			}
			
			else if (mes == 11) {
				
				validar_bisiesto (anio + 1, bisiesto2);
				
				if (((anio + 1) % 4 == 0) && (bisiesto2 == 'S')) {
				
					if ((dia >= 1) && (dia <= 4)) {
						cout << dia + 27 << " de Julio del " << anio + 1 << endl;
					}
					
					else if ((dia >= 5) && (dia <= 30)) {
						cout << dia - 4 << " de Agosto del " << anio + 1 << endl;
					}
				}
				
				else if (((anio + 1) % 4 == 0) && (bisiesto2 == 'N')) {
				
					if ((dia >= 1) && (dia <= 3)) {
						cout << dia + 28 << " de Julio del " << anio + 1 << endl;
					}
					
					else if ((dia >= 4) && (dia <= 30)) {
						cout << dia - 3 << " de Agosto del " << anio + 1 << endl;
					}
				}
			}
			
			else if (mes == 12) {
				
				validar_bisiesto (anio + 1, bisiesto2);
				
				if (((anio + 1) % 4 == 0) && (bisiesto2 == 'S')) {
				
					if ((dia >= 1) && (dia <= 5)) {
						cout << dia + 26 << " de Agosto del " << anio + 1 << endl;
					}
					
					else if ((dia >= 6) && (dia <= 31)) {
						cout << dia - 5 << " de Septiembre del " << anio + 1 << endl;
					}
				}
				
				else if (((anio + 1) % 4 == 0) && (bisiesto2 == 'N')) {
				
					if ((dia >= 1) && (dia <= 4)) {
						cout << dia + 27 << " de Agosto del " << anio + 1 << endl;
					}
					
					else if ((dia >= 5) && (dia <= 31)) {
						cout << dia - 4 << " de Septiembre del " << anio + 1 << endl;
					}
				}
			}
		}
	}
	
	else if (plazo == 360) {
		
		if ((anio % 4 == 0) && (bisiesto == 'S')) {
			
			if (mes == 1) {
				
				if ((dia >= 1) && (dia <= 6)) {
					cout << dia + 25 << " de Diciembre del " << anio << endl;
				}
				
				else if ((dia >= 7) && (dia <= 31)) {
					cout << dia - 6 << " de Enero del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 2) {
				
				if ((dia >= 1) && (dia <= 6)) {
					cout << dia + 25 << " de Enero del " << anio + 1 << endl;
				}
				
				else if ((dia >= 7) && (dia <= 29)) {
					cout << dia - 6 << " de Febrero del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 3) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 23 << " de Febrero del " << anio + 1 << endl;
				}
				
				else if ((dia >= 6) && (dia <= 31)) {
					cout << dia - 5 << " de Marzo del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 4) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 26 << " de Marzo del " << anio + 1 << endl;
				}
				
				else if ((dia >= 6) && (dia <= 30)) {
					cout << dia - 5 << " de Abril del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 5) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 25 << " de Abril del " << anio + 1 << endl;
				}
				
				else if ((dia >= 6) && (dia <= 31)) {
					cout << dia - 5 << " de Mayo del " << anio + 1<< endl;
				}
			}
			
			else if (mes == 6) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 26 << " de Mayo del " << anio + 1 << endl;
				}
				
				else if ((dia >= 6) && (dia <= 30)) {
					cout << dia - 5 << " de Junio del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 7) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 25 << " de Junio del " << anio + 1 << endl;
				}
				
				else if ((dia >= 6) && (dia <= 31)) {
					cout << dia - 5 << " de Julio del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 8) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 26 << " de Julio del " << anio + 1 << endl;
				}
				
				else if ((dia >= 6) && (dia <= 31)) {
					cout << dia - 5 << " de Agosto del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 9) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 26 << " de Agosto del " << anio + 1 << endl;
				}
				
				else if ((dia >= 6) && (dia <= 30)) {
					cout << dia - 5 << " de Septiembre del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 10) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 25 << " de Septiembre del " << anio + 1 << endl;
				}
				
				else if ((dia >= 6) && (dia <= 31)) {
					cout << dia - 5 << " de Octubre del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 11) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 26 << " de Octubre del " << anio + 1 << endl;
				}
				
				else if ((dia >= 6) && (dia <= 30)) {
					cout << dia - 5 << " de Noviembre del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 12) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 25 << " de Noviembre del " << anio + 1 << endl;
				}
				
				else if ((dia >= 6) && (dia <= 31)) {
					cout << dia - 5 << " de Diciembre del " << anio + 1 << endl;
				}
			}
		}
		
		else if ((anio % 4 == 1) || (anio % 4 == 2) || ((anio % 4 == 0) && (bisiesto = 'N'))) {
			
			if (mes == 1) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 26 << " de Diciembre del " << anio << endl;
				}
				
				else if ((dia >= 6) && (dia <= 31)) {
					cout << dia - 5 << " de Enero del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 2) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 26 << " de Enero del " << anio + 1 << endl;
				}
				
				else if ((dia >= 6) && (dia <= 28)) {
					cout << dia - 5 << " de Febrero del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 3) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 23 << " de Febrero del " << anio + 1 << endl;
				}
				
				else if ((dia >= 6) && (dia <= 31)) {
					cout << dia - 5 << " de Marzo del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 4) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 26 << " de Marzo del " << anio + 1 << endl;
				}
				
				else if ((dia >= 6) && (dia <= 30)) {
					cout << dia - 5 << " de Abril del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 5) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 25 << " de Abril del " << anio + 1 << endl;
				}
				
				else if ((dia >= 6) && (dia <= 31)) {
					cout << dia - 5 << " de Mayo del " << anio + 1<< endl;
				}
			}
			
			else if (mes == 6) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 26 << " de Mayo del " << anio + 1 << endl;
				}
				
				else if ((dia >= 6) && (dia <= 30)) {
					cout << dia - 5 << " de Junio del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 7) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 25 << " de Junio del " << anio + 1 << endl;
				}
				
				else if ((dia >= 6) && (dia <= 31)) {
					cout << dia - 5 << " de Julio del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 8) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 26 << " de Julio del " << anio + 1 << endl;
				}
				
				else if ((dia >= 6) && (dia <= 31)) {
					cout << dia - 5 << " de Agosto del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 9) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 26 << " de Agosto del " << anio + 1 << endl;
				}
				
				else if ((dia >= 6) && (dia <= 30)) {
					cout << dia - 5 << " de Septiembre del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 10) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 25 << " de Septiembre del " << anio + 1 << endl;
				}
				
				else if ((dia >= 6) && (dia <= 31)) {
					cout << dia - 5 << " de Octubre del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 11) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 26 << " de Octubre del " << anio + 1 << endl;
				}
				
				else if ((dia >= 6) && (dia <= 30)) {
					cout << dia - 5 << " de Noviembre del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 12) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 25 << " de Noviembre del " << anio + 1 << endl;
				}
				
				else if ((dia >= 6) && (dia <= 31)) {
					cout << dia - 5 << " de Diciembre del " << anio + 1 << endl;
				}
			}
		}
		
		else if (anio % 4 == 3) {
			
			if (mes == 1) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 26 << " de Diciembre del " << anio << endl;
				}
				
				else if ((dia >= 6) && (dia <= 31)) {
					cout << dia - 5 << " de Enero del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 2) {
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 26 << " de Enero del " << anio + 1 << endl;
				}
				
				else if ((dia >= 6) && (dia <= 28)) {
					cout << dia - 5 << " de Febrero del " << anio + 1 << endl;
				}
			}
			
			else if (mes == 3) {
				
				validar_bisiesto (anio + 1, bisiesto2);
				
				if ((dia >= 1) && (dia <= 5)) {
					cout << dia + 23 << " de Febrero del " << anio + 1 << endl;
				}
				
				if (((anio + 1) % 4 == 0) && (bisiesto2 == 'S')) {
					
					if (dia == 6) {
						cout << dia + 23 << " de Febrero del " << anio + 1 << endl;
					}
					
					else if ((dia >= 7) && (dia <= 31)) {
						cout << dia - 6 << " de Marzo del " << anio + 1 << endl;
					}
				}
				
				else if (((anio + 1) % 4 == 0) && (bisiesto2 == 'N')) {
					
					if ((dia >= 6) && (dia <= 31)) {
						cout << dia - 5 << " de Marzo del " << anio + 1 << endl;
					}
				}
			}
			
			else if (mes == 4) {
				
				validar_bisiesto (anio + 1, bisiesto2);
				
				if (((anio + 1) % 4 == 0) && (bisiesto2 == 'S')) {
				
					if ((dia >= 1) && (dia <= 6)) {
						cout << dia + 25 << " de Marzo del " << anio + 1 << endl;
					}
					
					else if ((dia >= 7) && (dia <= 30)) {
						cout << dia - 6 << " de Abril del " << anio + 1 << endl;
					}
				}
				
				else if (((anio + 1) % 4 == 0) && (bisiesto2 == 'N')) {
				
					if ((dia >= 1) && (dia <= 5)) {
						cout << dia + 26 << " de Marzo del " << anio + 1 << endl;
					}
					
					else if ((dia >= 6) && (dia <= 30)) {
						cout << dia - 5 << " de Abril del " << anio + 1 << endl;
					}
				}
			}
			
			else if (mes == 5) {
				
				validar_bisiesto (anio + 1, bisiesto2);
				
				if (((anio + 1) % 4 == 0) && (bisiesto2 == 'S')) {
				
					if ((dia >= 1) && (dia <= 6)) {
						cout << dia + 24 << " de Abril del " << anio + 1 << endl;
					}
					
					else if ((dia >= 7) && (dia <= 31)) {
						cout << dia - 6 << " de Mayo del " << anio + 1 << endl;
					}
				}
				
				else if (((anio + 1) % 4 == 0) && (bisiesto2 == 'N')) {
				
					if ((dia >= 1) && (dia <= 5)) {
						cout << dia + 25 << " de Abril del " << anio + 1 << endl;
					}
					
					else if ((dia >= 6) && (dia <= 31)) {
						cout << dia - 5 << " de Mayo del " << anio + 1 << endl;
					}
				}
			}
			
			else if (mes == 6) {
				
				validar_bisiesto (anio + 1, bisiesto2);
				
				if (((anio + 1) % 4 == 0) && (bisiesto2 == 'S')) {
				
					if ((dia >= 1) && (dia <= 6)) {
						cout << dia + 25 << " de Mayo del " << anio + 1 << endl;
					}
					
					else if ((dia >= 7) && (dia <= 30)) {
						cout << dia - 6 << " de Junio del " << anio + 1 << endl;
					}
				}
				
				else if (((anio + 1) % 4 == 0) && (bisiesto2 == 'N')) {
				
					if ((dia >= 1) && (dia <= 5)) {
						cout << dia + 26 << " de Mayo del " << anio + 1 << endl;
					}
					
					else if ((dia >= 6) && (dia <= 30)) {
						cout << dia - 5 << " de Junio del " << anio + 1 << endl;
					}
				}
			}
			
			else if (mes == 7) {
				
				validar_bisiesto (anio + 1, bisiesto2);
				
				if (((anio + 1) % 4 == 0) && (bisiesto2 == 'S')) {
				
					if ((dia >= 1) && (dia <= 6)) {
						cout << dia + 24 << " de Junio del " << anio + 1 << endl;
					}
					
					else if ((dia >= 7) && (dia <= 31)) {
						cout << dia - 6 << " de Julio del " << anio + 1 << endl;
					}
				}
				
				else if (((anio + 1) % 4 == 0) && (bisiesto2 == 'N')) {
				
					if ((dia >= 1) && (dia <= 5)) {
						cout << dia + 25 << " de Junio del " << anio + 1 << endl;
					}
					
					else if ((dia >= 6) && (dia <= 31)) {
						cout << dia - 5 << " de Julio del " << anio + 1 << endl;
					}
				}
			}
			
			else if (mes == 8) {
				
				validar_bisiesto (anio + 1, bisiesto2);
				
				if (((anio + 1) % 4 == 0) && (bisiesto2 == 'S')) {
				
					if ((dia >= 1) && (dia <= 6)) {
						cout << dia + 25 << " de Julio del " << anio + 1 << endl;
					}
					
					else if ((dia >= 7) && (dia <= 31)) {
						cout << dia - 6 << " de Agosto del " << anio + 1 << endl;
					}
				}
				
				else if (((anio + 1) % 4 == 0) && (bisiesto2 == 'N')) {
				
					if ((dia >= 1) && (dia <= 5)) {
						cout << dia + 26 << " de Julio del " << anio + 1 << endl;
					}
					
					else if ((dia >= 6) && (dia <= 31)) {
						cout << dia - 5 << " de Agosto del " << anio + 1 << endl;
					}
				}
			}
			
			else if (mes == 9) {
				
				validar_bisiesto (anio + 1, bisiesto2);
				
				if (((anio + 1) % 4 == 0) && (bisiesto2 == 'S')) {
				
					if ((dia >= 1) && (dia <= 6)) {
						cout << dia + 25 << " de Agosto del " << anio + 1 << endl;
					}
					
					else if ((dia >= 7) && (dia <= 30)) {
						cout << dia - 6 << " de Septiembre del " << anio + 1 << endl;
					}
				}
				
				else if (((anio + 1) % 4 == 0) && (bisiesto2 == 'N')) {
				
					if ((dia >= 1) && (dia <= 5)) {
						cout << dia + 26 << " de Agosto del " << anio + 1 << endl;
					}
					
					else if ((dia >= 6) && (dia <= 30)) {
						cout << dia - 5 << " de Septiembre del " << anio + 1 << endl;
					}
				}
			}
			
			else if (mes == 10) {
				
				validar_bisiesto (anio + 1, bisiesto2);
				
				if (((anio + 1) % 4 == 0) && (bisiesto2 == 'S')) {
				
					if ((dia >= 1) && (dia <= 6)) {
						cout << dia + 24 << " de Septiembre del " << anio + 1 << endl;
					}
					
					else if ((dia >= 7) && (dia <= 31)) {
						cout << dia - 6 << " de Octubre del " << anio + 1 << endl;
					}
				}
				
				else if (((anio + 1) % 4 == 0) && (bisiesto2 == 'N')) {
				
					if ((dia >= 1) && (dia <= 5)) {
						cout << dia + 25 << " de Septiembre del " << anio + 1 << endl;
					}
					
					else if ((dia >= 6) && (dia <= 31)) {
						cout << dia - 5 << " de Octubre del " << anio + 1 << endl;
					}
				}
			}
			
			else if (mes == 11) {
				
				validar_bisiesto (anio + 1, bisiesto2);
				
				if (((anio + 1) % 4 == 0) && (bisiesto2 == 'S')) {
				
					if ((dia >= 1) && (dia <= 6)) {
						cout << dia + 25 << " de Octubre del " << anio + 1 << endl;
					}
					
					else if ((dia >= 7) && (dia <= 30)) {
						cout << dia - 6 << " de Noviembre del " << anio + 1 << endl;
					}
				}
				
				else if (((anio + 1) % 4 == 0) && (bisiesto2 == 'N')) {
				
					if ((dia >= 1) && (dia <= 5)) {
						cout << dia + 26 << " de Octubre del " << anio + 1 << endl;
					}
					
					else if ((dia >= 6) && (dia <= 30)) {
						cout << dia - 5 << " de Noviembre del " << anio + 1 << endl;
					}
				}
			}
			
			else if (mes == 12) {
				
				validar_bisiesto (anio + 1, bisiesto2);
				
				if (((anio + 1) % 4 == 0) && (bisiesto2 == 'S')) {
				
					if ((dia >= 1) && (dia <= 6)) {
						cout << dia + 24 << " de Noviembre del " << anio + 1 << endl;
					}
					
					else if ((dia >= 7) && (dia <= 31)) {
						cout << dia - 6 << " de Diciembre del " << anio + 1 << endl;
					}
				}
				
				else if (((anio + 1) % 4 == 0) && (bisiesto2 == 'N')) {
				
					if ((dia >= 1) && (dia <= 5)) {
						cout << dia + 25 << " de Noviembre del " << anio + 1 << endl;
					}
					
					else if ((dia >= 6) && (dia <= 31)) {
						cout << dia - 5 << " de Diciembre del " << anio + 1 << endl;
					}
				}
			}
		}
	}
}

