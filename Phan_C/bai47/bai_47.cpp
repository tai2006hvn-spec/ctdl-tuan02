#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

struct MauHoa {
    int id;
    vector<double> dac_trung;
    string nhan;
};

int main() {
    system("chcp 65001 > nul");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("hoa30.txt");
    if (!fin.is_open()) return 1;

    int n, d;
    if (!(fin >> n >> d)) return 1;

    vector<MauHoa> tap_huan_luyen;
    tap_huan_luyen.reserve(n);

    for (int i = 0; i < n; i++) {
        vector<double> x(d);
        for (int j = 0; j < d; j++) {
            fin >> x[j];
        }
        string label;
        fin >> label;
        tap_huan_luyen.push_back({i + 1, x, label});
    }
    fin.close();

    vector<double> q;
    double val;
    while (cin >> val) {
        q.push_back(val);
    }

    if (tap_huan_luyen.empty() || q.empty()) return 0;

    double min_dist_sq = -1.0;
    int best_index = -1;
    string best_label = "";

    for (const auto& mau : tap_huan_luyen) {
        double current_dist_sq = 0.0;
        size_t limit = min(q.size(), mau.dac_trung.size());
        for (size_t j = 0; j < limit; j++) {
            double diff = q[j] - mau.dac_trung[j];
            current_dist_sq += diff * diff;
        }

        if (min_dist_sq < 0 || current_dist_sq < min_dist_sq) {
            min_dist_sq = current_dist_sq;
            best_index = mau.id;
            best_label = mau.nhan;
        }
    }

    double final_dist = sqrt(min_dist_sq);

    cout << fixed << setprecision(4);
    cout << best_label << " — mẫu " << best_index << ", khoảng cách " << final_dist << "\n";

    return 0;
}