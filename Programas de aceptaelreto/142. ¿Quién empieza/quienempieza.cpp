//Marcos Herrero

#include <iostream>
#include <queue>

bool resuelveCaso() {
	int N, s;
	std::cin >> N >> s;
	if (N == 0 && s == 0)return false;

	std::queue<int> alumnos;
	for (int i = 1; i <= N; ++i) alumnos.push(i);

	while (alumnos.size() > 1) {
		for (int i = 0; i < s; ++i) {
			alumnos.push(alumnos.front());
			alumnos.pop();
		}

		alumnos.pop();
	}

	std::cout << alumnos.front() << '\n';

	return true;
}


int main() {
	while (resuelveCaso());
}