#include "num.h"

num::num() {}

num::num(const unsigned int& ta, const unsigned int& tb) {
    a = ta;
    b = tb;
}

unsigned int num::NOD() {
    while (a != 0 && b != 0) {
        if(a>b) {
            a%=b;
        } else {
            b%=a;
        }
    }
    return a>b?a:b;
}
