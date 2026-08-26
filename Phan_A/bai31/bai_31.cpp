#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    long long tong = 0;
    int nho_nhat = 0, lon_nhat = 0;
    
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        tong += x;
        if (i == 0) {
            nho_nhat = x;
            lon_nhat = x;
        } else {
            if (x < nho_nhat) nho_nhat = x;
            if (x > lon_nhat) lon_nhat = x;
        }
    }
    
    double trung_binh = static_cast<double>(tong) / n;
    cout << tong << " " << fixed << setprecision(4) << trung_binh << " " << nho_nhat << " " << lon_nhat << "\n";
    
    return 0;
}