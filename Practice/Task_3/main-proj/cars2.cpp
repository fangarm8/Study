#include "cars2.h"

Cars2::Cars2() {
    cars.clear();
}

price& Cars2::operator[](uint i) {
    if (i >= 0 && i < cars.size())
        throw QString{"There isn't car with that number"};
    return this->cars[i];
}

void Cars2::SortUp() {
    std::sort(cars.begin(), cars.end(), [](price& left, price& right){return left.price < right.price;});
}

QVector<int> Cars2::SearchCar(QString& ob_model) {
    QVector<int> ans;
    for (qsizetype i = 0; i < cars.size(); i++) {
        if (cars[i].model == ob_model) {
            ans.push_back(i);
        }
    }
    if(ans.size() == 0) {
        throw QString{"There aren't cars such model"};
    }
    return ans;
}

void Cars2::AddEl(price& ob) {
    cars.push_back(ob);
}

