#include <fstream>
// #include <iostream>
#include <set>
#include <vector>

int moscitos(short * array, int i, std::vector<short>& path) {
    if (i >= 3) {
        int m2 = moscitos(array, i-2, path);
        int m3 = moscitos(array, i-3, path);
        if (m2 > m3) {
            path.push_back(i-1);
            return m2 + array[i];
        }
        path.push_back(i-2);
        return m3 + array[i];
    } else if (i == 2) {
        path.push_back(1);
        return array[i] + array[0];
    } else if (i == 0){
        return array[i];       
    }
    return -1;
}

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    int s;
    fin >> s;
    // std::cin >> s;
    short * array = new short[s];
    for (int i = 0; i < s; i++)
        fin >> array[i];
        // std::cin >> array[i];
    array[1] = -1;
    std::vector<short> path;
    if (s > 2) {
        fout << moscitos(array, s-1, path) << "\n";
        // std::cout << moscitos(array, s-1, path) << "\n";
        int i = path.size() - 1;
        while (path[i] != 1) {
            i--;
        }
        int sum = 0;
        for (i; i < path.size(); i++) {
            fout << path[i] << " ";
            sum+=array[path[i]];
            // std::cout << path[i] << " ";  
        }
        fout << s << "\n";
        fout << sum + array[s-1];
        // std::cout << s;
    } else {
        fout << -1;
        // std::cout << -1;
    }
}