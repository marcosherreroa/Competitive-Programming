// Nombre del alumno Marcos Herrero
// Usuario del Juez DG11


#include <iostream>
#include <iomanip>
#include <fstream>

 int tiempoaseg(int d, int h, int min, int s) {
	s += 24 * 60 * 60 * d + 60 * 60 * h + 60 * min;
	return s;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	 char puntos = 0;
	int drest = 0, hrest = 0, minrest = 0, srest = 0, 
		h = 0, min = 0, s = 0, dtot=0, htot=0, mintot=0, stot=0 ;

	std::cin >> drest >> puntos >> hrest >> puntos 
		>> minrest>> puntos >> srest;

	std::cin >> h >> puntos >>min>>puntos>>s;

	while (h != 0 || min != 0 || s != 0) {
		htot += h; mintot += min; stot += s;
		std::cin >> h >> puntos >> min >> puntos >> s;
	}
	stot = tiempoaseg(dtot, htot, mintot, stot);
	srest = tiempoaseg(drest, hrest, minrest, srest);

	if (srest > stot)std::cout << "SI\n";
	else std::cout << "NO\n";
      
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
   // #ifndef DOMJUDGE
    // std::ifstream in("datos1.txt");
    // auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
   //  #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
    // #ifndef DOMJUDGE // para dejar todo como estaba al principio
     //std::cin.rdbuf(cinbuf);
    // system("PAUSE");
    // #endif
    
    return 0;
}