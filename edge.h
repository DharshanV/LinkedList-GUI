#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsItem>
#include <qmath.h>
#include <QPainter>
#include "node.h"

class _Node;

class Edge : public QGraphicsItem
{
public:
    /* CONSTRUCTOR & DESTRUCTOR */
    Edge(_Node* source_Node,                        //IN/OUT - node right
         _Node* dest_Node);                         //IN/OUT - node left

    /* MUTATORS */
    void adjust();

    /* ACCESSORS */
    enum { Type = UserType + 2 };
    int type() const override { return Type; }
    _Node* getSource();
    _Node* getDest();


protected:
    /* MUTATORS */
    void paint(QPainter *painter,                   //IN/OUT - painter
               const QStyleOptionGraphicsItem       //IN/OUT - options
               *option,
               QWidget *widget) override;           //IN/OUT - widget

    /* ACCESSORS */
    QRectF boundingRect() const override;
private:
    _Node *source;                                  //IN/OUT - source node
    _Node *dest;                                    //IN/OUT - dest node

    QPointF sourcePoint;                            //IN/OUT - point of source
    QPointF destPoint;                              //IN/OUT - pont of dest
    qreal arrowSize;                                //IN/OUT - arrow size
};

#endif // EDGE_H

/*
    Edge class
     This is an LinkedList class and
     an object. It manages 5
     attributes: source, dest,
     source point, dest point,
     and arrow size;
*/

/* CONSTRUCTOR & DESTRUCTOR */

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

/* MUTATORS */

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


/* ACCESSORS */

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
