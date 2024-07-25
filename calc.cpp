/*
    Name: Dallin Dutson
    Desc: Programming Lab 3 Calculator
          While running the program promts the user for mathematical operations and utilizes the fraction.h class and fraction.cpp
          functions to carry out these operations on two fraction objects.
 */
#include <iostream>
#include <climits>
#include <string>
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
                std::cin >> fract1;
                std::cin >> fract2;

                solution = fract1 + fract2;
                std::cout << solution << " = " << fract1 << " + " << fract2 << std::endl;
            } else if (menu == 'S' || menu == 's') {
                std::cin >> fract1;
                std::cin >> fract2;

                solution = fract1 - fract2;
                std::cout << solution << " = " << fract1 << " - " << fract2 << std::endl;
            } else if (menu == 'M' || menu == 'm') {
                std::cin >> fract1;
                std::cin >> fract2;

                solution = fract1 * fract2;
                std::cout << solution << " = " << fract1 << " * " << fract2 << std::endl;
            } else if (menu == 'D' || menu == 'd') {
                std::cin >> fract1;
                std::cin >> fract2;

                solution = fract1 / fract2;
                std::cout << solution << " = " << fract1 << " / " << fract2 << std::endl;
            } else if (menu == 'E' || menu == 'e') {
                running = false; // exit loop
                std::cout << "Program closing...\n";
            } else {
                throw "Invalid selection, please try again";
            }
        } catch (const char* err) {
            std::cin.clear(); // clear error
            std::cin.ignore(INT_MAX, '\n'); // clear input stream

            std::cout << "\n\nError: " << err << std::endl << std::endl;
        }
    } while (running);

    Fraction test(8);
    Fraction test2;

    solution = test + test2;
    std::cout << solution << " = " << test << " + " << test2 << std::endl;

    return 0;
}