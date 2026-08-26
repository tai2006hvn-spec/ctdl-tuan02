#include <iostream>
#include <climits>

using namespace std;

void print_int128(__int128_t x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    string s = "";
    while (x > 0) {
        s += (char)('0' + (x % 10));
        x /= 10;
    }
    for (int i = (int)s.length() - 1; i >= 0; i--) {
        cout << s[i];
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    long long LLONG_MAX_VAL = 9223372036854775807LL;
    
    // Kiểm tra tràn số cho long long
    __int128_t exact = 1;
    bool overflow = false;
    for (int i = 1; i <= n; i++) {
        exact *= i;
        if (i > 20 || exact > (__int128_t)LLONG_MAX_VAL) {
            overflow = true;
        }
    }

    if (!overflow) {
        cout << (long long)exact << endl;
    } else {
        cout << "TRAN SO (" << n << "! = ";
        print_int128(exact);
        cout << " > " << LLONG_MAX_VAL << ")" << endl;
    }
    
    return 0;
}