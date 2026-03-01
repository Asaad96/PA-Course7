// Write a program to join a strings into a one string with separators
// Join String (overloading)

#include<iostream>
#include<string>
#include<vector>

using namespace std;


string JoinString(vector<string> vString, string Delim)
{
    string S1 = "";
    for (string& s: vString)
    {
        S1 = S1 + s + Delim;
    }

    return S1.substr(0, S1.length() - Delim.length());
}



string JoinString (string Arr[], short length, string Delim )
{
    string S1 = "";
    
    for( short i = 0 ; i < length; i ++)
    {
        S1 = S1 + Arr[i]+ Delim;
    }
    return S1.substr(0, S1.length() - Delim.length());
}




int main()
{
    vector<string> vString = { "Asaad", "Baz", "Great", "Developer"};
    cout << "\nVector after join:\n";
    cout<< JoinString(vString, "->") << endl;

    string Arr[]= { " I'm ", " With ", " You ", " From ", " twitch.tv ", " Don't forget to ", " Follow"};
    cout << "\nArray after join: \n";
    cout<< JoinString(Arr,7 , "*-*") << endl;
    

    return 0;
}