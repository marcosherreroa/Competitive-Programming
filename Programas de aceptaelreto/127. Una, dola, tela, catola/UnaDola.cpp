//Marcos Herrero
#include <string>
#include <vector>
#include <iostream>
#include <queue>

void resuelveCaso() {
	std::vector<std::string> per;
	
	std::string nombre;
	std::cin >> nombre;
	while (nombre != "F") {
		per.push_back(nombre);
		std::cin >> nombre;
	}

	int numcamas, numpalabras;
	std::cin >> numcamas >> numpalabras;

	std::queue<int> cola;
	for (int i = 0; i < per.size(); ++i)cola.push(i);

	if (numcamas == 0 && per.size() > 0) std::cout << "NADIE TIENE CAMA\n";
	else if (numcamas >= per.size()) std::cout << "TODOS TIENEN CAMA\n";
	else {
		int n = per.size();
		for (int i = 0; i < n - numcamas; ++i) {
			for (int j = 0; j < numpalabras - 1; ++j) {
				cola.push(cola.front());
				cola.pop();
			}

			cola.pop();
		}


		int aux = cola.front();
		cola.pop();
		cola.push(aux);
		while (aux < cola.front()) {
			aux = cola.front();
			cola.pop();
			cola.push(aux);
		}

		std::cout << per[cola.front()];
		cola.pop();
		while (!cola.empty()) {
			std::cout << ' ' << per[cola.front()];
			cola.pop();
		}

		std::cout << '\n';
	}
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) resuelveCaso();
}