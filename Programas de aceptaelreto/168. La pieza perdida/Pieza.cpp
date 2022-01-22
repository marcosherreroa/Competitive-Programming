//Marcos Herrero

#include <iostream>
#include <vector>

/*
P:= {N > 1 && for all i: 0<= i <= N-2:(exists j: 1<= j <= N: v[i] = j)}
	fun piezaFalta(v[0,...,N-2] de ent) dev p: ent
Q:= {p = min i : 1<= i <= N: (for all j: 0<= j <= N-2: i !=v[j])}

I:= 0 <= n <= N-2 && for all i: 0<= i <= n: p != v[i]
B:= n < N-2
C= N-2-n
R:= 0<= n+1 <= N-2 && 0 <= p <= N-1  && 
     for all i: 0<= i <= n+1: w[i]= (p=v[i]) && for all i: 0<= i <= n+1: p != v[i]


(vector w[0,...,N-1] de bool)

I1:= 0 <= n <= N-2 && for all i: 0<= i <= N-1: (w[i]= (for all j: 0<= j <= n: v[j] != i+1)
B1: n < N-1
C1:= N-1-n
R1:= 0 <= n+1 <= N-2 && for all i: 0<= i <= N-1: (w[i]= (for all j: 0<= j <= n+1: v[j] != i+1)


I2:= 1 <= m <= N-1 && for all i: 0<= i <= N-1: w[i]= (for all j: 0<= j <= N-2: v[j]!= i+1) && 
(p = min{ min i : 1<= i <= m : w[i-1], m+1})
B2:= m < N-1
C2:= N-m
R2:= 1 <= m+1 <= N-1 && for all i: 0<= i <= N-1: w[i]= (for all j: 0<= j <= N-2: v[j] != i+1) && 
(p = min{ min i : 1<= i <= m+1 : w[i-1], m+2})
*/

int piezaFalta(std::vector<int> & v, int N) {
	int n,m, p;
	std::vector<int> w(N, true);

	n = 0;
	w[v[0]-1] = false;

	while (n < N - 1) {
		w[v[n]-1] = false;

		n = n + 1;
	}

	m = 1;
	if (w[0]) p = 1;
	else p = 2;

	while (m < N) {
		if (!w[p - 1]) p = m + 1;

		m = m + 1;
	}

	return p;
}


bool resuelveCaso(){
	int N;
	std::cin >> N;

	if ( N == 0) return false;

	std::vector<int> v(N - 1);
	for (int i = 0; i < N- 1; ++i) std::cin >> v[i];
    
	std::cout << piezaFalta(v, N)<< '\n';
	return true;
}


int main() {
	while (resuelveCaso());
	return 0;
}