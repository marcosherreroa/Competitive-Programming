//Marcos Herrero
#include <iostream>
#include <queue>

bool resuelveCaso() {
	int N, A, B;
	std::cin >> N >> A >> B;
	if (!std::cin)return false;

	std::priority_queue<int> pilasA, pilasB; int pila;
	for (int i = 0; i < A; ++i) {
		std::cin >> pila;
		pilasA.push(pila);
	}
	
	for (int i = 0; i < B; ++i) {
		std::cin >> pila;
		pilasB.push(pila);
	}

	std::vector<int> sol; int horas;
	std::queue<int> sobrasA, sobrasB;
	while (!pilasA.empty() && !pilasB.empty()) {
		horas = 0;
		for (int i = 0; !pilasA.empty() && !pilasB.empty() && i < N; ++i) {
			if (pilasA.top() < pilasB.top()) {
				horas += pilasA.top();
				sobrasB.push(pilasB.top() - pilasA.top());
			}
			else if (pilasB.top() < pilasA.top()) {
				horas += pilasB.top();
				sobrasA.push(pilasA.top() - pilasB.top());
			}
			else horas += pilasA.top();

			pilasA.pop();
			pilasB.pop();
		}

		sol.push_back(horas);
		while (!sobrasA.empty()) {
			pilasA.push(sobrasA.front());
			sobrasA.pop();
		}

		while (!sobrasB.empty()) {
			pilasB.push(sobrasB.front());
			sobrasB.pop();
		}
	}

	std::cout << sol[0];
	for (int i = 1; i < sol.size(); ++i) std::cout << ' ' <<sol[i];
	std::cout << '\n';

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}