#include "paint.h"

Paint::Paint(QObject *parent): QGraphicsScene() {
    Q_UNUSED(parent);
    figures.clear();
}

void Paint::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    switch(obj_type) {
    case 0 : {
        Rectangle *item = new Rectangle(event->scenePos(), selColor);
        item->setPos(event->scenePos());
        rec = item;
        figures.push_back(rec);
        break;
    }
    case 1: {
        Ellipse* item = new Ellipse(event->scenePos(), selColor);
        item->setPos(event->scenePos());
        rec = item;
        figures.push_back(rec);
        break;
    }
    case 2: {
        Polygon* item = new Polygon(event->scenePos(), selColor);
        item->setPos(event->scenePos());
        rec = item;
        figures.push_back(rec);
        break;
    }
    case 3: {
        addEllipse(event->scenePos().x() - 5,
                   event->scenePos().y() - 5,
                   10,
                   10,
                   QPen(Qt::NoPen),
                   QBrush(Qt::red));
        target = event->scenePos();
        break;
    }
    }
    this->addItem(rec);
}

void Paint::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    switch(obj_type) {
    case 0: {
        rec->points[1] = event->scenePos();
        this->update(QRectF(0,0,this->width(), this->height()));
        break;
    }
    case 1: {
        rec->points[1] = event->scenePos();
        this->update(QRectF(0,0,this->width(), this->height()));
        break;
    }
    case 2: {
        rec->points[1] = event->scenePos();
        this->update(QRectF(0,0,this->width(), this->height()));
        break;
    }
    case 3: {
        addLine(target.x(),
                target.y(),
                event->scenePos().x(),
                event->scenePos().y(),
                QPen(Qt::red, 10, Qt::SolidLine, Qt::RoundCap));
        target = event->scenePos();
        break;
    }
    }
}

/*void Paint::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    switch(obj_type) {
    case 0: {
        Rectangle* rec = new Rectangle(event->scenePos(), target, selColor);
        this->addItem(rec);
        this->update();
        break;
    }
    case 1: {
        Ellipse* rec = new Ellipse(event->scenePos(), target, selColor);
        this->addItem(rec);
        this->update();
        break;
    }
    case 2: {
        Polygon* rec = new Polygon(event->scenePos(), target, selColor);
        this->addItem(rec);
        this->update();
        break;
    }
    }
}*/

