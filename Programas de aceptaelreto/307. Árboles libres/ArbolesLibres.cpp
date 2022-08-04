#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>

struct Node {
    int ind;
    int indParent;
};

bool resuelveCaso() {
    int V, A;
    std::cin >> V >> A;
    if (!std::cin) return false;

    std::vector<std::vector<int>> G(V);
    int u, v;
    for (int i = 0; i < A; ++i) {
        std::cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    bool freeTree = true;
    std::vector<bool> visited(V, false);
    std::stack<Node> st;

    visited[0] = true;
    st.push({0,-1});

    while (freeTree && !st.empty()) {
        Node u = st.top();
        st.pop();

        for (int indv : G[u.ind]) {
            if (indv != u.indParent) {
                if (visited[indv]) {
                    freeTree = false;
                    break;
                }

                else {
                    visited[indv] = true;
                    st.push({indv,u.ind});
                }
            }
        }
    }

    for (int i = 0; freeTree && i < V; ++i) {
        freeTree &= visited[i];
    }

    if (freeTree) std::cout << "SI\n";
    else std::cout << "NO\n";

    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    while (resuelveCaso());
}