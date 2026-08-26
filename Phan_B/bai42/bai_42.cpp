#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <chrono>
#include <random>

using namespace std;

// 1. Cách ngây thơ: O(n * k)
pair<long long, int> cua_so_ngay_tho(const vector<long long>& a, int k) {
    int n = a.size();
    long long max_sum = LLONG_MIN;
    int best_idx = 1;
    for (int i = 0; i <= n - k; i++) {
        long long current_sum = 0;
        for (int j = i; j < i + k; j++) {
            current_sum += a[j];
        }
        if (current_sum > max_sum) {
            max_sum = current_sum;
            best_idx = i + 1;
        }
    }
    return {max_sum, best_idx};
}

// 2. Cửa sổ trượt: O(n)
pair<long long, int> cua_so_truot(const vector<long long>& a, int k) {
    int n = a.size();
    long long current_sum = 0;
    for (int i = 0; i < k; i++) {
        current_sum += a[i];
    }
    long long max_sum = current_sum;
    int best_idx = 1;

    for (int i = k; i < n; i++) {
        current_sum = current_sum + a[i] - a[i - k];
        if (current_sum > max_sum) {
            max_sum = current_sum;
            best_idx = i - k + 2;
        }
    }
    return {max_sum, best_idx};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (cin >> n >> k) {
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        if (n >= 100000) {
            cout << "--- BANG DO THOI GIAN VỚI n = " << n << ", k = " << k << " ---\n";
            
            auto start1 = chrono::high_resolution_clock::now();
            // Lưu ý: với n = 10^6, cách ngây thơ O(n*k) sẽ mất hơn 1 giây, ta chạy thật:
            auto kq1 = cua_so_ngay_tho(a, k);
            auto end1 = chrono::high_resolution_clock::now();
            chrono::duration<double> t1 = end1 - start1;

            auto start2 = chrono::high_resolution_clock::now();
            auto kq2 = cua_so_truot(a, k);
            auto end2 = chrono::high_resolution_clock::now();
            chrono::duration<double> t2 = end2 - start2;

            cout << "Cach ngay tho O(n*k): " << t1.count() << "s (Ket qua: " << kq1.first << ")\n";
            cout << "Cua so truot O(n)   : " << t2.count() << "s (Ket qua: " << kq2.first << ")\n";
            cout << "So lan nhanh hon    : ~" << (t1.count() / t2.count()) << " lan\n";
        } else {
            // Chế độ chạy cho Bảng 1 (Các test nhỏ bắt buộc)
            auto kq = cua_so_truot(a, k);
            cout << "tong " << kq.first << ", bat dau tai vi tri " << kq.second << "\n";
        }
    }
    return 0;
}