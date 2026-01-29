#include<iostream>

using namespace std;

int main (){
float score;
char grade;

    cout << "Enter Your score :- ";
    cin >> score;

    if (score >= 90){
        cout << "Your grade is A";
        cout << "excellent work !";
    } else if (score >= 80){
        cout << "Your grade is B";
        cout << "Well done";
    } else if (score >= 70){
        cout << "Your grade is C";
        cout << "Good Job";
    } else if (score >= 60){
        cout << "Your grade is D";
    } else if (score >= 50){
        cout << "Your grade is E";
        cout << "You Passed, but you could do better";
    } else if (score <= 40){
        cout << "Your grade is F";
    }

    score = grade ;


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