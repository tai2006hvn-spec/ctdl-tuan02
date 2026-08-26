#include <iostream>
#include <vector>
#include <climits>

using namespace std;

long long dem_de_quy = 0;

long long fib_de_quy(int n) {
    dem_de_quy++;
    if (n <= 2) return 1;
    return fib_de_quy(n - 1) + fib_de_quy(n - 2);
}

long long fib_ghi_nho_helper(int n, vector<long long>& memo) {
    if (n <= 2) return 1;
    if (memo[n] != -1) return memo[n];
    memo[n] = fib_ghi_nho_helper(n - 1, memo) + fib_ghi_nho_helper(n - 2, memo);
    return memo[n];
}

long long fib_ghi_nho(int n) {
    vector<long long> memo(n + 1, -1);
    return fib_ghi_nho_helper(n, memo);
}

long long fib_lap(int n, bool& overflow) {
    overflow = false;
    if (n <= 2) return 1;
    long long a = 1, b = 1, c = 1;
    for (int i = 3; i <= n; i++) {
        if (b > LLONG_MAX - a) {
            overflow = true;
            return -1;
        }
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    if (n >= 93) {
        cout << "tran long long -- phai phat hien va bao\n";
        return 0;
    }

    bool overflow = false;
    long long f_val = fib_lap(n, overflow);

    if (overflow) {
        cout << "tran long long -- phai phat hien va bao\n";
    } else {
        if (n <= 30) {
            dem_de_quy = 0;
            fib_de_quy(n);
            cout << "F = " << f_val << ", so loi goi = " << dem_de_quy << endl;
        } else {
            cout << "F = " << f_val << ", so loi goi = " << (2 * f_val - 1) << endl;
        }
    }
    return 0;
}