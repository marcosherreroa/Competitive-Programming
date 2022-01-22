// Nombre del alumno Marcos Herrero
// Usuario del Juez DG11


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema
int resolver(int ax,int ay, int bx, int by) {
	int area = 0, base = 0, altura = 0;
	base = bx - ax;
	altura = by - ay;
	area = base*altura;
	return area;   
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int ax = 0, ay = 0, bx = 0, by = 0;
	std::cin >> ax >> ay >> bx >> by;
    
    if (bx<ax||by<ay)
        return false;
    
    int area = resolver(ax,ay,bx,by);
    // escribir sol
	std::cout << area <<'\n';
    
    return true;
    
}

int main() {
    
    
    while (resuelveCaso()) ;

    
  
    return 0;
}