// write a program to check if the matrix is Scalar or Not
// example 
// 9 0 0 
// 0 9 0
// 0 0 9

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int RandomNumber (int From, int To)
{
    int Number = rand()%(To - From + 1) + From;
    return Number;
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


bool IsScalar (int Matrix[3][3], short Rows, short Cols)
{   
    int FirstDiagElement = Matrix[0][0]; 
    for(short i = 0; i < Rows ; i ++ )
    {
        for(short j = 0 ; j < Cols ; j++)
        {
            if( i == j && Matrix[i][j] != FirstDiagElement )
            {
                return false;
            }
            

            if (i != j && Matrix[i][j] != 0)
            {
                return false;
            }
            
        }
    }
    return true;
}


int main()
{
    srand((unsigned)time(NULL));

   // int Matrix[3][3];
    int Matrix[3][3] = {{6,0,0,},{0,6,0},{0,0,6}};

   // FillMatrix(Matrix, 3, 3);
    PrintMatrix(Matrix, 3, 3);

    if (IsScalar(Matrix, 3, 3))
    cout << "\n YES: Matrix is Scalar.\n";
    else 
    cout << "\n No: Matrix is Not Scalar.\n";

    return 0;
}