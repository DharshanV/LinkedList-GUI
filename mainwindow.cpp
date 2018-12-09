#include "mainwindow.h"
#include "ui_mainwindow.h"

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
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    onStart();
}

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
MainWindow::~MainWindow()
{
    delete ui;
}

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
void MainWindow::onStart(){
    ui->radioInteger->setChecked (true);
    ui->comboBoxCopyListSelect->setEnabled (false);
    ui->radioNew->setAutoExclusive (false);
    ui->radioCopy->setAutoExclusive (false);
    ui->radioNew->setChecked (true);
}

//Display
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
template<typename T>
void MainWindow::displayList(MyGraphWidget*& graph,LinkedList<T>*& list, int min,int max){
    resetScene (graph,min,max);
    typename LinkedList<T>::Iterator it;
    for(it = list->begin ();it!=list->end ();++it){
        QString value = QString::number (*it);
        int nodeLength = value.length ()*10;
        if(nodeLength<30){ nodeLength = 30;}
        addNode (new _Node(nodeLength,30,value));
    }
    showNodes (graph,min,max);
}

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
void MainWindow::displayListS(MyGraphWidget*& graph, LinkedList<string>*& list, int min,int max){
    resetScene (graph,min,max);
    typename LinkedList<string>::Iterator it;
    for(it = list->begin ();it!=list->end ();++it){
        string temp(*it);
        QString value(temp.c_str ());
        int nodeLength = value.length ()*10;
        if(nodeLength<30){ nodeLength = 30;}
        addNode (new _Node(nodeLength,30,value));
    }
    showNodes (graph,min,max);
}

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
void MainWindow::displayListR(MyGraphWidget*& graph, LinkedList<Rational>*& list, int min,int max){
    resetScene (graph,min,max);
    typename LinkedList<Rational>::Iterator it;
    for(it = list->begin ();it!=list->end ();++it){
        Rational tempR = *it;
        string temp = tempR.toString ();
        QString value(temp.c_str ());
        int nodeLength = value.length ()*10;
        if(nodeLength<30){ nodeLength = 30;}
        addNode (new _Node(nodeLength,30,value));
    }
    showNodes (graph,min,max);
}

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
void MainWindow::on_buttonDisplay_clicked()
{
    int index = ui->tabLists->currentIndex ();
    int min = ui->comboBoxMin->currentText ().toInt ();
    int max = ui->comboBoxMax->currentText ().toInt ();
    QString tabType = ui->tabLists->tabText (index).split (" ")[0];
    MyGraphWidget* graph = &(ui->tabLists->currentWidget()->
                             findChild<MyGraphWidget*>()[0]);
    if(!tabType.compare ("Integer")){
        LinkedList<int>* intTemp = intVector.at(index);
        displayList(graph,intTemp,min,max);
    }
    else if(!tabType.compare ("Double")){
        index -= intVector.size ();
        LinkedList<double>* doubleTemp = doubleVector.at(index);
        displayList(graph,doubleTemp,min,max);
    }
    else if(!tabType.compare ("String")){
        index -= (intVector.size ()+doubleVector.size ());
        LinkedList<string>* stringTemp = stringVector.at(index);
        displayListS(graph,stringTemp,min,max);
    }
    else if(!tabType.compare ("Rational")){
        index -= (intVector.size ()+
                  doubleVector.size ()+
                  stringVector.size ());
        LinkedList<Rational>* rationalTemp = rationalVector.at(index);
        displayListR(graph,rationalTemp,min,max);
    }
}

//Linked list events
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
void MainWindow::on_buttonPushBack_clicked()
{
    int index = ui->tabLists->currentIndex ();
    QString tabType = ui->tabLists->tabText (index).split (" ")[0];
    QString readValue = ui->lineEditPushBack->text ();
    MyGraphWidget* graph = &(ui->tabLists->currentWidget()->
                             findChild<MyGraphWidget*>()[0]);
    bool ok = false;
    int nodeLength = readValue.length ()*10;
    if(nodeLength<30){ nodeLength = 30;}

    if(!tabType.compare ("Integer")){
        LinkedList<int>* intTemp = intVector.at(index);
        int value = readValue.toInt (&ok);
        if(ok) {
            intTemp->push_back (value);
            displayList(graph,intTemp,0,intTemp->length ()-1);
        }
    }
    else if(!tabType.compare ("Double")){
        index -= intVector.size ();
        LinkedList<double>* doubleTemp = doubleVector.at(index);
        double value = readValue.toDouble (&ok);
        if(ok) {
            doubleTemp->push_back (value);
            displayList(graph,doubleTemp,0,doubleTemp->length ()-1);
        }
    }
    else if(!tabType.compare ("String")){
        index -= (intVector.size ()+doubleVector.size ());
        LinkedList<string>* stringTemp = stringVector.at(index);
        stringTemp->push_back (readValue.toStdString ());
        displayListS(graph,stringTemp,0,stringTemp->length ()-1);
    }
    else if(!tabType.compare ("Rational")){
        index -= (intVector.size ()+ doubleVector.size ()+
                  stringVector.size ());
        LinkedList<Rational>* rationalTemp = rationalVector.at(index);
        Rational* temp = getRational(readValue);
        if(temp == NULL){ return; }
        rationalTemp->push_back (*temp);
        displayListR(graph,rationalTemp,0,rationalTemp->length ()-1);
    }
    updateComboBoxItems ();
}

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
void MainWindow::on_buttonPush_clicked()
{
    int index = ui->tabLists->currentIndex ();
    QString tabType = ui->tabLists->tabText (index).split (" ")[0];
    QString readValue = ui->lineEditPushFront->text ();
    MyGraphWidget* graph = &(ui->tabLists->currentWidget()->
                             findChild<MyGraphWidget*>()[0]);
    bool ok = false;
    int nodeLength = readValue.length ()*10;
    if(nodeLength<30){ nodeLength = 30;}

    if(!tabType.compare ("Integer")){
        LinkedList<int>* intTemp = intVector.at(index);
        int value = readValue.toInt (&ok);
        if(ok){
            intTemp->push_front (value);
            displayList(graph,intTemp,0,intTemp->length ()-1);
        }
    }
    else if(!tabType.compare ("Double")){
        index -= intVector.size ();
        LinkedList<double>* doubleTemp = doubleVector.at(index);
        double value = readValue.toDouble (&ok);
        if(ok){
            doubleTemp->push_front (value);
            displayList(graph,doubleTemp,0,doubleTemp->length ()-1);
        }
    }
    else if(!tabType.compare ("String")){
        index -= (intVector.size ()+doubleVector.size ());
        LinkedList<string>* stringTemp = stringVector.at(index);
        stringTemp->push_front (readValue.toStdString ());
        displayListS(graph,stringTemp,0,stringTemp->length ()-1);
    }
    else if(!tabType.compare ("Rational")){
        index -= (intVector.size ()+
                  doubleVector.size ()+
                  stringVector.size ());
        LinkedList<Rational>* rationalTemp = rationalVector.at(index);
        Rational* temp = getRational(readValue);
        if(temp == NULL){ return; }
        rationalTemp->push_front (*temp);
        displayListR(graph,rationalTemp,0,rationalTemp->length ()-1);
    }
    updateComboBoxItems ();
}

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
void MainWindow::on_buttonPopFront_clicked()
{
    int index = ui->tabLists->currentIndex ();
    MyGraphWidget* graph = &(ui->tabLists->currentWidget()->
                             findChild<MyGraphWidget*>()[0]);
    QString tabType = ui->tabLists->tabText (index).split (" ")[0];
    if(!tabType.compare ("Integer")){
        LinkedList<int>* intTemp = intVector.at(index);
        intTemp->pop_front ();
        displayList(graph,intTemp,0,intTemp->length ()-1);
    }
    else if(!tabType.compare ("Double")){
        index -= intVector.size ();
        LinkedList<double>* doubleTemp = doubleVector.at(index);
        doubleTemp->pop_front ();
        displayList(graph,doubleTemp,0,doubleTemp->length ()-1);
    }
    else if(!tabType.compare ("String")){
        index -= (intVector.size ()+doubleVector.size ());
        LinkedList<string>* stringTemp = stringVector.at(index);
        stringTemp->pop_front ();
        displayListS(graph,stringTemp,0,stringTemp->length ()-1);
    }
    else if(!tabType.compare ("Rational")){
        index -= (intVector.size ()+
                  doubleVector.size ()+
                  stringVector.size ());
        LinkedList<Rational>* rationalTemp = rationalVector.at(index);
        rationalTemp->pop_front();
        displayListR(graph,rationalTemp,0,rationalTemp->length ()-1);
    }
    updateComboBoxItems ();
}

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
void MainWindow::on_buttonRemoveDuplicates_clicked()
{
    int index = ui->tabLists->currentIndex ();
    QString tabType = ui->tabLists->tabText (index).split (" ")[0];
    MyGraphWidget* graph = &(ui->tabLists->currentWidget()->
                             findChild<MyGraphWidget*>()[0]);
    if(!tabType.compare ("Integer")){
        LinkedList<int>* intTemp = intVector.at(index);
        intTemp->remove_duplicates ();
        displayList(graph,intTemp,0,intTemp->length ()-1);
    }
    else if(!tabType.compare ("Double")){
        index -= intVector.size ();
        LinkedList<double>* doubleTemp = doubleVector.at(index);
        doubleTemp->remove_duplicates ();
        displayList(graph,doubleTemp,0,doubleTemp->length ()-1);
    }
    else if(!tabType.compare ("String")){
        index -= (intVector.size ()+doubleVector.size ());
        LinkedList<string>* stringTemp = stringVector.at(index);
        stringTemp->remove_duplicates ();
        displayListS(graph,stringTemp,0,stringTemp->length ()-1);
    }
    else if(!tabType.compare ("Rational")){
        index -= (intVector.size ()+
                  doubleVector.size ()+
                  stringVector.size ());
        LinkedList<Rational>* rationalTemp = rationalVector.at(index);
        rationalTemp->remove_duplicates ();
        displayListR(graph,rationalTemp,0,rationalTemp->length ()-1);
    }
    updateComboBoxItems ();
}

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
void MainWindow::on_buttonInsertSorted_clicked()
{
    int index = ui->tabLists->currentIndex ();
    QString tabType = ui->tabLists->tabText (index).split (" ")[0];
    MyGraphWidget* graph = &(ui->tabLists->currentWidget()->
                             findChild<MyGraphWidget*>()[0]);
    QString readValue = ui->lineEditInsertSorted->text ();
    bool ok;

    if(!tabType.compare ("Integer")){
        LinkedList<int>* intTemp = intVector.at(index);
        int value = readValue.toInt (&ok);
        if(ok){
            intTemp->insert_sorted (value);
            displayList(graph,intTemp,0,intTemp->length ()-1);
            updateComboBoxItems ();
        }
    }
    else if(!tabType.compare ("Double")){
        index -= intVector.size ();
        LinkedList<double>* doubleTemp = doubleVector.at(index);
        double value = readValue.toDouble (&ok);
        if(ok){
            doubleTemp->insert_sorted (value);
            displayList(graph,doubleTemp,0,doubleTemp->length ()-1);
            updateComboBoxItems ();
        }
    }
    else if(!tabType.compare ("String")){
        index -= (intVector.size ()+doubleVector.size ());
        LinkedList<string>* stringTemp = stringVector.at(index);
        string value = readValue.toStdString ();
        stringTemp->insert_sorted (value);
        displayListS(graph,stringTemp,0,stringTemp->length ()-1);
        updateComboBoxItems ();
    }
    else if(!tabType.compare ("Rational")){
        index -= (intVector.size ()+
                  doubleVector.size ()+
                  stringVector.size ());
        LinkedList<Rational>* rationalTemp = rationalVector.at(index);
        Rational* temp = getRational(readValue);
        if(temp == NULL){ return; }
        rationalTemp->insert_sorted (*temp);
        displayListR(graph,rationalTemp,0,rationalTemp->length ()-1);
        updateComboBoxItems ();
    }
}

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

void MainWindow::on_buttonSort_clicked()
{
    int index = ui->tabLists->currentIndex ();
    QString tabType = ui->tabLists->tabText (index).split (" ")[0];
    MyGraphWidget* graph = &(ui->tabLists->currentWidget()->
                             findChild<MyGraphWidget*>()[0]);
    if(!tabType.compare ("Integer")){
        LinkedList<int>* intTemp = intVector.at(index);
        intTemp->select_sort ();
        displayList(graph,intTemp,0,intTemp->length ()-1);
    }
    else if(!tabType.compare ("Double")){
        index -= intVector.size ();
        LinkedList<double>* doubleTemp = doubleVector.at(index);
        doubleTemp->select_sort ();
        displayList(graph,doubleTemp,0,doubleTemp->length ()-1);
    }
    else if(!tabType.compare ("String")){
        index -= (intVector.size ()+doubleVector.size ());
        LinkedList<string>* stringTemp = stringVector.at(index);
        stringTemp->select_sort ();
        displayListS(graph,stringTemp,0,stringTemp->length ()-1);
    }
    else if(!tabType.compare ("Rational")){
        index -= (intVector.size ()+
                  doubleVector.size ()+
                  stringVector.size ());
        LinkedList<Rational>* rationalTemp = rationalVector.at(index);
        rationalTemp->select_sort ();
        displayListR(graph,rationalTemp,0,rationalTemp->length ()-1);
    }
    updateComboBoxItems ();
}

//Nodes
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
void MainWindow::addNode(_Node* node){
    int size = nodeList.size ();
    if(size == 0){
        nodeList.push_back (node);
    }
    else{
        nodeList.push_back (node);
        _Node* previousNode = nodeList.at (size-1);
        int newSpawnX = previousNode->x () + previousNode->getWidth ()+25;
        node->setPos (newSpawnX,previousNode->y ());
        edgeList.push_back (new Edge(previousNode,node));
    }
}

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
void MainWindow::showNodes(MyGraphWidget*& graph,int min,int max){
    if(nodeList.size ()==0){
        return;
    }

    for(unsigned i=0;i<nodeList.size ();i++){
        graph->getScene ()->addItem (nodeList.at(i));
        nodeList.at(i)->hide ();
    }
    for(unsigned i=0;i<edgeList.size ();i++){
        graph->getScene ()->addItem (edgeList.at(i));
        edgeList.at(i)->hide ();
    }

    for(int i=min;i<=max;i++){
        nodeList.at(i)->show ();
    }
    if(edgeList.size ()==0){ return;}
    min--;
    max--;
    if(min<0){min =0;}
    if(max<0){max =0;}
    for(int i=min;i<=max;i++){
        edgeList.at (i)->show();
    }
    if(!edgeList.at(min)->getSource ()->isVisible ()){
       edgeList.at (min)->hide ();
    }
}

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
template<typename T>
void MainWindow::addTab(QString& callName,MyVector<LinkedList<T>*>& vectorList,int index){
    QString typeCount;
    QString tabName;
    string size;

    size = to_string(vectorList.size ());
    typeCount.append (size.c_str ());
    tabName.append (callName+" "+typeCount);

    LinkedList<T>* temp;
    if(ui->radioCopy->isChecked ()){
        int copyIndex = ui->comboBoxCopyListSelect->currentText ().toInt();
        LinkedList<T>* other = vectorList.at (copyIndex);
        temp = new LinkedList<T>(*other);
    }
    else{
        temp = new LinkedList<T>();
    }
    vectorList.push_back (temp);

    ui->tabLists->insertTab (index,new QWidget(),tabName);
    QWidget* tab = ui->tabLists->widget (index);
    QGridLayout* layout = new QGridLayout(tab);
    layout->addWidget (new MyGraphWidget(tab));
    ui->tabLists->setCurrentIndex (index);
    if(ui->radioCopy->isChecked ()){
        on_buttonDisplay_clicked();
    }
}

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
template<typename T>
void MainWindow::removeTab (MyVector<LinkedList<T>*>& vectorList,int index){
    vectorList.at (index)->~LinkedList ();
    vectorList.erase (index);
}

//RESETS
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
void MainWindow::on_radioInteger_clicked()
{
    reset();
}

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
void MainWindow::on_radioDouble_clicked()
{
    reset();
}

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
void MainWindow::on_radioString_clicked()
{
    reset();
}

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

void MainWindow::on_radioRational_clicked()
{
    reset();
}

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

void MainWindow::reset()
{
    ui->radioCopy->setChecked (false);
    ui->comboBoxCopyListSelect->clear ();
    ui->comboBoxCopyListSelect->setEnabled (false);
    ui->radioNew->setChecked (true);
}

//Other
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
void MainWindow::on_tabLists_tabCloseRequested(int index)
{
    QString tabType = ui->tabLists->tabText (index).split (" ")[0];
    int vectorIndex = index;
    if(!tabType.compare ("Integer")){
        removeTab (intVector,index);
    }
    else if(!tabType.compare ("Double")){
        vectorIndex -= intVector.size ();
        removeTab(doubleVector,vectorIndex);
    }
    else if(!tabType.compare ("String")){
        vectorIndex -= (intVector.size ()+doubleVector.size ());
        removeTab(stringVector,vectorIndex);
    }
    else if(!tabType.compare ("Rational")){
        vectorIndex -= (intVector.size ()+
                        doubleVector.size ()+
                        stringVector.size ());
        removeTab(rationalVector,vectorIndex);
    }
    ui->tabLists->removeTab (index);
}

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
void MainWindow::on_buttonNewList_clicked()
{
    int placeTabIndex = 0;
    QString radioName = getSelectedDataType ()->text ();
    if(!radioName.compare ("Integer")){
        placeTabIndex = intVector.size ();
        addTab(radioName,intVector,placeTabIndex);
    }
    else if(!radioName.compare ("Double")){
        placeTabIndex = intVector.size () + doubleVector.size ();
        addTab(radioName,doubleVector,placeTabIndex);
    }
    else if(!radioName.compare ("String")){
        placeTabIndex = intVector.size ()+doubleVector.size () + stringVector.size ();
        addTab(radioName,stringVector,placeTabIndex);
    }
    else if(!radioName.compare ("Rational")){
        placeTabIndex = intVector.size ()+doubleVector.size () +
                        stringVector.size () + rationalVector.size ();
        addTab(radioName,rationalVector,placeTabIndex);
    }
    reset();
}

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
void MainWindow::on_radioCopy_clicked()
{
    ui->comboBoxCopyListSelect->setEnabled (true);
    ui->buttonNewList->setEnabled (true);
    ui->radioNew->setChecked (false);

    int size =0;
    QString radioName = getSelectedDataType ()->text ();
    if(!radioName.compare ("Integer")){
        size = intVector.size ();
    }
    else if(!radioName.compare ("Double")){
        size = doubleVector.size ();
    }
    else if(!radioName.compare ("String")){
        size = stringVector.size ();
    }
    else if(!radioName.compare ("Rational")){
        size = rationalVector.size ();
    }
    for(int i=0;i<size;i++){
        ui->comboBoxCopyListSelect->addItem (QString::number (i));
    }
}

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
void MainWindow::on_radioNew_clicked()
{
    ui->buttonNewList->setEnabled (true);
    ui->radioCopy->setChecked (false);
    ui->comboBoxCopyListSelect->clear ();
    ui->comboBoxCopyListSelect->setEnabled (false);
}

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
void MainWindow::on_buttonReset_clicked()
{
    reset();
}

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
QRadioButton* MainWindow::getSelectedDataType(){
    if(ui->radioInteger->isChecked ()){
        return ui->radioInteger;
    }
    if(ui->radioDouble->isChecked ()){
        return ui->radioDouble;
    }
    if(ui->radioString->isChecked ()){
        return ui->radioString;
    }
    if(ui->radioRational->isChecked ()){
        return ui->radioRational;
    }
    return NULL;
}

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

void MainWindow::on_tabLists_currentChanged(int index)
{
    updateComboBoxItems ();
    index++;
}

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
void MainWindow::updateComboBoxItems(){
    int index = ui->tabLists->currentIndex ();
    QString tabType = ui->tabLists->tabText (index).split (" ")[0];
    int vectorIndex = index;
    int size = 0;
    ui->comboBoxMin->clear ();
    ui->comboBoxMax->clear ();

    if(!tabType.compare ("Integer")){
        size = intVector.at (vectorIndex)->length ();
    }
    else if(!tabType.compare ("Double")){
        vectorIndex -= intVector.size ();
        size = doubleVector.at (vectorIndex)->length ();
    }
    else if(!tabType.compare ("String")){
        vectorIndex -= (intVector.size ()+doubleVector.size ());
        size = stringVector.at (vectorIndex)->length ();
    }
    else if(!tabType.compare ("Rational")){
        vectorIndex -= (intVector.size ()+
                        doubleVector.size ()+
                        stringVector.size ());
        size = rationalVector.at (vectorIndex)->length ();
    }
    for(int i=0;i<size;i++){
        ui->comboBoxMin->addItem (QString::number (i));
        ui->comboBoxMax->addItem (QString::number (i));
    }
    ui->comboBoxMax->setCurrentIndex (size-1);
}

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
Rational* MainWindow::getRational(QString readValue){
    QString num;
    QString denom;
    int index = 0;
    int intNum;
    int intDenom = 0;
    bool ok;

    if(!readValue.contains (QChar('/'))) {
        int intNum = readValue.toInt (&ok);
        if(ok==true){
            return new Rational(intNum,1);
        }
        return NULL;
    }

    while(readValue.at (index)!=QChar('/')){
        num.append (readValue.at (index));
        index++;
    }

    if(index == readValue.size ()){ return NULL; }
    index++;

    while(index<readValue.size ()){
        denom.append (readValue.at (index));
        index++;
    }

    intNum = num.toInt (&ok);
    if(ok == false){ return NULL; }
    intDenom = denom.toInt (&ok);
    if(ok == false || intDenom == 0){ return NULL; }
    return new Rational(intNum,intDenom);
}

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
void MainWindow::resetScene(MyGraphWidget*& graph,int min,int max){
    if(max<min){
        graph->getScene ()->~QGraphicsScene ();
        nodeList.clear ();
        edgeList.clear ();
        graph->setNewScene (new QGraphicsScene());
        return;
    }
    graph->getScene ()->~QGraphicsScene ();
    nodeList.clear ();
    edgeList.clear ();
    graph->setNewScene (new QGraphicsScene());
}
