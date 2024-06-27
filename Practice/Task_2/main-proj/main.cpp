#include "mainwindow.h"
#include <QApplication>
typedef unsigned int uint;

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}





/*bool IsPrimary(unsigned int N) {
    for (int i = 1; i < N; i++) {
        if (i*i > N)
            return true;
        else {
            int check = N % i;
            if(check == 0)
                return false;
        }
    }
}
void PrimaryMultiple(unsigned int N) {
    unsigned int primary = 2;
    while (N > 1) {
        while (N % primary == 0) {
            cout << " * " << primary;
            N /= primary;
        }
        primary++;
    }
}
unsigned int N;
    cin >> N;
    if (!IsPrimary(N)) {
        cout << N << " = 1";
        PrimaryMultiple(N);
    }
    else
        cout << N << " is primary number";
    return 0;
}*/
