/*
    Name: Dallin Dutson
    Desc: Programming Lab 3 Calculator
          While running the program promts the user for mathematical operations and utilizes the fraction.h class and fraction.cpp
          functions to carry out these operations on two fraction objects.
 */
#include <iostream>
#include "fraction.h"


int main() {
    Fraction fract1, fract2, solution;
    char menu;
    bool running;

    do {
        try {
            running = true;

            std::cout << "A add\nS subtract\nM multiply\nD divide\nE exit\n"; // Menu
            std::cin >> menu;

            if (menu == 'A' || menu == 'a') {
                fract1.Read();
                fract2.Read();

                solution = fract1.Add(fract2);
                solution.Print();
            } else if (menu == 'S' || menu == 's') {
                fract1.Read();
                fract2.Read();
                            
                solution = fract1.Sub(fract2);
                solution.Print();
            } else if (menu == 'M' || menu == 'm') {
                fract1.Read();
                fract2.Read();
                
                solution = fract1.Mult(fract2);
                solution.Print();
            } else if (menu == 'D' || menu == 'd') {
                fract1.Read();
                fract2.Read();
                
                solution = fract1.Div(fract2);
                solution.Print();
            } else if (menu == 'E' || menu == 'e') {
                running = false; // exit loop
                std::cout << "Program closing...\n";
            } else {
                std::cout << "Invalid selection, please try again\n";
            }
        } catch (const char* err) {
            std::cin.clear(); // clear error
            std::cin.ignore(INT_MAX, '\n'); // clear input stream

            std::cout << "\n\nError: " << err << std::endl << std::endl;
        }
    } while (running);

    return 0;
}