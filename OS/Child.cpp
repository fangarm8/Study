#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    // Получаем массив данных из командной строки
    if (argc < 2) {
        cout << "No array passed" << endl;
        return 1;
    }

    int size = atoi(argv[1]);  // Первый аргумент — размер массива
    vector<int8_t> array;

    for (int i = 2; i < argc; i++) {
        array.push_back(atoi(argv[i]));
    }

    // Выводим отрицательные элементы, заканчивающиеся на 0
    cout << "Negative elements ending with 0:" << endl;
    for (int8_t elem : array) {
        if (elem < 0 && (elem % 10 == 0)) {
            cout << (int)elem << " ";
        }
    }
    cout << endl;
    return 0;
}
