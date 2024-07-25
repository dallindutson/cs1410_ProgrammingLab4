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
Fraction Fraction::Add(Fraction rhs) {
    int newNumerator = (numerator * rhs.denominator) + (denominator * rhs.numerator); // cross-multiply and add numerators
    int newDenominator = (denominator * rhs.denominator); // multiply denominators straight across
    
    return Fraction(newNumerator, newDenominator); // automatically reduces answer
}

// Sub function for subtraction
Fraction Fraction::Sub(Fraction rhs) {
    int newNumerator = (numerator * rhs.denominator) - (denominator * rhs.numerator); // cross-multiply and subtract numerators
    int newDenominator = (denominator * rhs.denominator); // multiply denominators straight across

    return Fraction(newNumerator, newDenominator); 
}

// Mult function for multiplication
Fraction Fraction::Mult(Fraction rhs) {
    int newNumerator = (numerator * rhs.numerator); // multiply straight across
    int newDenominator = (denominator * rhs.denominator); // multiply straight across

    return Fraction(newNumerator, newDenominator);
}

// Div function to divide
Fraction Fraction::Div(Fraction rhs) {
    if (rhs.numerator == 0) {
        throw "Zero division error"; // throw zero division error
    }

    int newNumerator = (numerator * rhs.denominator); // flip second fraction
    int newDenominator = (denominator * rhs.numerator);

    return Fraction(newNumerator, newDenominator);
}

// Print function to display results
void Fraction::Print() {
    if (denominator == 1) {
        std::cout << "Solution: " << numerator << std::endl << std::endl; // if whole number, only output numerator
    } else {
        std::cout << "Solution: " << numerator << "/" << denominator << std::endl << std::endl;
    }
}

// Read function for input
void Fraction::Read() {
    std::cout << "Please enter a value for the numerator: ";
    std::cin >> numerator;
    if (!std::cin) {
        throw "Invalid input!"; // throw error for invalid input
    } 
    
    std::cout << "Please enter a value for the denominator: ";
    std::cin >> denominator;
    if (!std::cin) {
        throw "Invalid input!"; // throw error for invalid input
    } else if (denominator == 0) {
        throw "The denominator cannot be 0"; // denominator cannot be zero
    }    
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