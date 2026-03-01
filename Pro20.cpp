// Write a program to check if the matrix is Palindrome or NOT

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

int ReverseNumber(int Number)
{
    int Remainder = 0;
    int Number2 = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        Number2 = Number2 * 10 + Remainder;
    }

    return Number2;
}

void IsPalindromeNumber(int Number)
{
    if (Number == ReverseNumber(Number))
    {
        cout << "Is Palindrome Number \n";
    }

    else
    {
        cout << "Is NOT Palindrome Number \n";
    }
}

int IsPalindromeMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols / 2; j++)
        {
            if (Matrix1[i][j] != Matrix1[i][Cols - 1 - j]) // goes from right side one step and left side one step
            {
                return false;
            }
        }
    }
    return true;
}
// IsPalindromeNumber(ReverseNumber(Matrix[i][i]));
int main()
{
    srand((unsigned)time(NULL));
    int Matrix[3][3];
    int arr[3];
    int arr2[3];
    FillMatrix(Matrix, 3, 3);
    PrintMatrix(Matrix, 3, 3);
    CheckElementMatrix(Matrix, arr, arr2, 3, 3);

    return 0;
}