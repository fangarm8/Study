#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long long Huffman(vector<long long>& huff1) {
    int n = huff1.size();
    int i(0), j(0), ans(0);
    vector<long long> huff2(n, 9223372036854775807);
    for (int k = 0; k < n - 2; k++) {
        long long m(0);
        if (huff1[i] <= huff2[j]) {
            m += huff1[i];
            i++;
        } else {
            m += huff2[j];
            j++;
        }
        if (huff1[i] <= huff2[j]) {
            m += huff1[i];
            i++;
        } else {
            m += huff2[j];
            j++;
        }
        huff2[k] = m;
        ans += m;
        
    }
    return ans;   
}

int main() {
    ifstream in("huffman.in");
    int n;
    in >> n;
    vector<long long> huff(n+1, 9223372036854775807);
    for (int i = 0; i < n; i++)
        in >> huff[i]; 
    long long ans = Huffman(huff);
    ofstream out("huffman.out");
    out << ans;
}