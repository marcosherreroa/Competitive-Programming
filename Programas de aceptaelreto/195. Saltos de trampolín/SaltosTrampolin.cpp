// Nombre del alumno Marcos Herrero
// Usuario del Juez DG-11


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>



// función que resuelve el problema
const float CD = 2.0;

int resolver(std::vector<float> & notas) {
	std::sort(notas.begin(), notas.end());

	int sol = (notas[2] + notas[3] + notas[4])*CD;
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	std::vector<float> notas(7);

	for (int i = 0; i < 7; ++i) {
		std::cin >> notas[i];
	}
    
    if (! std::cin)
        return false;
    
    int sol = resolver(notas);
    
    // escribir sol
	std::cout << sol<<'\n';
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
  //  #ifndef DOMJUDGE
  //   std::ifstream in("datos1.txt");
 //    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
 //    #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
  //   #ifndef DOMJUDGE // para dejar todo como estaba al principio
 //    std::cin.rdbuf(cinbuf);
 //    system("PAUSE");
 //    #endif
    
    return 0;
}