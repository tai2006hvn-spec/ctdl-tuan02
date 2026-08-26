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

// Hàm khoảng cách Manhattan
double kc_manhattan(const vector<double>& u, const vector<double>& v) {
    double s = 0;
    for (size_t i = 0; i < u.size(); i++) {
        s += abs(u[i] - v[i]);
    }
    return s;
}

// Tìm láng giềng gần nhất cho mẫu mới q
void lang_gieng_gan_nhat(const vector<double>& q, const vector<Mau>& D, function<double(const vector<double>&, const vector<double>&)> ham_kc, const string& ten_do_do) {
    double min_dist = 1e18;
    int best_index = -1;
    string best_label = "";

    for (const auto& mau : D) {
        double d = ham_kc(q, mau.dac_trung);
        if (d < min_dist) {
            min_dist = d;
            best_index = mau.id;
            best_label = mau.nhan;
        }
    }
    cout << ten_do_do << ": " << best_label << " — mau " << best_index << ", khoang cach " << fixed << setprecision(4) << min_dist << "\n";
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
    cout << ten_do_do << " tong the: " << dung << "/" << tong << " = " << fixed << setprecision(2) << ti_le << "%";
    if (!danh_sach_sai.empty()) {
        cout << " — sai mau: ";
        for (int id : danh_sach_sai) cout << id << " ";
    } else {
        cout << " — khong mau nao sai";
    }
    cout << "\n";
}

void kiem_tra_mau_26(const vector<Mau>& D) {
    int target_id = 26;
    int idx_26 = -1;
    for(size_t i=0; i<D.size(); i++) {
        if(D[i].id == target_id) {
            idx_26 = i;
            break;
        }
    }
    if(idx_26 == -1) return;

    double min_dist = 1e18;
    int best_index = -1;
    string best_label = "";

    for (size_t j = 0; j < D.size(); j++) {
        if ((int)j == idx_26) continue;
        double d = kc_manhattan(D[idx_26].dac_trung, D[j].dac_trung);
        if (d < min_dist) {
            min_dist = d;
            best_index = D[j].id;
            best_label = D[j].nhan;
        }
    }
    cout << "Kiem tra mau 26 khi bi bo ra (Manhattan) -> Du doan: " << best_label << " (lang gieng mau " << best_index << ", khoang cach " << fixed << setprecision(1) << min_dist << ")\n";
}

int main() {
    system("chcp 65001 > nul");
    ifstream fin("hoa30.txt");
    if (!fin.is_open()) {
        cerr << "Khong the mo tep hoa30.txt!\n";
        return 1;
    }

    int n, d;
    if (!(fin >> n >> d)) return 1;

    vector<Mau> D;
    for (int i = 0; i < n; i++) {
        vector<double> x(d);
        for (int j = 0; j < d; j++) fin >> x[j];
        string label;
        fin >> label;
        D.push_back({i + 1, x, label});
    }
    fin.close();

    cout << "--- 1. Mau moi (6.5; 3.0; 5.5; 2.0) ---\n";
    vector<double> q = {6.5, 3.0, 5.5, 2.0};
    lang_gieng_gan_nhat(q, D, kc_euclid, "Euclid");
    lang_gieng_gan_nhat(q, D, kc_manhattan, "Manhattan");

    cout << "\n--- 2. Bo mot mau tren toan tap ---\n";
    chay_bo_mot_mau(D, kc_euclid, "Euclid");
    chay_bo_mot_mau(D, kc_manhattan, "Manhattan");

    cout << "\n--- 3. Truong hop mau 26 bi bo ra ---\n";
    kiem_tra_mau_26(D);

    return 0;
}