/*
    Name: Dallin Dutson
    Desc: Programming Lab 3 Functions
          This program defines the functions of the Fraction class, including all four arithmetic operations, 
          a print and read function, and the gcd() function.
 */
#include <iostream>
#include "fraction.h"


// Constructor
Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
    int common = gcd(numerator, denominator); // finds common denom
    this->numerator /= common; // divides by common denom
    this->denominator /= common;
}

// Add function for addition
Fraction operator+(Fraction lhs, Fraction rhs) {
    int newNumerator = (lhs.numerator * rhs.denominator) + (lhs.denominator * rhs.numerator); // cross-multiply and add numerators
    int newDenominator = (lhs.denominator * rhs.denominator); // multiply denominators straight across
    
    return Fraction(newNumerator, newDenominator); // automatically reduces answer
}

// Sub function for subtraction
Fraction operator-(Fraction lhs, Fraction rhs) {
    int newNumerator = (lhs.numerator * rhs.denominator) - (lhs.denominator * rhs.numerator); // cross-multiply and subtract numerators
    int newDenominator = (lhs.denominator * rhs.denominator); // multiply denominators straight across

    return Fraction(newNumerator, newDenominator); 
}

// Mult function for multiplication
Fraction operator*(Fraction lhs, Fraction rhs) {
    int newNumerator = (lhs.numerator * rhs.numerator); // multiply straight across
    int newDenominator = (lhs.denominator * rhs.denominator); // multiply straight across

    return Fraction(newNumerator, newDenominator);
}

// Div function to divide
Fraction operator/(Fraction lhs, Fraction rhs) {
    if (rhs.numerator == 0) {
        throw "Zero division error"; // throw zero division error
    }

    int newNumerator = (lhs.numerator * rhs.denominator); // flip second fraction
    int newDenominator = (lhs.denominator * rhs.numerator);

    return Fraction(newNumerator, newDenominator);
}

// Print function to display results
std::ostream& operator<<(std::ostream& out, Fraction& obj) {
    if (obj.denominator == 1) {
        std::cout << obj.numerator; // if whole number, only output numerator
    } else {
        std::cout << obj.numerator << "/" << obj.denominator;
    }

    return out;
}

// Read function for input
std::istream& operator>>(std::istream& in, Fraction& obj) {
    std::cout << "Please enter a value for the numerator: ";
    std::cin >> obj.numerator;
    if (!std::cin) {
        throw "Invalid input!"; // throw error for invalid input
    } 
    
    std::cout << "Please enter a value for the denominator: ";
    std::cin >> obj.denominator;
    if (!std::cin) {
        throw "Invalid input!"; // throw error for invalid input
    } else if (obj.denominator == 0) {
        throw "The denominator cannot be 0"; // denominator cannot be zero
    }

    return in;
}

// Euclid's Algorithm for finding the greatest common divisor
int gcd(int u, int v) {
    u = (u < 0) ? -u : u; // make u non-negative
    v = (v < 0) ? -v : v; // make v non-negative
    while (u > 0) {
        if (u < v) {
            int t = u; // swap u and v 
            u = v;
            v = t;
        } // end if
        u -= v;
    } // end while
    return v; // the GCD of u and v
} // end function