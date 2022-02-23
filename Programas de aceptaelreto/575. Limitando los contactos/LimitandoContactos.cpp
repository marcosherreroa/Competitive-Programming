//Marcos Herrero
#include <iostream>
#include <vector>
#include <queue>

bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (!std::cin)return false;

	std::vector<std::vector<int>> G(n+1);
	int num, nroads, dest;
	std::cin >> num;
	while (num != 0) {
		std::cin >> nroads;

		for (int i = 0; i < nroads; ++i) {
			std::cin >> dest;
			G[num].push_back(dest);
		}

		std::cin >> num;
	}

	std::vector<std::vector<bool>> connection(n + 1, std::vector<bool>(n + 1,false));
	for (int i = 1; i <= n; ++i) {
		std::queue<int> q;
		connection[i][i] = true;
		q.push(i);

		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int v : G[u]) {
				if (!connection[i][v]) {
					connection[i][v] = true;
					q.push(v);
				}
			}
		}
	}

	int max = 0, sum;
	for (int i = 1; i <= n; ++i) {
		sum = 0;

		for (int j = 1; j <= n; ++j) {
			if (connection[i][j] && connection[j][i])++sum;
		}

		if (sum > max) max = sum;
	}

	std::cout << max << '\n';

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}