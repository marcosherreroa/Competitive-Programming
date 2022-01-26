//Marcos Herrero
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

struct destValue {
	int dest;
	int value;

	bool operator<(destValue const & that)const {
		return value > that.value;
	}
};

void Dijskstra(std::vector<std::vector<destValue>> const & G, std::vector<int> & dist, int O) {
	std::priority_queue<destValue> pq;
	dist[O] = 0;
	pq.push({ O,0 });

	while (!pq.empty()) {
		int u = pq.top().dest;
		pq.pop();

		for (destValue dv : G[u]) {
			if (dist[u] + dv.value < dist[dv.dest]) {
				dist[dv.dest] = dist[u] + dv.value;

				pq.push({ dv.dest, dist[dv.dest] });
			}
		}
	}

}

bool resuelveCaso() {
	int N, C;

	std::cin >> N;

	if (!std::cin)return false;

	std::cin >> C;

	std::vector<std::vector<destValue>> Gdir(N+1);
	std::vector<std::vector<destValue>> Ginv(N+1);

	int orig, dest, esf;
	for (int i = 0; i < C; ++i) {
		std::cin >> orig >> dest >> esf;

		Gdir[orig].push_back({ dest,esf });
		Ginv[dest].push_back({ orig,esf });
	}

	int O, P;
	std::cin >> O >> P;

	std::vector<int> distGo(N + 1, INT_MAX);
	std::vector<int> distCome(N + 1, INT_MAX);

	Dijskstra(Gdir, distGo, O);
	Dijskstra(Ginv, distCome, O);

	long long int sol = 0;
	int u;
	bool impossible = false;

	for (int i = 0; i < P; ++i) {
		std::cin >> u;

		if (distGo[u] == INT_MAX || distCome[u] == INT_MAX) {
			impossible = true;
			
		} 

		sol += distGo[u];
		sol += distCome[u];
	}
	
	if (impossible)std::cout << "Imposible\n";
	else std::cout << sol << '\n';

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}