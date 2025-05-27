#include <iostream>
using namespace std;

int main() {
    int num, digits = 0;
    cout << "Enter a number: ";
    cin >> num;

    if(num == 0){
        cout << "Enter valid number :- ";
        return 0;
    } else {
        while (num != 0) {
        num = num / 10;
        digits++;
        }
    }

    cout << "Total number of digits: " << digits << endl;

    return 0;
}
