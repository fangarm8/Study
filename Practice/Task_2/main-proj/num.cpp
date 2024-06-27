#include "num.h"
#include <QVector>
#include <math.h>
using namespace std;

num::num() {}

bool num::IsPrime(uint a) {
    for (uint i = 1; i < a; i++) {
        if (i*i > a)
            return true;
        else {
            if(a % i == 0)
                return false;
        }
    }
    return true;
}

QVector<uint> num::PrimaryMultiple(uint a) {
    QVector<uint> ans;
    if (!this->IsPrime(a)) {
        uint primary = 2;
        while (a > 1) {
            while (a % primary == 0) {
                ans.push_back(primary);
                a /= primary;
            }
            primary++;
        }
        return ans;
    } else {
        return ans;
    }
}

double num::sin(double x, double eps) {
    double x_abs = abs(x);
    while(x_abs >= 2 * M_PI) {
        x_abs = x_abs - 2 * M_PI;
    }
    if(x < 0)
        x = -x_abs;
    else
        x = x_abs;
    double a_0{x}, a_n, sum{x}, n = 0;
    a_n = a_0;
    while(abs(a_n) > eps) {
        double k = (-1 * x*x) / ((2 * n + 2) * (2 * n + 3));
        a_n = a_n * k;
        sum += a_n;
        n++;
    }
    return sum;
}

QVector<double> num::SqEq(double ax, double bx, double cx) {
    QVector<double> ans;
    if (ax == 0) {
        double x1 = (0 - cx) / bx;
        ans.push_back(x1);
        return ans;
    }
    else {
        double D = bx*bx - 4 * ax * cx, x1, x2;
        if (D < 0) {
            throw QString{"No real roots!"};
        }
        if (D == 0) {
            x1 = (-bx) / (2 * ax);
            ans.push_back(x1);
        }
        else {
            x1 = (-bx + sqrt(D)) / (2 * ax);
            x2 = (-bx - sqrt(D)) / (2 * ax);
            ans.push_back(x1);
            ans.push_back(x2);
        }
        return ans;
    }
}

