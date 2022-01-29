//Marcos Herrero
#include <iostream>

void resuelveCaso() {
	int N;
	std::cin >> N;

	std::cout << N / 3 << '\n';
}

int main(){
	std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}