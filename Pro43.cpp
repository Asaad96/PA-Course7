// Write a program to replace words in string using custom funtion

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString()
{
    string S1 = "";
    cout << "Please Enter your Sentence\n";
    getline(cin, S1);
    return S1;
}
vector<string> SplitString(string S1, string Delim)
{
vector<string> vString;
short pos = 0;
string sWord;
while ((pos = S1.find(Delim)) != std::string::npos)
{
    sWord = S1.substr(0,pos);
    if (sWord != "")
    {
        vString.push_back(sWord);
    }
    S1.erase(0,pos + Delim.length());
}

if(S1 != "")
{
    vString.push_back(S1);
}
return vString;
}

string JoinString(vector<string> vString, string Delim)
{
string S1;
for (string& s : vString)
{
S1 = S1 + s + Delim;
}
return S1.substr(0, S1.length() - Delim.length());
}
string LowerAllString(string S1)
{
for (short i = 0; i < S1.length(); i++)
{
S1[i] = tolower(S1[i]);
}
return S1;
}

string ReplaceString(string S1, string StringToReplace, string ToReplace, bool MatchCase = true)
{
    vector<string> vString = SplitString(S1, " ");

    for (string& s : vString) 
    {
        if (MatchCase)
        {
            if (s == StringToReplace)
            {
                s = ToReplace;
            }
            else 
            {
                if (LowerAllString(s) == LowerAllString(StringToReplace))
                {
                    s= ToReplace;

                }
            }
        }
    }
    return JoinString(vString, " ");
}

int main()
{
    string S1 = "Hello I'm here From Twitch, Twitch is a Streaming platform\n";
    // string S1 = ReadString();
    // string StringToReplace = ReadString();
    string StringToReplace = "Twitch";
  //  string ToReplace = ReadString();
    string ToReplace = "YouTube";
    cout << "After deleting the word\n";
    cout << ReplaceString(S1, StringToReplace, ToReplace);
    return 0;
}