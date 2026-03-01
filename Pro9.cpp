// Write ar progarm to fill a 3x3 matrix with random numbers
// print it, then print the middle row and middle col.

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// My Method

// int RandomNumber(int From, int To)
// {
//     int Number = rand() % (To - From + 1) + From;

//     return Number;
// }

// void FillMatrix(int arr[3][3], short Rows, short Cols)
// {
//     for (short i = 0; i < Rows; i++)
//     {
//         for (short j = 0; j < Cols; j++)
//         {
//             arr[i][j] = RandomNumber(1, 10);
//         }
//     }
// }

// void PrintMatrix(int arr[3][3], short Rows, short Cols)
// {
//     for (short i = 0; i < Rows; i++)
//     {
//         for (short j = 0; j < Cols; j++)
//         {
//             cout << setw(3) << arr[i][j] << "   ";
//         }
//         cout << endl;
//     }
// }

// void PrintMiddleRowMatrix (int arr[3][3] ,short Rows, short Cols )
// {

// cout << "Middle Row of The Matrix is: \n" ;

//     for(short j = 0 ; j < Cols ; j++)
//     {

//     cout << setw(3) << arr[1][j] << "   ";

//     }
//     cout << endl;

// }

// void PrintMiddleColMatrix (int arr[3][3] ,short Rows, short Cols )
// {

// cout << "Middle Row of The Matrix is: \n" ;

//     for(short i = 0 ; i < Rows ; i++)
//     {

//     cout << setw(3) << arr[i][1] << "   ";

//     }
//     cout << endl;

// }

// int main()
// {
//     srand((unsigned)time(NULL));
//     int arr[3][3];
//     int MRarr[3][3];
//     FillMatrix(arr, 3 ,3 );
//     cout <<  "The Full Matrix is:  \n";
//     PrintMatrix(arr, 3, 3 );
//     PrintMiddleRowMatrix(arr,3, 3);
//     PrintMiddleColMatrix(arr,3,3);
// return 0;
// }

int RandomNumber(int From, int To)
{
    // Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 10);
        }
    }
}

void PrintMatrix (int arr[3][3], short Rows, short Cols)
{
    for ( short i = 0; i < Rows ; i++)
    {
        for ( short j = 0 ; j < Cols ; j++)
        {
            printf(" %0*d ",2 , arr[i][j] );
        }
        cout << "\n";
    }
}

void PrintMiddleRowOfMatrix(int arr[3][3], short Rows , short Cols)
{
    short MiddleRow = Rows / 2 ;

    for (short j = 0 ; j < Cols ; j++)
    {
         printf ( " %0*d  ", 2, arr[MiddleRow][j]);
    }
    cout << "\n";
}

void PrintMiddleColOfMatrix(int arr[3][3], short Rows , short Cols)
{
    short MiddleCol = Cols / 2 ;

    for (short i = 0 ; i < Rows ; i++)
    {
         printf ( " %0*d  ", 2, arr[i][MiddleCol]);
    }
    cout << "\n";
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3];
    FillMatrixWithRandomNumbers(Matrix1, 3,3 );
    PrintMatrix(Matrix1, 3, 3);
    cout << "\nMiddle Row of Matrix1 is: \n";
    PrintMiddleRowOfMatrix(Matrix1, 3, 3);
    cout << "\nMiddle Col of Matrix1 is: \n";
    PrintMiddleColOfMatrix(Matrix1, 3, 3);

return 0 ;
}