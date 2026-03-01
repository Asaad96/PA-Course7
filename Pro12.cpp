// Write a program to compare two matrices and check if they 
// are typical or not 


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

bool AreTypical (int Matrix[3][3], int Matrix2[3][3], short Rows, short Cols)
{
    for(short i = 0 ; i < Rows ; i++)
    {
        for(short j = 0; j < Cols; j++)
        {if (Matrix[i][j] != Matrix2[i][j])
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
    int Matrix[3][3];
    int Matrix2[3][3];
    FillMatrix(Matrix, 3,3);
    FillMatrix(Matrix2, 3,3);
    cout<< "Matrix1"<<endl;
    PrintMatrix(Matrix, 3,3);
    cout<< "Matrix2"<<endl;
    PrintMatrix(Matrix2, 3,3);
  
    if (AreTypical(Matrix, Matrix2, 3,3))
        cout << "\n YES: both Matrices are Typical";
    else 
        cout << "\n No: Matrices are Not Typical";


    return 0;
}