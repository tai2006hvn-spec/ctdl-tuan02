#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <functional>

using namespace std;

struct Mau {
    int id;
    vector<double> dac_trung;
    string nhan;
};

double kc_euclid(const vector<double>& u, const vector<double>& v) {
    double s = 0;
    for (size_t i = 0; i < u.size(); i++) {
        double diff = u[i] - v[i];
        s += diff * diff;
    }
    return sqrt(s);
}

double kc_manhattan(const vector<double>& u, const vector<double>& v) {
    double s = 0;
    for (size_t i = 0; i < u.size(); i++) {
        s += abs(u[i] - v[i]);
    }
    return s;
}

void chay_bo_mot_mau(const vector<Mau>& D, function<double(const vector<double>&, const vector<double>&)> kc, const string& ten_do_do) {
    int dung = 0;
    int tong = D.size();
    vector<int> danh_sach_sai;

    for (size_t i = 0; i < D.size(); i++) {
        double min_dist = 1e18;
        string best_label = "";
        for (size_t j = 0; j < D.size(); j++) {
            if (i == j) continue;
            double d = kc(D[i].dac_trung, D[j].dac_trung);
            if (d < min_dist) {
                min_dist = d;
                best_label = D[j].nhan;
            }
        }
        if (best_label == D[i].nhan) {
            dung++;
        } else {
            danh_sach_sai.push_back(D[i].id);
        }
    }
    double ti_le = (double)dung / tong * 100.0;
    cout << ten_do_do << ": " << dung << "/" << tong << " = " << fixed << setprecision(2) << ti_le << "%";
    if (!danh_sach_sai.empty()) {
        cout << " — sai mau: ";
        for (int id : danh_sach_sai) cout << id << " ";
    } else {
        cout << " — khong mau nao sai";
    }
    cout << "\n";
}

vector<Mau> doc_file(const string& filename) {
    ifstream fin(filename);
    vector<Mau> D;
    if (!fin.is_open()) return D;
    int n, d;
    if (!(fin >> n >> d)) return D;
    for (int i = 0; i < n; i++) {
        vector<double> x(d);
        for (int j = 0; j < d; j++) fin >> x[j];
        string label;
        fin >> label;
        D.push_back({i + 1, x, label});
    }
    fin.close();
    return D;
}

int main() {
    system("chcp 65001 > nul");
    
    vector<Mau> D30 = doc_file("hoa30.txt");
    if (!D30.empty()) {
        chay_bo_mot_mau(D30, kc_euclid, "Euclid");
        chay_bo_mot_mau(D30, kc_manhattan, "Manhattan");
    }

    // 3. Chạy trên hoa9.txt (Tập 9 mẫu Ví dụ 1.8)
    vector<Mau> D9 = doc_file("hoa9.txt");
    if (!D9.empty()) {
        chay_bo_mot_mau(D9, kc_euclid, "Tap 9 mau - Euclid");
        chay_bo_mot_mau(D9, kc_manhattan, "Tap 9 mau - Manhattan");
    }

    return 0;
}