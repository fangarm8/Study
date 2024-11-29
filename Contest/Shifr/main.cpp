#include <iostream>
#include <cstring>
using namespace std;
const char alph[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char hex_nums[] = "0123456789ABCDEF";
int main() {
    int N;
    cin >> N;
    char ** input = new char * [N];
    for (int i = 0; i < N; i++) {
        input[i] = new char[59];
        scanf("%s", input[i]);
    }
    for (int i = 0; i < N; i++) {
        char uniqASCII[256], ans[10];
        int uniqsym(0), sumDate(0), firstletter;
        int date[3];
        memset(uniqASCII, 0, 256);
        memset(date, 0, 3);
        for(int j = 0; j < 10; j++) {
            ans[j] = '0';
        }
        char *pch = strtok(input[i], ",");
        for (int j = 0; j < 3; j++) {
            for(int k = 0; k < strlen(pch); k++) {
                ++uniqASCII[(unsigned char)pch[k]];
            }
            pch = strtok(NULL, ",");
        }
        for (int j = 0; j < 3; j++) {
            date[j] = (short) strtol(pch, NULL, 10);
            pch = strtok(NULL, ",");
        }
        for (int j = 0; j < 256; j++) {
            if (uniqASCII[j])
                uniqsym++;
        }
        for (int j = 0; j < 2; j++) {
            while (date[j] > 0) {
                sumDate += date[j]%10;
                date[j] /= 10;
            }
        }
        firstletter = strchr(alph, toupper(input[i][0])) - alph + 1;
        int result = uniqsym + sumDate*64 + firstletter*256;
        
        int j = 0;
        while (result > 0) {
            ans[9-j] = hex_nums[result%16];
            result /= 16;
            j++;
        } 

        for (int k = 7; k < 10; k++) {
            cout << ans[k];
        }
        cout << " ";
    } 
}