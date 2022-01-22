// Nombre del alumno Marcos Herrero
// Usuario del Juez DG-11


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <climits>

// función que resuelve el problema
std::string diasemana(int diacrit) {
	switch (diacrit) {
	case 0: return "L ";
	case 1: return "M ";
	case 2: return "X ";
	case 3: return "J ";
	case 4: return "V ";
	case 5: return "S ";
	case 6: return "D ";
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	std::vector<int> pastdias(7);
	int semanas = 0, pastdiacrit = 0, diacrit = 0; 
	char simbolo = ' ';

	std::cin >> semanas;
	if (semanas != 0) {

		for (int i = 0; i < semanas - 1; i++) {
			for (int j = 0; j < pastdias.size(); j++) {
				std::cin >> simbolo;
				if (simbolo == '*')pastdias[j]++;
			}
		}
		std::cin >> simbolo;
		if (simbolo == '*')pastdias[0]++;
		pastdiacrit = pastdias[0];

		for (int j = 1; j < pastdias.size(); j++) {
			std::cin >> simbolo;
			if (simbolo == '*')pastdias[j]++;
			if (pastdias[j] < pastdiacrit) {
				pastdiacrit = pastdias[j];
				diacrit = j;
			}
		}	
	}
    // escribir sol
    
	std::cout << diasemana(diacrit) <<pastdiacrit+1<<'\n';
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
//#ifndef DOMJUDGE
//  std::ifstream in("datos1.txt");
// auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
// #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    //Para restablecer entrada. Comentar para acepta el reto
 // #ifndef DOMJUDGE // para dejar todo como estaba al principio
 // std::cin.rdbuf(cinbuf);
//  system("PAUSE");
 //#endif
    
    return 0;
}