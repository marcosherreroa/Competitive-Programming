#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

long long int reverseNum(long long int n) {
    int numDigs = 0;
    std::stack<int> st;
    while (n != 0) {
        ++numDigs;
        st.push(n % 10);
        n /= 10;
    }

    long long int sol = 0, pot = 1;
    while (!st.empty()) {
        sol += st.top() * pot;
        st.pop();
        pot *= 10;
    }

    return sol;
}

void resuelveCaso() {
    int n;
    std::cin >> n;

    long long int revNum = reverseNum(n);
    long long int num = n + revNum;
    revNum = reverseNum(num);
    long long int iters = 1;

    while (num != revNum && num < 1000000000) {
        num = num + revNum;
        revNum = reverseNum(num);
        ++iters;
    }

    if(num == revNum) std::cout << iters << ' ' << num <<'\n';
    else  std::cout << "Lychrel?"<<'\n';
}

int main() {
    //std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) resuelveCaso();
}