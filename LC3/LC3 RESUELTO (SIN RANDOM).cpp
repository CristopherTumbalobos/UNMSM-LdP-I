// UNMSM � Facultad de Ing. Electr�nica y El�ctrica 
// Escuela de Ingenier�a Electr�nica
// Curso: Lenguaje de Programaci�n
// Docente: Avila L�pez, B. Patricio 
// Estudiante: Tumbalobos Peralta, Cristopher Rigoberto
// Fecha: 20/06/2020 
// Laboratorio Calificado 02 
// Objetivo: Cu�ntos baldes de pintura se debe comprar. 
// Datos de entrada: Lados de una superficie rectangular para pintar.
// Restricciones: Los datos ingresados deben estar en metros y ser v�lidos (positivos).

#include <iostream>
#include <cmath>	//para usar trunc() y ceil()
#include <locale.h>
#include <string>	//para usar getline
#include <sstream>	//para usar istringstream
#include <iomanip>	//para usar setprecision
#include <stdlib.h>	//para usar system ("pause")

using namespace std;

int main() {
	setlocale(LC_ALL,"");
	
	const double CONVERSION = 0.2641720512415584;
	
	string n1, n2;
	double primer_lado, segundo_lado, superficie, galones_por_balde, litros_necesitados,
	galones_necesitados, baldes_necesitados;
	
	while (!((istringstream(n1) >> primer_lado) && (primer_lado > 0))) {
		
		cout << "\n\tIngrese el valor del primer lado de la superficie rectangular: "; getline(cin,n1);
		
		if (istringstream(n1) >> primer_lado) {
			
			if (primer_lado > 0) {
			}
			
			else if (primer_lado == 0) {
				cout << "\tUsted ingres� el cero, por favor ingrese valores positivos." << endl;	
			}
			
			else {
				cout << "\tUsted ingres� n�meros negativos, por favor ingrese valores positivos." << endl;
			}
		}
		
		else {
			cout << "\tUsted ingres� letra(s), debe digitar n�meros positivos." << endl;
		}
	}
	
	while (!((istringstream(n2) >> segundo_lado) && (segundo_lado > 0))) {
		
		cout << "\n\tIngrese el valor del segundo lado de la superficie rectangular: "; getline(cin,n2);
		
		if (istringstream(n2) >> segundo_lado) {
			
			if (segundo_lado > 0) {
			}
			
			else if (segundo_lado == 0) {
				cout << "\tUsted ingres� el cero, por favor ingrese valores positivos." << endl;	
			}
			
			else {
				cout << "\tUsted ingres� n�meros negativos, por favor ingrese valores positivos." << endl;
			}
		}
		
		else {
			cout << "\tUsted ingres� letra(s), debe digitar n�meros positivos." << endl;
		}
	}	
	
	superficie = primer_lado * segundo_lado;
	litros_necesitados = superficie / 10.0;
	galones_por_balde = (99.9) / 100;	//Asumimos que el balde tiene un 0.1% menos de galones de pintura ("Mejor que sobre a que falte")
	galones_necesitados = litros_necesitados * CONVERSION;
	baldes_necesitados = galones_necesitados / galones_por_balde;
	
	cout << "\n\n\tLa cantidad de baldes que se necesitar� es: " << fixed << setprecision(16) << baldes_necesitados << " baldes." << endl;
	cout << "\n\tPor lo tanto, debe comprar " << fixed << setprecision(0) << trunc((baldes_necesitados * 1) / 1) + 1 << " balde(s) ('Mejor que sobre a que falte')." <<endl;	//tambien puede usar ceil = trunc + 1
	
	cout << "\n\n";
	system ("pause");
	return 0;
}

