// Write a program to check if the matrix i identity or Not مصفوفة قطرية

// 1 0 0 mt[0][0] 
// 0 1 0 mt[1][1]
// 0 0 1 mt[2][2]

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

// My Method
// bool IsIdentity(int Matrix2[3][3], short Rows , short Cols)
// {
//     for(short i = 0 ; i < Rows ; i++)
//     {
//         for(short j = 0 ; j < Cols ; j++)
//         {
//             if (i == j)
//             {
//                 if (Matrix2[i][j] != 1)
//                 return false;
//             }
//         }
//     }

//     return true;
// }

// Teacher's Method
bool IsidentityMartix( int Matrix[3][3], short Rows, short Cols)
{
    for ( short i = 0 ; i < Rows ; i++)
    {
        for(short j = 0; j < Cols; j ++ )
        {   
            // Check for diagonal element
            if (i == j && Matrix[i][j] != 1)
            {
                return false; 
            }
            else if ( i != j && Matrix[i][j] != 0)
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
    //int Matrix[3][3]= {{1,0,0},{0,1,0}, {0,0,1}};
    FillMatrix(Matrix, 3,3);
    
    cout<< "Matrix1"<<endl;
    PrintMatrix(Matrix, 3,3);
    // cout<< "Matrix2"<<endl;
    // PrintMatrix(Matrix2, 3,3);
    
    if (IsidentityMartix(Matrix, 3,3))
        cout << "\n YES: Matrix is Identity";
    else 
        cout << "\n No:  Matrix is NOT Identity";


    return 0;
}