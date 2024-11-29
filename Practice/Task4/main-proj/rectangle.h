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
    Rectangle(QPointF start_p, QPointF end_p, QColor selColor);
private:
    QPointF points[2];
    QColor figColor;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
};

class Ellipse : public Rectangle
{
public:
    Ellipse();
    Ellipse(QPointF start_p, QPointF end_p, QColor selColor);
private:
    QPointF points[2];
    QColor figColor;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

class Polygon : public Rectangle
{
public:
    Polygon();
    Polygon(QPointF start_p, QPointF end_p, QColor selColor);
private:
    QPointF points[2];
    QColor figColor;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // RECTANGLE_H
