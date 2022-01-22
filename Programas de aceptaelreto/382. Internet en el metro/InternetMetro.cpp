//Marcos Herrero
#include <iostream>

void resuelveCaso() {
	int l, antenas;
	std::cin >> l >> antenas;

	int dist, radio, act = 0;
	for (int i = 0; i < antenas; ++i) {
		std::cin >> dist>> radio;
		if (dist - act <= radio && act < dist+radio)act = dist + radio;
	}

	if (act >= l) std::cout << "SI\n";
	else std::cout << "NO\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}