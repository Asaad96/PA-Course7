// Write a program to read a string then Trim left , Right , All


#include<string>
#include<iostream>
#include<vector>

using namespace std;

// string ReadString ()
// {
//     string S1;
//     cout << "Please Enter your string\n";
//     getline(cin,S1);
//     return S1;
// }

string TrimLeft(string S1)
{
    for (short i = 0 ; i < S1.length() ; i++)
    {
        if (S1[i] != ' ')
        {
            return S1.substr(i, S1.length() - 1);
        }
    }
    return "";
}

string TrimRight( string S1)
{
    for (short i =S1.length() -1  ; i >= 0  ; i-- )
    {
        if (S1[i] != ' ')
        {
            return S1.substr(0, i+1);

        }
    }
    return "";
}

string TrimAll(string S1)
{
    return (TrimLeft(TrimRight(S1)));
}

int main ()
{
    string S1 = "           Hello my name is Asaad          ";

 cout << "\nLeft Trim " << TrimLeft(S1) << endl;
 cout << "\nRight Trim " <<TrimRight(S1)<< endl;
 cout << "\nTrim All " << TrimAll(S1)<< endl;
return 0;
}