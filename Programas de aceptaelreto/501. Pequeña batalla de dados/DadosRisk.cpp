//Marcos Herrero
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

bool resuelveCaso() {
	int td, ta, dd, da, no;
	std::cin >> td >> ta >> dd >> da >> no;
	if (!std::cin)return false;
	
	std::priority_queue<int, std::vector<int>> vd, va; int dado;
	for (int i = 0; i < no; ++i) {
		if (td < dd) dd = td;
		if (ta < da) da = ta;
		
		for (int j = 0; j < dd; ++j) {
			std::cin >> dado;
			vd.push(dado);
		}

		for (int j = 0; j < da; ++j) {
			std::cin >> dado;
			va.push(dado);
		}

		while (!vd.empty() && !va.empty()) {
			if (vd.top() < va.top()) --td;
			else --ta;

			vd.pop();
			va.pop();
		}

		while (!vd.empty())vd.pop();
		while (!va.empty())va.pop();
	}

	std::cout << td << ' ' << ta << '\n';
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
	return 0;
}