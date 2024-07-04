#include "paint.h"

Paint::Paint(QObject *parent): QGraphicsScene() {
    Q_UNUSED(parent);
    figures.clear();
}

void Paint::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    target = event->scenePos();
}

/*void Paint::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    switch(obj_type) {
    case 0: {
        rec = new Rectangle(event->scenePos(), target, selColor);
        this->addItem(rec);
        this->update(QRectF(QRectF(0,0,this->width(), this->height())));
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

void Paint::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
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
}

