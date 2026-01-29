#include <iostream>
using namespace std;

int main(){
    int row, col;
    cout << "Enter the size row and column: ";
    cin >> row >> col;
    int arr[row][col] = {};
    int choice, sum=0;

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cout << "Enter [" << i << "][" << j << "]th element";
            cin >> arr[i][j];
        }
        cout << "\n";
    }

    cout << "2D Array :\n";
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    
    cout << "Please Enter the row number you want to sum: ";
    cin >> choice;
    
    if (choice < 1 || choice > row){
        cout << "Please Enter valid range";
        return 1;
    }
    for (int i = 0; i < col; i++){
        sum += arr[choice-1][i];
    }

    cout << "Sum of row " << choice << " is " << sum << "\n";

    sum=0;
    cout << "Please Enter the column number you want to sum: ";
    cin >> choice;

    if (choice < 1 || choice > col){
        cout << "Please Enter valid range";
        return 1;
    }
    for (int i = 0; i < row; i++){
        sum += arr[i][choice-1];
    }

    cout << "Sum of column " << choice << " is " << sum << "\n";


    return 0;
}