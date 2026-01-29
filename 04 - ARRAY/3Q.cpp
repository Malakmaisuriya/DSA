#include <iostream>
using namespace std;

int main(){
    int size;
    cout << "Enter the size of an Array: ";
    cin >> size;
    int arr[size] = {};
    int max = arr[0];
    int min = arr[0];
    
    for (int i = 0; i < size; i++){
        cout << "Enter [" << i << "] value: ";
        cin >> arr[i]; 
    }

    cout << endl;
    cout << "Array: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    
    for (int i = 1; i < size; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    cout << endl;
    cout << "Max element: " << max;

    
    for (int i = 1; i < size; i++){
        if (arr[i] < min){
            min = arr[i];
        }
    }
    cout << endl;
    cout << "Min element: " << min;
    return 0;
}