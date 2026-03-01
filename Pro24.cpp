// write a program to read a string then uppercase the first letter
// of each word in that string

#include<iostream>
#include<string>

using namespace std;

// My Method
// string ReadString ()
// {
//     string text;
//     cout << "Please enter a string\n";
//     getline(cin, text);   

//     return text;
// }

// void PrintEachLetterOfString (string text)
// {   
//     bool isFirstLetter = true;
//     //cout << "\n First Letters of this string\n";

//     for (int i = 0 ; i < text.length() ; i++)
//     {  
//         if (text[i] != ' ' && isFirstLetter)
//         {
//           text[i] = (char)toupper(text[i]);
           
//         }

//         isFirstLetter = (text[i] == ' ' ? true : false);

//     }
//      cout << text << endl;
// }

// int main ()
// {

   
//    PrintEachLetterOfString(ReadString());
//     return 0;
// }



// Teacher's method

string ReadString()
{
string S1;
cout << "Please Enter Your String?\n";
getline(cin, S1);
return S1;
}
string UpperFirstLetterOfEachWord(string S1)
{
bool isFirstLetter = true;
for (short i = 0; i < S1.length(); i++)
{
if (S1[i] != ' ' && isFirstLetter)
{
S1[i] = toupper(S1[i]);
}
isFirstLetter = (S1[i] == ' ' ? true : false);
}
return S1;
}
int main()
{
string S1 = ReadString();
cout << "\nString after conversion:\n";
S1 = UpperFirstLetterOfEachWord(S1);
cout << S1 << endl;
system("pause>0");
}