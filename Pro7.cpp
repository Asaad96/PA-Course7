// Write a program to fill 3x3 matrix with ordered numbers
// and print it, then transpose matrix and print it

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void FillMatrix(int arr[3][3], short Rows, short Cols)
{
    int counter = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            counter++;
            arr[i][j] = counter;
        }
    }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << arr[i][j] << "   ";
        }
        cout << endl;
    }
}

void PrintMatrixTran(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << arr[j][i] << "   ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[3][3];
    FillMatrix(arr, 3, 3);
    cout << "The Matrix Before Transpose\n";
    PrintMatrix(arr, 3, 3);

    cout << "The Matrix After Transpose\n";
    PrintMatrixTran(arr,3,3);

    return 0;
}
