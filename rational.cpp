#include "rational.h"

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
Rational::Rational()
{
    this->numer = 0;
    this->denom = 1;
}

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
Rational::Rational(int numer){
    this->numer = numer;
    this->denom = 1;
}

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
Rational::Rational(int numer, int denom){
    this->numer = numer;
    this->denom = denom;
}

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
const Rational Rational::add(const Rational& other) const{
    Rational temp;
    temp.numer = (numer*other.denom + denom * other.numer);
    temp.denom = denom*other.denom;
    return temp;
}

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
const Rational Rational::subtract(const Rational& other) const{
    Rational temp;
    temp.numer = (numer*other.denom - denom * other.numer);
    temp.denom = denom*other.denom;
    return temp;
}

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
const Rational Rational::multiply(const Rational& other) const{
    Rational temp;
    temp.numer = numer*other.numer;
    temp.denom = denom*other.denom;
    return temp;
}

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
const Rational Rational::divide(const Rational& other) const{
    Rational temp;
    temp.numer = numer*other.denom;
    temp.denom = denom*other.numer;
    return temp;
}

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
void Rational::display() const{
    cout<<numer<<"/"<<denom;
}

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

string Rational::toString(){
    return string(to_string(numer)+"/"+to_string (denom));
}

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
bool Rational::operator<(const Rational& other){
    double temp1 = (double)numer/denom;
    double temp2 = (double)other.numer/other.denom;
    if(temp1 < temp2){
        return true;
    }
    return false;
}

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
bool Rational::operator==(const Rational& other){
    if(this->numer == other.numer &&
            this->denom == other.denom){
        return true;
    }
    return false;
}

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
bool Rational::operator>=(const Rational& other){
    double temp1 = (double)numer/denom;
    double temp2 = (double)other.numer/other.denom;
    if(temp1 >= temp2){
        return true;
    }
    return false;
}
