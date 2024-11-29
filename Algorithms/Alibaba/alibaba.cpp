#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

double alibaba(const vector<vector<int>>& array, vector<vector<int>>& ans) {
    int n = ans.size();
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < n - j; ++i) {
            ans[i][i + j] = min(ans[i][i + j - 1] + array[i + j][0] - array[i + j - 1][0],
                                ans[i + j - 1][i] + array[i + j][0] - array[i][0]);

            if (ans[i][i + j] > array[i + j][1]) {
                ans[i][i + j] = 2147300000;
            }

            ans[i + j][i] = min(ans[i + j][i + 1] + array[i + 1][0] - array[i][0],
                                ans[i + 1][i + j] + array[i + j][0] - array[i][0]);

            if (ans[i + j][i] > array[i][1]) {
                ans[i + j][i] = 2147300000;
            }
        }
    }
    return min(ans[0][n - 1], ans[n - 1][0]);
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int n;
    input >> n;
    vector<vector<int>> money(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        input >> money[i][0] >> money[i][1];
    }

    vector<vector<int>> ans(n, vector<int>(n, 0));

    double total = alibaba(money, ans);
    if (total >= 2147300000) {
        output << "No solution";
    } else {
        output << total;
    }

    return 0;
}
