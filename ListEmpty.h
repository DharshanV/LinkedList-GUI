#ifndef LIST_EMPTY_H
#define LIST_EMPTY_H
#include <iostream>
using namespace std;

class ListEmpty {
private:
    string errorMessage;                            //IN/OUT - error message
public:
    /* CONSTRUCTOR & DESTRUCTOR */
	ListEmpty() {
		errorMessage = "Error occurred";
	}

    ListEmpty(string errorMessage) {                //IN/OUT - error message
		this->errorMessage = errorMessage;
	}

    /* ACCESSORS */
	string what() {
		return errorMessage;
	}
};
#endif // !LIST_EMPTY_H

/*
    ListEmpty class
     This is an LinkedList class and
     an object. It manages 1
     attributes: errorMessage
*/

/* CONSTRUCTOR & DESTRUCTOR */

/*
    Method ListEmpty: Class ListEmpty
    -------------------------------------
    This function is a constructor, and
    sets the error message to default
    error message
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/

/*
    Method ListEmpty: Class ListEmpty
    -------------------------------------
    This function is a constructor, and
    sets the error message to passed
    in message
    ------------------------------------
    PRE-CONDITIONS
        errorMessage - user error message
    POST-CONDITION
        None
*/

/* ACCESSORS */

/*
    Method what: Class ListEmpty
    -------------------------------------
    This function returns the error
    message
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        returns errorMessage
*/
