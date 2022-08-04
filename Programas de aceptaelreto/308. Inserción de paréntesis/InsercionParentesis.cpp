#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>

/*
posib(s) is true iff we can make the products in such order so that we obtain an a

posib("a") = true, posib("b") = false, posib("c") = false
posib(s) = OR : 0<= i <= s.size()-2: posib(s_i) , where s_i is the chain obtained when operating characters
i and i+1 in s  
*/

const std::unordered_map<std::string, std::string> op = {
    {"aa","b"},
    {"ab","b"},
    {"ac","a"},
    {"ba","c"},
    {"bb","b"},
    {"bc","a"},
    {"ca","a"},
    {"cb","c"},
    {"cc","c"}
};

bool posiblea(std::string s, std::unordered_map<std::string, bool> & posib) {
    if (posib.count(s)) return posib[s];

    bool found = false;

    for (int i = 0; !found && i < s.size() - 1; ++i) {
        found = posiblea(s.substr(0, i) + op.at(s.substr(i,2)) + s.substr(i + 2, -1), posib);
    }

    posib[s] = found;
    return found;
}

bool resuelveCaso() {
    std::string chain;
    std::cin >> chain;
    if (!std::cin) return false;

    std::unordered_map<std::string,bool> posib;
    posib["a"] = true;
    posib["b"] = false;
    posib["c"] = false;

    if (posiblea(chain,posib)) std::cout << "SI\n";
    else std::cout << "NO\n";

    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    while (resuelveCaso());
}