// Write a program to read a string then upper all letters, then
// lower all letters, and print them

#include<iostream>
#include<string>

using namespace std;

string ReadString ()
{
string S1;

cout << "Please Enter Your String?\n";
    getline(cin, S1);
    

return S1;
}

string UpperLetterOfEachWord (string S1)
{
for (short i = 0 ; i < S1.length(); i ++)
{

    S1[i]= toupper(S1[i]);
}
return S1;
}

string LowerLetterOfEachWord (string S1)
{
for (short i = 0 ; i < S1.length(); i ++)
{

    S1[i]= tolower(S1[i]);
}
return S1;
}

int main()
{
    string S1 = ReadString();
    cout << "\nString after conversion to Upper Letters:\n";
    S1 = UpperLetterOfEachWord(S1);
    cout << S1 << endl;
     cout << "\nString after conversion to Lower Letters:\n";
    S1 = LowerLetterOfEachWord(S1);
    cout << S1 << endl;
return 0;
}