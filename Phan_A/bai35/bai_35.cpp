#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool la_nguyen_to(long long x) {
    if (x < 2) return false;
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

pair<long long, long long> dem_va_tong_kiem_tra_tung_so(long long n) {
    long long dem = 0, tong = 0;
    for (long long i = 2; i <= n; i++) {
        if (la_nguyen_to(i)) {
            dem++;
            tong += i;
        }
    }
    return {dem, tong};
}

pair<long long, long long> sang_eratosthenes(long long n) {
    if (n < 2) return {0, 0};
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (long long p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (long long i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    long long dem = 0, tong = 0;
    for (long long i = 2; i <= n; i++) {
        if (is_prime[i]) {
            dem++;
            tong += i;
        }
    }
    return {dem, tong};
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    int mode = 2; 
    if (argc > 1) {
        mode = stoi(argv[1]);
    }
    if (cin >> n) {
        if (n <= 30) {
            for (long long i = 2; i <= n; i++) {
                if (la_nguyen_to(i)) cout << i << " ";
            }
            cout << "\n";
        } else {
            auto kq = (mode == 1) ? dem_va_tong_kiem_tra_tung_so(n) : sang_eratosthenes(n);
            cout << "so luong = " << kq.first;
            if (n >= 1000000) cout << ", tong = " << kq.second;
            cout << "\n";
        }
    }
    return 0;
}
