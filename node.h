#ifndef _Node_H
#define _Node_H

#include <QGraphicsItem>
#include <QList>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>
#include <QDebug>
#include "mygraphwidget.h"

class Edge;
class MyGraphWidget;
class QGraphicsSceneMouseEvent;

class _Node : public QGraphicsItem
{
public:
    /* CONSTRUCTOR & DESTRUCTOR */
    _Node(int width,                                    //IN/OUT - node width
          int height,                                   //IN/OUT - node height
          const QString& value);                        //IN/OUT - node value

    /* MUTATORS */
    void addEdge(Edge *edge);                           //IN/OUT - node edge
    bool advancePosition();
    void paint(QPainter *painter,                       //IN/OUT - painter
               const QStyleOptionGraphicsItem *option,  //IN/OUT - painter option
               QWidget *widget) override;               //IN/OUT - painter widget
    void drawText(QPainter & painter,                   //IN/OUT - painter
                  qreal x,                              //IN/OUT - x position
                  qreal y,                              //IN/OUT - y position
                  Qt::Alignment flags,                  //IN/OUT - text position
                  const QString & text,                 //IN/OUT - text
                  QRectF * boundingRect = 0);           //IN/OUT - bouding rectangle

    /* ACCESSORS */
    enum { Type = UserType + 1 };
    int type() const override { return Type; }
    QList<Edge *> edges() const;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    int getWidth()const;
    int getHeight()const;

protected:
    /* MUTATORS */
    QVariant itemChange(GraphicsItemChange change,      //IN/OUT - change in item
                        const QVariant &value) override;//IN/OUT - value
    void mousePressEvent(
            QGraphicsSceneMouseEvent *event) override;  //IN/OUT - mouse event
    void mouseReleaseEvent(
            QGraphicsSceneMouseEvent *event) override;  //IN/OUT - mouse event

private:
    QList<Edge *> edgeList;                             //IN/OUT - edge list
    QPointF newPos;                                     //IN/OUT - node position
    int width;                                          //IN/OUT - node width
    int height;                                         //IN/OUT - node height
    QString value;                                      //IN/OUT - node value
};
#endif // _Node_H

/*
    _Node class
     This is an LinkedList class and
     an object. It manages 5
     attributes: edgeList, newPos,
     width, height, value.
*/

/* CONSTRUCTOR & DESTRUCTOR */

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

/* MUTATORS */

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

/* ACCESSORS */

/*
    Method type: Class _Node
    -------------------------------------
    This function is called when the program
    needs the type.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        returns type
*/

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
