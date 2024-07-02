#ifndef PAINT_H
#define PAINT_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include "rectangle.h"


class Paint : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Paint(QObject *parent = 0);
    QPointF target;
signals:
    // Сигнал для передачи координат положения курсора мыши
    void signalTargetCoordinate(QPointF point);
public slots:

private:
    // Функция, в которой производится отслеживание положения мыши
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PAINT_H
