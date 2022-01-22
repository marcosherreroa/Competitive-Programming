//Marcos Herrero
#include <iostream>
#include <algorithm>

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0)return false;

	if (N == 2) {
		long long int num1, num2;
		std::cin >> num1 >> num2;
		std::cout << num1 * num2 << '\n';
	}

	else {
		long long int max1pos = 0, max2pos = 0, max1neg = 0, max2neg = 0;


		long long int num;
		for (int i = 0; i < N; ++i) {
			std::cin >> num;
			if (num > 0) {
				if (num > max1pos) {
					max2pos = max1pos;
					max1pos = num;
				}
				else if (num > max2pos) max2pos = num;
			}
			else {
				if (num < max1neg) {
					max2neg = max1neg;
					max1neg = num;
				}

				else if (num < max2neg) max2neg = num;
			}
		}

		std::cout << std::max(max1pos*max2pos, max1neg*max2neg) << '\n';
	}

	return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	while (resuelveCaso());
}