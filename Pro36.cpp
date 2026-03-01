// Write a program to read a string then count each word in that string


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


void PrintEachWorInString (string S1)
{
 string delim = " ";
 short pos = 0 ;
 short counter = 0;    
string sWord;

 while ((pos = S1.find(delim)) != std::string::npos)
{
    sWord = S1.substr(0,pos);
    if (sWord != "")
    {
        counter++;
        //cout << sWord << endl;

    }
     S1.erase(0, pos + delim.length()); 
    
}
if (S1 != "")
    {
        counter = counter + 1;
    }
cout << "The Number of words in your string is: " << counter << endl;
}
int main()
{

    PrintEachWorInString(ReadString());

    return 0;
}