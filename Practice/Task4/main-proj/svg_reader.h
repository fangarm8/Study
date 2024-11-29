#ifndef SVG_READER_H
#define SVG_READER_H

#include <QGraphicsItem>
#include <QList>

class SVG_reader
{
public:
    SVG_reader();
    static QList<QGraphicsItem *> getEl(const QString filename);
    static QRectF getSizes(const QString filename);
};

#endif // SVG_READER_H
