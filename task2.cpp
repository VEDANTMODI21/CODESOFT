#include <iostream>
using namespace std;

class Calculation {  // Class for calculation
public:
    void calculate() { // Function to calculate
        double num1, num2;
        char operation;
        cout << "********WELCOME TO CALCULATOR*********" << endl; // Displaying welcome message
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter an operation (+, -, *, /): "; // Ask for operation
        cin >> operation;
        cout << "Enter second number: ";
        cin >> num2;

        switch (operation) { // switch statement to handle different operations
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            if(num1<num2)  // Check if num1 is less than num2
                 cout << "Result: " << num2 - num1 << endl;
            else          // If num1 is not less than num2
                cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) // Check if num2 is not equal to 0
                cout << "Result: " << num1 / num2 << endl;
                else 
                cout << "Error: Division by zero!" << endl;
            break;
        default:
            cout << "Invalid operation!" << endl;
        }
    }
};

int main() {
    Calculation calc;  // Create an object of the Calculation class
    calc.calculate();  // Call the calculate() method
    cout<< "**********THANKS FOR USING MY CALCULATOR*********" <<endl; // Displaying thank you message
    return 0;
}


