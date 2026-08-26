#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

struct Mau {
    vector<double> x;
    string y;
};

int main() {
    system("chcp 65001 > nul");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Mau> D = {
        {{1.4, 0.2}, "Setosa"},     
        {{1.4, 0.1}, "Setosa"},    
        {{1.3, 0.2}, "Setosa"},     
        {{4.7, 1.4}, "Versicolor"}, 
        {{4.5, 1.5}, "Versicolor"}, 
        {{4.9, 1.5}, "Versicolor"}, 
        {{5.9, 2.2}, "Virginica"},  
        {{6.9, 2.1}, "Virginica"},  
        {{5.8, 2.2}, "Virginica"}   
    };

    vector<double> q;
    double val;
    while (cin >> val) {
        q.push_back(val);
    }

    if (D.empty() || q.empty()) return 0;

    double min_dist_sq = 1e18;
    string best_label = "";
    int best_index = -1;

    for (size_t i = 0; i < D.size(); i++) {
        double s = 0;
        for (size_t j = 0; j < q.size(); j++) {
            double d = q[j] - D[i].x[j];
            s += d * d;
        }
        if (s < min_dist_sq) {
            min_dist_sq = s;
            best_label = D[i].y;
            best_index = (int)i + 1;
        }
    }

    double actual_dist = sqrt(min_dist_sq);

    if (actual_dist < 1e-9) {
        cout << best_label << " — trùng đúng mẫu " << best_index << ", khoảng cách 0\n";
    } else {
        cout << fixed;
        if (actual_dist < 1) {
            cout << setprecision(1);
        } else {
            cout << setprecision(4);
        }
        cout << best_label << " — láng giềng là mẫu " << best_index << ", khoảng cách " << actual_dist << "\n";
    }

    return 0;
}