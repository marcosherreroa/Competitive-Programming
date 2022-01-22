//Marcos Herrero

#include <iostream>
#include <vector>

using tMatriz = std::vector<std::vector<int>>;

const std::vector<int> movsX = { -1, 0, 1, 0 };
const std::vector<int> movsY = { 0, 1, 0, -1 };

int dirToInt(char dir) {
	switch (dir) {
	case 'N': return 0;
	case 'E': return 1;
	case 'S': return 2;
	case 'W': return 3;
	}
}

void resuelveCaso() {
	int M, N, K;
	std::cin >> M >> N >> K;

	tMatriz pienso(M, std::vector<int>(N, 0));
	int x, y, pasos, dirnum; char dir;
	int nivel, pasosParaGirar, contTramos;
	for (int i = 0; i < K; ++i) {
		std::cin >> x >> y >> dir>>pasos;
		--x;
		--y;
		++pienso[x][y];
		dirnum = dirToInt(dir);
		nivel = 1;
		pasosParaGirar = 1;
		contTramos = 0;
		while (pasos > 0 && 0<= x && x< M && 0<= y && y< N) {
			x += movsX[dirnum];
			y += movsY[dirnum];
			--pasosParaGirar;
			if (pasosParaGirar == 0) {
				dirnum = (dirnum + 1) % 4;
				++contTramos;
				if (contTramos == 2) {
					++nivel;
					contTramos = 0;
				}
				pasosParaGirar = nivel;
			}
			--pasos;
			if(0 <= x && x < M && 0 <= y && y < N) ++pienso[x][y];
		}
	}

	for (int i = 0; i < M; ++i) {
		std::cout << pienso[i][0];
		for (int j = 1; j < N; ++j) {
			std::cout << ' '<<pienso[i][j];
		}
		std::cout << '\n';
	}

	std::cout << "---\n";
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}