// Nombre del alumno Marcos Herrero
// Usuario del Juez DG-11


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>


// función que resuelve el problema
bool anagrama(std::string frase1, std::string frase2) {
	int cont1 = 0;
	for (int i = 0; i < frase1.size(); ++i) {
		frase1[i] = tolower(frase1[i]);
		if (frase1[i] == ' ')++cont1;
	}
	int cont2 = 0;
	for (int i = 0; i < frase2.size(); ++i) {
		frase2[i] = tolower(frase2[i]);
		if (frase2[i] == ' ')++cont2;
	}
	
	sort(frase1.begin(), frase1.end());
	sort(frase2.begin(), frase2.end());

	frase1.erase(0, cont1);
	frase2.erase(0, cont2);

	return(frase1 == frase2);
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	std::string frase1 = "", frase2 = "";

	getline(std::cin, frase1);
	getline(std::cin, frase2);
    
    if(anagrama(frase1, frase2)) std::cout<< "SI\n";
	else std::cout << "NO\n";
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
	std::cin.ignore(1);
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
   //  #ifndef DOMJUDGE // para dejar todo como estaba al principio
//     std::cin.rdbuf(cinbuf);
 //    system("PAUSE");
 //    #endif
    
    return 0;
}