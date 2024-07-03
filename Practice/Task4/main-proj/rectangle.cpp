#include "rectangle.h"

Rectangle::Rectangle() : QGraphicsItem() {
    points[0] = QPointF(-20, 10);
    points[1] = QPointF(20, -10);
}

Rectangle::Rectangle(QPointF start_p, QPointF end_p)
{
    points[0] = start_p;
    points[1] = end_p;
}

QRectF Rectangle::boundingRect() const {
    return QRectF(-200, 100, 200, -100);
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawRect(QRectF(points[1], points[0]));
}
