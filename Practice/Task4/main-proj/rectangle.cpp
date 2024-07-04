#include "rectangle.h"

Rectangle::Rectangle() : QGraphicsItem() {
    points[0] = QPointF(-20, 10);
    points[1] = QPointF(20, -10);
}

Rectangle::Rectangle(QPointF start_p, QColor selColor)
{
    points[0] = mapFromScene(start_p);
    points[1] = mapFromScene(start_p);
    figColor = selColor;
}

QRectF Rectangle::boundingRect() const {
    return QRectF((points[1].x() > points[0].x() ? points[0].x() : points[1].x()),
                (points[1].y() > points[0].y() ? points[0].y() : points[1].y()),
                qAbs(points[1].x() - points[0].x()),
                qAbs(points[1].y() - points[0].y()));
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(figColor);
    painter->setPen(figColor);

    painter->drawRect(QRectF(points[1], points[0]));
}

Ellipse::Ellipse() {
    points[0] = QPointF(-20, 10);
    points[1] = QPointF(20, -10);
}

Ellipse::Ellipse(QPointF start_p, QColor selColor)
{
    points[0] = mapFromScene(start_p);
    points[1] = mapFromScene(start_p);
    figColor = selColor;
}

void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(figColor);
    painter->setPen(figColor);


    painter->drawEllipse(QRectF(points[1], points[0]));
}

Polygon::Polygon()
{
    points[0] = QPoint(-20, 10);
    points[1] = QPoint(20, -10);
}

Polygon::Polygon(QPointF start_p, QColor selColor)
{
    points[0] = mapFromScene(start_p);
    points[1] = mapFromScene(start_p);
    figColor = selColor;
}

void Polygon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPolygonF polygon;
    polygon << QPointF(points[0].x() + (points[1].x() > points[0].x() ? + 1 : - 1)*abs((points[1].x() - points[0].x())/2), points[0].y())
            << QPointF(points[1].x(), points[0].y() + (points[1].y() > points[0].y() ? + 1 : - 1)*abs((points[1].y() - points[0].y())/2))
            << QPointF(points[0].x() + (points[1].x() > points[0].x() ? + 1 : - 1)*abs((points[1].x() - points[0].x())/2), points[1].y())
            << QPointF(points[0].x(), points[0].y() + (points[1].y() > points[0].y() ? + 1 : - 1)*abs((points[1].y() - points[0].y())/2));
    painter->setBrush(figColor);
    painter->setPen(figColor);

    painter->drawPolygon(polygon);
}
