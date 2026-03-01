// Write a program to fill 3x3x3 matrix with random numbers

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int RandomNumber (int From , int To)
{
 int Number = rand()%(To - From + 1) + From;

 return Number;
}

void FillMatrixWithRandomNumber (int arr[3][3][3], short Rows, short Cols, short depth)
{
    for (short i = 0 ;  i < Rows ; i++ )
    {
        for (short j = 0; j < Cols ; j++ )
        {
            for (short k = 0 ; k < depth ; k++)
            {
                arr[i][j][k] = RandomNumber(1,100);
            }
            
        }
    }
}

void PrintMatrixWithRandomNumber (int arr[3][3][3], short Rows, short Cols, short depth )
{
    for (short i = 0 ;  i < Rows ; i++ )
    {   
        for (short j = 0; j < Cols ; j++ )
        {
            for (short k = 0 ; k < depth ; k ++)
               {cout << setw(3) << arr[i][j][k]<< "   ";}
        } cout << endl;

        cout << endl;
    }
}

int main ()
{

    int arr[3][3][3];
    srand((unsigned)time(NULL));
    FillMatrixWithRandomNumber(arr, 3 , 3, 3);
    cout << "Your Array is \n";
    PrintMatrixWithRandomNumber(arr, 3, 3, 3);


return 0;
}