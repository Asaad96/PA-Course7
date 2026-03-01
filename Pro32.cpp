// Write a program to read a character then check if it is a vowel or Not (a, e, i , o , u)

#include <iostream>
#include <string>

using namespace std;

// My Method
// char ReadChar()
// {
//     char Ch1;
//     cout << "Please enter a character\n";
//     cin >> Ch1;

//     return Ch1;
// }

// bool CheckChar(char Ch)
// {
   

//     switch (Ch) 
//    {
    
//     case 'a':
//     case 'e':
//     case 'i':
//     case 'o':
//     case 'u':
//         return true;
//         default:
//         return false;
//     }
// }

// int main ()
// {char letter = ReadChar();
//     if(CheckChar(letter))
//     cout << "The letter is a Vowel\n";
//     else 
//     cout << "The letter is NOT a Vowel\n";

//     return 0;

// }

// Instructor's Method

char ReadChar()
{
    char Ch1;
    cout << "Please enter a character\n";
    cin >> Ch1;

    return Ch1;
}

bool IsVowel (char Ch1)
{
    Ch1 = tolower(Ch1);

    return ((Ch1 == 'a')||(Ch1 == 'i')||(Ch1 == 'e')||(Ch1 == 'o')||(Ch1 == 'u'));
}

int main()
{
    char Ch1 = ReadChar();
    if(IsVowel(Ch1))
        cout << "\nYes letter \'"<< Ch1 << "\' is Vowel\n";
    else
        cout << "\nNO Letter \'"<< Ch1 << "\' is NOT a Vowel\n";


return 0;
}