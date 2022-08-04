#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void resuelveCaso() {
    int a,b;
    std::cin >> a >> b;

    if (b == 0) std::cout << "DIV0\n";
    else {
        int c = a / b, r = a % b;
        while (r < 0) {
            r += std::abs(b);
            c -= std::abs(b) / b;
        }

        std::cout << c << ' ' << r << '\n';
    }
}

int main() {
    //std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) resuelveCaso();
}