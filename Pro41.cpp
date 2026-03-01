// Write a program to read string and reverse its word 
// ex: Hello I'm Asaad -> Asaad I'm Hello

#include<iostream>
#include<string>
#include<vector>

using namespace std;


// My method -> Grabage :(
                        

// string ReadString ()
// {   
//     string S1;
//     cout << "please Enter your sentence\n";
//     getline(cin,S1);

//     return S1;
// }

// string ReversesubString (string S1)
// {
//       string S1Rev = " ";
//     for (short i = S1.length() ; i >= 0 ; i -- )
//     {
//         S1Rev = S1Rev + S1[i] ;
//     }
//      return S1Rev;
// }

// string ReverseString (string S1, string Delim )
// {
//     string S1Rev = " ";
//     string S2Rev = " ";
//     char Space = ' ';
//     for (short i = S1.length() ; i >= 0 ; i -- )
//     {
//         S1Rev = S1Rev + S1[i] ;
//         if(S1[i] == Space)
//         {
//              S2Rev = ReversesubString(S1Rev);
//         }
//         cout << S1Rev; 
//     }
    

//     return S2Rev;
// }




// int main()
// {

// string S1 = "Hello my name is Asaad"; 
// cout <<  ReverseString(S1, " ") << endl;

// return 0;
// }


string ReadString ()
{   
    string S1;
    cout << "please Enter your sentence\n";
    getline(cin,S1);

    return S1;
}


vector<string> SplitString (string S1, string Delim)
{
    vector<string> vString;
    short pos = 0; 
    string sWord; 

    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if(sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0,pos + Delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
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


// string ReverseWordInString (string S1)
// {

// vector<string> vString;
// string S2 = "";

// vString = SplitString(S1, " ");

// vector<string>::iterator iter = vString.end();
// while (iter != vString.begin())
// {
//     --iter; 
//     S2 += *iter + " ";  
// }
// S2 = S2.substr(0,S2.length()-1);
// return S2;
// }

// int main ()
// {
//     string S1 = ReadString();
//     cout << "\nAfter Reversing Wrods:\n";
//     cout << ReverseWordInString(S1);

//     return 0;
// }


string ReverseWordsInString(string S1)
{
vector<string> vString;
string S2 = "";
vString = SplitString(S1, " ");
// declare iterator
vector<string>::iterator iter = vString.end();
while (iter != vString.begin())
{
--iter;
S2 += *iter + " ";
}

//S2 = S2.substr(0, S2.length() - 1); //remove last space.

S2 = TrimRight(S2);
return S2;
}
int main()
{
string S1 = ReadString();
cout << "\n\nString after reversing words:";
cout << "\n" << ReverseWordsInString(S1) << endl;
return 0;
}