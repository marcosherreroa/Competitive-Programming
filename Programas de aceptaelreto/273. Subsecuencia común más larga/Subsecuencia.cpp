//Marcos Herrero

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int longComun(std::string const& s1, std::string const& s2, int i, int j, std::vector<std::vector<int>> & mat) {
    if (i == 0 || j == 0) {
        mat[i][j] = 0;
    }
    else if (s1[i-1] == s2[j-1]) {
        if (mat[i - 1][j - 1] == -1)mat[i - 1][j - 1] = longComun(s1, s2, i - 1, j - 1, mat);
        mat[i][j] = 1 + mat[i - 1][j - 1];
    }
    else {
        if (mat[i - 1][j] == -1)mat[i - 1][j] = longComun(s1, s2, i - 1, j, mat);
        if (mat[i][j - 1] == -1)mat[i][j - 1] = longComun(s1, s2, i, j - 1, mat);

        mat[i][j] = std::max(mat[i - 1][j], mat[i][j - 1]);
    }

    return mat[i][j];
}

bool resuelveCaso() {
    std::string s1, s2;

    std::cin >> s1 >> s2;
    if (!std::cin)return false;

    std::vector<std::vector<int>> mat(s1.size()+1, std::vector<int>(s2.size()+1, -1));
    std::cout << longComun(s1, s2, s1.size(), s2.size(), mat)<<'\n';

    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    while (resuelveCaso());
}