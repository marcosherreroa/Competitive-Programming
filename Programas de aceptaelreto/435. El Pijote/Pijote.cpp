//Marcos Herrero
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

bool resuelveCaso() {
	std::string sec;
	std::cin >> sec;
	if (!std::cin)return false;

	std::vector<int> apar(10);
	for (int i = 0; i < sec.size(); ++i) {
		if (isdigit(sec[i]))++apar[sec[i] - '0'];
	}

	bool OK = true;
	for (int i = 1; OK && i < 10; ++i) {
		if (apar[i] != apar[0])OK = false;
	}

	if (OK)std::cout << "subnormal\n";
	else std::cout << "no subnormal\n";

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}