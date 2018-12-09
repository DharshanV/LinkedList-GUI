#ifndef MyVector_H
#define MyVector_H
#include <iostream>
#include <stdlib.h>
using namespace std;
template<typename T>
class MyVector
{
private:
    unsigned int sz;							//IN/OUT - size of the array
    unsigned int cap;							//IN/OUT - capcity of the array
    T* data;									//IN/OUT - pointer to the array
    void expand();
    void expand(unsigned int amount);			//IN/OUT - new amount of array capacity
public:
    /* CONSTRUCTOR & DESTRUCTOR */
    MyVector();
    MyVector(unsigned int size,                 //IN/OUT - size of array
        T value);								//IN/OUT - value of all elements
    ~MyVector();

    /* MUTATORS */
    void insert(unsigned int index,				//IN/OUT - index of the array
        T value);								//IN/OUT - value of each index
    void erase(unsigned int index);				//IN/OUT - index of the array
    void assign(unsigned int n,					//IN/OUT - new array size
        T value);								//IN/OUT - value at each index
    void push_back(T value);					//IN/OUT - value to add to array
    void pop_back();
    void clear();
    void resize(unsigned int size);				//IN/OUT - new size of the array
    void resize(unsigned int size,				//IN/OUT - new size of the array
        int value);								//IN/OUT - value at each index
    void reserve(unsigned int n);				//IN/OUT - new size of the array

    /* ACCESSORS */
    unsigned int size();
    unsigned int capacity();
    bool empty() const;
    const T& at(unsigned int index) const;	//IN/OUT - index of the array
    T& at(unsigned int index);				//IN/OUT - index of the array
    const T& front() const;
    T& front();
    const T& back() const;
    T& back();
};
#endif // MyVector_H
/*
    MyVector class
     This class a MyVector
     object. It manages 3
     attributes: sz (size),
     cap (capacity), data.

*/

/*
    Method MyVector: Class MyVector
    -------------------------------------
    This function is a constructor, and
    sets the data to null, sz and cap to 0.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/
template<typename T>
MyVector<T>::MyVector()
{
    data = NULL;
    sz = 0;
    cap = 0;
}

/*
    Method MyVector: Class MyVector
    -------------------------------------
    This function is a constructor
    creates a array of the passes size,
    and sets each element to a value.
    ------------------------------------
    PRE-CONDITIONS
        size - size of the array
        value - value of each element
    POST-CONDITION
        a pointer to the newly created
        array.
*/
template<typename T>
MyVector<T>::MyVector(unsigned int size,				//IN/OUT - size of array
    T value)										//IN/OUT - value of all elements
{
    sz = size;
    cap = size;
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = value;
    }
}

/*
    Method size: Class MyVector
    -------------------------------------
    This function gets the size of the
    array.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/
template<typename T>
unsigned int MyVector<T>::size()
{
    return sz;
}

/*
    Method capacity: Class MyVector
    -------------------------------------
    This function gets the capacity of the
    array.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/
template<typename T>
unsigned int MyVector<T>::capacity()
{
    return cap;
}

/*
    Method empty: Class MyVector
    -------------------------------------
    This function checks if the current
    array is empty or not.
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        returns true if its empty or false
        if its not.
*/
template<typename T>
bool MyVector<T>::empty() const
{
    if (sz == 0) {
        return true;
    }
    return false;
}

/*
    Method at: Class MyVector
    -------------------------------------
    This function gets the element
    at an index.
    ------------------------------------
    PRE-CONDITIONS
        index - index of the array
    POST-CONDITION
        returns an int at that
        index.
*/
template<typename T>
const T& MyVector<T>::at(unsigned int index) const	//IN/OUT - index of the array
{
    if (index >= sz) {
        exit(0);
    }
    return data[index];
}

/*
    Method at: Class MyVector
    -------------------------------------
    This function gets the element
    at an index.
    ------------------------------------
    PRE-CONDITIONS
        index - index of the array
    POST-CONDITION
        returns an int at that
        index.
*/
template<typename T>
T& MyVector<T>::at(unsigned int index)
{
    if (index >= sz) {
        exit(0);
    }
    return data[index];
}

/*
    Method front: Class MyVector
    -------------------------------------
    This function gets the element
    at the index 0.
    ------------------------------------
    PRE-CONDITIONS
        none
    POST-CONDITION
        none
*/
template<typename T>
const T& MyVector<T>::front() const
{
    return data[0];
}

/*
    Method front: Class MyVector
    -------------------------------------
    This function gets the element
    at the index 0.
    ------------------------------------
    PRE-CONDITIONS
        none
    POST-CONDITION
        none
*/
template<typename T>
T& MyVector<T>::front()
{
    return data[0];
}

/*
    Method back: Class MyVector
    -------------------------------------
    This function gets the element
    at the index size - 1.
    ------------------------------------
    PRE-CONDITIONS
        none
    POST-CONDITION
        none
*/
template<typename T>
const T& MyVector<T>::back() const
{
    return data[sz-1];
}

/*
    Method back: Class MyVector
    -------------------------------------
    This function gets the element
    at the index size - 1.
    ------------------------------------
    PRE-CONDITIONS
        none
    POST-CONDITION
        none
*/
template<typename T>
T& MyVector<T>::back()
{
    return data[sz - 1];
}

/*
    Method insert: Class MyVector
    -------------------------------------
    This function inserts an
    value at a index. It loops through
    the array starting at size - 1 and
    ending at index, and having the element
    at i equal to i - 1.
    ------------------------------------
    PRE-CONDITIONS
        index: index or the position to insert
        value: value of the element
    POST-CONDITION
        returns nothing.
        Changes the array size by 1 or even
        double the capacity if needed
*/
template<typename T>
void MyVector<T>::insert(unsigned int index, T value)
{
    if (index >= sz) {
        exit(0);
    }
    if (sz + 1 > cap) {
        this->expand();
    }
    T temp = data[index];
    for (int i = sz-1; i > index; i--) {
        data[i + 1] = data[i];
    }
    data[index + 1] = temp;
    data[index] = value;
    sz++;
}

/*
    Method insert: Class MyVector
    -------------------------------------
    This function deletes
    an element at an index. It loops
    through the array starting at index
    and ending at sz (size), and having the
    element at i equal to the next element
    i + 1. And setting the size--.
    ------------------------------------
    PRE-CONDITIONS
        index: index or the position to insert
    POST-CONDITION
        returns nothing.
        Changes the array size by 1.
*/
template<typename T>
void MyVector<T>::erase(unsigned int index)
{
    if (index >= sz) {
        exit(0);
    }
    for (unsigned i = index; i < sz-1; i++) {
        data[i] = data[i + 1];
    }
    sz--;
}

/*
    Method assign: Class MyVector
    -------------------------------------
    This function sets all
    the elements to the value. It first
    checks if the new size is bigger
    than capacity, than it creates a new
    array of that size.
    ------------------------------------
    PRE-CONDITIONS
        n: new size of the array
        value: value of each element
    POST-CONDITION
        returns nothing.
        Changes all the values to the passed
        value.
*/
template<typename T>
void MyVector<T>::assign(unsigned int n, T value)
{
    if (n > cap) {
        this->expand(n);
    }
    for (int i = 0; i < n; i++) {
        data[i] = value;
    }
    sz = n;
}

/*
    Method push_back: Class MyVector
    -------------------------------------
    This function sets the last
    element plus 1 to the passed value.
    It first checks if the size + 1 bigger
    than the capacity, than it creates a
    new array big enough to add a new
    value.
    ------------------------------------
    PRE-CONDITIONS
        value: value of the new element
    POST-CONDITION
        returns nothing.
        Changes the size to size + 1.
*/
template<typename T>
void MyVector<T>::push_back(T value)
{
    if (sz + 1 > cap) {
        this->expand();
    }
    data[sz] = value;
    sz++;
}

/*
    Method pop_back: Class MyVector
    -------------------------------------
    This function sets the size to
    size - 1. If the size goes below 0
    than the program exits.
    ------------------------------------
    PRE-CONDITIONS
        value: value of the new element
    POST-CONDITION
        returns nothing.
        Changes the size to size - 1.
*/
template<typename T>
void MyVector<T>::pop_back()
{
    if (sz == 0) {
        exit(0);
    }
    sz--;
}

/*
    Method expand: Class MyVector
    -------------------------------------
    This function sets the capacity to
    twice the previous size. It creates
    a brand new array of the new size, and
    gets the pointer to the first value.
    It later copys all value from data
    to the temp array. It later deletes
    and cleans up previous data, and
    assigns the data pointer to
    the temp pointer.
    ------------------------------------
    PRE-CONDITIONS
        none
    POST-CONDITION
        returns nothing.
        Changes the array capacity to
        double the previous capacity.
*/
template<typename T>
void MyVector<T>::expand()
{
    T* temp;
    if (cap == 0) {
        cap++;
        temp = new T[cap];
    }
    else {
        temp = new T[cap * 2];
        cap *= 2;
    }
    for (unsigned i = 0; i < sz; i++) {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
}

/*
    Method expand: Class MyVector
    -------------------------------------
    This function sets the capacity to
    passed value. It creates a brand new
    array of the new size, and
    gets the pointer to the first value.
    It later copys all value from data
    to the temp array. It later deletes
    and cleans up previous data, and
    assigns the data pointer to
    the temp pointer.
    ------------------------------------
    PRE-CONDITIONS
        amount: new size of the capacity.
    POST-CONDITION
        returns nothing.
        Changes the array capacity to
        new amount.
*/
template<typename T>
void MyVector<T>::expand(unsigned int amount)
{
    cap += amount;
    T* temp = new T[cap];
    for (int i = 0; i < sz; i++) {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
}

/*
    Method clear: Class MyVector
    -------------------------------------
    This function sets the size to
    size 0.
    ------------------------------------
    PRE-CONDITIONS
        none
    POST-CONDITION
        returns nothing.
        Changes to size to 0.
*/
template<typename T>
void MyVector<T>::clear()
{
    sz = 0;
    //delete[] this->data;
}

/*
    Method resize: Class MyVector
    -------------------------------------
    This function resizes the
    entire array to a new size. If the
    new size smaller than original size, than
    it sets sz to new size. It also checks
    if the new size is inbetween the original
    size and the capacity, if this is true
    than it sets all elements from sz to
    size to 0.
    ------------------------------------
    PRE-CONDITIONS
        size: size of the new array
    POST-CONDITION
        returns nothing.
        Changes to sz to passed size.
*/
template<typename T>
void MyVector<T>::resize(unsigned int size)
{
    if (size < sz) {
        sz = size;
    }
    else if (size > sz && size < cap) {
        for (int i = sz; i < size; i++) {
            data[i] = 0;
        }
        sz = size;
    }
    else if (size > sz && size > cap) {
        while (cap <= size) {
            this->expand();
        }
        for (int i = sz; i < size; i++) {
            data[i] = 0;
        }
        sz = size;
    }
}

/*
    Method resize: Class MyVector
    -------------------------------------
    This function resizes the
    entire array to a new size. If the
    new size smaller than original size, than
    it sets sz to new size. It also checks
    if the new size is inbetween the original
    size and the capacity, if this is true
    than it sets all elements from sz to
    size to value.
    ------------------------------------
    PRE-CONDITIONS
        size: size of the new array
        value: value of new element
    POST-CONDITION
        returns nothing.
        Changes to sz to passed size,
        and each new element to value.
*/
template<typename T>
void MyVector<T>::resize(unsigned int size, int value)
{
    if (size < sz) {
        sz = size;
    }
    else if (size > sz && size < cap) {
        for (int i = sz; i < size; i++) {
            data[i] = value;
        }
        sz = size;
    }
    else if (size > sz && size > cap) {
        while (cap <= size) {
            this->expand();
        }
        for (int i = sz; i < size; i++) {
            data[i] = value;
        }
    }
}

/*
    Method reserve: Class MyVector
    -------------------------------------
    This function resizes the
    capacity to n (new capacity). It does
    nothing if the new capacity is less
    than size. It sets all new elements to
    0.
    ------------------------------------
    PRE-CONDITIONS
        n: new capacity of the array
    POST-CONDITION
        returns nothing.
        Changes the capacity to n.
*/
template<typename T>
void MyVector<T>::reserve(unsigned int n)
{
    int temp = 0;
    if (n > cap) {
        if (cap*2 < n) {
            this->expand(n - cap);
        }
        else {
            this->expand();
        }
        for (int i = sz; i < cap; i++) {
            data[i] = 0;
        }
    }
}

/*
    Method ~MyVector: Class MyVector
    -------------------------------------
    This function delets the dynamic
    allocated array (data).
    ------------------------------------
    PRE-CONDITIONS
        none
    POST-CONDITION
        returns nothing.
        deletes data.
*/
template<typename T>
MyVector<T>::~MyVector()
{
    delete[] data;
}
