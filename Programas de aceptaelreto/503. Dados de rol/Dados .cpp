//Marcoa Herrero
#include <iostream>
#include <vector>

void resuelveCaso() {
	int d1, d2;
	std::cin >> d1 >> d2;

	std::vector<int> sumas(d1 + d2+1, 0);
	for (int i = 1; i <= d1; ++i) {
		for (int j = 1; j <= d2; ++j) {
			++sumas[i + j];
		}
	}

	int max = sumas[0];
	std::vector<int> index;
	for (int i = 0; i < d1 + d2+1; ++i) {
		if (sumas[i] > max) {
			max = sumas[i];
			index.clear();
			index.push_back(i);
		}
		else if (sumas[i] == max)index.push_back(i);
	}

	std::cout << index[0];
	for (int i = 1; i < index.size(); ++i)std::cout << ' '<<index[i];
	std::cout << '\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}