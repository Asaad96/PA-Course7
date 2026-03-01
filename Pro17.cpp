// Write a program to check a given number exist in the Matrix or NOT 


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

int SearchNumber (int Matrix[3][3], int &Number, short Rows, short Cols)
{
   
    for(short i = 0 ; i < Rows ; i ++)
    {
        for (short j = 0; j < Cols ; j ++)
        {
            if(Number == Matrix[i][j])
            return true;
        }
    }
    return false;
}

bool CheckExistNumber(int Matrix[3][3], int &Number,short Rows, short Cols)
{
    return(SearchNumber(Matrix, Number,3,3));
}


int main()
{
srand((unsigned)time(NULL));
int Matrix[3][3];
int Number;
 
FillMatrix( Matrix, 3, 3);
PrintMatrix(Matrix, 3,3);
SearchNumber(Matrix,Number, 3,3);
cin >> Number;
if(CheckExistNumber(Matrix,Number, 3,3))
    cout << "Yes : it's exist\n";
else 
    cout << "NO : Does NOT exist\n";


return 0; 
}