#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long tich_lon_nhat(const vector<long long>& a) {
    if (a.empty()) return 0;
    long long max_so_far = a[0];
    long long curr_max = a[0];
    long long curr_min = a[0];

    for (size_t i = 1; i < a.size(); i++) {
        if (a[i] < 0) {
            swap(curr_max, curr_min);
        }
        curr_max = max(a[i], curr_max * a[i]);
        curr_min = min(a[i], curr_min * a[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

long long tich_lon_nhat_n2(const vector<long long>& a) {
    int n = a.size();
    long long max_prod = a[0];
    for (int i = 0; i < n; i++) {
        long long p = 1;
        for (int j = i; j < n; j++) {
            p *= a[j];
            max_prod = max(max_prod, p);
        }
    }
    return max_prod;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << tich_lon_nhat(a) << endl;
    return 0;
}