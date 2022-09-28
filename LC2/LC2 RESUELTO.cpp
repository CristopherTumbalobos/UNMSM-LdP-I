// UNMSM – Facultad de Ing. Electrónica y Eléctrica 
// Escuela de Ingeniería Electrónica
// Curso: Lenguaje de Programación
// Docente: Avila López, B. Patricio 
// Estudiante: Tumbalobos Peralta, Cristopher Rigoberto
// Fecha: 20/06/2020 
// Laboratorio Calificado 02 
// Objetivo: Determinar el volumen del lapiz. 
// Datos de entrada: Radio del borrador, altura del cuerpo y altura de la punta.
// Restricciones: Los datos ingresados deben estar en milímetros y ser válidos (positivos).

#include <iostream>
#include <cmath>
#include <locale.h>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main() {
	setlocale(LC_ALL,"");
	
	const float PI = 3.141592;
	
	string n1, n2, n3;
	double radio, altura_cuerpo, altura_punta, area_base, volumen_cono,
	volumen_cilindro, volumen_semiesfera, volumen_lapiz = 0;
	
	cout << "\n\tIngrese el valor del radio del borrador (en milímetros): "; getline(cin,n1);
	cout << "\tIngrese el valor de la altura del cuerpo (en milímetros): "; getline(cin,n2);
	cout << "\tIngrese el valor de la altura de la punta (en milímetros): "; getline(cin,n3);
	
	if((istringstream(n1) >> radio) && (istringstream(n2) >> altura_cuerpo) &&
		 (istringstream(n3) >> altura_punta)) {
		 	
		if ((radio > 0) && (altura_cuerpo > 0) && (altura_punta > 0)) {	
			
			area_base = PI * pow (radio, 2);
			volumen_cono = (area_base * altura_punta) / 3;
			volumen_cilindro = area_base * altura_cuerpo;
			volumen_semiesfera = (2 * PI * pow (radio, 3)) / 3;
			volumen_lapiz = volumen_cono + volumen_cilindro + volumen_semiesfera;
			
			cout << "\n\tEl volumen que ocupa el lápiz es de " << volumen_lapiz << " milímetros cúbicos." << endl;	
		}
		
		else {
			cout << "\n\tLos valores ingresados no son válidos, por favor ingrese valores positivos." << endl;
		}		 		 	
	}
	
	else {
		cout << "\n\tUsted ingreso letra(s), debe digitar números positivos." << endl;
	}

	cout<<"\n\n";
	system("pause");
	return 0;
}
