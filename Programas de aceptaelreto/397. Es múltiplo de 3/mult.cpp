//Marcos Herrero
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

void resuelveCaso() {
	unsigned int N;
	scanf("%u", &N);
	if ((N+2) % 3 == 0)printf("NO\n");
	else printf("SI\n");
}

int main() {
	unsigned int n;
	scanf("%u",&n);
	for (int i = 0; i < n; ++i) resuelveCaso();
}