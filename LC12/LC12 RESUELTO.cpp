// UNMSM – Facultad de Ing. Electrónica y Eléctrica
// Escuela de Ingeniería Electrónica
// Curso: Lenguaje de Programación
// Docente: Avila López, B. Patricio
// Estudiante: Tumbalobos Peralta, Cristopher Rigoberto
// Fecha: 12/09/2020
// Laboratorio Calificado 12
// Objetivo: JUEGO: "Buscapantanos" y grabar los 5 nombres de los jugadores con menor tiempo.
// Datos de entrada: 	- El número de una fila o columna de una matriz de 4 x 4.
//						- Una opción para "Ver mejores marcas".
//
// Restricciones: 	- El número de la fila o la columna debe ser un número entero del 1 al 4.
//					- El tiempo que demora el jugador en terminar el juego considera hasta las milésimas de segundos (Ej. 54.637 segundos) 
//					- El fichero "Ranking_Tumbalobos.txt" se creará inicialmente con los nombres y tiempos de 5 personas:
//
//												JUAN ; 242.13
//												JOSE ; 253.44
//												PEDRO ; 266.12
//												MARÍA ; 270.22
//												ANA ; 281.44

#include <iostream>		// Para el flujo (entrada y salida) de datos
#include <locale.h>		// Para la ortografía de las palabras
#include <stdlib.h>		// Para usar srand (), rand (), atoi () y system("pause")
#include <time.h>		// Para usar time(NULL) y clock ()
#include <windows.h>	// Para usar SetConsoleTextAttribute ()
#include <fstream>		// Para usar ifstream [input file] y ofstream [output file]
#include <stdio.h>		// Para usar fflush ()
#include <string>		// Para usar getline (), strcpy () y strlen ()
#include <iomanip>		// Para usar setprecision ()
#include <sstream>		// Para usar istringstream ()

using namespace std;	// Para omitir el uso de (std::)

// Definición de la estructura "record" 
struct record {
	string nombre;	// Campo "nombre"
	string tiempo;	// Campo "tiempo"
};

// Prototipo de la función "gotoxy"
void gotoxy (int x, int y);

// Prototipo de la función "generar_matriz_numerica_nula"
int generar_matriz_numerica_nula (int matriz_numerica[4][4]);

// Prototipo de la función "generar_pantanos_aleatorios"	
int generar_pantanos_aleatorios (int matriz_numerica[4][4]);

// Prototipo de la función "contar_pantanos"	
int contar_pantanos (int matriz_numerica[4][4]);

// Prototipo de la función "generar_matriz_caracter"
char generar_matriz_caracter (int matriz_numerica[4][4], char matriz_caracter[4][4]);

// Prototipo de la función "generar_mapa"
char generar_mapa (char mapa[4][4]);

// Prototipo de la función "color"
void color (int n);

// Prototipo de la función "ingresar_valor"
template <class STRING>
int ingresar_fila (STRING num, double numero, int entero);

// Prototipo de la función "ingresar_columna"
template <class STRING>
int ingresar_columna (STRING num, double numero, int entero);

// Prototipo de la función "pintar_nombre_juego"
void pintar_nombre_juego ();

// Prototipo de la función "pintar_limites"
void pintar_limites ();

// Prototipo de la función "mostrar_mapa"
void mostrar_mapa ();

// Prototipo de la función "mostrar_casilla"
void mostrar_casilla (char matriz_caracter[4][4], char mapa[4][4], int fila_usuario, int columna_usuario);

// Prototipo de la función "juego"
void juego (char matriz_caracter[4][4], char mapa[4][4], bool &fin2, bool &fin3);

// Prototipo de la función "mostrar_solucion"
void mostrar_solucion (int matriz_numerica[4][4]);

// Prototipo de la función "extraer_contenido_fichero"
template <class STRING>
void extraer_contenido_fichero (STRING &linea1, STRING &linea2, STRING &linea3, STRING &linea4, STRING &linea5);

int main () {	// FUNCIÓN PRINCIPAL
	setlocale (LC_ALL, "");
	
	string num;
	double numero;
	
	int matriz_numerica[4][4];
	char matriz_caracter[4][4];
	char mapa[4][4];
	
	bool fin2 = false;	// Si pierde
	bool fin3 = false;	// Si gana
	
	string linea1, linea2, linea3, linea4, linea5;
	
	record records[6];
	double tiempos[6];
	
	string nombre_ganador;
	double tiempo;
	
	double aux;
	
	char opc;	// OPCIÓN: "Ver mejores marcas"
	bool fin4 = false;	// Validar opción

	srand (time(NULL));
	
	generar_matriz_numerica_nula (matriz_numerica);
	
	generar_pantanos_aleatorios (matriz_numerica);

	contar_pantanos (matriz_numerica);

	generar_matriz_caracter (matriz_numerica, matriz_caracter);
	
	generar_mapa (mapa);
	
	//mostrar_solucion (matriz_numerica);	// P A R A   H A C E R   T R A M P A
	
	pintar_nombre_juego ();
	
	pintar_limites ();
	
	mostrar_mapa ();
	
	clock_t inicio = clock ();	// Marca tiempo inicio del proceso
	
	juego (matriz_caracter, mapa, fin2, fin3);

	clock_t fin = clock ();	// Marca tiempo fin del proceso

	if (fin3 == true) {
		
		gotoxy (10, 21);
		cout << "¡ C O N G R A T U L A T I O N S !" << endl;	
	}
	if (fin2 == true) {
		
		gotoxy (10, 21);
		cout << "G A M E   O V E R" << endl;
		
		mostrar_solucion (matriz_numerica);	// Mostrar solución
	}
	
	tiempo = double (fin - inicio) / CLOCKS_PER_SEC;	// Tiempo que demoró en terminar el juego
	
	gotoxy (43, 9);
	cout << "Tiempo que demoró en terminar el juego (en segundos): ";
	cout << tiempo;

	extraer_contenido_fichero (linea1, linea2, linea3, linea4, linea5);

	// Manejo de string
	records[0].nombre = linea1.substr(0, linea1.find(";"));
	records[0].tiempo = linea1.erase (0, linea1.find(";") + 1);
	
	records[1].nombre = linea2.substr(0, linea2.find(";"));
	records[1].tiempo = linea2.erase (0, linea2.find(";") + 1);
	
	records[2].nombre = linea3.substr(0, linea3.find(";"));
	records[2].tiempo = linea3.erase (0, linea3.find(";") + 1);

	records[3].nombre = linea4.substr(0, linea4.find(";"));
	records[3].tiempo = linea4.erase (0, linea4.find(";") + 1);
	
	records[4].nombre = linea5.substr(0, linea5.find(";"));
	records[4].tiempo = linea5.erase (0, linea5.find(";") + 1);
	
	tiempos[0] = atof(records[0].tiempo.c_str());
	tiempos[1] = atof(records[1].tiempo.c_str());
	tiempos[2] = atof(records[2].tiempo.c_str());
	tiempos[3] = atof(records[3].tiempo.c_str());
	tiempos[4] = atof(records[4].tiempo.c_str());
	
	if ((tiempo < tiempos[4]) && (fin3 == true)) {
		fflush(stdin);
		gotoxy (43, 11);
		cout << "¡NUEVO RECORD!. Ingrese nombre del jugador: ";
		getline(cin, nombre_ganador);
		
		records[5].nombre = nombre_ganador;
		records[5].tiempo = tiempo;
		tiempos[5] = tiempo;
		
		// Ubicando al ganador y ordenando arreglo de estructuras "records[6]"
		if ((tiempos[5] < tiempos[4]) && (tiempos[5] > tiempos[3])) {
			records[4].nombre = records[5].nombre;
			records[4].tiempo = records[5].tiempo;
		}
		
		else if ((tiempos[5] < tiempos[3]) && (tiempos[5] > tiempos[2])) {
			records[4].nombre = records[3].nombre;
			records[4].tiempo = records[3].tiempo;
			records[3].nombre = records[5].nombre;
			records[3].tiempo = records[5].tiempo;
		}
		
		else if ((tiempos[5] < tiempos[2]) && (tiempos[5] > tiempos[1])) {
			records[4].nombre = records[3].nombre;
			records[4].tiempo = records[3].tiempo;
			records[3].nombre = records[2].nombre;
			records[3].tiempo = records[2].tiempo;
			records[2].nombre = records[5].nombre;
			records[2].tiempo = records[5].tiempo;
		}
		
		else if ((tiempos[5] < tiempos[1]) && (tiempos[5] > tiempos[0])) {
			records[4].nombre = records[3].nombre;
			records[4].tiempo = records[3].tiempo;
			records[3].nombre = records[2].nombre;
			records[3].tiempo = records[2].tiempo;
			records[2].nombre = records[1].nombre;
			records[2].tiempo = records[1].tiempo;
			records[1].nombre = records[5].nombre;
			records[1].tiempo = records[5].tiempo;
		}
		
		else if (tiempos[5] < tiempos[0]) {
			records[4].nombre = records[3].nombre;
			records[4].tiempo = records[3].tiempo;
			records[3].nombre = records[2].nombre;
			records[3].tiempo = records[2].tiempo;
			records[2].nombre = records[1].nombre;
			records[2].tiempo = records[1].tiempo;
			records[1].nombre = records[0].nombre;
			records[1].tiempo = records[0].tiempo;
			records[0].nombre = records[5].nombre;
			records[0].tiempo = records[5].tiempo;
		}
		
		// Ordenando arreglo "tiempos[6]" de menor a mayor
		for (int i = 0; i < 6; i++) {
			for (int j = i + 1; j < 6; j++) {
				if (tiempos[i] > tiempos[j]) {
					aux = tiempos[i];
					tiempos[i] = tiempos[j];
					tiempos[j] = aux;			
				}
			}
		}
		
		// Reemplazando en el fichero
		ofstream WriteFile ("Ranking_Tumbalobos.txt");
		
		WriteFile << records[0].nombre << ";" << tiempos[0] << endl;
		WriteFile << records[1].nombre << ";" << tiempos[1] << endl;
		WriteFile << records[2].nombre << ";" << tiempos[2] << endl;
		WriteFile << records[3].nombre << ";" << tiempos[3] << endl;
		WriteFile << records[4].nombre << ";" << tiempos[4] << endl;
		
		WriteFile.close();
	}
	
	while (fin4 != true) {
		
		gotoxy (43, 14);
		cout << "\t\t\t\t\t\t\t\t";
		gotoxy (43, 14);
		fflush (stdin);
		cout << "Ver mejores marcas ( S / N ): ";
		cin.get(opc);
		
		if ((opc == 'S') || (opc == 's')) {
			
			gotoxy (10, 25);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
			
			fin4 = true;
			
			extraer_contenido_fichero (linea1, linea2, linea3, linea4, linea5);
			
			// Manejo de string
			records[0].nombre = linea1.substr(0, linea1.find(";"));
			records[0].tiempo = linea1.erase (0, linea1.find(";") + 1);
			
			records[1].nombre = linea2.substr(0, linea2.find(";"));
			records[1].tiempo = linea2.erase (0, linea2.find(";") + 1);
			
			records[2].nombre = linea3.substr(0, linea3.find(";"));
			records[2].tiempo = linea3.erase (0, linea3.find(";") + 1);
			
			records[3].nombre = linea4.substr(0, linea4.find(";"));
			records[3].tiempo = linea4.erase (0, linea4.find(";") + 1);
			
			records[4].nombre = linea5.substr(0, linea5.find(";"));
			records[4].tiempo = linea5.erase (0, linea5.find(";") + 1);
			
			tiempos[0] = atof(records[0].tiempo.c_str());
			tiempos[1] = atof(records[1].tiempo.c_str());
			tiempos[2] = atof(records[2].tiempo.c_str());
			tiempos[3] = atof(records[3].tiempo.c_str());
			tiempos[4] = atof(records[4].tiempo.c_str());
			
			gotoxy (60, 16);
			cout << "M E J O R E S   M A R C A S";
			
			cout << fixed << setprecision(3);
			
			gotoxy (65, 18); cout << records[0].nombre;	
			gotoxy (75, 18); cout << tiempos[0] << endl;
			gotoxy (65, 19); cout << records[1].nombre;	
			gotoxy (75, 19); cout << tiempos[1] << endl;
			gotoxy (65, 20); cout << records[2].nombre;	
			gotoxy (75, 20); cout << tiempos[2] << endl;
			gotoxy (65, 21); cout << records[3].nombre;	
			gotoxy (75, 21); cout << tiempos[3] << endl;
			gotoxy (65, 22); cout << records[4].nombre;	
			gotoxy (75, 22); cout << tiempos[4] << endl;
		}
		
		else if ((opc == 'N') || (opc == 'n')) {
			gotoxy (10, 25);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
			fin4 = true;
		}
		
		else {
			gotoxy (10, 25);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
			gotoxy (10, 25);
			cout << "Opción no válida";	
		}
	}
	
	gotoxy (10, 25);
	system ("pause");
	return 0;
}

// Definición de la función "gotoxy"
void gotoxy (int x, int y) {	// Ancho = 120, Alto = 30
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}

// Definición de la función "generar_matriz_numerica_nula"
int generar_matriz_numerica_nula (int matriz_numerica[4][4]) {
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matriz_numerica[i][j] = 0;
		}
	}
	
	return matriz_numerica[4][4];
}

// Definición de la función "generar_pantanos_aleatorios"
int generar_pantanos_aleatorios (int matriz_numerica[4][4]) {
	
	int fila_aleatoria;
	int columna_aleatoria;
	int verificar_pantanos;
	char letra164 = 164;
	
	bool fin1 = false;
	
	for (int i = 0; i < 4; i++) {
		fila_aleatoria = rand() % 4;
		columna_aleatoria = rand() % 4;
		matriz_numerica[fila_aleatoria][columna_aleatoria] = -1;
	}
	
	// Verificar 4 pantanos
	do {
		verificar_pantanos = 0;
		
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (matriz_numerica[i][j] == -1) verificar_pantanos++;
			}
		}
		
		if (verificar_pantanos < 4) {
			for (int i = 0; i < 4 - verificar_pantanos; i++) {
				fila_aleatoria = rand() % 4;
				columna_aleatoria = rand() % 4;
				matriz_numerica[fila_aleatoria][columna_aleatoria] = -1;
			}
		}
		
		else if (verificar_pantanos == 4) fin1 = true;
		
	} while (fin1 != true);
	
	return matriz_numerica[4][4];
}
	
// Definición de la función "contar_pantanos"	
int contar_pantanos (int matriz_numerica[4][4]) {
	
	int contador_pantanos;
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			
			contador_pantanos = 0;
			
			if ((i != 0) && (i != 3) && (j != 0) && (j != 3)) {	// No en bordes ni esquinas
				
				if (matriz_numerica[i+1][j+1] == -1) contador_pantanos++;
				if (matriz_numerica[i+1][j] == -1) contador_pantanos++;
				if (matriz_numerica[i+1][j-1] == -1) contador_pantanos++;
				
				if (matriz_numerica[i][j-1] == -1) contador_pantanos++;				
				if (matriz_numerica[i][j+1] == -1) contador_pantanos++;	
				
				if (matriz_numerica[i-1][j-1] == -1) contador_pantanos++;			
				if (matriz_numerica[i-1][j] == -1) contador_pantanos++;				
				if (matriz_numerica[i-1][j+1] == -1) contador_pantanos++;	
			}
			
			else if ((i == 0) && (j != 0) && (j != 3)) {	// Borde superior no esquinas
				
				if (matriz_numerica[i][j-1] == -1) contador_pantanos++;			
				if (matriz_numerica[i][j+1] == -1) contador_pantanos++;	
				
				if (matriz_numerica[i+1][j-1] == -1) contador_pantanos++;		
				if (matriz_numerica[i+1][j] == -1) contador_pantanos++;				
				if (matriz_numerica[i+1][j+1] == -1) contador_pantanos++;
			}
			
			else if ((i == 3) && (j != 0) && (j != 3)) {	// Borde inferior no esquinas
				
				if (matriz_numerica[i][j-1] == -1) contador_pantanos++;	
				if (matriz_numerica[i][j+1] == -1) contador_pantanos++;
				
				if (matriz_numerica[i-1][j-1] == -1) contador_pantanos++;
				if (matriz_numerica[i-1][j] == -1) contador_pantanos++;						
				if (matriz_numerica[i-1][j+1] == -1) contador_pantanos++;
			}
			
			else if ((j == 0) && (i != 0) && (i != 3)) {	// Borde izquierdo no esquinas
				
				if (matriz_numerica[i-1][j] == -1) contador_pantanos++;
				if (matriz_numerica[i+1][j] == -1) contador_pantanos++;
				
				if (matriz_numerica[i-1][j+1] == -1) contador_pantanos++;
				if (matriz_numerica[i][j+1] == -1) contador_pantanos++;
				if (matriz_numerica[i+1][j+1] == -1) contador_pantanos++;
			}
			
			else if ((j == 3) && (i != 0) && (i != 3)) {	// Borde derecho no esquinas
				
				if (matriz_numerica[i-1][j] == -1) contador_pantanos++;
				if (matriz_numerica[i+1][j] == -1) contador_pantanos++;
				
				if (matriz_numerica[i-1][j-1] == -1) contador_pantanos++;
				if (matriz_numerica[i][j-1] == -1) contador_pantanos++;
				if (matriz_numerica[i+1][j-1] == -1) contador_pantanos++;
			}
			
			else if ((i == 0) && (j == 0)) {	// Esquina superior izquierda
				
				if (matriz_numerica[i+1][j] == -1) contador_pantanos++;
				if (matriz_numerica[i][j+1] == -1) contador_pantanos++;
				if (matriz_numerica[i+1][j+1] == -1) contador_pantanos++;
			}
			
			else if ((i == 3) && (j == 0)) {	// Esquina inferior izquierda
				
				if (matriz_numerica[i-1][j] == -1) contador_pantanos++;
				if (matriz_numerica[i][j+1] == -1) contador_pantanos++;
				if (matriz_numerica[i-1][j+1] == -1) contador_pantanos++;
			}
			
			else if ((i == 0) && (j == 3)) {	// Esquina superior derecha
				
				if (matriz_numerica[i][j-1] == -1) contador_pantanos++;
				if (matriz_numerica[i+1][j] == -1) contador_pantanos++;
				if (matriz_numerica[i+1][j-1] == -1) contador_pantanos++;
			}
			
			else if ((i == 3) && (j == 3)) {	// Esquina inferior derecha
				
				if (matriz_numerica[i-1][j] == -1) contador_pantanos++;
				if (matriz_numerica[i][j-1] == -1) contador_pantanos++;
				if (matriz_numerica[i-1][j-1] == -1) contador_pantanos++;
			}
			
			if (matriz_numerica[i][j] != -1) matriz_numerica[i][j] = contador_pantanos;
		}
	}
	
	return matriz_numerica[4][4];
}
	
// Definición de la función "generar_matriz_caracter"	
char generar_matriz_caracter (int matriz_numerica[4][4], char matriz_caracter[4][4]) {
	
	char letra164 = 164;
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			
			if (matriz_numerica[i][j] == -1) matriz_caracter[i][j] = letra164;
			if (matriz_numerica[i][j] == 0) matriz_caracter[i][j] = 0 + '0';
			if (matriz_numerica[i][j] == 1) matriz_caracter[i][j] = 1 + '0';
			if (matriz_numerica[i][j] == 2) matriz_caracter[i][j] = 2 + '0';
			if (matriz_numerica[i][j] == 3) matriz_caracter[i][j] = 3 + '0';
			if (matriz_numerica[i][j] == 4) matriz_caracter[i][j] = 4 + '0';
		}
	}
	
	return matriz_caracter[4][4];
}
	
// Definición de la función "generar_mapa"		
char generar_mapa (char mapa[4][4]) {

	char letra160 = 160;
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mapa[i][j] = letra160;
		}
	}
	
	return mapa[4][4];
}

// Definición de la función "color"		
void color (int n) {
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), n);
}

// Definición de la función "ingresar_valor"		
template <class STRING>
int ingresar_fila (STRING num, double numero, int entero) {
	
	int longitud_caracteres, espacios_blanco = 0;
	char cadena [100] = "";
	bool fin2 = false;
	
	while (!fin2) {	
		
		gotoxy (10, 16);
		cout << "\t\t\t\t\t\t\t\t";
		gotoxy (10, 16);
		fflush (stdin);	 // Para limpiar la entrada de datos
		cout<<"Ingrese una fila: ";
		getline(cin,num);
		
		if (istringstream(num) >> numero) {		// Con este if verificamos si es un número
			
			entero = numero;
			entero = atoi (num.c_str());	// Conversión de char a entero
			
			if (numero - entero) {	// Con este if verificamos si el número es un decimal
				gotoxy (10, 25);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
				gotoxy (10, 25);
				cout << "Usted ingresó un número decimal, por favor ingrese un número entero del 1 al 4." << endl;
			}
			
			else if ((numero >= 1) && (numero <= 4)) {	// Con este if verificamos que sea el número 1 o 2
				fin2 = true;
			}
			
			else {
				gotoxy (10, 25);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
				gotoxy (10, 25);
				cout << "Usted ingresó el número de una fila no válida, por favor ingrese un número entero del 1 al 4." << endl;	// Ej: -6, 0, 3, 4, ...
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
				gotoxy (10, 25);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
				gotoxy (10, 25);
				cout << "Usted digitó un espacio en blanco, por favor ingrese un número entero del 1 al 4." << endl;
			}
			
			else if (espacios_blanco > 1) {	// verificamos si digitó más de un espacio en blanco
				gotoxy (10, 25);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
				gotoxy (10, 25);
				cout << "Usted digitó varios espacios en blanco, por favor ingrese un número entero del 1 al 4." << endl;
			}
			
			else if (longitud_caracteres == 0){	// verificamos si no digitó ningún valor
				gotoxy (10, 25);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
				gotoxy (10, 25);
				cout << "No digitó ningun valor, por favor ingrese un número entero del 1 al 4." << endl;
			}
			
			else if (longitud_caracteres == 1) {	// verificamos si ingresó un caracter
				gotoxy (10, 25);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
				gotoxy (10, 25);
				cout << "Usted ingresó una caracter, por favor ingrese un número entero del 1 al 4." << endl;
			}
			
			else if (longitud_caracteres > 1) {	// verificamos si ingreso más de un caracter
				gotoxy (10, 25);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
				gotoxy (10, 25);
				cout << "Usted ingresó varios caracteres, por favor ingrese un número entero del 1 al 4." << endl;
			}
		}
	}
	
	return entero;
}

// Definición de la función "ingresar_valor"		
template <class STRING>
int ingresar_columna (STRING num, double numero, int entero) {
	
	int longitud_caracteres, espacios_blanco = 0;
	char cadena [100] = "";
	bool fin2 = false;
	
	while (!fin2) {	
		
		gotoxy (10, 18);
		cout << "\t\t\t\t\t\t\t\t";
		gotoxy (10, 18);
		fflush (stdin);	 // Para limpiar la entrada de datos
		cout<<"Ingrese una columna: ";
		getline(cin,num);
		
		if (istringstream(num) >> numero) {		// Con este if verificamos si es un número
			
			entero = numero;
			entero = atoi (num.c_str());	// Conversión de char a entero
			
			if (numero - entero) {	// Con este if verificamos si el número es un decimal
				gotoxy (10, 25);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
				gotoxy (10, 25);
				cout << "Usted ingresó un número decimal, por favor ingrese un número entero del 1 al 4." << endl;
			}
			
			else if ((numero >= 1) && (numero <= 4)) {	// Con este if verificamos que sea el número 1 o 2
				fin2 = true;
			}
			
			else {
				gotoxy (10, 25);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
				gotoxy (10, 25);
				cout << "Usted ingresó el número de una columna no válida, por favor ingrese un número entero del 1 al 4." << endl;	// Ej: -6, 0, 3, 4, ...
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
				gotoxy (10, 25);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
				gotoxy (10, 25);
				cout << "Usted digitó un espacio en blanco, por favor ingrese un número entero del 1 al 4." << endl;
			}
			
			else if (espacios_blanco > 1) {	// verificamos si digitó más de un espacio en blanco
				gotoxy (10, 25);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
				gotoxy (10, 25);
				cout << "Usted digitó varios espacios en blanco, por favor ingrese un número entero del 1 al 4." << endl;
			}
			
			else if (longitud_caracteres == 0){	// verificamos si no digitó ningún valor
				gotoxy (10, 25);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
				gotoxy (10, 25);
				cout << "No digitó ningun valor, por favor ingrese un número entero del 1 al 4." << endl;
			}
			
			else if (longitud_caracteres == 1) {	// verificamos si ingresó un caracter
				gotoxy (10, 25);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
				gotoxy (10, 25);
				cout << "Usted ingresó una caracter, por favor ingrese un número entero del 1 al 4." << endl;
			}
			
			else if (longitud_caracteres > 1) {	// verificamos si ingreso más de un caracter
				gotoxy (10, 25);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
				gotoxy (10, 25);
				cout << "Usted ingresó varios caracteres, por favor ingrese un número entero del 1 al 4." << endl;
			}
		}
	}
	
	return entero;
}

// Definiión de la función "nombre_juego"
void pintar_nombre_juego () {
	gotoxy (10, 1);
	cout << "B U S C A P A N T A N O S";
}

// Definición de la función "pintar_limites"
void pintar_limites () {
	
	for (int i = 10; i < 34; i++) {
		gotoxy (i, 2);
		printf ("%c", 95);
		
		gotoxy (i, 12);
		printf ("%c", 95);
	}
	
	for (int i = 3; i < 13; i++) {
		gotoxy (9, i);
		printf ("%c", 124);
		
		gotoxy (34, i);
		printf ("%c", 124);
	}
}

// Definición de la función "mostrar_mapa"
void mostrar_mapa () {

	char letra160 = 160;

	gotoxy (15, 4);

	cout << "   C o l u m n a";
	
	gotoxy (15, 5);
	
	cout << "     1" << "  2" << "  3" << "  4";
	
	for (int i = 0; i < 4; i++) {
		
		color (7);
		
		gotoxy (12, 7 + i);
		
		switch (i) {
			case 0: cout << "F"; break;
			case 1: cout << "i"; break;
			case 2: cout << "l"; break;
			case 3: cout << "a"; break;
		}
		
		gotoxy (15, 7 + i);
		
		cout << i + 1 << "   ";
	
		for (int j = 0; j < 5; j++) {
			
			if (j == 4) {
				color (00);
				cout << "[ " << "]";
			}

			else if ((i + j) % 2 == 0) {
				color (135);
				cout << " " << letra160 << " ";
				
			}
			
			else {
				color (880);
				cout << " " << letra160 << " ";
			}
		}
	}
	color (7);
}

// Definición de la función "mostrar_casilla"
void mostrar_casilla (char matriz_caracter[4][4], char mapa[4][4], int fila_usuario, int columna_usuario) {

	char letra164 = 164;
		
	for (int i = 0; i < 4; i++) {
		
		color (7);
		
		gotoxy (15, 7 + i);
		
		cout << i + 1 << "   ";
		
		for (int j = 0; j < 5; j++) {
			
			if (j == 4) {
				color (00);
				cout << "[ " << "]";
			}

			else if ((i + j) % 2 == 0) {
				color (135);
				
				if (((i == fila_usuario) && (j == columna_usuario)) && (matriz_caracter[fila_usuario][columna_usuario] == letra164)) {
					color (452);
					cout << " " << letra164 << " ";
				}
				else cout << " " << mapa[i][j] << " ";		
			}
			
			else {
				color (880);
				
				if (((i == fila_usuario) && (j == columna_usuario)) && (matriz_caracter[fila_usuario][columna_usuario] == letra164)) {
					color (452);
					cout << " " << letra164 << " ";
				}
				else cout << " " << mapa[i][j] << " ";
			}
		}
		cout << endl;
	}
	color (7);
}

// Definición de la función "juego"
void juego (char matriz_caracter[4][4], char mapa[4][4], bool &fin2, bool &fin3) {

	char letra164 = 164;
	char letra160 = 160;
	
	int contador_anterior;
	int contador_posterior;
	
	int turno = 1;
	int racha = 0;
	
	string n1;
	double numero;
	
	int fila_usuario;
	int columna_usuario;
	
	do {
		contador_anterior = 0;
		contador_posterior = 0;
		
		gotoxy (15, 14); cout << "T U R N O   " << turno;
		
		gotoxy (30, 18);
		cout << "\t\t\t\t\t\t\t\t";
		
		// Pedir datos al usuario
		fila_usuario = ingresar_fila (n1, numero, fila_usuario);
		gotoxy (10, 25);
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";

		columna_usuario = ingresar_columna (n1, numero, columna_usuario);
		gotoxy (10, 25);
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
		
		fila_usuario--;
		columna_usuario--;
		
		// Contador de '?' anterior
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (mapa[i][j] == letra160) contador_anterior++;
			}
		}
		
		// Algoritmo para relacionar matrices
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				mapa[fila_usuario][columna_usuario] = matriz_caracter[fila_usuario][columna_usuario];
				if (matriz_caracter[fila_usuario][columna_usuario] == letra164) fin2 = true;
			}
		}

		// Contador de '?' posterior
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (mapa[i][j] == letra160) contador_posterior++;
			}
		}
		
		if (contador_anterior != contador_posterior) {
			mostrar_casilla (matriz_caracter, mapa, fila_usuario, columna_usuario);			
			racha++;
		}
		
		else {
			gotoxy (10, 25);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
			gotoxy (10, 25);
			cout << "CASILLA YA DESCUBIERTA";
		}

		if (racha == 12) fin3 = true;
		
		turno++;
	
	} while ((fin2 != true) && (fin3 != true));
}

// Definición de la función "mostrar_solucion"
void mostrar_solucion (int matriz_numerica[4][4]) {

	char letra164 = 164;
	
	gotoxy (59, 1);
	cout << "S O L U C I Ó N";
	
	for (int i = 0; i < 4; i++) {
		
		color (7);
		
		gotoxy (61, 3 + i);
		
		for (int j = 0; j < 5; j++) {
			
			if (j == 4) {
				color (00);
				cout << "[ " << "]";
			}
			
			else if ((i + j) % 2 == 0) {
				color (135);
				
				if (matriz_numerica[i][j] == -1) {
					color (452);
					cout << " " << letra164 << " ";
				}
				else if (matriz_numerica[i][j] == 0) cout << " 0 ";
				else if (matriz_numerica[i][j] == 1) cout << " 1 ";
				else if (matriz_numerica[i][j] == 2) cout << " 2 ";
				else if (matriz_numerica[i][j] == 3) cout << " 3 ";
				else if (matriz_numerica[i][j] == 4) cout << " 4 ";
			}

			else {
				color (880);
				
				if (matriz_numerica[i][j] == -1) {
					color (452);
					cout << " " << letra164 << " ";
				}
				else if (matriz_numerica[i][j] == 0) cout << " 0 ";
				else if (matriz_numerica[i][j] == 1) cout << " 1 ";
				else if (matriz_numerica[i][j] == 2) cout << " 2 ";
				else if (matriz_numerica[i][j] == 3) cout << " 3 ";
				else if (matriz_numerica[i][j] == 4) cout << " 4 ";
			}		
		}
		
		cout << endl;
	}
	color (7);
}

// Definición de la función "extraer_contenido_fichero"
template <class STRING>
void extraer_contenido_fichero (STRING &linea1, STRING &linea2, STRING &linea3, STRING &linea4,STRING &linea5) {
	
	ifstream archivo;
	archivo.open("Ranking_Tumbalobos.txt", ios::in);	// Intenta abrir archivo
	
	if (archivo.fail()) {	// Si marca error
	
		ofstream archivo;
		archivo.open("Ranking_Tumbalobos.txt", ios::out);	// Creamos el archivo
		
		archivo << "JUAN;242.13" << endl;
		archivo << "JOSE;253.44" << endl;
		archivo << "PEDRO;266.12" << endl;
		archivo << "MARÍA;270.22" << endl;
		archivo << "ANA;281.44" << endl;
		
		archivo.close();	// Cerramos archivo creado
	}
	
	archivo.close(); // Cerramos archivo
	
	ifstream ReadFile("Ranking_Tumbalobos.txt");	// Modo lectura
	archivo.open("Ranking_Tumbalobos.txt", ios::in);	
	
	getline (archivo, linea1);	
	getline (archivo, linea2);
	getline (archivo, linea3);
	getline (archivo, linea4);
	getline (archivo, linea5);

	ReadFile.close();	// Cerramos el archivo	
}

