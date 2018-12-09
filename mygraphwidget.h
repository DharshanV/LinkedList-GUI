#ifndef MYGRAPHWIDGET_H
#define MYGRAPHWIDGET_H
#include "edge.h"
#include "node.h"
#include "LinkedList.h"
#include <QGraphicsView>
#include <QDebug>
#include <QKeyEvent>

class _Node;                                    //IN/OUT - forward node
class Edge;                                     //IN/OUT - forward edge

class MyGraphWidget : public QGraphicsView
{
    Q_OBJECT
public slots:
    /* MUTATORS */
    void zoomIn();
    void zoomOut();
public:
    /* CONSTRUCTOR & DESTRUCTOR */
    MyGraphWidget(QWidget* parent);             //IN/OUT - parent widget
    ~MyGraphWidget();
#if QT_CONFIG(wheelevent)
    /* MUTATORS */
    void wheelEvent(QWheelEvent *event) override;//IN/OUT - wheel event
#endif
    /* MUTATORS */
    void scaleView(qreal scaleFactor);          //IN/OUT - zoom
    void setNewScene (QGraphicsScene *scene);   //IN/OUT - drawing scene
    /* ACCESSORS */
    QGraphicsScene* getScene();
private:
    QGraphicsScene *scene;                      //IN/OUT - scene
};

#endif //!MYGRAPHWIDGET_H

/*
    MyGraphWidget class
     This is an LinkedList class and
     an object. It manages 1
     attributes: scene.
*/

/* CONSTRUCTOR & DESTRUCTOR */

/*
    Method MyGraphWidget: Class MyGraphWidget
    -------------------------------------
    This function is a constructor, creates
    scene to draw all the nodes
    ------------------------------------
    PRE-CONDITIONS
        parent - parent window
    POST-CONDITION
        None
*/

/*
    Method ~MyGraphWidget: Class MyGraphWidget
    -------------------------------------
    This function is a destructor,
    and deletes all the things
    inside the graphics scene.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/

/* MUTATORS */

/*
    Method wheelEvent: Class MyGraphWidget
    -------------------------------------
    This function is called when ever
    the user changes the state of the
    scroll mouse wheel.
    ------------------------------------
    PRE-CONDITIONS
        event - mouse event
    POST-CONDITION
        None
*/

/*
    Method scaleView: Class MyGraphWidget
    -------------------------------------
    This function is called when ever
    the user changes the state of the
    scroll mouse wheel, and changes
    the scale of the draw. (zooming)
    ------------------------------------
    PRE-CONDITIONS
        scaleFactor - scale factor
    POST-CONDITION
        None
*/

/*
    Method setNewScene: Class MyGraphWidget
    -------------------------------------
    This function is called when ever
    the user deletes a scene, or
    a new scene gets called.
    ------------------------------------
    PRE-CONDITIONS
        scene - graphic scene
    POST-CONDITION
        None
*/

/*
    Method zoomIn: Class MyGraphWidget
    -------------------------------------
    This function is called when ever
    the user zooms in.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/

/*
    Method zoomOut: Class MyGraphWidget
    -------------------------------------
    This function is called when ever
    the user zooms out.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/

/* ACCESSORS */

/*
    Method getScene: Class MyGraphWidget
    -------------------------------------
    This function is called when ever
    the program needs a scene to
    draw the list.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        QGraphicsScene - returns this scene
*/
