//Marcos Herrero
#include <iostream>
#include <vector>
#include <algorithm>

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (!std::cin)return false;

	std::vector<int> montones;
	int concha;
	for (int i = 0; i < N; ++i) {
		std::cin >> concha;
		
		auto it = std::upper_bound(montones.begin(), montones.end(), concha);
		if (it != montones.end()) *it = concha;
		else montones.push_back(concha);
	}

	std::cout << montones.size() << '\n';
	return true;
}

int main() {
	//std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}