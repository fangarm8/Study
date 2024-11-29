#include <iostream>
#include <vector>

using namespace std;

bool IsPrimary(unsigned long long N) {
    for (int i = 2; i < N; i++) {
        if (i*i > N)
            return true;
        else if(N % i == 0) {
            return false;
        }            
    }
}

void vectorDividers(unsigned long long N, vector<unsigned long long>& dividers) {
    if (N == 1) {
        dividers.push_back(1);
        return;
    }
    unsigned long long divider = 1;
    while (N / divider != 1) {
        if (N % divider == 0)
            dividers.push_back(divider);
        divider++; 
    }
    dividers.push_back(N);
}

int main() {
    unsigned long long left, right;
    cin >> left >> right;
    unsigned long long ans = 0;
    for (int i = left; i <= right; i++) {
        vector<unsigned long long> idiv;
        vectorDividers(i, idiv);
        unsigned long long s = idiv.size();
        if (s > 2 && IsPrimary(s)) {
            ans++;
        }
    }
    cout << ans;
}