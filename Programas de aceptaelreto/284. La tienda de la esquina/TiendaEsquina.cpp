// Nombre del alumno Marcos Herrero
// Usuario del Juez DG11


#include <iostream>
#include <iomanip>
#include <fstream>


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int centcoste = 0, centpagado = 0, moned2eur = 0, moned1eur = 0, moned50cent = 0, moned20cent = 0,
		moned10cent = 0, moned5cent = 0, moned2cent = 0, moned1cent = 0, deuda = 0, devolucion = 0;
	std::cin >> centcoste >> centpagado;

	// escribir sol
	if (centpagado < centcoste) {
		deuda = centcoste - centpagado;
		std::cout << "DEBE " << centcoste - centpagado<<'\n';
	}
	else {
		devolucion = centpagado - centcoste;

		moned2eur = devolucion / 200;devolucion %= 200;
		moned1eur = devolucion / 100; devolucion %= 100;
		moned50cent = devolucion / 50; devolucion %= 50;
		moned20cent = devolucion / 20; devolucion %= 20;
		moned10cent = devolucion / 10; devolucion %= 10;
		moned5cent = devolucion / 5; devolucion %= 5;
		moned2cent = devolucion / 2; devolucion %= 2;
		moned1cent = devolucion;

		std::cout << moned2eur << ' ' << moned1eur << ' ' << moned50cent << ' ' << moned20cent << ' '
			<< moned10cent << ' ' << moned5cent << ' ' << moned2cent << ' ' << moned1cent << '\n';
	}
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
   // #ifndef DOMJUDGE
  //  std::ifstream in("datos1.txt");
   //  auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
   //  #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
    // #ifndef DOMJUDGE // para dejar todo como estaba al principio
    // std::cin.rdbuf(cinbuf);
    // system("PAUSE");
    // #endif
    
    return 0;
}