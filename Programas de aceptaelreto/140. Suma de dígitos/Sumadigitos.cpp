// Nombre del alumno Marcos Herrero
// Usuario del Juez DG-11


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


// función que resuelve el problema
int resolver(std::string digitos) {
	int suma = 0;
	for (int i = 0; i < digitos.size() - 1; i++) {
		suma += int(digitos[i])-int('0');
		std::cout << digitos[i] << " + ";	
	}
	suma += int(digitos[digitos.size() - 1])-int('0');
	std::cout << digitos[digitos.size() - 1]<<" = ";
	return suma;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	std::string digitos="";

	getline(std::cin, digitos);

	if (digitos[0]=='-')
		return false;
    
    int sol = resolver(digitos);
    
    // escribir sol
	std::cout << sol<<'\n';
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
   // #ifndef DOMJUDGE
   //  std::ifstream in("datos1.txt");
   //  auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
   //  #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
   //  #ifndef DOMJUDGE // para dejar todo como estaba al principio
  //   std::cin.rdbuf(cinbuf);
  //   system("PAUSE");
  //   #endif
    
    return 0;
}