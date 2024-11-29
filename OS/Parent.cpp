#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
using namespace std;

int main() {
    // Ввод массива
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> array(size);
    cout << "Enter array elements: ";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    // Создаем командную строку
    wstring commandLine = L"ChildProcess.exe ";
    commandLine += to_wstring(size) + L" ";
    for (int elem : array) {
        commandLine += to_wstring(elem) + L" ";
    }

    // Преобразуем командную строку в wchar_t*
    wchar_t* cmdLine = new wchar_t[commandLine.length() + 1];
    wcscpy(cmdLine, commandLine.c_str());

    // Информация для процесса
    STARTUPINFOW si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Запуск дочернего процесса
    if (!CreateProcessW(NULL, cmdLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        cout << "Failed to create process." << endl;
        return 1;
    }

    // Устанавливаем заголовок окна
    SetConsoleTitle(L"Parent Process");

    // Ожидание завершения дочернего процесса
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Закрытие дескрипторов
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    
    delete[] cmdLine;
    return 0;
}
