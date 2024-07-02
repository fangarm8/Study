#include "paint.h"

Paint::Paint(QObject *parent): QGraphicsScene() {
    Q_UNUSED(parent);
}

void Paint::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    target = event->scenePos();
    Rectangle* rec = new Rectangle(this->target);
    this->addItem(rec);
}

