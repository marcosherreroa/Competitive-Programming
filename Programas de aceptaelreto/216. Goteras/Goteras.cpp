// Nombre del alumno Marcos Herrero
// Usuario del Juez DG-11


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int gotascubo = 0, h = 0, min = 0, s = 0;
	std::cin >> gotascubo;
	s = gotascubo;
	
	min = s / 60;
	s = s % 60;
		
	h = min / 60;
	min = min % 60;
	
    // escribir sol
	std::cout <<std::setfill('0')<<std::setw(2)<<h<<':';
	std::cout << std::setfill('0') << std::setw(2) << min<<':';
	std::cout << std::setfill('0') << std::setw(2) << s<<'\n';
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
    // #ifndef DOMJUDGE // para dejar todo como estaba al principio
//     std::cin.rdbuf(cinbuf);
    // system("PAUSE");
    // #endif
    
    return 0;
}