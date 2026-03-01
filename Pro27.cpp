// Write a program to read a character then invert it's case and print it
#include<iostream>
#include<string>

using namespace std;


char ReadChar()
{   
   
    char letter;
    cout << "Please enter a character!\n";
    cin >> letter;

return letter;
}

char InvertLetterCase(char char1)
{
    return isupper(char1) ? tolower(char1) : toupper(char1);
}

int main()
{
   char Ch1 = ReadChar();
   cout << "\nafter inverting case \n";
   Ch1 = InvertLetterCase(Ch1);
   cout << Ch1<< endl;

    return 0;
}