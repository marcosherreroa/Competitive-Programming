// Nombre del alumno Marcos Herrero
// Usuario del Juez DG11


#include <iostream>
#include <iomanip>
#include <fstream>

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int dias = 0, emisoras = 0, s = 0, min = 0, h = 0, d = 0;
	std::cin >> dias >> emisoras;

	if (dias == 0 && emisoras == 0)
			return false;
    
    s = dias*24*6*emisoras;
	min = s / 60;
	s = s % 60;
		
	h = min/60;
    min = min%60;
	
	d = h/24;
	h = h%24;
    // escribir sol
	std::cout << d << ':'
		<< std::setfill('0') << std::setw(2) << h << ':'
		<< std::setfill('0') << std::setw(2) << min << ':'
		<< std::setfill('0') << std::setw(2) << s <<'\n';

    
    return true;
    
}

int main() {
    
    
    while (resuelveCaso()) ;


    
    return 0;
}