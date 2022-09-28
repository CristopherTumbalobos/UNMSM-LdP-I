// UNMSM – Facultad de Ing. Electrónica y Eléctrica 
// Escuela de Ingeniería Electrónica
// Curso: Lenguaje de Programación
// Docente: Avila López, B. Patricio 
// Estudiante: Tumbalobos Peralta, Cristopher Rigoberto
// Fecha: 13/06/2020 
// Laboratorio Calificado 01 
// Objetivo: Resolver la expresión. 
// Datos de entrada: Número real. 
// Restricciones:No permite números negativos, ni el cero.
//				 El número ingresado con dos cifras decimales debe ser menor a 0.72.

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
			
		cout << "\nLa expresión no tiene solución real" << endl;
		}	
	}
	
	return 0;
}
