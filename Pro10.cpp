// Write a program to fill two 3x3 matrix with random numbers 
// and then write a function to sum all numbers in this matrix & Print it

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int RandomNumber(int From, int To)
{
    int Num = rand()% (To - From + 1) + From;

    return Num;
}

void FillMatrix (int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows ; i++)
    {
        for (short j = 0 ; j < Cols ; j ++)
        {
            arr[i][j] = RandomNumber(1, 10);
        }
        cout << endl;
    }

}

void PrintMatrix (int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows ; i++)
    {
        for (short j = 0 ; j < Cols ; j ++)
        {
           cout << setw(3) << arr[i][j] << "  ";
        }
        cout << endl;
    }

}


// void SumMatrix (int arr[3][3], short Rows, short Cols)
// {
//     int Sum = 0;
//         for (short i = 0; i < Rows ; i++)
//     {
//         for (short j = 0 ; j < Cols ; j ++)
//         {
//            Sum = Sum + arr[i][j];
//         }
    
        
//     }
// cout << " The Sum of all elements of the matrix is : " << Sum;
// cout << endl;
// }



int SumOFMatrix(int arr[3][3], short Rows , short Cols)
{
    int Sum = 0; 
    for(short i= 0; i < Rows,  i++)
    {
        for (short j = 0 ; j < Cols ; j++)
        {
            Sum += arr[i][j]; 
        }
    }

    return Sum;
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[3][3];
    //int Sum = 0; 

    FillMatrix(arr, 3, 3);
    cout << "The Full Matrix is: \n";
    PrintMatrix(arr, 3, 3);
    //SumMatrix(arr, 3 , 3);

    cout << "\n Sum of the Matrix is : " <<SumOFMatrix(arr, 3, 3);
    return 0;
}