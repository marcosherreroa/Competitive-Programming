//Marcos Herrero

#include <iostream>
#include <vector>

/*
P:={1<=N<=200000 && p>=1} 
    fun minNiños(v[0,...,N-1] de ent) dev p: ent
Q:={1 <= p <= N && (for all j: p<= j <= N-1 :max i: 0 <= i <= p-1: v[i] < v[j]) && for all i: 1<= i <= N && 
    (for all k : i <= k <= N-1: max j: 0 <= j <= i-1: v[j] < v[k]): p <= i }

I:= 1<= n <= N && 1 <= p <= n && (for all j: p <= j <= n-1 : maxl < v[j]) && for all i: 1<= i <= n && 
    (for all k : i <= k <= n-1: max j: 0 <= j <= i-1: v[j] < v[k]): p <= i && maxl = max i: 0 <= i <= p-1: v[i]
	&& max = max i:0<=i<= n-1: v[i]
B:= n <  N-1
C:= N-n
R:= 1<= n+1 <= N && 1 <= p <= n+1 && (for all j: p <= j <= n : maxl < v[j]) && for all i: 1<= i <= n+1 && 
    (for all k : i <= k <= n: max j: 0 <= j <= i-1: v[j] < v[k]): p <= i && maxl = max i: 0 <= i <= p-1: v[i] && max= max i:0 <= i <= n: v[i]
	Si v[n] >= maxl , hacer p= n+1 y maxl= max

*/

int minChildren(std::vector<int> const & v, int N) {
	int n,m , p, maxl, max;

	n = 1;
	p = 1;
	maxl = v[0];
	max = v[0];

	while (n < N ) {
		if (v[n] > max) max = v[n];

		if (maxl >= v[n]) {
			p = n+1;
			maxl = max;
		}

		n = n + 1;
	}

	return p;
}

bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (N == 0)return false;

	std::vector<int> v(N);
	for (int i = 0; i < N; ++i) std::cin >> v[i];

	std::cout << minChildren(v,N)<<'\n';

	return true;
}

int main() {
	while (resuelveCaso());
}