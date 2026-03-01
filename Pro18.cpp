// // Write a program to print the intersected number in two given matrices

// #include <iostream>
// #include <iomanip>
// #include <string>

// using namespace std;

// My Method 

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

// int SearchNumber (int Matrix[3][3], int Number, short Rows, short Cols)
// {
   
//     for(short i = 0 ; i < Rows ; i ++)
//     {
//         for (short j = 0; j < Cols ; j ++)
//         {
//             if(Number == Matrix[i][j])
//             return true;
//         }
//     }
//     return false;
// }

// bool CheckExistNumber(int Matrix[3][3], int Number,short Rows, short Cols)
// {
//     return(SearchNumber(Matrix, Number,3,3));
// }


// void CompareElements (int Matrix1[3][3],int Matrix2[3][3], short Rows, short Cols )
// {
//     int CommonNumber ;
    
//     for(short i = 0 ; i < Rows ; i ++ )
//     {
//         for(short j = 0 ; j < Cols ; j ++)
//         { CommonNumber = Matrix1[i][j];
//             if(CheckExistNumber(Matrix2, CommonNumber, Rows, Cols))
//             {
//                 cout << setw(3) << CommonNumber << "   " ;
                
//             }
//         }
//     }
//      cout << endl;
            
// }

// int main()
// {
// srand((unsigned)time(NULL));
// int Matrix1[3][3];
// int Matrix2[3][3];
 
// FillMatrix( Matrix1, 3, 3);
// FillMatrix( Matrix2, 3, 3);
// cout<<"Matrix №1\n";
// PrintMatrix(Matrix1, 3,3);
// cout<<"Matrix №2\n";
// PrintMatrix(Matrix2, 3,3);
// cout<< "Common Elements are: " ;
// CompareElements(Matrix1, Matrix2, 3, 3);
// return 0;
// }

// Teacher's Method

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
for (short i = 0; i < Rows; i++)
{
for (short j = 0; j < Cols; j++)
{
//printf(" %0*d ", 2, arr[i][j]);
cout << setw(3) << arr[i][j] << " ";
}
cout << "\n";
}
}
bool IsNumberInMatrix(int Matrix1[3][3], int Number, short Rows,
short Cols)
{
short NumberCount = 0;
for (short i = 0; i < Rows; i++)
{
for (short j = 0; j < Cols; j++)
{
if (Matrix1[i][j] == Number)
{
return true;
};
}
}
return false;
}


void PrintIntersectedNumbers(int Matrix1[3][3], int Matrix2[3][3],
short Rows, short Cols)
{
int Number;
for (short i = 0; i < Rows; i++)
{
for (short j = 0; j < Cols; j++)
{
Number = Matrix1[i][j];
if (IsNumberInMatrix(Matrix2, Number, Rows, Cols))
{
cout << setw(3) << Number << " ";
}
}
}
}
int main()
{
int Matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} };
int Matrix2[3][3] = { {5,80,90},{22,77,1},{10,8,33} };
cout << "\nMatrix1:\n";
PrintMatrix(Matrix1, 3, 3);
cout << "\nMatrix2:\n";
PrintMatrix(Matrix2, 3, 3);
cout << "\nIntersected Numbers are: \n\n";
PrintIntersectedNumbers(Matrix1, Matrix2, 3, 3);
system("pause>0");
}