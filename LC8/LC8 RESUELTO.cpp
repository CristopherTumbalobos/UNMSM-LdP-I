// UNMSM – Facultad de Ing. Electrónica y Eléctrica 
// Escuela de Ingeniería Electrónica
// Curso: Lenguaje de Programación
// Docente: Avila López, B. Patricio 
// Estudiante: Tumbalobos Peralta, Cristopher Rigoberto
// Fecha: 14/08/2020 
// Laboratorio Calificado 08
// Objetivo: Registro de las notas de N alumnos del curso de Lenguaje de Programación.
// Datos de entrada: Notas de las 4 prácticas, exámenes (parcial, final y sustitutorio) y promedio de laboratorios.
// Restricciones: Solo se puede ingresar notas del 0 al 20 (incluyendo 0 y 20).

#include <iostream>		// Para el flujo (entrada y salida) de datos
#include <locale.h>		// Para la ortografía de las palabras
#include <string>		// Para usar getline (), strcpy () y strlen ()
#include <sstream>		// Para usar istringstream ()
#include <stdlib.h>		// Para usar atoi ()
#include <conio.h>		// Para usar getch ()
#include <stdio.h>		// Para usar fflush ()
#include <windows.h>	// Para usar SetConsoleTextAttribute ()
#include <iomanip>		// Para usar setprecision ()
#include <math.h>		// Para usar round ()

using namespace std;	// Para omitir el uso de (std::)

// Prototipo de la función "validacion_nota"
template <class TIPOD>	// Plantilla de función
int validacion_nota (TIPOD& num, double& numero, int& entero);	// Paso de parámetros por referencia

// Prototipo de la función "validacion_cantidad"
template <class TIPOD>
int validacion_cantidad (TIPOD& num, double& numero, int& entero);	// Paso de parámetros por referencia

// Prototipo de la función "menor_de_practicas"
void menor_de_practicas (int& nota_practica1, int& nota_practica2, int& nota_practica3, int& nota_practica4, int& menor_practica);	// Paso de parámetros por referencia

// Prototipo de la función "menor_de_examenes"
void menor_de_examenes (int& examen_parcial, int& examen_final, int& menor_examen, int& mayor_examen);	// Paso de parámetros por referencia

// Prototipo de la función "color"
int color (int n);

int main () {	// Función principal
	setlocale (LC_ALL, "");
	
	string n1;
	double numero;
	int entero;
	
	int cantidad_alumnos;
	int alumno = 1;
	int nota_practica1 [cantidad_alumnos], nota_practica2 [cantidad_alumnos], nota_practica3 [cantidad_alumnos], nota_practica4 [cantidad_alumnos];
	int menor_practica [cantidad_alumnos];
	double suma_practicas [cantidad_alumnos];
	double promedio_practicas [cantidad_alumnos];
	int aux [cantidad_alumnos];	// Para expresar el promedio de prácticas con dos decimales
	int examen_parcial [cantidad_alumnos], examen_final [cantidad_alumnos], examen_sustitutorio [cantidad_alumnos];
	int menor_examen [cantidad_alumnos], mayor_examen [cantidad_alumnos];
	double nota_teoria [cantidad_alumnos];
	int promedio_laboratorios [cantidad_alumnos];
	double nota_final [cantidad_alumnos];
	char condicion [cantidad_alumnos];
	int cantidad_aprobados = 0;
	double suma_notas_finales = 0;
	double promedio_notas_finales, porcentaje_aprobados;
	
	cout << "\n\t\t\t\tR E G I S T R O   D E   N O T A S" << endl;
	
	cantidad_alumnos = validacion_cantidad (n1, numero, entero);
	
	for (int i = 0; i < cantidad_alumnos; i++) {
		
		printf ("\n\n\t\t\t\tA L U M N O   %d\n", alumno);
		
		cout << "\n\tNOTA DE LA PRÁCTICA 1: " << endl;
		nota_practica1 [i] = validacion_nota (n1, numero, entero);
		
		cout << "\n\tNOTA DE LA PRÁCTICA 2: " << endl;
		nota_practica2 [i] = validacion_nota (n1, numero, entero);
		
		cout << "\n\tNOTA DE LA PRÁCTICA 3: " << endl;
		nota_practica3 [i] = validacion_nota (n1, numero, entero);
		
		cout << "\n\tNOTA DE LA PRÁCTICA 4: " << endl;
		nota_practica4 [i] = validacion_nota (n1, numero, entero);
		
		menor_practica [i] = 9999;
		
		menor_de_practicas (nota_practica1 [i], nota_practica2 [i], nota_practica3 [i], nota_practica4 [i], menor_practica [i]);
		
		suma_practicas [i] = nota_practica1 [i] + nota_practica2 [i] + nota_practica3 [i] + nota_practica4 [i] - menor_practica [i];
		
		promedio_practicas [i] = suma_practicas [i] / 3.0;
		
		aux [i] = promedio_practicas [i] * 100;		// Artificio
		promedio_practicas [i] = (double) aux [i] / 100;	// Recortando a partir del 2do decimal
		
		cout << fixed << setprecision (2);

		cout << "\n\tNOTA DEL EXAMEN PARCIAL: " << endl;
		examen_parcial [i] = validacion_nota (n1, numero, entero);
		
		cout << "\n\tNOTA DEL EXAMEN FINAL: " << endl;
		examen_final [i] = validacion_nota (n1, numero, entero);
		
		menor_de_examenes (examen_parcial [i], examen_final [i], menor_examen [i], mayor_examen [i]);
		
		cout << "\n\tNOTA DEL EXAMEN SUSTITUTORIO: " << endl;
		examen_sustitutorio [i] = validacion_nota (n1, numero, entero);
		
		if (examen_sustitutorio [i] > menor_examen [i]) {
			menor_examen [i] = examen_sustitutorio [i];
		}
		
		nota_teoria [i] = (double) (promedio_practicas [i] + mayor_examen [i] + menor_examen [i]) / 3.0;

		cout << "\n\tNOTA DEL PROMEDIO DE LABORATORIOS: " << endl;
		promedio_laboratorios [i] = validacion_nota (n1, numero, entero);
		
		if (nota_teoria [i] >= 10) {
			nota_final [i] = (2 * roundl (nota_teoria [i]) + promedio_laboratorios [i]) / 3.0;
		}
		
		else {
			nota_final [i] = roundl (nota_teoria [i]);
		}
		
		cout << fixed << setprecision (0);
		
		cout << "\n\n\t\tLa nota final (redondeado al entero) es: ";

		if (nota_final [i] >= 11) {
			color (02);		// Texto color verde
			cout << roundl (nota_final [i]);
			cout << "\tAprobado" << endl;
			condicion [i] = 'A';
		}
		
		else {
			color (04);		// Texto color rojo
			cout.fill ('0');	// Para completar con ceros de izquierda a derecha
			cout.width (2); 	// Para que se escriba como un número de 2 cifras
			cout << roundl (nota_final [i]);
			cout << "\tDesaprobado" << endl;
			condicion [i] = 'D';
		}
		
		color (07);		// Fondo oscuro con texto de color blanco
		
		suma_notas_finales += roundl (nota_final [i]);
		
		if (condicion [i] == 'A') {
			cantidad_aprobados++;
		}

		alumno++;	
	}
	
	cout << "\n\n\t\t\t\tD A T O S   G E N E R A L E S" << endl;
	
	promedio_notas_finales = suma_notas_finales / cantidad_alumnos;
	
	cout << "\n\tEl promedio de notas finales (redondeado al entero) es: " << roundl (promedio_notas_finales) << endl;
	
	porcentaje_aprobados = (double) (100 * cantidad_aprobados) / cantidad_alumnos;
	
	cout << "\n\tEl porcentaje de alumnos que aprobaron el curso (redondeado al entero) es: " << roundl (porcentaje_aprobados) << " %" << endl;
	
	return 0;
}

// Definición de la función "validacion_nota"
template <class TIPOD>	// Plantilla de función
int validacion_nota (TIPOD& num, double& numero, int& entero) {
	
	int longitud_caracteres, espacios_blanco = 0;
	char cadena [100] = "";
	bool fin1 = false;
	
	while (!fin1) {	
		
		fflush (stdin);	 // Para limpiar la entrada de datos
		cout << "\n\t\tIngrese la NOTA: ";
		getline(cin,num);
		
		if (istringstream(num) >> numero) {		// Con este if verificamos si es un número
			
			entero = numero;
			entero = atoi (num.c_str());	// Conversión de char a entero
			
			if (numero - entero) {	// Con este if verificamos si el número es un decimal
				cout << "\t\tUsted ingresó un número decimal, por favor ingrese un número entero de 0 a 20 (incluyendo 0 y 20)." << endl;
			}
			
			else if ((numero >= 0) && (numero <= 20)) {	// Con este if verificamos que sea el número 1 o 2
				fin1 = true;
			}
			
			else {
				cout << "\t\tUsted ingresó una opción no válida, por favor ingrese un número entero de 0 a 20 (incluyendo 0 y 20)." << endl;
			}
		}
		
		else {
			int longitud_caracteres, espacios_blanco = 0;
			char cadena [100] = "";
			
			strcpy (cadena, num.c_str());	// Convierte el string "num" y lo copia en el char "cadena"
			
			longitud_caracteres = strlen (cadena);	// Para contar los caracteres del char "cadena" 
			
			for (int i = 0; i <= longitud_caracteres; i++) {	// Para saber cuántos espacios en blanco hay en el char "cadena"
				
				if (cadena [i] == ' ') {
					espacios_blanco++;
				}
			}
			
			if (espacios_blanco == 1) {	// Verificamos si digitó un espacio en blanco
				cout << "\t\tUsted digitó un espacio en blanco, por favor ingrese un número entero de 0 a 20 (incluyendo 0 y 20)." << endl;
			}
			
			else if (espacios_blanco > 1) {	// Verificamos si digitó más de un espacio en blanco
				cout << "\t\tUsted digitó varios espacios en blanco, por favor ingrese un número entero de 0 a 20 (incluyendo 0 y 20)." << endl;
			}
			
			else if (longitud_caracteres == 0) {	// Verificamos si no digitó ningún valor
				cout << "\t\tNo digitó ningun valor, por favor ingrese un número entero de 0 a 20 (incluyendo 0 y 20)." << endl;
			}
			
			else if (longitud_caracteres == 1) {	// Verificamos si ingresó un caracter
				cout << "\t\tUsted ingresó una caracter, por favor ingrese un número entero de 0 a 20 (incluyendo 0 y 20)." << endl;
			}
			
			else if (longitud_caracteres > 1) {	// Verificamos si ingresó más de un caracter
				cout << "\t\tUsted ingresó varios caracteres, por favor ingrese un número entero de 0 a 20 (incluyendo 0 y 20)." << endl;
			}
		}
	}
	
	return entero;
}

// Definición de la función "validacion_cantidad"
template <class TIPOD>	// Plantilla de función
int validacion_cantidad (TIPOD& num, double& numero, int& entero) {
	
	int longitud_caracteres, espacios_blanco = 0;
	char cadena [100] = "";
	bool fin1 = false;
	
	while (!fin1) {	
		
		fflush (stdin);	 // Para limpiar la entrada de datos
		cout << "\n\t\tIngrese el número de alumnos (solo se tomará en cuenta el primer número escrito): ";
		getline(cin,num);
		
		if (istringstream(num) >> numero) {		// Con este if verificamos si es un número
			
			entero = numero;
			entero = atoi (num.c_str());	// Conversión de char a entero
			
			if (numero - entero) {	// Con este if verificamos si el número es un decimal
				cout << "\t\tUsted ingresó un número decimal, por favor ingrese un número entero positivo." << endl;
			}
			
			else if (numero <= 0) {
				cout << "\t\tUsted ingresó una cantidad no válida, por favor ingrese un número entero positivo." << endl;
			}
			
			else {
				fin1 = true;
			}
		}
		
		else {
			int longitud_caracteres, espacios_blanco = 0;
			char cadena [100] = "";
			
			strcpy (cadena, num.c_str());	// Convierte el string "num" y lo copia en el char "cadena"
			
			longitud_caracteres = strlen (cadena);	// Para contar los caracteres del char "cadena" 
			
			for (int i = 0; i <= longitud_caracteres; i++) {	// Para saber cuántos espacios en blanco hay en el char "cadena"
				
				if (cadena [i] == ' ') {
					espacios_blanco++;
				}
			}
			
			if (espacios_blanco == 1) {	// Verificamos si digitó un espacio en blanco
				cout << "\t\tUsted digitó un espacio en blanco, por favor ingrese un número entero positivo." << endl;
			}
			
			else if (espacios_blanco > 1) {	// Verificamos si digitó más de un espacio en blanco
				cout << "\t\tUsted digitó varios espacios en blanco, por favor ingrese un número entero positivo." << endl;
			}
			
			else if (longitud_caracteres == 0) {	// Verificamos si no digitó ningún valor
				cout << "\t\tNo digitó ningun valor, por favor ingrese un número entero positivo." << endl;
			}
			
			else if (longitud_caracteres == 1) {	// Verificamos si ingresó un caracter
				cout << "\t\tUsted ingresó una caracter, por favor ingrese un número entero positivo." << endl;
			}
			
			else if (longitud_caracteres > 1) {	// verificamos si ingreso más de un caracter
				cout << "\t\tUsted ingresó varios caracteres, por favor ingrese un número entero positivo." << endl;
			}
		}
	}
	
	return entero;
}

// Definición de la función "menor_de_practicas"
void menor_de_practicas (int& nota_practica1, int& nota_practica2, int& nota_practica3, int& nota_practica4, int& menor_practica) {	
	
	if (nota_practica1 < menor_practica) {
		menor_practica = nota_practica1;
	}
	
	if (nota_practica2 < menor_practica) {
		menor_practica = nota_practica2;
	}
	
	if (nota_practica3 < menor_practica) {
		menor_practica = nota_practica3;
	}
	
	if (nota_practica4 < menor_practica) {
		menor_practica = nota_practica4;
	}
}

// Definición de la función "menor_de_examenes"
void menor_de_examenes (int& examen_parcial, int& examen_final, int& menor_examen, int& mayor_examen) {
	
	if (examen_parcial < examen_final) {
		menor_examen = examen_parcial;
		mayor_examen = examen_final;
	}
	
	else {
		menor_examen = examen_final;
		mayor_examen = examen_parcial;
	}
}

// Definición de la función "color"
int color (int n) {
	
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), n);
}

