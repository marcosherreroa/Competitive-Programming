// Nombre del alumno Marcos Herrero
// Usuario del Juez DG-11


#include <iostream>
#include <iomanip>
#include <fstream>

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int l1 = 0, l2 = 0, l3 = 0, a = 0, b = 0, c = 0;
	std::cin >> l1 >> l2 >> l3;
	// a es el lado mayor del triángulo ( la hipotenusa si es rectángulo)
	if (l1 >= l2&&l1 >= l3) {
		a = l1; b = l2; c = l3;
	}
	else if (l2 >= l1&&l2 >= l3) {
		a = l2; b = l1; c = l3;
	}
	else {
		a = l3; b = l1; c = l2;
	} 
    // escribir sol
	if (b + c <= a)std::cout << "IMPOSIBLE\n";
	else if (a * a < b * b + c * c)std::cout << "ACUTANGULO\n";
	else if (a * a == b * b + c * c)std::cout << "RECTANGULO\n";
	else std::cout << "OBTUSANGULO\n";
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
   // #ifndef DOMJUDGE
//     std::ifstream in("datos1.txt");
//     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
    // #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
   //  #ifndef DOMJUDGE // para dejar todo como estaba al principio
//     std::cin.rdbuf(cinbuf);
   //  system("PAUSE");
   //  #endif
    
    return 0;
}