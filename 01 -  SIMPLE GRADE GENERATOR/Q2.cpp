#include<iostream>

using namespace std;

int main (){
char grade;

    cout << "Enter Your grade :- ";
    cin >> grade;

    switch (grade){
        case 'A':
            cout << "excellent work !";  
            break;
        case 'B' :
            cout << "Well done";
            break;
        case 'C' :
            cout << "Good Job";  
            break;
        case 'D' :
            cout << "You Passed, but you could do better";  
            break;
        case 'F' :
            cout << "Sorry, you failed";  
            cout << "Please try again next time ";
            break;

        default:
            cout << "Pls Enter valid grade :- ";
            break;
    }

    return 0;
}