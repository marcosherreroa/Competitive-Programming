//Marcos Herrero
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

struct destValor {
	int dest;
	int valor;

	bool operator<(destValor const & that)const {
		return valor > that.valor;
	}
};

bool resuelveCaso() {
	int N, S, P, T;

	std::cin >> N >> S >> T >> P;
	if (!std::cin) return false;

	std::vector<std::vector<destValor>> G(N+1);

	int A, B, secs;
	for (int i = 0; i < P; ++i) {
		std::cin >> A >> B >> secs;
		G[B].push_back({ A,secs });
	}

	std::vector<int> dist(N+1,INT_MAX);
	std::priority_queue<destValor> pq;

	dist[S] = 0;
	pq.push({ S,0 });
	
	int u;
	while (!pq.empty()) {
		u = pq.top().dest;
		pq.pop();

		for (destValor a : G[u]) {
			if (dist[u] + a.valor < dist[a.dest]) {
				dist[a.dest] = dist[u] + a.valor;
				pq.push({ a.dest,dist[a.dest] });
			}
		}
	}

	int sol = 0;
	for (int i = 1; i <= N; ++i) {
		if (i != S && dist[i] <= T)++sol;
	}

	std::cout << sol << '\n';

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}