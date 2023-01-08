#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

const std::vector<short> electsSub = { 2,6,10,14 };
const std::vector<char> charSub = { 's','p','d','f'};

std::string electConf(short z) {

    std::stringstream ss;
    bool complete = false;
    // d = i+j  determines diagonal
    for (int d = 0; !complete && d < 8; ++d) {
        int iMin = std::max(0, std::max(d - 3, (d + 1) / 2));
        int iMax = d / 2;
        for (int i = iMin; !complete &&  i <= d; ++i) {
            int j = d - i;

            if (z > electsSub[j]) {
                ss << i + 1 << charSub[j] << electsSub[j]<< ' ';
                z -= electsSub[j];
            }

            else {
                ss << i + 1 << charSub[j] << z;
                complete = true;
            }
        }
    }

    return ss.str();
}

bool resuelveCaso() {
    std::string name;
    short z;

    std::cin >> name;
    if (name == "Exit") return false;
    std::cin >> z;

    std::cout << electConf(z) << '\n';

    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    while (resuelveCaso());
}