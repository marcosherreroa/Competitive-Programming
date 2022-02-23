//Marcos Herrero
#include <iostream>

void resuelveCaso() {
	int N;
	std::cin >> N;

	int sol = 0, num;
	for (int i = 0; i < N; ++i){
		std::cin >> num;
		if (num % 2 == 0)++sol;
	}

	std::cout << sol << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}