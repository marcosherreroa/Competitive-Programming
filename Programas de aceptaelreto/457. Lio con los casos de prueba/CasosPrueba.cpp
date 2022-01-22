//Marcos Herrero

#include <iostream>
#include <vector>

int posible(int i, int N, std::vector<int> const & nums, std::vector<int> & posibles) {
	if (i + nums[i] >= N) return 1;
	else if (i + nums[i] + 1 == N)return 2;
	else {
		if (posibles[i + nums[i] + 1] == 0)posibles[i + nums[i] + 1] = posible(i + nums[i] + 1, N, nums, posibles); 
		return posibles[i + nums[i] + 1];
	}
}

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0)return false;

	std::vector<int> nums(N);
	for (int i = 0; i < N; ++i) std::cin >> nums[i];
	
	int ini = 1; bool encontrado = false;
	std::vector<int> posibles(N, 0);
	while (!encontrado && ini < N) {
		if (posible(ini, N, nums, posibles) == 2)encontrado = true;
		else ++ini;
	}

	std::cout << ini<<'\n';

	return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	while (resuelveCaso());
}