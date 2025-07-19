#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char op;
    char choice;

    cout << "🧮 Welcome to madhusudan the C++ Calculator!" << endl;

    do {
        // Input two numbers
        cout << "\nEnter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        // Choose operation
        cout << "Choose operation (+, -, *, /): ";
        cin >> op;

        // Perform calculation
        switch (op) {
            case '+':
                result = num1 + num2;
                cout << "✅ Result: " << num1 << " + " << num2 << " = " << result << endl;
                break;
            case '-':
                result = num1 - num2;
                cout << "✅ Result: " << num1 << " - " << num2 << " = " << result << endl;
                break;
            case '*':
                result = num1 * num2;
                cout << "✅ Result: " << num1 << " * " << num2 << " = " << result << endl;
                break;
            case '/':
                if (num2 == 0) {
                    cout << "❌ Error: Division by zero is not allowed." << endl;
                } else {
                    result = num1 / num2;
                    cout << "✅ Result: " << num1 << " / " << num2 << " = " << result << endl;
                }
                break;
            default:
                cout << "❌ Invalid operation!" << endl;
        }

        // Ask if user want to carry on
        cout << "\n🔁 Do you want to perform another calculation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "👋 Thank you for using the calculator. Goodbye!" << endl;
    return 0;
}
