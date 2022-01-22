// Nombre del alumno Marcos Herrero
// Usuario del Juez DG-11


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


// función que resuelve el problema
int resolver(std::vector<int> & pesosacos, int nburros, int nsacos) {
	sort(pesosacos.begin(), pesosacos.end());

	int sacoant = pesosacos[0];
	int sol = 0;

	for (int i = 1; i < nsacos && nburros>0; ++i) {
		if (pesosacos[i] == sacoant) {
			++sol;
			--nburros;
			sacoant = 0;
		}
		else sacoant = pesosacos[i];
	}
	return sol;   
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int nburros=0, nsacos=0;

	std::cin >> nburros >> nsacos;

	std::vector<int> pesosacos(nsacos);
	for (int i = 0; i < nsacos; ++i) {
		std::cin >> pesosacos[i];
	}

    int sol = resolver(pesosacos, nburros, nsacos);
    // escribir sol
	std::cout << sol<<'\n';
    
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
  //  #ifndef DOMJUDGE
//     std::ifstream in("datos1.txt");
//     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
  //   #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
   //  #ifndef DOMJUDGE // para dejar todo como estaba al principio
//     std::cin.rdbuf(cinbuf);
  //   system("PAUSE");
   //  #endif
    
    return 0;
}