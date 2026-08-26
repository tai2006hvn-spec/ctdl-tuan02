#include <iostream>

using namespace std;

long long luy_thua_mod(long long a, long long b, long long m) {
    if (m == 1) return 0;
    long long r = 1 % m;
    a %= m;
    while (b > 0) {
        if (b % 2 == 1) {
            r = (__int128)r * a % m;
        }
        a = (__int128)a * a % m;
        b /= 2;
    }
    return r;
}

int main() {
    long long a, b, m;
    if (cin >> a >> b >> m) {
        long long actual = luy_thua_mod(a, b, m);
        cout << "Ket qua: " << actual << "\n";
    }
    return 0;
}