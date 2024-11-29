#include <iostream>

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

unsigned long long C(int n, int k) {
    unsigned long long * B[n+1];
    for(int i = 0 ; i <= n; i++) {
       B[i] = new unsigned long long[i+1]; 
       B[i][0]=1;
       B[i][i]=1;
       for(int j = 1; j < i; j++) {
           B[i][j] = (B[i-1][j-1] + B[i-1][j]) % (step(10, 9) + 7);
       }
    }
    return B[n][k];
}

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    cout << C(N, K) << "\n";
}