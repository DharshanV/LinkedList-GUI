#include "edge.h"

/*
    Method Edge: Class Edge
    -------------------------------------
    This function is a constructor, and
    sets the source and dest to the passed
    values.
    ------------------------------------
    PRE-CONDITIONS
        source_Node - source node
        dest_Node - dest node
    POST-CONDITION
        None
*/
Edge::Edge(_Node *sourceNode, _Node *destNode)
    : arrowSize(10)
{
    setAcceptedMouseButtons(0);
    source = sourceNode;
    dest = destNode;
    source->addEdge(this);
    dest->addEdge(this);
    adjust();
}

/*
    Method adjust: Class Edge
    -------------------------------------
    This function is updates the
    edge drawings by adjusting its
    values that match the desrired drawings.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/
void Edge::adjust()
{
    if (!source || !dest)
        return;

    QLineF line(mapFromItem(source, 0, 0),
                mapFromItem(dest, 0, 0));
    qreal length = line.length();

    prepareGeometryChange();

    if (length > qreal(20.)) {
        sourcePoint = line.p1() +
                QPointF(getSource ()->getWidth (),
                getSource ()->getHeight ()/2);
        destPoint = line.p2() +
                QPointF(0,0 +
                getDest ()->getHeight ()/2);
    } else {
        sourcePoint = destPoint = line.p1();
    }
}

/*
    Method boundingRect: Class Edge
    -------------------------------------
    This function returns the bounding
    rectangle that covers the entire
    node.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        returns rectangle float.
*/
QRectF Edge::boundingRect() const
{
    if (!source || !dest)
        return QRectF();

    qreal penWidth = 1;
    qreal extra = (penWidth + arrowSize) / 2.0;

    return QRectF(sourcePoint,
                  QSizeF(destPoint.x() - sourcePoint.x(),
                    destPoint.y() - sourcePoint.y()))
        .normalized()
        .adjusted(-extra, -extra, extra, extra);
}

/*
    Method paint: Class Edge
    -------------------------------------
    This function is paints
    all the drawings for this class.
    ------------------------------------
    PRE-CONDITIONS
        painter - painter to use to pain
        option - options of the paint
        widget - widget to draw on
    POST-CONDITION
        None
*/
void Edge::paint(QPainter *painter,
                 const QStyleOptionGraphicsItem *,
                 QWidget *)
{
    if (!source || !dest)
        return;

    QLineF line(sourcePoint, destPoint);
    if (qFuzzyCompare(line.length(), qreal(0.)))
        return;

    painter->setPen(QPen(Qt::black, 1,
                         Qt::SolidLine, Qt::RoundCap,
                         Qt::RoundJoin));
    painter->drawLine(line);

    double angle = std::atan2(-line.dy(), line.dx());

    QPointF destArrowP1 = destPoint +
            QPointF(sin(angle - M_PI / 3) * arrowSize,
            cos(angle - M_PI / 3) * arrowSize);
    QPointF destArrowP2 = destPoint +
            QPointF(sin(angle - M_PI + M_PI / 3) * arrowSize,
            cos(angle - M_PI + M_PI / 3) * arrowSize);

    painter->setBrush(Qt::black);
    painter->drawPolygon(QPolygonF() << line.p2()
                         << destArrowP1 << destArrowP2);
}

/*
    Method sourceNode: Class Edge
    -------------------------------------
    This function returns the source
    node of this edge.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        returns source node
*/
_Node* Edge::getSource(){
    return source;
}

/*
    Method destNode: Class Edge
    -------------------------------------
    This function returns the destination
    node of this edge.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        returns destination node
*/
_Node* Edge::getDest(){
    return dest;
}
