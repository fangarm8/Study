#include <fstream>
#include <set>

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    std::set<int> nums;
    while(!fin.eof()) {
        int tmp;
        fin >> tmp;
        nums.insert(tmp);
    }

    long long sum = 0;
    for (auto &item : nums) {
        sum+=item;
    }
    fout << sum;
}