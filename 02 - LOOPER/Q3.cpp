#include<iostream>
using namespace std;

int main (){
    int num, firstDigit, lastDigit;

    
    cout << "Enter a number: ";
    cin >> num;

    lastDigit = num % 10;
   
    int temp = num;
    while (temp >= 10) {
        temp /= 10;
    }
    firstDigit = temp;

    int sum = firstDigit + lastDigit;

    cout << "Sum: " << sum << endl;

    return 0;

    

    return 0;

}