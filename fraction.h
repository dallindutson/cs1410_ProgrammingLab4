/*
    Name: Dallin Dutson
    Desc: Programming Lab 3 Header file
          The program defines the Fraction class with it's functions and attributes, 
          as well as the gcd() function.
 */
#pragma once

#include <iostream>


int gcd(int u, int v);

class Fraction {
    private:
        int numerator;
        int denominator;

    public:
        Fraction(int numerator = 0, int denominator = 1);
        friend Fraction operator+(Fraction lhs, Fraction rhs);
        friend Fraction operator-(Fraction lhs, Fraction rhs);
        friend Fraction operator*(Fraction lhs, Fraction rhs);
        friend Fraction operator/(Fraction lhs, Fraction rhs);
        friend std::ostream& operator<<(std::ostream& os, Fraction& obj);
        friend std::istream& operator>>(std::istream& is, Fraction& obj);
};