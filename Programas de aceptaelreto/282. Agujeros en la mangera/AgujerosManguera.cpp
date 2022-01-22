// Nombre del alumno Marcos Herrero
// Usuario del Juez DG-11


#include <iostream>
#include <iomanip>
#include <fstream>

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int N = 0, L = 0, P1 = 0, P2 = 0, sol = 0;
	std::cin >> N >> L >>P1;
	if (!std::cin)
		return false;

	for (int i = 1; i < N; i++) {
		std::cin >> P2;
		if (P2 - P1 > L) {
			sol += 1; P1 = P2;
		}
	}
		// escribir sol
	sol += 1;
	std::cout << sol << '\n';

	return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
   // #ifndef DOMJUDGE
    // std::ifstream in("datos1.txt");
    // auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
    // #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
   //  #ifndef DOMJUDGE // para dejar todo como estaba al principio
   //  std::cin.rdbuf(cinbuf);
   //  system("PAUSE");
    // #endif
    
    return 0;
}