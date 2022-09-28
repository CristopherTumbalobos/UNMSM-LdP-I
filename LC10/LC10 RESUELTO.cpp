// UNMSM – Facultad de Ing. Electrónica y Eléctrica 
// Escuela de Ingeniería Electrónica
// Curso: Lenguaje de Programación
// Docente: Avila López, B. Patricio 
// Estudiante: Tumbalobos Peralta, Cristopher Rigoberto
// Fecha: 28/08/2020 
// Laboratorio Calificado 10
// Objetivo: Validar cuenta de correo institucional de la UNMSM y generar una contraseña aleatoria.
// Datos de entrada: Cuenta de correo institucional de la UNMSM.
// Restricciones: 	- Solo acepta las cuentas de correo cuyo dominio sea "@unmsm.edu.pe".
//					- Almacena los correos y las contraseñas de hasta 50 personas [tamaño del arreglo].

#include <iostream>		// Para el flujo (entrada y salida) de datos
#include <locale.h>		// Para la ortografía de las palabras
#include <stdio.h>		// Para usar fflush () y printf ()
#include <string.h>		// Para usar getline (), strcpy (), strlen (), .substr () y .find ()
#include <ctime>		// Para usar time ()
#include <stdlib.h>		// Para usar srand () y rand ()
#include <conio.h>		// Para usar getch ()
#include <sstream>		// Para usar istringstream ()

using namespace std;	// Para omitir el uso de (std::)

// Definición de la estructura "persona"
struct persona {
	string correo;		// Campo "correo"
	string contrasenia;		// Campo "contrasenia"
};

// Prototipo de la función "ingresar_opcion"
template <class STRING>
int ingresar_opcion (STRING num, double numero, int entero);

// Prototipó de la función "ingresar_correo"
template <class STRING>
STRING ingresar_correo (STRING correo);

// Prototipo de la función "generar_contrasenia"
template <class STRING>
STRING generar_contrasenia (STRING contrasenia);

int main () {	// Función principal
	setlocale (LC_ALL, "");	// Idioma predeterminado del sistema
	
	struct persona personas[50];	// Arreglo de estructuras
	
	string n1;
	double numero;
	int entero;
	
	string correo;
	string contrasenia;
	
	int turno = 1;
	bool fin1 = false;
	
	srand (time (NULL));	// Semilla de pseudo aleatorios
	
	cout << "\t\tC O R R E O   I N T I T U C I O N A L   U N M S M   1\n";
	
	personas[0].correo = ingresar_correo (correo);
	
	personas[0].contrasenia = generar_contrasenia (contrasenia);
	
	cout << "\n\tContraseña: " << personas[0].contrasenia << endl;
	
	cout << "\n\t\tOpciones: " << endl;
	cout << "\t\t1. Ingresar otra cuenta de correo institucional de la UNMSM." << endl;
	cout << "\t\t2. Salir." << endl;
	
	while (!fin1) {	// Estructura iterativa  W H I L E
		
		entero = ingresar_opcion (n1, numero, entero);
		
		if (entero == 2) {
			fin1 = true;
		}
		
		else {
			turno++;
			
			printf ("\n\n\t\tC O R R E O   I N T I T U C I O N A L   U N M S M   %d\n", turno);
			
			personas[turno - 1].correo = ingresar_correo (correo);
			
			personas[turno - 1].contrasenia = generar_contrasenia (contrasenia);
			
			cout << "\n\tContraseña: " << personas[turno - 1].contrasenia << endl;
			
			cout << "\n\t\tOpciones: " << endl;
			cout << "\t\t1. Ingresar otra cuenta de correo institucional de la UNMSM." << endl;
			cout << "\t\t2. Salir." << endl;	
		}
	}
	
	cout << "\n\n\tL I S T A   D E   C O R R E O (S)   Y   C O N T R A S E Ñ A (S)\n";
	
	for (int i = 0; i < turno; i++) {	// Estructura iterativa  F O R
		
		cout << "\n\t\tCorreo: " << personas[i].correo << "  ---->  " << "Contraseña: " << personas[i].contrasenia << endl;
	}
	
	getch ();	// Evita que se cierre el ejecutable (.exe)
	return 0;
}

// Definición de la función "ingresar_opcion"
template <class STRING>
int ingresar_opcion (STRING num, double numero, int entero) {
	
	int longitud_caracteres, espacios_blanco = 0;
	char cadena [100] = "";
	bool fin2 = false;
	
	while (!fin2) {	// Estructura iterativa  W H I L E
		
		fflush (stdin);		// Vaciar el buffer y permitir digitar los valores
		cout<<"\n\t\tIngrese una opción: ";
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
			
			strcpy (cadena, num.c_str());	// Convierte el string "num" y lo copia en el char "cadena"
			
			longitud_caracteres = strlen (cadena);	// Para contar los caracteres del char "cadena" 
			
			for (int i = 0; i <= longitud_caracteres; i++) {	// Para saber cuantos espacios en blanco hay en el char "cadena"
				
				if (cadena [i] == ' ') {
					espacios_blanco++;
				}
			}
			
			if (espacios_blanco == 1) {	// Verificamos si digitó un espacio en blanco
				cout << "\t\tUsted digitó un espacio en blanco, por favor ingrese el número 1 o 2." << endl;
			}
			
			else if (espacios_blanco > 1) {	// Verificamos si digitó más de un espacio en blanco
				cout << "\t\tUsted digitó varios espacios en blanco, por favor ingrese el número 1 o 2." << endl;
			}
			
			else if (longitud_caracteres == 0){	// Verificamos si no digitó ningún valor
				cout << "\t\tNo digitó ningun valor, por favor ingrese el número 1 o 2." << endl;
			}
			
			else if (longitud_caracteres == 1) {	// Verificamos si ingresó un caracter
				cout << "\t\tUsted ingresó una caracter, por favor ingrese el número 1 o 2." << endl;
			}
			
			else if (longitud_caracteres > 1) {	// Verificamos si ingreso más de un caracter
				cout << "\t\tUsted ingresó varios caracteres, por favor ingrese el número 1 o 2." << endl;
			}
		}
	}
	
	return entero;
}

// Definición de la función "ingresar_correo"
template <class STRING>
STRING ingresar_correo (STRING correo) {
	
	char cad_correo [100];
	int longitud_cadena;
	int total_arroba = 0;
	int total_espacios = 0;
	
	bool fin2 = false;
	
	while (!fin2) {	// Estructura iterativa  W H I L E
		
		fflush (stdin);	// Vaciar el buffer y permitir digitar los valores
		cout << "\n\tIngrese una cuenta de correo institucional de la UNMSM: ";
		getline (cin, correo);	// Almacenar en el string "correo"
		
		strcpy (cad_correo, correo.c_str());	// Copiando el string "correo" a la cadena "cad_correo"
		
		longitud_cadena = strlen (cad_correo);	// Medir cadena "cad_correo"
		
		for (int i = 0; i < longitud_cadena; i++) {	// Estructura iterativa  F O R
			
			if (cad_correo [i] == '@') {
				total_arroba++;		// Contabilizar arrobas ('@')
			}
			
			if (cad_correo [i] == ' ') {
				total_espacios++;	// Contabilizar espacios en blanco (' ')
			}
		}
	
		if (total_arroba > 1) {
			cout << "\tERROR: La cuenta de correo contiene más de un @" << endl;
		}
		
		else if (total_espacios > 0) {
			cout << "\tERROR: La cuenta de correo no debe contener espacio(s) en blanco" << endl;
		}
		
		else if (longitud_cadena == 0) {
			cout << "\tERROR: No digitó ninguna cuenta de correo institucional" << endl;
		}
		
		else if (correo.substr (correo.find ("@")) != "@unmsm.edu.pe"){		// Subcadena de correo -> DOMINIO
			cout << "\tERROR: El dominio de correo debe ser @unmsm.edu.pe" << endl;
		}
		
		else if (longitud_cadena == 13) {
			cout << "\tERROR: La cuenta de correo no tiene un nombre antes del @" << endl;
		}
		
		else if (correo.substr (correo.find ("@")) == "@unmsm.edu.pe") {	// Subcadena de correo -> DOMINIO
			cout << "\tCorreo válido" << endl;
			fin2 = true;
		}

		total_arroba = 0;	// Reseteamos el contador "total_arroba"
		total_espacios = 0;	// Reseteamos el contador "total_espacios"
	}
	
	return correo;
}

// Definición de la función "generar_contrasenia"
template <class STRING>
STRING generar_contrasenia (STRING contrasenia) {
	
	char char_letra;
	char char_numero;
	
	for (int i = 0; i < 8; i++) {	// Constraseña de 8 caracteres
		
		if (i % 2 == 0) {	// Posición 0, 2, 4, 6 -> LETRA ALEATORIA
			
			char_letra = "abcdefghijklmnopqrstuvwxyz" [rand () % 26];	// Genera una letra aleatoria
			contrasenia += char_letra;	// Concatena al string "constrasenia"
		}
		
		else if (i % 2 != 0) {	// Posición 1, 3, 5, 7 -> NÚMERO ALEATORIO
			
			char_numero = 0 + (rand () % 10) + '0';		// Artificio: Pasar de int a char
			contrasenia += char_numero;	// Concatena al string "constrasenia"
		}
	}
	
	return contrasenia;
}

