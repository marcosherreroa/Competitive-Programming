//Marcos Herrero

#include <iostream>
#include <vector>

/*

minEsfuerzo [i,j] es el el minimo esfuerzo para cortar el tablon entre las marcas i y j
0 <= i <= j <= N+1

minEsfuerzo [i,i+1] = 0 para todo i

minEsfuerzo [i,j] = min: i+1 <= k <= j-1: 2*(marca[j]-marca[i]) + minEsfuerzo[i,k] + minEsfuerzo[k,j]

*/

bool resuelveCaso() {
	int L, N;
	std::cin >> L >> N;

	if (L == 0 && N == 0)return false;

	std::vector<int> marca(N+2);

	marca[0] = 0;
	for (int i = 1; i <= N; ++i) {
		std::cin >> marca[i];
	}
	marca[N + 1] = L;

	std::vector<std::vector<long long int>> minEsfuerzo(N + 2, std::vector<long long int>(N + 2, 0));

	long long int minValor, aux, esf, j;

	for (int d = 2; d < N + 2; ++d) {
		for (int i = 0; i <= N + 1-d; ++i) {
			j = d + i;
			esf = 2 * (marca[j] - marca[i]);

			minValor = minEsfuerzo[i + 1][j];

			for (int k = i + 2; k <= j - 1; ++k) {
				aux = minEsfuerzo[i][k] + minEsfuerzo[k][j];

				if (aux < minValor) minValor = aux;
			}

			minEsfuerzo[i][j] = esf + minValor;
		}
	}

	std::cout << minEsfuerzo[0][N + 1] << '\n';

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}