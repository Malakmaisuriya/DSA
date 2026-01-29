#include <iostream>
using namespace std;

int main(){
    int size;
    cout << "Enter the size of an Array: ";
    cin >> size;
    int arr[size] = {};

    for (int i = 0; i < size; i++){
        cout << "Enter [" << i << "] value: ";
        cin >> arr[i]; 
    }

    cout << "Array: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    int oddArr[size] = {};
    int count = 0;
    for (int i = 0; i< size; i++){
        if (arr[i]%2 != 0){
            oddArr[count++] = arr[i];
        }
    }

    cout << "\nOdd elements = ";
    for (int i = 0; i < count; i++){
        cout << oddArr[i] << " ";
    }

    int evenArray[size] = {};
    count = 0;
    for (int i = 0; i< size; i++){
        if (arr[i]%2 == 0){
            evenArray[count++] = arr[i];
        }
    }

    cout << "\nEven elements = ";
    for (int i = 0; i < count; i++){
        cout << evenArray[i] << " ";
    }
    return 0;
}