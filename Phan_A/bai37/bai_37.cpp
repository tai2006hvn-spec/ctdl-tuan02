#include <iostream>
#include <vector>

using namespace std;

void dem(const vector<int>& a, int &chan, int &le, int &am) {
    chan = 0;
    le = 0;
    am = 0;
    for (int x : a) {
        if (x % 2 != 0) {
            le++;
        } else {
            chan++;
        }
        if (x < 0) {
            am++;
        }
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int chan, le, am;
    dem(a, chan, le, am);
    cout << "chan " << chan << ", le " << le << ", am " << am << endl;
    return 0;
}