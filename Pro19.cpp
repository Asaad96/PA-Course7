// Write a program to print the Minimum and Maximum Numbers in Matrix 

#include<iostream>
#include<iomanip>
#include<string>
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

void MinimumNumberinMatrix(int Matrix[3][3], short Rows, short Cols)
{
int Mini = Matrix[0][0];
for (short i = 0; i < Rows; i++)
{
 for (short j = 0; j < Cols; j++)
 {
    
    if (Matrix[i][j] < Mini)
        Mini = Matrix[i][j];
 }
 
}
cout << "Minimum Number is " << Mini << endl;

}


void MaximumNumberinMatrix(int Matrix[3][3], short Rows, short Cols)
{
int Max = Matrix[0][0];
for (short i = 0; i < Rows; i++)
{
 for (short j = 0; j < Cols; j++)
 {
    
    if (Matrix[i][j] > Max)
        Max = Matrix[i][j];
 }
 
}
cout << "Maximum Number is " << Max << endl;

}



int main()
{
    srand((unsigned)time(NULL));
    int Matrix[3][3];
    FillMatrix(Matrix, 3,3); 
    PrintMatrix(Matrix, 3,3);
    MinimumNumberinMatrix(Matrix ,3,3);
    MaximumNumberinMatrix(Matrix, 3, 3);

    return 0;

}