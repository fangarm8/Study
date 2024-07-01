#pragma once
#include <QVector>
#include "carbase.h"

#include <QStandardItemModel>
#include <QStandardItem>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

struct distance {
    QString model;
    uint date;
    uint mileage;
    distance();
    distance(const QString& model_, const QString& date_, const QString& mileage_) {
        this->model = model_;
        this->date = date_.toUInt();
        this->mileage = mileage_.toUInt();
    }
    distance(const QString& model_, const uint& date_, const uint& mileage_);
    distance(QJsonObject obj);
    QJsonObject toJsonObj();
};

class Cars1 : public CarBase, public QAbstractListModel {
private:
    QList<distance>* cars;
public:
    Cars1(QObject* parent = nullptr);
    Cars1(const Cars1& cpy);
    Cars1(QJsonObject obj);

    QJsonObject toJsonObj() const;

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    void populate(QList<distance> *newValues);

    void append(distance value);
    void update(int idx, distance value);
    void deleteRow(int idx);
    void insertAt(int idx, distance value);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;


    bool load(const QString& fileName);
    bool save(const QString& fileName);

    void SortUp();
    QList<int> SearchCar(QString& ob_model);
};
