//Marcos Herrero
#include <iostream>
#include <queue>

void resuelveCaso() {
	int n, a;
	std::cin >> n >> a;

	std::queue<int> duendes; int aux;
	for (int i = 0; i < n; ++i) {
		std::cin >> aux;
		duendes.push(aux);
	}

	int sol = 0;
	bool stop = false; 
	while (!stop) {
		aux = duendes.front();
		duendes.pop();
		--aux;
		--a;
		if (aux > 0)duendes.push(aux);
		else if (a == 0)  stop = true;

		if (a == 0) a = duendes.size();
		sol += 2;
	}

	std::cout << sol << '\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}