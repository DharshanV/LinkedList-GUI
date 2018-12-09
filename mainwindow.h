#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <QWidget>
#include <QPlainTextEdit>
#include <QGridLayout>
#include <QRadioButton>
#include "mygraphwidget.h"
#include <QDebug>
#include "vector.h"
#include "rational.h"
#include <type_traits>
#include <cstdint>

using namespace std;
namespace Ui {
    class MainWindow;                                   //forward declaration
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /* CONSTRUCTOR & DESTRUCTOR */
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    /* MUTATORS */
    void on_tabLists_tabCloseRequested(int index);      //IN/OUT - index of tab

    void on_tabLists_currentChanged(int index);         //IN/OUT - index of tab

    void on_buttonNewList_clicked();

    void on_radioCopy_clicked();

    void on_radioNew_clicked();

    void on_buttonReset_clicked();

    void on_buttonPushBack_clicked();

    void on_buttonPush_clicked();

    void on_buttonPopFront_clicked();

    void on_buttonRemoveDuplicates_clicked();

    void on_buttonInsertSorted_clicked();

    void on_buttonSort_clicked();

    void on_buttonDisplay_clicked();

    void on_radioInteger_clicked();

    void on_radioDouble_clicked();

    void on_radioString_clicked();

    void on_radioRational_clicked();
//Templated functions
private:
    /* MUTATORS */
    template<typename T>
    void addTab(QString& callName,                      //IN/OUT - tab name
                MyVector<LinkedList<T>*>& MyVectorList, //IN/OUT - list vector
                int index);                             //IN/OUT - tab index

    template<typename T>
    void removeTab(MyVector<LinkedList<T>*>& MyVectorList,//IN/OUT - list vector
                   int index);                          //IN/OUT - tab index

    template<typename T>
    void displayList(MyGraphWidget*& graph,             //IN/OUT - graph window
                     LinkedList<T>*& list,              //IN/OUT - list
                     int min,                           //IN/OUT - min display
                     int max);                          //IN/OUT - max display
//Functions
private:
    /* MUTATORS */
    QRadioButton* getSelectedDataType();
    void displayListS(MyGraphWidget*& graph,             //IN/OUT - graph window
                      LinkedList<string>*& list,         //IN/OUT - list
                      int min,                           //IN/OUT - min display
                      int max);                          //IN/OUT - max display
    void displayListR(MyGraphWidget*& graph,             //IN/OUT - graph window
                      LinkedList<Rational>*& list,       //IN/OUT - list
                      int min,                           //IN/OUT - min display
                      int max);                          //IN/OUT - max display
    void resetScene(MyGraphWidget*& graph,               //IN/OUT - graph window
                    int min,                             //IN/OUT - min display
                    int max);                            //IN/OUT - max display
    void push_back(_Node* node);                         //IN/OUT - list node
    void push_front(_Node* node);                        //IN/OUT - list node
    void addNode(_Node* node);                           //IN/OUT - list node
    void showNodes(MyGraphWidget*& graph,                //IN/OUT - graph window
                   int min,                              //IN/OUT - min display
                   int max);                             //IN/OUT - max display
    Rational* getRational(QString readValue);            //IN/OUT - read value
    void onStart();
    void updateComboBoxItems();
    void reset();
//Variables
private:
    Ui::MainWindow* ui;                                  //IN/OUT - main ui
    MyVector<LinkedList<int>*> intVector;                //IN/OUT - int list vector
    MyVector<LinkedList<double>*> doubleVector;          //IN/OUT - double list vector
    MyVector<LinkedList<string>*> stringVector;          //IN/OUT - string list vector
    MyVector<LinkedList<Rational>*> rationalVector;      //IN/OUT - Rational list vector
    MyVector<_Node*> nodeList;                           //IN/OUT - vector of nodes
    MyVector<Edge*> edgeList;                            //IN/OUT - vector of edges
};
#endif // MAINWINDOW_H

/*
    MainWindow class
     This is an LinkedList class and
     an object. It manages 7
     attributes: ui, intVector,
     doubleVector, stringVector,
     rationalVector, nodeList,
     and edgeList.
*/

/* CONSTRUCTOR & DESTRUCTOR */

/*
    Method MainWindow: Class MainWindow
    -------------------------------------
    This function is a constructor, creates
    all the ui and places them in the parent
    window
    ------------------------------------
    PRE-CONDITIONS
        parent - parent window
    POST-CONDITION
        None
*/

/*
    Method ~MainWindow: Class MainWindow
    -------------------------------------
    This function is a destructor, which
    deletes all the ui's, vectors, and lists.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/

/* MUTATORS */

/*
    Method on_tabLists_tabCloseRequested: Class MainWindow
    -------------------------------------
    This function is called when ever
    the user closes a tab. And deletes
    the tab and the list it contained.
    ------------------------------------
    PRE-CONDITIONS
        index - index of the closed tab
    POST-CONDITION
        None
*/

/*
    Method on_buttonNewList_clicked: Class MainWindow
    -------------------------------------
    This function is called when ever
    the user clicks on new list button.
    It creates a new tab and a new list
    of the type.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/

/*
    Method on_radioCopy_clicked: Class MainWindow
    -------------------------------------
    This function is called when ever
    the user clicks on the radio button
    to copy from an exisiting list. And
    displays the number of that type list
    in the field.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/

/*
    Method on_radioNew_clicked: Class MainWindow
    -------------------------------------
    This function is called when ever
    the user clicks on the radio button
    to create a new list.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/

/*
    Method on_buttonReset_clicked: Class MainWindow
    -------------------------------------
    This function is called when ever
    the user clicks on reset button,
    and resets the options
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/

/*
    Method on_buttonPushBack_clicked: Class MainWindow
    -------------------------------------
    This function is called when ever
    the user clicks on push back button,
    and addes a node to the end of the list.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/

/*
    Method on_buttonPush_clicked: Class MainWindow
    -------------------------------------
    This function is called when ever
    the user clicks on push font button,
    and addes a node to the front of the list.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/

/*
    Method on_buttonPopFront_clicked: Class MainWindow
    -------------------------------------
    This function is called when ever
    the user clicks on push pop button,
    and deletes a node to the front of the list.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/

/*
    Method on_buttonRemoveDuplicates_clicked: Class MainWindow
    -------------------------------------
    This function is called when ever
    the user clicks on remove duplicates button,
    and deletes all the duplicates from the list.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/

/*
    Method on_buttonInsertSorted_clicked: Class MainWindow
    -------------------------------------
    This function is called when ever
    the user clicks on inset sorted button,
    and inserts a node sorted in the list.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/

/*
    Method on_buttonSort_clicked: Class MainWindow
    -------------------------------------
    This function is called when ever
    the user clicks on sort button,
    and sorts the entire list.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/

/*
    Method on_tabLists_currentChanged: Class MainWindow
    -------------------------------------
    This function is called when ever
    the user clicks on a different tabs
    ------------------------------------
    PRE-CONDITIONS
        index - index of the changed tab
    POST-CONDITION
        None
*/

/*
    Method on_buttonDisplay_clicked: Class MainWindow
    -------------------------------------
    This function is called when ever
    the user clicks the display button. It
    displays the entire list.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/

/*
    Method on_radioInteger_clicked: Class MainWindow
    -------------------------------------
    This function is called when ever
    the user clicks the integer type radio.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/

/*
    Method on_radioDouble_clicked: Class MainWindow
    -------------------------------------
    This function is called when ever
    the user clicks the double type radio.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/

/*
    Method on_radioString_clicked: Class MainWindow
    -------------------------------------
    This function is called when ever
    the user clicks the string type radio.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/

/*
    Method on_radioRational_clicked: Class MainWindow
    -------------------------------------
    This function is called when ever
    the user clicks the rational type radio.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/

/*
    Method addTab: Class MainWindow
    -------------------------------------
    This function is called when ever
    the user clicks on new list or copy
    list, and adds a tab to the tab view.
    ------------------------------------
    PRE-CONDITIONS
        callName - name of the tab
        MyVectorList - vector of lists
        index - index to insert
    POST-CONDITION
        None
*/

/*
    Method removeTab: Class MainWindow
    -------------------------------------
    This function is called when ever
    the user closes a tab, and deletes
    all nodes and the list in that tab.
    ------------------------------------
    PRE-CONDITIONS
        MyVectorList - vector of lists
        index - index to remove
    POST-CONDITION
        None
*/

/*
    Method displayList: Class MainWindow
    -------------------------------------
    This function is called when ever
    the user wants to display the list.
    ------------------------------------
    PRE-CONDITIONS
        graph - graph window widget
        list - list to display
        min - min of list
        max - max of list
    POST-CONDITION
        None
*/

/*
    Method onStart: Class MainWindow
    -------------------------------------
    This function is called when ever
    the program starts, and initilizes
    all the widgets to default state.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/

/*
    Method getSelectedDataType: Class MainWindow
    -------------------------------------
    This function is called when ever
    the program needs to know which
    data type has the user clicked to
    create.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        QRadioButton - radio button of the type
*/

/*
    Method displayListS: Class MainWindow
    -------------------------------------
    This function is called when ever
    the user wants to display the string list.
    ------------------------------------
    PRE-CONDITIONS
        graph - graph window widget
        list - list to display
        min - min of list
        max - max of list
    POST-CONDITION
        None
*/

/*
    Method displayListR: Class MainWindow
    -------------------------------------
    This function is called when ever
    the user wants to display the rational list.
    ------------------------------------
    PRE-CONDITIONS
        graph - graph window widget
        list - list to display
        min - min of list
        max - max of list
    POST-CONDITION
        None
*/

/*
    Method updateComboBoxItems: Class MainWindow
    -------------------------------------
    This function is called when ever
    the program needs to update
    the number of items in the combo box.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/

/*
    Method reset: Class MainWindow
    -------------------------------------
    This function is called when ever
    the user needs to reset there options.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/

/*
    Method push_back: Class MainWindow
    -------------------------------------
    This function is called when ever
    the user pushs back a node,
    and stores the value in the list, and
    displays the list.
    ------------------------------------
    PRE-CONDITIONS
        node - node of the list
    POST-CONDITION
        None
*/

/*
    Method push_front: Class MainWindow
    -------------------------------------
    This function is called when ever
    the user pushs front a node,
    and stores the value in the list, and
    displays the list.
    ------------------------------------
    PRE-CONDITIONS
        node - node of the list
    POST-CONDITION
        None
*/

/*
    Method addNode: Class MainWindow
    -------------------------------------
    This function is called when ever
    the program needs to add a node
    to the display.
    ------------------------------------
    PRE-CONDITIONS
        node - node of the list
    POST-CONDITION
        None
*/

/*
    Method showNodes: Class MainWindow
    -------------------------------------
    This function is called when ever
    the program needs to display all
    the nodes.
    ------------------------------------
    PRE-CONDITIONS
        graph - graph widget
        min - min to display
        max - max to display
    POST-CONDITION
        None
*/

/*
    Method getRational: Class MainWindow
    -------------------------------------
    This function is called when ever
    the user inserts a rational type node.
    ------------------------------------
    PRE-CONDITIONS
        readValue - read value to store
    POST-CONDITION
        Rational - returns a rational
        object of the passed value.
*/

/*
    Method resetScene: Class MainWindow
    -------------------------------------
    This function is called when ever
    the program needs to reset
    the scene and draw all the nodes
    again.
    ------------------------------------
    PRE-CONDITIONS
        graph - graph window widget
        min - min of list
        max - max of list
    POST-CONDITION
        None
*/
