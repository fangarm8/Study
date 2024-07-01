#pragma once
#include <QVector>
#include "carbase.h"

struct price {
    QString model;
    uint date;
    double price;
};

class Cars2 : public CarBase {
    QVector<price> cars;
public:
    Cars2();
    price& operator[](uint i);
    void SortUp();
    QVector<int> SearchCar(QString& ob_model);
    void AddEl(price& ob);
};
