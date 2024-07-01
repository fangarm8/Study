#pragma once
#include <QVector>
#include <QAbstractTableModel>


class CarBase {
public:
    CarBase();

    virtual void SortUp() = 0;
    virtual QVector<int> SearchCar(QString& ob_model) = 0;
};
