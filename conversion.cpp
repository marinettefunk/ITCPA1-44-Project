#include <iostream>
#include <iomanip>
#include <limits>
#include "calculation.h"

using namespace std;

// Function to display the menu with program options.
void menu() {
    cout << "1. Convert Fahrenheit to Celsius" << endl;
    cout << "2. Convert USD to ZAR" << endl;
    cout << "3. Convert MPH to KMH" << endl;
    cout << "4. Exit" << endl;
    cout << endl;
}

// Function to facilitate program execution based on the option chosen from the menu.
void option() {
    int choice;
    bool running = true;

    do {
        menu();
        cout << "Choose an option (1-4): ";

        if (!(cin >> choice)) {
            inputError("Invalid input. Please enter an integer option (1-4).");
        } else {
            switch (choice) {
                case 1: {
                    temperature();
                    break;
                }
                case 2: {
                    currency();
                    break;
                }
                case 3: {
                    speed();
                    break;
                }
                case 4:
                    running = false;
                    break;
                default:
                    cout << "Invalid option. Please enter an integer option (1-4)." << endl;
                    break;
            }
        }

    } while (running);
}