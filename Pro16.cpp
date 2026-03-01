// Write a program to check if the matrix is sparse or Not

// Matrix1  -> NOT Sparse    Matrix2 -> Sparse 
// 10 0 12                   0 0 12
// 20 15 1                   0 0  1
// 0  0  9                   0 0  9

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//My Method

// int RandomNumber(int From, int To)
// {
//     int Number = rand() % (To - From + 1) + From;
//     return Number;
// }

// void FillMatrix(int Matrix[3][3], short Rows, short Cols)
// {
//     for (short i = 0; i < Rows; i++)
//     {
//         for (short j = 0; j < Cols; j++)
//         {
//             Matrix[i][j] = RandomNumber(1, 10);
//         }
//         cout << endl;
//     }
// }

// void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
// {
//     for (short i = 0; i < Rows; i++)
//     {
//         for (short j = 0; j < Cols; j++)
//         {
//             cout << setw(3) << Matrix[i][j] << "  ";
//         }
//         cout << endl;
//     }
// }

// void countZero(int Matrix[3][3], short Rows, short Cols, short &Zerocounter, short &Numberscounter ) 
// {
//     Zerocounter = 0;
//     Numberscounter = 0;
    
//     for(short i = 0 ; i < Rows ; i ++)
//     {
//         for(short j = 0; j < Cols ; j++)
//         {
//             if(Matrix[i][j] == 0)
//                 Zerocounter++;
            
//             else Numberscounter++;
//         }
//     }

// }


// bool CheckSparseMatrix (int Matrix [3][3], short Rows, short Cols)
// {
//    short Zerocounter, Numbercounter;
//    countZero(Matrix , Rows, Cols,Zerocounter, Numbercounter);
//    return Zerocounter > Numbercounter;
// }


// int main()
// {
//     srand((unsigned)time(NULL));

//     //int Matrix[3][3];
//      int Matrix[3][3] = {{6,0,0,},{0, 6, 0},{0, 0, 6}};

//     //FillMatrix(Matrix, 3, 3);
//     PrintMatrix(Matrix, 3, 3);

//     if (CheckSparseMatrix(Matrix, 3, 3))
//         cout << "Matrix is Sparse \n";
//     else 
//         cout << "Matrix is NOT Sparse \n";
//     return 0;
// }

// Teacher's Method

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for(short i =0; i < Rows ; i++)
    {
        for (short j = 0; j < Cols ; j++)
        {
            cout << setw(3) << Matrix[i][j] << "   ";
        }
        cout << "\n";

    }
}

short CountNumberInMatrix(int Matrix[3][3], int Number, short Rows, short Cols)
{
    short NumberCount = 0;
    for(short i = 0 ; i < Rows; i++)
    {   for(short j = 0; j < Cols; j++)
        
        {
            if(Matrix[i][j] == Number)
            {
            NumberCount++;
            };
        }
        
    }
    return NumberCount;
}

bool IsSparseMatrix(int Matrix[3][3], short Rows , short Cols)
{
    short MatrixSize = Rows * Cols;
    return (CountNumberInMatrix(Matrix, 0, 3, 3)>= ceil((float)MatrixSize/2));
}

int main()
{
    int Matrix[3][3] = {{0,0,12}, {9,9,1}, {0,0,9}};

    cout << "\n Matrix:\n";
    PrintMatrix(Matrix, 3,3);

    if(IsSparseMatrix(Matrix, 3,3))
        cout<<"\n Yes: It is Sparse\n";
    else 
        cout <<"\n No: It is NOT Sparse \n";
    return 0;
    }