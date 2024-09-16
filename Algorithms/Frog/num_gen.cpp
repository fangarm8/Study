#include <ctime>
#include <iostream>
#include <fstream>

int main() {
    srand(time(0));
    std::ofstream fout("input.txt");
    int size = rand() % 50 + 1;
    fout << size << "\n";
    for (int i = 0; i < size; i++) {
        fout << rand() % 100 + 1 << " ";
    }
}