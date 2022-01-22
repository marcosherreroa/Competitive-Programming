// Nombre del alumno Marcos Herrero
// Usuario del Juez DG11


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema
int resolver(int base,int altura,int maxdist) {
	int sol = 0, postbase = 0, postaltura = 0;

	if(base%maxdist==0)postbase = base / maxdist - 1;
	else postbase = base / maxdist ;

	if (altura%maxdist == 0)postaltura = altura / maxdist - 1;
	else postaltura = altura / maxdist;

	sol = 2 * postbase + 2 * postaltura + 4;
	return sol; 
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int base = 0, altura = 0, maxdist = 0;
	std::cin >> base >> altura >> maxdist;
	if (base == 0 && altura == 0 && maxdist == 0)
		return false;
    
    int sol = resolver(base,altura,maxdist);
    
    // escribir sol
	std::cout << sol<<'\n';
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
  //  #ifndef DOMJUDGE
    // std::ifstream in("datos1.txt");
    // auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
    // #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
    // #ifndef DOMJUDGE // para dejar todo como estaba al principio
    // std::cin.rdbuf(cinbuf);
    // system("PAUSE");
     //#endif
    
    return 0;
}