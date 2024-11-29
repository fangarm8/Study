#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    string s;
    in >> s;
    int n = s.size();
    if (n == 1) {
        out << 1 << "\n";
        out << s[0];
    } else {
        /*int** */vector<vector<int>> F(n);
        for(int j = 0; j < n; j++) {
            F[j] = vector<int>(j+1, 1);
            // for(int i = 0; i<=j; i++) {
            //     F[j][i] = 1;
            // }
        }
        for (int i = 0; i < n-1; i++) {
            if(s[i] == s[i+1])
                F[i+1][i] += 1; 
        }
        for (int j = 2; j < n-1; j++) {
            for (int i = 0; i < n - j; i++) {
                if (s[i] == s[i+j]) {
                    F[i+j][i] = F[i+j-1][i+1] + 2;
                } else {
                    F[i+j][i] = max(F[i+j][i+1], F[i+j-1][i]);
                }                
            }
        }
        F[n-1][0] = s[0]==s[n-1]? F[n-2][1] + 2 : max(F[n-1][1], F[n-2][0]);

        int i = 0;
        int j = n-1;
        string str_pal = "";
        while (i >= 0 and j >= i) {
            if(s[i]==s[j]) {
                str_pal = str_pal + s[i];
                i+=1;
                j-=1;
            } else {
                if (max(F[j][i+1], F[j-1][i]) == F[j-1][i])
                    j-=1;
                else
                    i+=1;
            }
        }
        if(F[n-1][0]%2==1)
            for (i = size(str_pal) - 2; i>=0; i--)
                str_pal = str_pal + str_pal[i];
        else
            for (i = size(str_pal) - 1; i>=0; i--)
                str_pal = str_pal + str_pal[i];

        out << F[n-1][0] << "\n";
        for (i = 0; i < size(str_pal); i++)
            out << str_pal[i];
    }

}