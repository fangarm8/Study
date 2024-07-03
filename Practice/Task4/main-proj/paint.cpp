#include "paint.h"

Paint::Paint(QObject *parent): QGraphicsScene() {
    Q_UNUSED(parent);
    figures.clear();
}

void Paint::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    target[0] = event->scenePos();
}

void Paint::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (figures.empty()) {
        throw QString{"Please, choose figure!"};
    } else {
        target[1] = event->scenePos();
        figures.last() = new Rectangle(target[1], target[0]);
        this->addItem(figures.last());
        this->update();
    }
}

