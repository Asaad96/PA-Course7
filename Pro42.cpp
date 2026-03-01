// Write a program to replace words in String
#include<iostream>
#include<string>
#include<vector>

using namespace std;

string ReadString ()
{
    string S1 = "";
    cout << "Please Enter your Sentence\n";
    getline(cin,S1);
    return S1;
}

// vector<string> SplitString (string S1, string Delim)
// {
//     vector<string> vString;
//     short pos = 0; 
//     string sWord;

//     while((pos=S1.find(Delim)) != std::string::npos)
//     {
//         sWord = S1.substr(0, pos);
//         if(sWord != "")
//         {
//             vString.push_back(sWord);
//         }
//         S1.erase(0,pos + Delim.length());
//     }
//     if (S1 != "")
//     {
//         vString.push_back(S1);

//     }
//     return vString;
// }

string ReplaceWord (string S1, string ToReplace, string cReplaceTo)
{
   short pos = S1.find(ToReplace);
    while (pos != std::string::npos )
    {
        S1 = S1.replace(pos, ToReplace.length(), cReplaceTo);
        pos = S1.find(ToReplace);
    }

    return S1;
}



int main()
{

  //  string S1 = "Hello I'm here From Twitch, Twitch is a Streaming platform\n";
    string S1 =  ReadString(); 
  string ToReplace = ReadString();
    string cReplaceTo = ReadString();

    cout << "The Orginal String is \n" << S1<< endl;

    cout << "The String after replacement is \n";
    cout << ReplaceWord(S1, ToReplace, cReplaceTo ) << endl;

return 0;
}