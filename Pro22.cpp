// Write a program to print Fibonacci Series of 10

#include<iostream>
#include<string>

using namespace std;

void FibonacciSeries (short Number, int Perv1 , int Perv2)
{
    int FebNumber = 0;
    
    if (Number > 0)
    {
         FebNumber = Perv2 + Perv1;
        Perv2 =  Perv1;
        Perv1 = FebNumber;
         cout << FebNumber<< "  ";
        FibonacciSeries(Number - 1, Perv1 , Perv2);

    }
      
        
}


int main ()
{
    FibonacciSeries(10, 0 ,1);

    return 0;
}