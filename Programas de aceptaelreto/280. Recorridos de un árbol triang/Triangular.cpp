//Marcos Herrero

#include <iostream>
#include <vector>

void prepost(std::vector<int> const & inorden, std::vector<int> & preorden, std::vector<int>  & postorden, int ini, int fin) {
	if (ini < fin) {
		int indraiz;
		if ((fin - ini) % 2 == 0) indraiz = (ini + fin) / 2;
		else indraiz = (ini + fin - 1) / 2;

		preorden.push_back(inorden[indraiz]);
		prepost(inorden, preorden, postorden, ini, indraiz);
		prepost(inorden,preorden, postorden,  indraiz + 1, fin);
		postorden.push_back(inorden[indraiz]);
	}
}

bool resuelveCaso() {
	int aux;
	std::cin >> aux;
	if (aux == -1)return false;

	std::vector<int> inorden;
	while (aux != -1) {
		inorden.push_back(aux);
		std::cin >> aux;
	}

	std::vector<int> pre, post;
	prepost(inorden, pre, post, 0, inorden.size());

	std::cout << pre[0];
	for (int i = 1; i < pre.size(); ++i)std::cout << ' ' << pre[i];
	std::cout << '\n';

	std::cout << post[0];
	for (int i = 1; i < post.size(); ++i)std::cout << ' ' << post[i];
	std::cout << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}