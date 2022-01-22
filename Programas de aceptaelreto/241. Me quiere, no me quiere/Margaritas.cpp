// Nombre del alumno Marcos Herrero
// Usuario del Juez DG-11


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema
int resolver(int numhojas) {
	int sol = 0;
	sol = numhojas % 3;

	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int numhojas = 0;
	std::cin >> numhojas;
    
    // escribir sol
	if (numhojas < 3 || numhojas == 5) std::cout <<"IMPOSIBLE\n";
	else {
		int sol = resolver(numhojas);
		std::cout << sol << '\n';
	}
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
//    #ifndef DOMJUDGE
//     std::ifstream in("datos1.txt");
//     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//     #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
//     #ifndef DOMJUDGE // para dejar todo como estaba al principio
//     std::cin.rdbuf(cinbuf);
//     system("PAUSE");
//     #endif
    
    return 0;
}