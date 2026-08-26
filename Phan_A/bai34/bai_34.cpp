#include <iostream>
#include <cmath>

using namespace std;

long long dao_nguoc(long long n) {
    long long sign = (n < 0) ? -1 : 1;
    long long temp = abs(n);
    long long rev = 0;
    while (temp > 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    return rev * sign;
}

int main() {
    long long n;
    if (cin >> n) {
        cout << dao_nguoc(n) << "\n";
    }
    return 0;
}