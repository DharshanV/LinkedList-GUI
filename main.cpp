/****************************************************************
*  Author          : Dharshan Vishwanath
*  Assignment #11  : GUI Linked List Display
*  Class           : CS03A
*  Section         : MTWTh -1-3:00pm
*  Due Date        : 12/6/2018
****************************************************************/
#include "mainwindow.h"
#include <QApplication>
/***********************************************************
* Assignment #11 : GUI Linked List Display
*_________________________________________________________
*	This program is a GUI program that shows a graphical
*   representation of linked list. It supports 4 different
*   types of linked list: Integer, Double, String, and the
*   Rational. It is a singly linked list going in one
*   direction.
*_________________________________________________________
* INPUT:
*   There are many different inputs the user can input:
*   Radio button: To iterator of different data types.
*   Push back: Allows the user to push back on selected list.
*   Push front: Allows the user to push font on selected list.
*   Pop front: Allows the user to pop front on selected list.
*   Remove Duplicates: Allows the user to remove duplicated data
*                      on selected list.
*   Inserted Sorted: Allows the user to insert sorted on selected list.
*   Display: Allows the user to display on selected list given a range
*            from min to max.
*   Sort: Allows the user to sort the selected list.
* OUTPUT:
*   The outputs of the program are mainly located in the graphical
*   view or the scene of the program. It shows the nodes
*   and arrows connecting from each node or data. It also allows
*   the user to move the nodes, and zoom in/out of the scene.
***********************************************************/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
