#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <random>
#include <climits>
#include <cstdlib>

using namespace std;

long long thuat_toan_o_n2(const vector<int>& a) {
    int n = a.size();
    long long max_sum = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        long long current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += a[j];
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
    }
    return max_sum;
}

double do_thoi_gian(int n, int lap = 3) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(-50, 50);

    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = dis(gen);

    double min_time = 1e9;
    for (int l = 0; l < lap; l++) {
        auto t0 = chrono::steady_clock::now();
        volatile long long res = thuat_toan_o_n2(a);
        auto t1 = chrono::steady_clock::now();
        double giay = chrono::duration<double>(t1 - t0).count();
        if (giay < min_time) min_time = giay;
    }
    return min_time;
}

int main() {
    vector<int> moc_ns = {500, 1000, 2000, 4000};
    
    ofstream temp_file("temp_data.txt");
    
    cout << "Dang do thoi gian va xu ly du lieu...\n";
    for (int n : moc_ns) {
        double t = do_thoi_gian(n);
        temp_file << n << " " << t << "\n";
        cout << "Da do xong: n = " << n << " -> " << t << " giay\n";
    }
    temp_file.close();

    cout << "\nDang tao anh do thi...\n";
    
    string python_command = "python -c \""
        "import matplotlib.pyplot as plt; "
        "f = open('temp_data.txt', 'r'); "
        "x, y = [], []; "
        "[ (x.append(int(line.split()[0])), y.append(float(line.split()[1]))) for line in f ]; "
        "f.close(); "
        "plt.plot(x, y, marker='o', color='r', linestyle='-'); "
        "plt.title('Do thi chi phi thoi gian O(n^2)(C++)'); "
        "plt.xlabel('Kich thuoc dau vao (n)'); "
        "plt.ylabel('Thoi gian (giay)'); "
        "plt.grid(True); "
        "plt.savefig('do_thi_bai44.png'); "
        "\"";

    int ket_qua = system(python_command.c_str());
    
    remove("temp_data.txt");

    if (ket_qua == 0) {
        cout << "Hoan tat! Da tao thanh cong file anh: do_thi_bai44.png\n";
    } else {
        cerr << "Loi khi tao anh do thi! Hay dam bao may da cai dat thu vien matplotlib.\n";
    }

    return 0;
}