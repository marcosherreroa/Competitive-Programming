//Marcos Herrero
#include <iostream>
#include <vector>

int minas(std::vector<std::vector<char>> const & tab, int m, int n) {
	int sol = 0, count;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (tab[i][j] == '-') {
				count = 0;
				if (0 <= i - 1 && i - 1 < m && 0 <= j && j < n && tab[i - 1][j] == '*')++count;
				if (0 <= i - 1 && i - 1 < m && 0 <= j + 1 && j + 1 < n && tab[i - 1][j + 1] == '*')++count;
				if (0 <= i && i < m && 0 <= j + 1 && j + 1 < n && tab[i][j + 1] == '*')++count;
				if (0 <= i + 1 && i + 1 < m && 0 <= j + 1 && j + 1 < n && tab[i + 1][j + 1] == '*')++count;
				if (0 <= i + 1 && i + 1 < m && 0 <= j && j < n && tab[i + 1][j] == '*')++count;
				if (0 <= i + 1 && i + 1 < m && 0 <= j - 1 && j - 1 < n && tab[i + 1][j - 1] == '*')++count;
				if (0 <= i && i < m && 0 <= j - 1 && j - 1 < n && tab[i][j - 1] == '*')++count;
				if (0 <= i - 1 && i - 1 < m && 0 <= j - 1 && j - 1 < n && tab[i - 1][j - 1] == '*')++count;

				if (count >= 6) ++sol;
			}
		}
	}

	return sol;
}

bool resuelveCaso() {
	int m, n;
	std::cin >> n >> m;
	if (m == 0 || n == 0) return false;
	std::vector<std::vector<char>> tab(m, std::vector<char>(n));

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cin >> tab[i][j];
		}
	}
	std::cout << minas(tab,m ,n)<<'\n';

	return true;
}

int main() {
	while (resuelveCaso());
}