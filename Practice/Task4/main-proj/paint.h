#ifndef PAINT_H
#define PAINT_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QMessageBox>
#include <QSvgGenerator>
#include <QFileDialog>
#include <QTimer>
#include "rectangle.h"


class Paint : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Paint(QObject *parent = 0);
    QPointF target;
    uint obj_type;
    QVector<Rectangle*> figures;
    Rectangle* rec;
    QColor selColor = QColorConstants::White;
signals:
    // Сигнал для передачи координат положения курсора мыши
    void signalTargetCoordinate(QPointF point);
private:
    // Функция, в которой производится отслеживание положения мыши
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    // void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PAINT_H
