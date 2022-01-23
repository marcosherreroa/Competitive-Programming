//Marcos Herrero
#include <iostream>
#include <vector>

/*

ways[i] = ways to climb i steps
0<= i <= n

ways[0] = 1
ways[1] = 1

ways[i] = sum : k in steps && k <= i: ways(i-k)


*/


bool resuelveCaso() {
	int n;
	std::cin >> n;

	if (n == 0)return false;

	int k;
	std::cin >> k;

	std::vector<int> steps(k);
	for (int i = 0; i < k; ++i) {
		std::cin >> steps[i];
	}

	std::vector<long long int> ways(n + 1, 1);

	for (int i = 2; i <= n; ++i) {
		ways[i] = 0;

		for (int k : steps) {
			if (k <= i)ways[i] = (ways[i] + ways[i - k] )% 1000000007;
		}
	}

	std::cout << ways[n]<<'\n';


	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}