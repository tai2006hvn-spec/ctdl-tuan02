#include <iostream>
#include <vector>

using namespace std;

bool tang_nghiem_ngat(const vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        if (a[i] >= a[i + 1]) return false;
    }
    return true;
}

bool khong_giam(const vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) return false;
    }
    return true;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "nghiem ngat: " << (tang_nghiem_ngat(a) ? "YES" : "NO") 
         << " - khong giam: " << (khong_giam(a) ? "YES" : "NO") << endl;
    return 0;
}