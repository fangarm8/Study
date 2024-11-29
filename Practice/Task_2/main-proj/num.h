#pragma once
#include <QVector>
typedef unsigned int uint;

class num
{
    bool IsPrime(uint a);
public:
    num();
    QVector<uint> PrimaryMultiple(uint a);
    QVector<double> SqEq(double a_x, double b_x, double c_x);
    double sin(double x, double eps);
};
