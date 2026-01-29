
#include <iostream>
using namespace std;

int main(){
    
    int size = 0;
    cout << "Enter the size of an Array: ";
    cin >> size;

    int arr[size] = {};
    int negcount = 0;
    int poscount = 0;

    for (int i = 0; i < size; i++){
        cout << "Enter ["<< i <<"] value: ";
        cin >> arr[i]; 
    }

    cout << "\nArray :- ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    for (int i = 0; i < size; i++){
        if (arr[i] < 0) {
            cout << arr[i] << " ";
            negcount = negcount + 1;
        }
    }
    cout << "\nNegative elements :- " << negcount;

    cout << "\nPositive elements :- = ";
    for (int i = 0; i < size; i++){
        if (arr[i] > 0){
            cout << arr[i] << " ";
            poscount  = poscount + 1; 
        }
    }
    cout << "\nNumber of positive elements: " << poscount;

    return 0;
}
