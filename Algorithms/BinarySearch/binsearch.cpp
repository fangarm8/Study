#include <iostream>
#include <vector>
// #include <fstream>

int lowerbound(int L, int R, const std::vector<int>& Arr, int ser) {
    int i;
    while (L < R) {
        i = L + (R - L) / 2;
        if (Arr[i] >= ser)
            R = i;
        else if (Arr[i] < ser)
            L = i + 1;
    }
    return L;
}

int upperbound(int L, int R, const std::vector<int>& Arr, int ser) {
    int i;
    while (L < R) {
        i = L + (R - L) / 2;
        if (Arr[i] > ser) {
            R = i;
        } else {
            L = i + 1;
        }
    }
    return L;
}

using namespace std;

int main() {
    // ifstream cin("input.txt");
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    vector<int> req(k);
    for (int i = 0; i < k; i++)
        cin >> req[i];
    for (int i = 0; i < k; i++) {
        int lw = lowerbound(0, n, arr, req[i]);
        int up = upperbound(0, n, arr, req[i]);

        if (lw < n && arr[lw] == req[i]) {
            cout << 1 << " " << lw << " " << up << "\n";
        } else {
            cout << 0 << " " << lw << " " << up << "\n";
        }
    }
}