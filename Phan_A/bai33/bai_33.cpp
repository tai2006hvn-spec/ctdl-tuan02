#include <iostream>
#include <utility>

using namespace std;

pair<long long, long long> phan_tich(long long n) {
    long long so_chu_so = 0;
    long long tong_chu_so = 0;
    if (n == 0) return {1, 0};
    while (n > 0) {
        tong_chu_so += n % 10;
        so_chu_so++;
        n /= 10;
    }
    return {so_chu_so, tong_chu_so};
}

int main() {
    long long n;
    if (cin >> n) {
        auto kq = phan_tich(n);
        cout << kq.first << " " << kq.second << "\n";
    }
    return 0;
}