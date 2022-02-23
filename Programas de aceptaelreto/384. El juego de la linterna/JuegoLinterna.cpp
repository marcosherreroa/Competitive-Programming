//Marcos Herrero
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

struct range {
	int ini;
	int fin;
};

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (!std::cin)return false;

	bool OK = true;
	std::stack<range> forbidden;
	int e, min;
	
	std::cin >> min;
	for (int i = 1; i < N; ++i) {
		std::cin >> e;

		if (OK) {
			if (e < min) min = e;
			else {
				while (OK && !forbidden.empty() && e > forbidden.top().ini) {
					if (e < forbidden.top().fin) OK = false;
					else forbidden.pop();
				}

				forbidden.push({ min,e });
			}
		}
	}

	if (OK)std::cout << "SIEMPRE PREMIO\n";
	else std::cout << "ELEGIR OTRA\n";

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}