// Write a program to print Fibonacci Series of 10

#include<iostream>
#include<string>

using namespace std;

void FibonacciSeries (short Number)
{
    int FebNumber = 0;
    int  Perv1 = 1;
    int  Perv2 = 0;

    
    cout << "1  "; 
    for(short i = 2 ; i <= Number ; ++i)
    {
         FebNumber = Perv2 + Perv1;
         cout << FebNumber<< "  ";
        Perv2 =  Perv1;
        Perv1 = FebNumber;
    }
}

int main ()
{
    FibonacciSeries(10);

    return 0;
}