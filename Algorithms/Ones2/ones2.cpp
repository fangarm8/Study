#include <iostream>
#include <vector>

unsigned long long step(int a, unsigned int b) {
    if (b == 0) 
        return 1;
    int c = 1;
    while (b != 0) {
        if (b % 2 == 1) {
            c = c * a;
            b--;
        }
        a = a * a;
        b = b / 2;
    }
    return c;
}

const long long mod = 1000000007;

unsigned long long C(int n, int k) {
    return 0;
}

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    if (K > N - K)
        cout << C(N, N - K) << "\n";
    else
        cout << C(N, K) << "\n";
}