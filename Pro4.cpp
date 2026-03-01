// write a program to fill 3x3 matrix with random numbers 
//and then print each col sum


#include<iostream>
#include<string>
#include<iomanip>

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

int ColSum(int arr[3][3], short Rows, short ColNumber)
{
    int Sum = 0; 
    for (short i = 0; i <= Rows - 1; i++)
    {
        Sum += arr[i][ColNumber];
    } 
    return Sum;
}

void PrintEachColSum (int arr[3][3], short Rows, short Cols)
{

    cout << "\n The following are the sum of each col in the matrix:\n";
    for (short j = 0; j < Cols ; j++)
    {
        cout << "Col " << j+1 << "Sum = " << ColSum(arr,Rows, j) << endl;
     }
    }

int main ()
{
 srand((unsigned)time(NULL));
 int arr[3][3];
 
 FillMatrixWithRandomNumber(arr, 3, 3);
 cout << "\n The following is a 3 x 3 random matrix: \n";
 PrintMatrixWithRandomNumber(arr, 3, 3);
 PrintEachColSum(arr,3, 3);
return 0;

}