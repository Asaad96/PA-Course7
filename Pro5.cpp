// Write a program to fill 3x3 matrix with random numbers then sum each col in another array and print them

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int RandomNumber(int From , int To)
{
   int number = rand() % (To - From + 1 ) + From;
   return number;
}


void FillMatrixWithRandomNumber(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i< Rows; i++)
	{
	 for (short j = 0 ; j< Cols; j ++)
	  { 
	    arr[i][j] = RandomNumber(1,100);
          }
        }
}


void PrintMatrixWithRandomNumber(int arr[3][3], short Rows, short Cols)
{  
	for (short i =0 ; i < Rows ; i++)
	{
  	  for (short j = 0 ; j  < Cols ; j++)
	  { cout << setw(3) << arr[i][j] << "   ";
	  }
	cout << endl;
	}
}

int ColSum (int arr[3][3], short Rows, short ColNumber)
{
  int Sum = 0;
	for (short i = 0; i <= Rows -1 ; i ++)
	{
	  Sum += arr[i][ColNumber];
	}
	return Sum;
}


void SumMatrixColsInArray (int arr[3][3],int arrSum[3],short Rows, short Cols)
{
   for (short j = 0; j < Cols ; j ++ )
	{
	  arrSum[j] = ColSum(arr,Rows,j);
   	}
}


void PrintColsSumArray(int arr[3], short length)

{

cout << "\n THe following are the sum of each col in the matrix: \n";

	for (short i = 0 ; i < length ; i ++ )
	{ 
		cout << " Col "<< i+1 << " Sum= " << arr[i] << endl;
	}
}


int main()
{

srand((unsigned)time(NULL));

int arr[3][3];
int arrSum[3];


FillMatrixWithRandomNumber(arr,3,3);
cout << " Your Matrix is : \n ";
PrintMatrixWithRandomNumber(arr,3,3);
SumMatrixColsInArray(arr,arrSum, 3, 3);
PrintColsSumArray(arrSum, 3);
 

return 0;
}
