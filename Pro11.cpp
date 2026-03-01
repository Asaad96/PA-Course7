// Write a program to compare two matrices and check if they are equal or Not



#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int RandomNumber(int From, int To)
{
    int Num = rand()% (To - From + 1) + From;

    return Num;
}

void FillMatrix (int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows ; i++)
    {
        for (short j = 0 ; j < Cols ; j ++)
        {
            Matrix[i][j] = RandomNumber(1, 10);
        }
        cout << endl;
    }

}

void PrintMatrix (int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows ; i++)
    {
        for (short j = 0 ; j < Cols ; j ++)
        {
            cout << setw(3) << Matrix[i][j] << "  ";
        }
        cout << endl;
    }

}

// first method
// bool CheckMatrices(int Matrix[3][3], int Matrix2[3][3])
// {
//     string equal = " THEY ARE EQUAL \n";
//     string NotEqual = "NOT EQUAL \n";
//     if(Matrix == Matrix2)
//     {
//         cout << equal ;
//     }
//     cout <<  NotEqual;
//     return false;
// }

// second method

int SumOFMatrix(int Matrix[3][3], short Rows , short Cols)
{
    int Sum = 0; 
    for(short i= 0; i < Rows ; i++)
    {
        for (short j = 0 ; j < Cols ; j++)
        {
            Sum += Matrix[i][j]; 
        }
    }

    return Sum;
}

bool AreEqualMatrices(int Matrix[3][3], int Matrix2[3][3], short Rows, short Cols)
{
    return (SumOFMatrix(Matrix, Rows, Cols) == SumOFMatrix(Matrix2, Rows, Cols));
}

int main()
{
    srand((unsigned)time(NULL));
    int Matrix[3][3];
    int Matrix2[3][3];
    FillMatrix(Matrix, 3,3);
    FillMatrix(Matrix2, 3,3);
    cout<< "Matrix1"<<endl;
    PrintMatrix(Matrix, 3,3);
    cout<< "Matrix2"<<endl;
    PrintMatrix(Matrix2, 3,3);
    // CheckMatrices(Matrix,Matrix2);
   cout << "Sum of Mat1" << SumOFMatrix(Matrix, 3, 3) << endl;
   cout << "Sum of Mat2" << SumOFMatrix(Matrix2, 3, 3) << endl;

    if (AreEqualMatrices(Matrix, Matrix2, 3,3))
        cout << "\n YES: both Matrices are equal";
    else 
        cout << "\n No: Matrices are Not equal";


    return 0;
}