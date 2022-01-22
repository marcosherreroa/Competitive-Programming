// Nombre del alumno Marcos Herrero
// Usuario del Juez DG-11


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema
int resolver(int A, int S, int I) {
	int sol = 0;
	sol = A / S -1;
	if (I==1 || S-I< A%S)sol+= 1;
	
	return sol;
}

	// Resuelve un caso de prueba, leyendo de la entrada la
	// configuración, y escribiendo la respuesta
	void resuelveCaso(){
		// leer los datos de la entrada
		int A = 0, S = 0, I = 0;
		std::cin >> A >> S >> I;

		int sol = resolver(A, S, I);
		// escribir sol
		std::cout << sol << '\n';
	}

	int main() {
		// Para la entrada por fichero.
		// Comentar para acepta el reto
//#ifndef DOMJUDGE
//     std::ifstream in("datos1.txt");
//     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif 


		int numCasos;
		std::cin >> numCasos;
		for (int i = 0; i < numCasos; ++i) {
			resuelveCaso();
			}


		// Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//     std::cin.rdbuf(cinbuf);
//      system("PAUSE");
//#endif

		return 0;
	}