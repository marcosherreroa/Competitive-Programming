#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <numeric>
#include <list>
#include <algorithm>

/*Dynamic programming approach (O(nk))

binomial(i,j) = i over j mod 1000000007

binomial(i,j) = 0 si j >  i
binomial(i,i) = 1
binomial(i,j) = binomial(i-1,j-1) + binomial(i-1,j) si 1 <= j < i

Saving space: the vector bin will be a row of the table

Loop approach: O(k)

binomial(n,k) = n*(n-1)*...*(n-k+1)/k! = (prod: 1<= i <= k: n+1-i)/k!

binomial(n,k) mod m = ((n*(n-1)*...*(n-k+1)) mod m * (k!)^(m-2) mod m) mod m

*/

struct bezCoefs {
    long long int x;
    long long int y;
};

//Returns the coefficients of Bezout identity. That is returns x,y such that ax+by=1
//Cost : O(log(min(a,b))
bezCoefs bezoutcoefs(long long int a, long long int b) {
    if (a < b) return bezoutcoefs(b, a);
    if (b == 1) return { 1,1 - a };

    bezCoefs aux = bezoutcoefs(b, a % b);
    return { aux.y, aux.x - a/b * aux.y };
}

//Returns the inverse of k in Zm
long long int inverseMod(long long int k, long long int m) {
    bezCoefs aux = bezoutcoefs(m, k);
    if (aux.y > 0) return aux.y;
    else return aux.y + m;
}


/*
The way to calculate the binomial coefficient fast enough is using the 
mutliplicative formula.
bin(n,k) = n*(n-1)*...*(n-k+1)/k!
However, as we are operating with modular arithmetic, the previous
formula requires to compute the inverse of k! in Z_m, where m is the prime
number with respect to we are taking modules.

*/
long long int binomial(int n, int k) {
    if (k < 0) return 0;

    long long int numerat = 1;
    for (int i = 1; i <= k; ++i) numerat = (numerat * (n + 1 - i)) % 1000000007;

    long long int kfact = 1;
    for (int i = 2; i <= k; ++i) kfact = (kfact * i) % 1000000007;

    return (numerat * inverseMod(kfact,1000000007)) % 1000000007;
}

bool resuelveCaso() {
    int n, k;
    std::cin >> n >> k;
    if (n == 0 && k == 0) return false;

    //They are asking for the binomial coefficient 
    std::cout << binomial(n,std::min(k,n-k)) << '\n';

    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    while (resuelveCaso());
}