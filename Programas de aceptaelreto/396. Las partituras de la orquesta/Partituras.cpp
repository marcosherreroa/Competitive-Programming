//Marcos Herrero

#include <iostream>
#include <queue>
#include <cmath>

struct musicosPartituras {
	float musicos;
	float partituras;
};

bool operator<(musicosPartituras const & mp1, musicosPartituras const & mp2) {
	return mp1.partituras / mp1.musicos > mp2.partituras / mp2.musicos;
}

bool resuelveCaso() {
	int P, N;
	std::cin >> P >> N;
	if (!std::cin)return false;

	std::priority_queue<musicosPartituras> pq;
	float num;
	for (int i = 0; i < N; ++i) {
		std::cin >> num;
		pq.push({ num, 1.0 });
	}
	P -= N;

	while (P > 0) {
		musicosPartituras aux = pq.top();
		pq.pop();
		pq.push({ aux.musicos, aux.partituras + 1 });
		--P;
	}

	std::cout << ceil(pq.top().musicos/pq.top().partituras) << '\n';
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}