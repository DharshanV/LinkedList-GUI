#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include <string>
#include <QDebug>
using namespace std;
class Rational
{
   private:
      int numer;                                        //IN/OUT - numerator
      int denom;                                        //IN/OUT - denomator
   public:
      /* CONSTRUCTOR & DESTRUCTOR */
      Rational();
      Rational(int numer);                              //IN/OUT - numerator
      Rational(int numer,                               //IN/OUT - numerator
               int denom);                              //IN/OUT - denomator
      /* ACCESSORS */
      const Rational add(const Rational& other) const;  //IN/OUT - other rational
      const Rational subtract(const Rational& other) const; //IN/OUT - other rational
      const Rational multiply(const Rational& other) const; //IN/OUT - other rational
      const Rational divide(const Rational& other) const;   //IN/OUT - other rational
      bool operator<(const Rational& other);            //IN/OUT - other rational
      bool operator==(const Rational& other);           //IN/OUT - other rational
      bool operator>=(const Rational& other);           //IN/OUT - other rational
      void display() const;
      string toString();
};
#endif // RATIONAL_H

/*
    Rational class
     This is an LinkedList class and
     an object. It manages 2
     attributes: numer, and denom.
*/

/* CONSTRUCTOR & DESTRUCTOR */

/*
    Method Rational: Class Rational
    -------------------------------------
    This function is a constructor, creates
    the rational object with
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/

/*
    Method Rational: Class Rational
    -------------------------------------
    This function is a constructor, creates
    the rational object with given numer
    and denom at 1.
    ------------------------------------
    PRE-CONDITIONS
        numer - numerator
    POST-CONDITION
        None
*/

/*
    Method Rational: Class Rational
    -------------------------------------
    This function is a constructor, creates
    the rational object with given numer
    and denom.
    ------------------------------------
    PRE-CONDITIONS
        numer - numerator
        denom - denomator
    POST-CONDITION
        None
*/

/* ACCESSORS */

/*
    Method add: Class _Node
    -------------------------------------
    This function is called when ever
    the user addes between two
    Rational objects.
    ------------------------------------
    PRE-CONDITIONS
        other - other rational
    POST-CONDITION
        Rational of the added value
*/

/*
    Method subtract: Class _Node
    -------------------------------------
    This function is called when ever
    the user subtracts between two
    Rational objects.
    ------------------------------------
    PRE-CONDITIONS
        other - other rational
    POST-CONDITION
        Rational of the subtracted value
*/

/*
    Method multiply: Class _Node
    -------------------------------------
    This function is called when ever
    the user multiplies between two
    Rational objects.
    ------------------------------------
    PRE-CONDITIONS
        other - other rational
    POST-CONDITION
        Rational of the multiplied value
*/

/*
    Method divide: Class _Node
    -------------------------------------
    This function is called when ever
    the user divides between two
    Rational objects.
    ------------------------------------
    PRE-CONDITIONS
        other - other rational
    POST-CONDITION
        Rational of the divied value
*/

/*
    Method operator<: Class _Node
    -------------------------------------
    This function is called when ever
    the user compares between two
    objects.
    ------------------------------------
    PRE-CONDITIONS
        other - other rational
    POST-CONDITION
        returns true of this is less than
        other
*/

/*
    Method operator==: Class _Node
    -------------------------------------
    This function is called when ever
    the user compares between two
    objects.
    ------------------------------------
    PRE-CONDITIONS
        other - other rational
    POST-CONDITION
        returns true of this is equals the
        other
*/

/*
    Method operator>=: Class _Node
    -------------------------------------
    This function is called when ever
    the user compares between two
    objects.
    ------------------------------------
    PRE-CONDITIONS
        other - other rational
    POST-CONDITION
        returns true of this is greater than
        the other.
*/

/*
    Method display: Class _Node
    -------------------------------------
    This function is called when ever
    the user wants to output a rational
    object
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        None
*/

/*
    Method toString: Class _Node
    -------------------------------------
    This function is called when ever
    the user wants the string of rational
    object
    ------------------------------------
    PRE-CONDITIONS
        None
    POST-CONDITION
        returns a string of rational object
*/
