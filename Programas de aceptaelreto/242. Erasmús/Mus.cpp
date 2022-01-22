//Marcos Herrero

#include <iostream>
#include <vector>

/*
P:={N>0}
   fun nparejas(v[0,...,N-1] de ent) dev p: ent
Q:={ p = sum i : 0 <= i <= N-1 : v[i] *(sum j: i+1 <= j <= N-1: v[j])}


I:= 0<= n <= N-1 && s= (sum j: n+1 <= j <= N-1: v[j]) && p= (sum i : n+1 <= i <= N-1 : v[i] *(sum j: i+1 <= j <= N-1: v[j]))
B:= n >= 0
C:= n
R:= 0<= n-1 <= N-1 && s= sum j: n <= j <= N-1: v[j] && p= sum i : n <= i <= N-1 : v[i] *(sum j: i+1 <= j <= N-1: v[j])

*/

long long int nparejas(std::vector<int> & v, int N) {
	int n ;
	long long int s, p;

	n = N-1;
	s = 0;
	p = 0;

	while (n >= 0) {
		p += v[n] * s;
		s += v[n];

		n = n - 1;
	}

	return p;
}

bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (N == 0) return false;

	std::vector<int> v(N);
	for (int i = 0; i < N; ++i) std::cin >> v[i];

	std::cout << nparejas(v, N) << '\n';
	return true;
}

int main() {
	while(resuelveCaso());
}