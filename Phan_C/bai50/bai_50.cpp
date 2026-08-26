#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <iomanip>
#include <limits>

using namespace std;

vector<vector<double>> generate_data(int n, int d, unsigned int seed) {
    mt19937 rng(seed);
    uniform_real_distribution<double> dist(0.0, 1.0);
    vector<vector<double>> data(n, vector<double>(d));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            data[i][j] = dist(rng);
        }
    }
    return data;
}

int classify(const vector<double>& query, const vector<vector<double>>& train, int d) {
    double min_dist = numeric_limits<double>::infinity();
    int best_idx = -1;
    for (int i = 0; i < (int)train.size(); ++i) {
        double dist = 0.0;
        for (int j = 0; j < d; ++j) {
            double diff = query[j] - train[i][j];
            dist += diff * diff;
        }
        if (dist < min_dist) {
            min_dist = dist;
            best_idx = i;
        }
    }
    return best_idx;
}

int main() {
    int d = 20;
    int q = 1000;
    vector<int> n_sizes = {1000, 10000, 100000};
    vector<double> times;

    auto queries = generate_data(q, d, 12345);

    volatile int dummy_sink = 0;
    for (int n : n_sizes) {
        auto train = generate_data(n, d, 54321);

        auto start = chrono::high_resolution_clock::now();
        for (const auto& query : queries) {
            dummy_sink += classify(query, train, d);
        }
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> elapsed = end - start;
        times.push_back(elapsed.count());
    }

    double ratio1 = times[1] / times[0];
    double ratio2 = times[2] / times[1];

    cout << fixed << setprecision(2);
    cout << "T(10k)/T(1k) = " << ratio1 << " ; T(100k)/T(10k) = " << ratio2 << "\n";
    cout << setprecision(4);
    cout << "n=10^3: " << times[0] << "s | n=10^4: " << times[1] << "s | n=10^5: " << times[2] << "s\n";

    return 0;
}