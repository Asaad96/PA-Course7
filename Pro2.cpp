// write a program to fill a 3x3 matrix with random numbers then print
// each row sum

// Row 1 Sum = ***
// Row 2 Sum = ***
// Row 3 Sum = ***

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To)
{
    int Number = rand() % (To - From + 1) + From;

    return Number;
}

void FillMatrixWithRandomNumber(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {

            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrixWithRandomNumber(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {

            cout << setw(3) << arr[i][j] << "   ";
        }
        cout << endl;

        cout << endl;
    }
}

void SumRowsMatrixNumbers(int arr[3][3], short Rows, short Cols)
{
    int Sum = 0;
    for (short i = 0; i < Rows; i++)
    {

        for (short j = 0; j < Cols; j++)
        { 
            Sum = Sum + arr[i][j];
        }
        cout << "Row " << i << " Sum = " <<   Sum  << endl;
        cout << endl;
        Sum = 0;
    }
}

int main()
{

    int arr[3][3];
    srand((unsigned)time(NULL));
    FillMatrixWithRandomNumber(arr, 3, 3);
    cout << "Your Array is \n";
    PrintMatrixWithRandomNumber(arr, 3, 3);
    cout << "The following are the sum of each row in the matrix: \n";
    SumRowsMatrixNumbers(arr, 3, 3);

    return 0;
}