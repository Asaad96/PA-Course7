//write a program to read a string and read a charater then 
// count the character in that string

#include<iostream>
#include<string>

using namespace std;

// My Method

// string ReadString()
// {
//     string S1;
//     cout<< "Please Enter the string\n";
//     getline(cin, S1);
//     return S1;
// }

// char ReadChar ()
// {
//     char Character;
//     cout << "Please Enter a Character\n";
//     cin >> Character;
//     return Character;
// }

// short CountChar (string S1, char char1)
// {
//     S1 = ReadString ();
//     char1 = ReadChar();
//     short counter = 0;
//     for (short i = 0; i <S1.length(); i++)
//     {
//         if (S1[i] == char1)
//         {
//             counter++;
//         }
//     }
//     cout << "Letter is: " << char1 << " Count = ";
//    return counter; 
// } 

// int main ()
// {   string S1;
//     char char1; 
//     cout << CountChar(S1, char1) << endl;
//     return 0;
// }


// Instructor's Method

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
char ReadChar()
{
char Ch1;
cout << "\nPlease Enter a Character?\n";
cin >> Ch1;
return Ch1;
}
short CountLetter(string S1, char Letter)
{
short Counter = 0;
for (short i = 0; i < S1.length(); i++)
{
if (S1[i] == Letter)
Counter++;
}
return Counter;
}


int main()
{
string S1 = ReadString();
char Ch1 = ReadChar();
cout << "\nLetter \'" << Ch1 << "\' Count = " <<
CountLetter(S1, Ch1);
system("pause>0"); }
