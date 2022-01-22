//Marcos Herrero

#include <iostream>
#include <vector>

/*
P:={N>0 && for all i,j:0<= i < j <= N-1: v[i] < v[j]}
	fun mayorNumero(v[0,...,N-1] de ent, ent A) dev r: ent
Q:={ r = max i,j: (0 <= i <= j <= N-1 && v[j]-v[i] <= A -1) : j-i+1}


I:= 0<=n<= N && r= max i,j: ( 0 <= i <= j <= n-1 && v[j]-v[i] <= A-1): j-i+1 && s= max i: 0<= i <= n-1 && v[n-1]-v[i] <= A-1):n-i && ini= m && 0<=ini<= fin <= n && r= fin-ini+1 && 0<=c<=n &&  s= n-c

R= 0<=n+1<= N && r= max i,j: ( 0 <= i <= j <= n && v[j]-v[i] <= A-1): j-i+1 && s= max i: 0<= i <= n && v[n]-v[i] <= A-1):n-i

I:= 0<= n <= N &&  r = max i,j: (0 <= i <= j <= n-1 && v[j]-v[i] <= A -1) : j-i
B:= n < N
C= N-n
R:= 0<= n+1 <= N &&  r = max i,j: (0 <= i <= j <= n && v[j]-v[i] <= A -1) : j-i

{r = max i,j: (0 <= i <= j <= n-1 && v[j]-v[i] <= A -1) : j-i}
if( max i: (0<= i <= n && v[n] -v[i] < = A-1): n-i > r) r =
{
*/

int mayorNumero(std::vector<int> & v, int N, int A) {
	int n, m, r, s, ini, fin, c;

	n = 1;
	r = 1;
	s = 1;
	ini = 0;
	fin = 0;
	c = 0;

	while (n < N) {
		if (v[n] - v[c] <= A - 1) ++s;
		else {
			while (v[n] - v[c] > A - 1) ++c;
			s= n - c + 1;
		}

		if (s > r) {
			r = s;
			fin = n;
			ini = c;
		}

		n = n + 1;
	}

	return r;
}

bool resuelveCaso() {
	int N, A;
	std::cin >> N >> A;

	if (N == 0 && A == 0) return false;

	std::vector<int> v(N);
	for (int i = 0; i < N; ++i) std::cin >> v[i];

	std::cout << mayorNumero(v, N, A)<<'\n';

	return true;
}

int main() {
	while (resuelveCaso());
}