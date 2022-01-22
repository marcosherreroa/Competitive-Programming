// Nombre del alumno Marcos Herrero
// Usuario del Juez DG-11


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int nmolinos = 0;

	std::cin >> nmolinos;

    if (nmolinos==0)
        return false;

	std::vector<int> molinos(nmolinos+1);
	int molino = 0;

	molinos[0]=0;
	for (int i = 1; i < nmolinos+1; ++i) {
		std::cin >> molino;
		molinos[i] = molinos[i - 1] + molino;
	}

	int nconsultas = 0, molinoa = 0, molinoz = 0;
	std::cin >> nconsultas;

	for (int i = 0; i < nconsultas; ++i) {
		std::cin >> molinoa >> molinoz;
		int sol = molinos[molinoz] - molinos[molinoa - 1];
		std::cout << sol<<'\n';
	}
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
  //  #ifndef DOMJUDGE
 //    std::ifstream in("datos1.txt");
 //    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
 //    #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
 //    #ifndef DOMJUDGE // para dejar todo como estaba al principio
 //    std::cin.rdbuf(cinbuf);
  //   system("PAUSE");
  //   #endif
    
    return 0;
}