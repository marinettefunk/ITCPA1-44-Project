#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

// Constant variables declared:
const float FAHRENHEIT_OFFSET = 32;
const float CELSIUS_CONVERSION_FACTOR = 5.0 / 9.0;
const float USD_TO_ZAR_CONVERSION = 18.5;
const float MILE_TO_KMH_CONVERSION = 1.609;

// Function to handle input errors.
void inputError(const string& errorMessage) {
    cin.clear(); // Clear error flag.
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore all remaining input until new line.
    cout << errorMessage << endl; // Message to be displayed when invalid input is entered.
}

// Function to convert Fahrenheit to Celsius.
float temperature() {
    float fahrenheit;
    float celsius;

    do {
        cout << "Enter the value to convert (Fahrenheit): ";
        if (!(cin >> fahrenheit)) {
            inputError("Invalid input. Please enter a number.");
        } else {
            celsius = (fahrenheit - FAHRENHEIT_OFFSET) * CELSIUS_CONVERSION_FACTOR;
            cout << fixed << setprecision(2) << fahrenheit << " Fahrenheit is " << celsius << " Celsius." << endl;
            cout<<endl;
            break;
        }

    } while (true);

    return celsius;
}

// Function to convert USD to ZAR.
float currency() {
    float USD;
    float ZAR;

    do {
        cout << "Enter the value to convert (USD): ";
        if (!(cin >> USD) || USD < 0) {
            inputError("Invalid input. Please enter positive a number.");
        } else {
            ZAR = USD * USD_TO_ZAR_CONVERSION;
            cout << fixed << setprecision(2) << USD << " USD is " << ZAR << " ZAR." << endl;
            cout<<endl;
            break;
        }

    } while (true);

    return ZAR;
}

// Function to convert MPH to KMH.
float speed() {
    float MPH;
    float KMH;

    do {
        cout << "Enter the value to convert (MPH): ";
        if (!(cin >> MPH) || MPH < 0) {
            inputError("Invalid input. Please enter a positive number.");
        } else {
            KMH = MPH * MILE_TO_KMH_CONVERSION;
            cout << fixed << setprecision(2) << MPH << " MPH is " << KMH << " KMH." << endl;
            cout<<endl;
            break;
        }
    } while (true);

    return KMH;
}