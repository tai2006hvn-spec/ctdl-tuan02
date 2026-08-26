#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct KetQua {
    long long tong;
    int dau, cuoi;
};

KetQua kadane_chi_so(const vector<int>& a) {
    int n = a.size();
    long long max_sum = a[0];
    long long current_sum = a[0];
    int best_start = 0, best_end = 0;
    int temp_start = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] > current_sum + a[i]) {
            current_sum = a[i];
            temp_start = i;
        } else {
            current_sum += a[i];
        }

        if (current_sum > max_sum) {
            max_sum = current_sum;
            best_start = temp_start;
            best_end = i;
        }
    }
    // Đề bài yêu cầu trả về đánh số từ 1
    return {max_sum, best_start + 1, best_end + 1};
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    KetQua kq = kadane_chi_so(a);
    cout << "tong " << kq.tong << ", doan [" << kq.dau << ".." << kq.cuoi << "]\n";
    return 0;
}