// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int num = 0;
	std::cin >> num;
    
    if (num==0)
        return false;
    
	// escribir sol
	if (num % 2 == 0)std::cout << "DERECHA\n";
	else std::cout << "IZQUIERDA\n";
   
    return true;
    
}

int main() {
    
    
    while (resuelveCaso()) ;

    
   
    return 0;
}