/*
    Name: Dallin Dutson
    Desc: Programming Lab 3 Header file
          The program defines the Fraction class with it's functions and attributes, 
          as well as the gcd() function.
 */
#pragma once


int gcd(int u, int v);

class Fraction {
    private:
        int numerator;
        int denominator;

    public:
        Fraction(int numerator = 0, int denominator = 1);
        Fraction Add(Fraction rhs);
        Fraction Sub(Fraction rhs);
        Fraction Mult(Fraction rhs);
        Fraction Div(Fraction rhs);
        void Print();
        void Read();
};