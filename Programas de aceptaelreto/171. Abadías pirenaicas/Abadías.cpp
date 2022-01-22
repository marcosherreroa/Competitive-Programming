//Marcos Herrero

#include <iostream>
#include <vector>

/*
P:={N>0}
  fun nabadias(v[0,...,N-1] de ent) dev a: ent
Q:={a = 1 + (# i: 0<= i <= N-2: v[i] > (max j: i+1 <= j <= N-1: v[j])}

I:= 0 <= n && maxr= max j: n+1 <= j <= N-1: v[j] && a= 1+ (#i: n <= i <= N-2: v[i] > (max j: i+1 <= j <= N-1: v[j]))
B:= n > 0;
C= n
R:= I:= 0 <= n-1 <= N-2 && maxr= max j: n <= j <= N-1: v[j] && a= 1+ (#i: n-1 <= i <= N-2: v[i] > (max j: i+1 <= j <= N-1: v[j]))


*/

int nabadias(std::vector<int> & v, int N) {
	int n, maxr, a;

	if (N == 1) {
		n = 0;
		maxr = v[0];
		a = 1;
	}

	else {
		n = N - 2;
		maxr = v[N - 1];
		if (v[N - 2] > v[N - 1]) a = 2;
		else a = 1;
	}

	while (n > 0) {
		if (v[n] > maxr) maxr = v[n];
		if (v[n - 1] > maxr) ++a;

		n = n - 1;
	}

	return a;
}

bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (N == 0) return false;

	std::vector<int> v(N);
	for (int i = 0; i < N; ++i) std::cin >> v[i];

	std::cout << nabadias(v, N) << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
}