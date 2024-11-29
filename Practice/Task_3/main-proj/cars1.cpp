#include "cars1.h"
#include <QModelIndex>
#include <QDebug>
#include <QPixmap>

distance::distance(const QString& model_, const uint& date_, const uint& mileage_)
{
    this->model = model_;
    this->date = date_;
    this->mileage = mileage_;
}

distance::distance(QJsonObject obj) {
    model = obj.value("Model").toString();
    date = obj.value("Date").toInteger();
    mileage = obj.value("Mileage").toInteger();
}

QJsonObject distance::toJsonObj() {

    QJsonObject obj;
    obj.insert("Model", QJsonValue::fromVariant(model));
    obj.insert("Date", QJsonValue::fromVariant(date));
    obj.insert("Mileage", QJsonValue::fromVariant(mileage));
    return obj;
};

Cars1::Cars1(QObject *parent)
    :QAbstractListModel(parent)
{
    cars = new QList<distance>();
}

Cars1::Cars1(QJsonObject obj) {
    QJsonArray j_arr = obj.value("Cars").toArray();
    foreach (QJsonValue it, j_arr) {
        QJsonObject tmp = it.toObject();
        cars->append(tmp);
    }
}

QJsonObject Cars1::toJsonObj() const {
    QJsonObject obj;
    QJsonArray obj_arr;
    foreach (distance it, *cars) {
        obj_arr.append(it.toJsonObj());
    }
    obj.insert("Cars", obj_arr);
    return obj;
}

int Cars1::rowCount(const QModelIndex &) const
{
    return cars->count();
}

int Cars1::columnCount(const QModelIndex &) const
{
    return 3;
}

QVariant Cars1::data( const QModelIndex &index, int role ) const
{
    QVariant value;
        switch ( role )
        {
            case Qt::DisplayRole: //string
            {
                switch (index.column()) {
                    case 0: {
                        value = this->cars->at(index.row()).model;
                        break;
                    }
                    case 1: {
                        value = this->cars->at(index.row()).date;
                        break;
                    }
                    case 2: {
                        value = this->cars->at(index.row()).mileage;
                        break;
                    }
                }
            }
            break;
            case Qt::UserRole: //data
            {
                value = this->cars->at(index.row()).model;
            }
            break;

            default:
                break;
        }

    return value;
}

void Cars1::populate(QList<distance> *newValues)
{
    int idx = this->cars->count();
    this->QAbstractListModel::beginInsertRows(QModelIndex(), 1, idx);
        this->cars = newValues;
    QAbstractListModel::endInsertRows();
}


void Cars1::SortUp() {
    std::sort(cars->begin(), cars->end(), [](distance& left, distance& right){return left.mileage < right.mileage;});
}

QVector<int> Cars1::SearchCar(QString& ob_model) {
    QVector<int> ans;
    for (qsizetype i = 0; i < (*cars).size(); i++) {
        if ((*cars)[i].model == ob_model) {
            ans.push_back(i);
        }
    }
    if(ans.size() == 0) {
        throw QString{"There aren't cars such model"};
    }
    return ans;
}

void Cars1::append(distance value)
{
    int newRow = this->cars->count()+1;
    this->QAbstractListModel::beginInsertRows(QModelIndex(), newRow, newRow);
    cars->append(value);
    QAbstractListModel::endInsertRows();
}

void Cars1::update(int idx, distance value)
{
    (*this->cars)[idx] = value;
    QModelIndex item_idx_s = this->QAbstractListModel::index(idx,0);
    QModelIndex item_idx_e = this->QAbstractListModel::index(idx,this->columnCount(QModelIndex()));
    emit this->QAbstractListModel::dataChanged(item_idx_s ,item_idx_e );
}

void Cars1::deleteRow(int idx)
{
    this->QAbstractListModel::beginRemoveRows(QModelIndex(), idx,idx);
    (*this->cars).removeAt(idx);
    this->QAbstractListModel::endRemoveRows();
}

void Cars1::insertAt(int idx, distance value)
{
    int newRow = idx;
    this->QAbstractListModel::beginInsertRows(QModelIndex(), newRow, newRow);
    cars->insert(newRow,value);
    QAbstractListModel::endInsertRows();
}

QVariant Cars1::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("Model");
        case 1:
            return QString("Date");
        case 2:
            return QString("Mileage");
        }
    }
    return QVariant();
}

bool Cars1::load(const QString& fileName) {
    QFile loadFile(fileName);
    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }

    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDoc = QJsonDocument::fromJson(saveData);
    QJsonObject json = loadDoc.object();

    QJsonArray data = json["Cars"].toArray();
    const int rowCount = json["rowCount"].toInt();

    for (int i = 0; i < rowCount; i++) {
        QJsonObject row = data[i].toObject();
        this->append(distance(row));
    }

    return true;
}

bool Cars1::save(const QString& fileName) {
    QFile saveFile(fileName);
    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }

    QJsonObject json = this->toJsonObj();
    json["rowCount"] = this->rowCount(QModelIndex());

    QJsonDocument saveDoc(json);
    saveFile.write(saveDoc.toJson());

    return true;
}


