//Marcos Herrero
#include <iostream>
#include <vector>
#include <queue>

bool resuelveCaso() {
	int P, C;

	std::cin >> P >> C;

	if (!std::cin)return false;

	std::vector<std::vector<int>> G(P+1);

	int u, v;
	for (int i = 0; i < C; ++i) {
		std::cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	std::vector<bool> visit(P + 1, false);
	std::queue<int> q;

	visit[1] = true;
	q.push(1);

	while (!q.empty()) {
		u = q.front();
		q.pop();

		for (int v : G[u]) {
			if (!visit[v]) {
				visit[v] = true;
				q.push(v);
			}
		}
	}

	bool connected = true;

	for (int i = 1; i <= P; ++i) {
		if (!visit[i]) {
			connected = false;
			break;
		}
	}

	if (connected)std::cout << "BICI\n";
	else std::cout << "A PIE\n";

	return true;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}