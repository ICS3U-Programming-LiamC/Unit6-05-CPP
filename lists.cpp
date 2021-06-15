// Copyright (c) 2021 Liam Csiffary All rights reserved.
//
// Created by: Liam Csiffary
// Date: May June 15, 2021
// This program gets various numbers from the user then calculates the average

#include <iostream>
#include <list>

// global on purpose
float numCurrentAsFloat;

// calculates the average
int Average(std::list<int> list) {
    int total = 0;
    int average;

    for (int each : list) {
        std::cout << each << ", ";
        total = total + each;
    }
    average = total / list.size();
    return average;
}


// gets the user input, made this into a funciton
// because I needed to do it so many times
int UserInput() {
    std::string numCurrentStr;
    int numCurrent;

    std::cout << "What is the number: ";
    std::cin >> numCurrentStr;

    try {
        numCurrent = std::stoi(numCurrentStr);
        numCurrentAsFloat = std::stof(numCurrentStr);
        return numCurrent;
    } catch (std::invalid_argument) {
        std::cout << "This is not a valid number";
    }
}


// main function
int main() {
    std::list<int> numbers;
    std::string numCurrentStr;
    int numCurrent;
    int average;

    // gets the number for the first time
    std::cout << "What is the number: ";
    std::cin >> numCurrentStr;

    // make sure its a number
    try {
        numCurrent = std::stoi(numCurrentStr);
        numCurrentAsFloat = std::stof(numCurrentStr);

        // start the while loop
        while (numCurrent != -1) {
            // if greater than 100 stop
            if (numCurrent > 100) {
                std::cout << "Number can't be greater than 100\n";
                numCurrent = UserInput();
            // if less than 0 stop
            } else if (numCurrent < 0) {
                std::cout << "Number can't be less than 0\n";
                numCurrent = UserInput();
            // if a decimal stop
            } else if (numCurrent != numCurrentAsFloat) {
                std::cout << "Number can't be a decimal\n";
                numCurrent = UserInput();
            // otherwise add it to the list
            } else {
                numbers.push_back(numCurrent);
                numCurrent = UserInput();
            }
        }
        // print the the user
        average = Average(numbers);
        std::cout << "\nThe average is " << average;

    // catch invalids
    } catch (std::invalid_argument) {
        std::cout << "This is not a valid number";
    }
}
