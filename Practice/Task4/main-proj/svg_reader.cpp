#include "svg_reader.h"
#include <QPen>
#include <QFile>
#include <QMessageBox>
#include <QDomDocument>
#include <QStringList>

SVG_reader::SVG_reader()
{

}

QList<QGraphicsItem *> SVG_reader::getEl(const QString filename)
{
    QList<QGraphicsItem *> itemList;

    QDomDocument doc;
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file))
        return itemList;

    QDomNodeList gList = doc.elementsByTagName("g");
    for (int i = 0; i < gList.size(); i++) {
        QDomNode gNode = gList.item(i);
        QDomElement itemDom = gNode.firstChildElement("ellipse");
        if (itemDom.isNull()){
            continue;
        } else {
            QGraphicsEllipseItem *ellipse = new QGraphicsEllipseItem;
            QDomElement gElement = gNode.toElement();
            ellipse->setRect(itemDom.attribute("cx").toFloat() - itemDom.attribute("rx").toFloat(),
                             itemDom.attribute("cy").toFloat() - itemDom.attribute("ry").toFloat(),
                             itemDom.attribute("rx").toFloat()*2,
                             itemDom.attribute("ry").toFloat()*2);
            QColor fillColor(gElement.attribute("fill", "#ffffff"));
            fillColor.setAlphaF(gElement.attribute("fill-opacity","0").toFloat());
            ellipse->setBrush(QBrush(fillColor));

            QColor strokeColor(gElement.attribute("stroke", "#000000"));
            strokeColor.setAlphaF(gElement.attribute("stroke-opacity").toFloat());

            ellipse->setPen(QPen(strokeColor,gElement.attribute("stroke-width", "0").toInt()));
            itemList.append(ellipse);
        }
    }

    for (int i = 0; i < gList.size(); i++) {
        QDomNode gNode = gList.item(i);
        QDomElement itemDom = gNode.firstChildElement("rect");
        if (itemDom.isNull()){
            continue;
        } else {
            QGraphicsRectItem *rect = new QGraphicsRectItem();
            rect->setFlag(QGraphicsItem::ItemIsMovable);
            QDomElement gElement = gNode.toElement();
            rect->setRect(itemDom.attribute("x").toFloat(),
                          itemDom.attribute("y").toFloat(),
                          itemDom.attribute("width").toFloat(),
                          itemDom.attribute("height").toFloat());
            QColor fillColor(gElement.attribute("fill", "#ffffff"));
            fillColor.setAlphaF(gElement.attribute("fill-opacity","0").toFloat());
            rect->setBrush(QBrush(fillColor));

            QColor strokeColor(gElement.attribute("stroke", "#000000"));
            strokeColor.setAlphaF(gElement.attribute("stroke-opacity").toFloat());

            rect->setPen(QPen(strokeColor,gElement.attribute("stroke-width", "0").toInt()));
            itemList.append(rect);
        }
    }

    for (int i = 0; i < gList.size(); i++) {
        QDomNode gNode = gList.item(i);
        QDomElement itemDom = gNode.firstChildElement("path");
        if (itemDom.isNull()){
            continue;
        } else {
            QStringList pol_str = itemDom.attribute("d").split(" ");
            QString it_x[4];
            QString it_y[4];
            for (int i = 0; i < 4; i++) {
                pol_str[i].remove(0,1);
                it_x[i] = pol_str[i].split(",")[0];
                it_y[i] = pol_str[i].split(",")[1];
            }
            QPolygonF pol;
            QPointF tmp_point;
            for (int i = 0; i < 4; i++) {
                tmp_point.setX(it_x[i].toDouble());
                tmp_point.setY(it_y[i].toDouble());
                pol << tmp_point;
            }
            QGraphicsPolygonItem* pol_gr = new QGraphicsPolygonItem(pol);
            QDomElement gElement = gNode.toElement();
            QColor fillColor(gElement.attribute("fill", "#ffffff"));
            fillColor.setAlphaF(gElement.attribute("fill-opacity","0").toFloat());
            pol_gr->setBrush(QBrush(fillColor));

            QColor strokeColor(gElement.attribute("stroke", "#000000"));
            strokeColor.setAlphaF(gElement.attribute("stroke-opacity").toFloat());

            pol_gr->setPen(QPen(strokeColor,gElement.attribute("stroke-width", "0").toInt()));
            itemList.append(pol_gr);
        }
    }
    file.close();
    return itemList;
}

QRectF SVG_reader::getSizes(const QString filename)
{
    QDomDocument doc;
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file))
        return QRectF(0,0,200,200);

    QDomNodeList list = doc.elementsByTagName("svg");
    if(list.length() > 0) {
        QDomElement svgElement = list.item(0).toElement();
        QStringList parameters = svgElement.attribute("viewBox").split(" ");
        return QRectF(parameters.at(0).toInt(),
                      parameters.at(1).toInt(),
                      parameters.at(2).toInt(),
                      parameters.at(3).toInt());
    }
    return QRectF(0,0,200,200);
}
