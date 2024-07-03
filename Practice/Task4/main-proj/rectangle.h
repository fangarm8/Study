#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QObject>
#include <QColor>
#include <QGraphicsItem>
#include <QPainter>

class Rectangle : public QGraphicsItem
{
public:
    Rectangle();
    Rectangle(QPointF start_p, QPointF end_p);
/*public slots:
    void slotTarget(QPointF mouse_point);*/
private:
    //QColor selColor;
    QPointF points[2];
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
};

class Ellipse : public Rectangle
{
public:
    Ellipse();
private:
};

class Polygon : public Rectangle
{
public:
    Polygon();
private:
};

#endif // RECTANGLE_H
