#include <iostream>
using namespace std;


void add(float, float);
void subtract(float, float);
void multiply(float, float);
void divide(float, float);
void mod(float, float);
void checkPalindrome(int);

int main() {
    float num1, num2;
    int choice;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Addition (+)\n";
        cout << "2. Subtraction (-)\n";
        cout << "3. Multiplication (*)\n";
        cout << "4. Division (/)\n";
        cout << "5. Modulo (%)\n";
        cout << "6. Check Palindrome\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: add(num1, num2); break;
            case 2: subtract(num1, num2); break;
            case 3: multiply(num1, num2); break;
            case 4: divide(num1, num2); break;
            case 5: mod(num1, num2); break;
            case 6: {
                int pal;
                cout << "Enter a number to check for palindrome: ";
                cin >> pal;
                checkPalindrome(pal);
                break;
            }
            case 7: cout << "Thank you for using the program!\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}


void add(float a, float b) {
    cout << "Result: " << a << " + " << b << " = " << a + b << "\n";
}

void subtract(float a, float b) {
    cout << "Result: " << a << " - " << b << " = " << a - b << "\n";
}

void multiply(float a, float b) {
    cout << "Result: " << a << " * " << b << " = " << a * b << "\n";
}

void divide(float a, float b) {
    if (b != 0)
        cout << "Result: " << a << " / " << b << " = " << a / b << "\n";
    else
        cout << "Error: Division by zero is not allowed.\n";
}

void mod(float a, float b) {
    if ((int)b != 0)
        cout << "Result: " << (int)a << " % " << (int)b << " = " << ((int)a % (int)b) << "\n";
    else
        cout << "Error: Modulo by zero is not allowed.\n";
}

void checkPalindrome(int n) {
    int reversed = 0, original = n;

    while (n != 0) {
        reversed = reversed * 10 + (n % 10);
        n /= 10;
    }

    if (reversed == original)
        cout << original << " is a Palindrome number.\n";
    else
        cout << original << " is NOT a Palindrome number.\n";
}
