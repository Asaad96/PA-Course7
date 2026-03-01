// Write a program to fill a 3x3 matrix with ordered numbers
// the following is a 3x3 ordered matrix
// 1 2 3 
// 4 5 6 
// 7 8 9


#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int OrderNumber(int From, int To) {
    static int Number = From;  // استخدم متغير ثابت حتى لا يعاد تعيينه في كل مرة
    if (Number > To) return -1;  // إذا تجاوز الرقم النهاية، قم بإرجاع قيمة غير صالحة
    return Number++;
}



void FillMatrix(int arr[3][3], int Rows, int Cols)
{

   for(int i = 0; i < Rows ; i ++ )
   {
	for (int j  = 0 ; j < Cols ; j++)
	{
	 arr[i][j] = OrderNumber(1,9);
	}
   }

}



void PrintMatrix(int arr[3][3], int Rows, int Cols)

{
	for (int i = 0 ; i < Rows ; i ++)
	{
	  for (int j = 0 ; j < Cols ; j++)
	  {
	    cout << setw(3) << arr[i][j] << "   ";
	  }
	  cout << endl;
	}
}


int main()
{

int arr[3][3];
FillMatrix(arr,3,3);

PrintMatrix(arr,3,3);

return 0;
}
