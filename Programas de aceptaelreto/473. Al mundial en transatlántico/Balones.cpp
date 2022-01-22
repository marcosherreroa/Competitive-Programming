//Marcos Herrero
#include <iostream>
#include <queue>

bool resuelveCaso() {
	int b, p;
	std::cin >> b >> p;
	if (b == 0 && p == 0)return false;

	std::queue<int> cola;
	for (int i = 1; i <= b; ++i)cola.push(i);

	while (cola.size() > 1) {
		for (int i = 0; i < p - 1; ++i) {
			cola.push(cola.front());
			cola.pop();
		}
		cola.pop();
	}

	std::cout << cola.front() << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}