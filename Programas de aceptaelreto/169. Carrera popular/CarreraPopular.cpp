//Marcos Herrero
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <unordered_map>

void resuelveCaso() {
	
	std::unordered_map<std::string, int> sameSur;
	std::string surname, name;
	std::cin >> surname;


	while (surname != "====") {
		surname.pop_back();
		std::cin >> name;
		std::cin.ignore(1);

		for (int i = 0; i < surname.size(); ++i) surname[i] = tolower(surname[i]);
		//for (int i = 0; i < name.size(); ++i)name[i] = tolower(name[i]);

		++sameSur[surname];
		std::cin >> surname;
	}

	int contestants = 0, withBro = 0;
	for (auto p : sameSur) {
		contestants += p.second;
		if (p.second > 1) withBro += p.second;
	}

	std::cout << contestants << ' ' << withBro << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}