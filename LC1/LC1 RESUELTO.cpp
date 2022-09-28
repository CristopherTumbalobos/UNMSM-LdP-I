// UNMSM � Facultad de Ing. Electr�nica y El�ctrica 
// Escuela de Ingenier�a Electr�nica
// Curso: Lenguaje de Programaci�n
// Docente: Avila L�pez, B. Patricio 
// Estudiante: Tumbalobos Peralta, Cristopher Rigoberto
// Fecha: 13/06/2020 
// Laboratorio Calificado 01 
// Objetivo: Resolver la expresi�n. 
// Datos de entrada: N�mero real. 
// Restricciones:No permite n�meros negativos, ni el cero.
//				 El n�mero ingresado con dos cifras decimales debe ser menor a 0.72.

#include <iostream>
#include <cmath>
#include <locale.h>

using namespace std;

int main() {
	setlocale(LC_ALL,"");
	
	double x, resultado = 0;		// x : variable real
	
	cout << "\nIngrese un valor positivo, con dos cifras decimales, menor a 0.72: ";
	cin >> x;
	
	if ((x > 0) && (x < 0.72)) {
		
		resultado = (5*pow(x,2) + pow((pow(x,2) - 6),-4) - (22/x) ) / (sqrt(pow(x,-3)-8*pow(x,2)+2*x)); 
		    
		cout << "\nEl resultado es: " << resultado << endl;
	}
	
	else{
		
		if (x == 0) {
			
			cout << "\nIndeterminado" << endl;
		}
		
		else {
			
		cout << "\nLa expresi�n no tiene soluci�n real" << endl;
		}	
	}
	
	return 0;
}
