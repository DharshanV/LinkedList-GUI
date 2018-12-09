#include "node.h"

/*
    Method _Node: Class _Node
    -------------------------------------
    This function is a constructor, creates
    the node object.
    ------------------------------------
    PRE-CONDITIONS
        width - width of node
        height - height of node
        value - value of node
    POST-CONDITION
        None
*/
_Node::_Node(int width,int height,const QString& value)
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);
    this->width = width;
    this->height = height;
    this->value = value;
}

/*
    Method addEdge: Class _Node
    -------------------------------------
    This function is called when ever
    the user addes a new element
    in the list, and creates a new node
    to draw.
    ------------------------------------
    PRE-CONDITIONS
        edge - edge to connect
    POST-CONDITION
        None
*/
void _Node::addEdge(Edge *edge)
{
    edgeList << edge;
    edge->adjust();
}

/*
    Method edges: Class _Node
    -------------------------------------
    This function is called when the program
    needs all the edges in the list
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        returns edge list
*/
QList<Edge *> _Node::edges() const
{
    return edgeList;
}

/*
    Method advancePosition: Class _Node
    -------------------------------------
    This function is called when ever
    the program needs to move
    the node to new position.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/
bool _Node::advancePosition()
{
    if (newPos == pos())
        return false;

    setPos(newPos);
    return true;
}

/*
    Method boundingRect: Class _Node
    -------------------------------------
    This function is called when the program
    needs the bounding rectangle.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        returns a rectangle position.
*/

QRectF _Node::boundingRect() const
{
    return QRectF(-2,-2,width+5, height+5);
}

/*
    Method shape: Class _Node
    -------------------------------------
    This function is called when the program
    needs the shape of node
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        returns a path to draw
*/
QPainterPath _Node::shape() const
{
    QPainterPath path;
    path.addRoundedRect (0,0, width, height,2,2);
    return path;
}

/*
    Method paint: Class _Node
    -------------------------------------
    This function is called when ever
    the program needs to paint the node.
    ------------------------------------
    PRE-CONDITIONS
        painter - painter
        option - painter option
        widget - widget to draw on
    POST-CONDITION
        None
*/
void _Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    //shadow
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::darkGray);
    painter->drawRoundedRect (3, 3, width+2, height+2,4,4);
    //node color
    QBrush nodeBrush(Qt::red);
    painter->setBrush(nodeBrush);
    //node border
    painter->setPen(QPen(Qt::black, 0));
    painter->drawRoundedRect (0,0,width, height,2,2);
    //draw text
    painter->setPen(Qt::yellow);
    drawText (*painter,(width/2),(height/2),Qt::AlignCenter,value);
    if(option->type){}
}

/*
    Method itemChange: Class _Node
    -------------------------------------
    This function is called when the user
    when they interact with the nodes.
    ------------------------------------
    PRE-CONDITIONS
        change - changed item
        value - value
    POST-CONDITION
        None
*/
QVariant _Node::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        foreach (Edge *edge, edgeList)
            edge->adjust();
        break;
    default:
        break;
    };

    return QGraphicsItem::itemChange(change, value);
}

/*
    Method mousePressEvent: Class _Node
    -------------------------------------
    This function is called when the user
    does mouse event pressed.
    ------------------------------------
    PRE-CONDITIONS
        event - mouse event
    POST-CONDITION
        None
*/
void _Node::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
}

/*
    Method mouseReleaseEvent: Class _Node
    -------------------------------------
    This function is called when the user
    does mouse event released.
    ------------------------------------
    PRE-CONDITIONS
        event - mouse event
    POST-CONDITION
        None
*/
void _Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

/*
    Method getHeight: Class _Node
    -------------------------------------
    This function is called when the program
    needs the node height
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        returns node height
*/
int _Node::getHeight () const{
    return height;
}

/*
    Method getWidth: Class _Node
    -------------------------------------
    This function is called when the program
    needs the node width
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        returns node width
*/
int _Node::getWidth () const{
    return width;
}

/*
    Method drawText: Class _Node
    -------------------------------------
    This function is called when the user
    adds a new node, and the value to draw.
    ------------------------------------
    PRE-CONDITIONS
        painter - painter
        x - x position
        y - y position
        flags - alignments
        text - text of node
        boundingRect - bounding rectangle
    POST-CONDITION
        None
*/
void _Node::drawText(QPainter & painter, qreal x, qreal y, Qt::Alignment flags,
              const QString & text, QRectF * boundingRect)
{
   const qreal size = 32767.0;
   QPointF corner(x, y - size);
   if (flags & Qt::AlignHCenter) corner.rx() -= size/2.0;
   else if (flags & Qt::AlignRight) corner.rx() -= size;
   if (flags & Qt::AlignVCenter) corner.ry() += size/2.0;
   else if (flags & Qt::AlignTop) corner.ry() += size;
   else flags |= Qt::AlignBottom;
   QRectF rect{corner.x(), corner.y(), size, size};
   painter.drawText(rect, flags, text, boundingRect);
}
