#include <iostream>
#include <string>


bool resuelveCaso(){
	int nespecies, nrelaciones;
	std::cin >> nespecies;

	if (nespecies == 0) return false;

	std::cin >> nrelaciones;

	int aux;
	for (int i = 0; i < nrelaciones; ++i) std::cin >> aux >> aux;

	if (nrelaciones == nespecies - 1)  std::cout << "TODAS\n";
	else std::cout << "FALTA ALGUNA\n";

	return true;
}


int main(){
	while (resuelveCaso());

	//system("PAUSE");
}