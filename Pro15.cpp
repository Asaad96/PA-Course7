// Write a program to count given number in matrix
// 9 1 12
// 0 9 1
// 0 9 9
// Enter the number to count in matrix? 9
// Number 9 count in Matrix is 4

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int RandomNumber(int From, int To)
{
    int Number = rand() % (To - From + 1) + From;
    return Number;
}

void FillMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Matrix[i][j] = RandomNumber(1, 10);
        }
        cout << endl;
    }
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << Matrix[i][j] << "  ";
        }
        cout << endl;
    }
}


int reqNum()
{
    int Num = 0;
    cout << "Please Enter the Number to count in Matrix! \n";
    cin >> Num;
    return Num;
}

void CountMatrix(int Matrix[3][3], short Rows, short Cols)
{
    int EnterNum = reqNum();
    int count = 0;

    for(short i = 0 ; i < Rows ; i++)
    {
        for(short j = 0 ; j < Cols; j++)
        {
            if (Matrix[i][j] == EnterNum)
            {
                count ++ ;
            }
        }
    }
    cout << "Number "<< EnterNum << " count in Matrix is " << count << endl;
   // return count ;
}

// bool IsScalar (int Matrix[3][3], short Rows, short Cols)
// {
//     int FirstDiagElement = Matrix[0][0];
//     for(short i = 0; i < Rows ; i ++ )
//     {
//         for(short j = 0 ; j < Cols ; j++)
//         {
//             if( i == j && Matrix[i][j] != FirstDiagElement )
//             {
//                 return false;
//             }

//             if (i != j && Matrix[i][j] != 0)
//             {
//                 return false;
//             }

//         }
//     }
//     return true;
// }

int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];
    // int Matrix[3][3] = {{6,0,0,},{0, 6, 0},{0, 0, 6}};

    FillMatrix(Matrix, 3, 3);
    PrintMatrix(Matrix, 3, 3);
    CountMatrix(Matrix, 3, 3);


    return 0;
}