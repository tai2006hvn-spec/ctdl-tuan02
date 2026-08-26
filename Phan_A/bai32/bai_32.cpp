#include <iostream>

using namespace std;

// Hàm kiểm tra chính phương
bool la_chinh_phuong(long long n) {
    if (n < 0) return false;
    long long l = 0, r = n;
    while (l <= r) {
        long long mid = l + (r - l) / 2;
        long long bp = mid * mid;
        if (bp == n) return true;
        else if (bp < n) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}

int main() {
    long long n;
    if (cin >> n) {
        if (la_chinh_phuong(n)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}