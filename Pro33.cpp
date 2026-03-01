// Write a program to read a string then all vowels in that string

#include <string>
#include <iostream>
using namespace std;
string ReadString()
{
    string S1;
    cout << "\nPlease Enter Your String?\n";
    getline(cin, S1);
    return S1;
}
bool IsVowel (char Ch1)
{
    Ch1 = tolower(Ch1);

    return ((Ch1 == 'a')||(Ch1 == 'i')||(Ch1 == 'e')||(Ch1 == 'o')||(Ch1 == 'u'));
}

short CountVowel (string S1)
{
    short counter = 0;
    for (short i = 0 ; i < S1.length() ; i ++)
    {
        if(IsVowel(S1[i]))
        {
            counter++;
        } 
    }
return counter; 
}

int main ()
{
    string S1 = ReadString();

cout <<"The Number of Vowel is your String is = "<<CountVowel(S1) << endl;

// if (CountVowel(S1) == 0)
// {
//     cout <<"The Number of Vowel is your String is = 0\n"; 
// }
return 0;
}