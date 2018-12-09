#include "mygraphwidget.h"

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
MyGraphWidget::MyGraphWidget(QWidget* parent):
    QGraphicsView(parent)
{
    scene = new QGraphicsScene(this);
    setRenderHint(QPainter::Antialiasing);
    this->setScene (scene);
}

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
#if QT_CONFIG(wheelevent)
void MyGraphWidget::wheelEvent(QWheelEvent *event)
{
    scaleView(pow((double)2, -event->delta() / 240.0));
}
#endif

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
void MyGraphWidget::scaleView(qreal scaleFactor)
{
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;
    scale(scaleFactor, scaleFactor);
}

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
void MyGraphWidget::zoomIn()
{
    scaleView(qreal(1.2));
}

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
void MyGraphWidget::zoomOut()
{
    scaleView(1 / qreal(1.2));
}

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

QGraphicsScene* MyGraphWidget::getScene(){
    return scene;
}

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
void MyGraphWidget::setNewScene (QGraphicsScene *scene){
    this->scene = scene;
    this->setScene (scene);
}

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

MyGraphWidget::~MyGraphWidget (){
    scene->~QGraphicsScene ();
}
