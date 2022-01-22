//Marcos Herrero
#include <iostream>
#include <queue>
#include <stack>

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0) return false;

	std::queue<int> cola;
	for (int i = 1; i <= N; ++i) cola.push(i);

	int i = 2;
	while (cola.size() >= i) {
		int n = cola.size();
		int j = 0;
		while (j < n) {
			cola.pop();
			++j;
			for (int k = 0; k < i - 1 && j < n; ++k) {
				cola.push(cola.front());
				cola.pop();
				++j;
			}
		}
		++i;
	}

	std::stack<int> sol;
	while (!cola.empty()) {
		sol.push(cola.front());
		cola.pop();
	}

	std::cout << N<<':';
	while (!sol.empty()) {
		std::cout << ' ' << sol.top();
		sol.pop();
	}
	std::cout << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}