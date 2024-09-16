#include <iostream>
#include <vector>

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int s;
    std::cin >> s;
    int * array = new int[s];
    for (int i = 0; i < s; i++)
        std::cin >> array[i];
    array[1] = -1;
    std::vector<std::pair<int, int>> path(s);
    std::vector<int> places(1, s);
    
    path[0].first = array[0];
    path[2].first = path[0].first + array[2]; 

    if (s > 2) {
        for (int i = 3; i < s; i++) {
            if (path[i-2].first > path[i-3].first) {
                path[i].first = path[i-2].first + array[i];
                path[i].second = i-2;
            } else {
                path[i].first = path[i-3].first + array[i];
                path[i].second = i-3;
            }
        }
        std::cout << path[s-1].first << "\n";
        for (int i = s-1; i > 0; ) {
            places.push_back(path[i].second + 1);
            i = path[i].second;
        }
        for (size_t i = 0; i < places.size(); i++) {
            std::cout << places[places.size() - i - 1] << " ";
        }
    } else if (s == 1) {
        std::cout << array[0] << "\n" << 1;
    } else {
        std::cout << -1;
    }
}