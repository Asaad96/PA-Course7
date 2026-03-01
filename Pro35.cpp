// Write a program to read a string then print each word in that string

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

// void PrintEachWord (string S1)
// {
//     short j = 0;
//     for (short i = 0; i < S1.length() ; i ++)
//     {   j++;
//         if(S1[i] == ' ')
//         {
//             for (short j = 0 ; j < S1.length(); j++)
//             {
//                 cout << S1[j - i - 1 ];
//             }
//         }
//     }
//   //  Hello my name is
// }

void PrintEachWordInString(string S1)
{
    string delim = " "; // delimiter
    cout << "\nYour string wrords are: \n\n";
    short pos = 0;
    string sWord; // define a string variable
    // use find() function to get the position of the delimiters
    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            cout << sWord << endl;
        }
        S1.erase(0, pos + delim.length()); /* erase() until
        positon and move to next word. */
    }
    if (S1 != "")
    {
        cout << S1 << endl; // it print last word of the string.
    }
}

int main()
{

    PrintEachWord(ReadString());

    return 0;
}