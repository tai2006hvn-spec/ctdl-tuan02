#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <chrono>

using namespace std;

long long cach1(const vector<long long>& a) {
    int n = a.size();
    long long max_sum = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long long sum = 0;
            for (int k = i; k <= j; k++) sum += a[k];
            max_sum = max(max_sum, sum);
        }
    }
    return max_sum;
}

long long cach2(const vector<long long>& a) {
    int n = a.size();
    long long max_sum = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            max_sum = max(max_sum, sum);
        }
    }
    return max_sum;
}

long long kadane(const vector<long long>& a) {
    long long max_sum = a[0];
    long long current_sum = a[0];
    for (size_t i = 1; i < a.size(); i++) {
        current_sum = max(a[i], current_sum + a[i]);
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    auto start = chrono::high_resolution_clock::now();
    long long r1 = cach1(a);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed1 = end - start;
    cout << "Cach 1 time: " << elapsed1.count() << "s (Ket qua: " << r1 << ")\n";

    start = chrono::high_resolution_clock::now();
    long long r2 = cach2(a);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed2 = end - start;
    cout << "Cach 2 time: " << elapsed2.count() << "s (Ket qua: " << r2 << ")\n";

    start = chrono::high_resolution_clock::now();
    long long r3 = kadane(a);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed3 = end - start;
    cout << "Cach 3 time: " << elapsed3.count() << "s (Ket qua: " << r3 << ")\n";

    return 0;
}