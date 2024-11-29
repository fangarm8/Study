#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream in("bst.in");
    int n;
    in >> n;
    int root;
    in >> root;
    
    long long ** arr = new long long*[n+1];
    for (int i = 0; i < n + 1; i++)
        arr[i] = new long long[3];
    
    arr[1][0] = -2147483649;
    arr[1][1] = root;
    arr[1][2] = 2147483648;
    bool isbst = true;
    for (int i = 2; i < n + 1; i++) {
        int child, parent;
        char LorR;
        in >> child >> parent >> LorR;
        if (LorR == 'L') {
            if (arr[parent][0] > child || child >= arr[parent][1])
                isbst = false;
            arr[i][0] = arr[parent][0];
            arr[i][1] = child;
            arr[i][2] = arr[parent][1];
        } else {
            if (arr[parent][1] > child || child >= arr[parent][2])
                isbst = false;
            arr[i][0] = arr[parent][1];
            arr[i][1] = child;
            arr[i][2] = arr[parent][2];
        }
        if (isbst == false)
            break;
    }
    ofstream out("bst.out");
    if (isbst == false)
        out << "NO";
    else
        out << "YES";
}