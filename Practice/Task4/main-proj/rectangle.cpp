#include "rectangle.h"

Rectangle::Rectangle(QObject *parent) : /*QObject(parent),*/ QGraphicsItem() {
    points[0] = QPointF(-20, 10);
    points[1] = QPointF(20, -10);
}

Rectangle::Rectangle(QPointF start_p, QObject *parent)
{
    points[0] = start_p;
    points[1] = QPointF(points[0].x() + 400, points[0].y() + 200);
}

/*void Rectangle::slotTarget(QPointF mouse_point)
{
    points[0] = mouse_point;
    points[1] = QPointF(points[0].x() + 400, points[0].y() + 200);
}*/

QRectF Rectangle::boundingRect() const {
    return QRectF(-200, 100, 200, -100);
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawRect(QRectF(points[1], points[0]));
}
