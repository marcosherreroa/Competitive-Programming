//Marcos Herrero
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

struct destValue {
	int dest;
	int value;

	bool operator<(destValue const & that)const {
		return  value > that.value;
	}
};


int minDistminCalles(std::vector <std::vector<destValue>> const & G, int orig, int dest) {
	std::vector<int> dist(G.size(), INT_MAX);
	std::vector<int> numCalles(G.size(), INT_MAX);

	std::queue<int> q;
	dist[orig] = 0;
	numCalles[orig] = 0;
	q.push(orig);

	while (!q.empty()) {

		int u = q.front();
		q.pop();

		if (u == dest) break;

		for (destValue dv : G[u]) {
			if (numCalles[u] + 1 < numCalles[dv.dest]) {

				numCalles[dv.dest] = numCalles[u] + 1;
				dist[dv.dest] = dist[u] + dv.value;
				q.push(dv.dest);
			}

			else if (numCalles[u] + 1 == numCalles[dv.dest] && dist[u] + dv.value < dist[dv.dest]) {
				dist[dv.dest] = dist[u] + dv.value;
				q.push(dv.dest);
			}
		}

	}

	return dist[dest];
}


int Dijkstra(std::vector<std::vector<destValue>> const & G, int orig, int dest) {
	std::vector<int> dist(G.size(), INT_MAX);

	std::priority_queue<destValue> pq;
	dist[orig] = 0;
	pq.push({ orig,dist[orig] });

	while (!pq.empty()) {
		int u = pq.top().dest;
		pq.pop();

		if (u == dest)break;

		for (destValue dv : G[u]) {
			if (dist[u] + dv.value < dist[dv.dest]) {
				dist[dv.dest] = dist[u] + dv.value;

	            pq.push({ dv.dest,dist[dv.dest] });
			}
		}
	}

	return dist[dest];
}

bool resuelveCaso() {
	int N, C;
	std::cin >> N >> C;
	if (!std::cin)return false;

	std::vector<std::vector<destValue>> G(N + 1);
	int a, b, l;
	for (int i = 0; i < C; ++i) {
		std::cin >> a >> b >> l;

		G[a].push_back({ b,l });
		G[b].push_back({ a,l });
	}

	int K;
	std::cin >> K;

	int orig, dest;
	for (int i = 0; i < K; ++i) {
		std::cin >> orig >> dest;

		int minDistCalles = minDistminCalles(G, orig, dest);

		if (minDistCalles == INT_MAX) std::cout << "SIN CAMINO\n";

		else {
			int minDist = Dijkstra(G, orig, dest);

			if (minDist == minDistCalles) {
				std::cout << minDist << ' ' << "SI\n";
			}

			else {
				std::cout << minDist << ' ' << "NO\n";
			}
		}

	}
	
	std::cout << "----\n";

	return true;
}

int main() {
	while (resuelveCaso());
}