// Write a program to read bank client data record and convert it to one line 
// one of the most important lessons 
// please enter Client Data;
//
//Enter Account Number? A150
//Enter PinCode? 1234
//Enter Name? Asaad Dev
//Enter Account Balance? 10000

// Client Record for saving is:
// A150#//#1234#//#Asaad Dev#//#10000



#include<iostream>
#include<string> 
#include<vector>

using namespace std;

string ReadString ()
{ string S1;
    getline(cin,S1);
    return S1;
}


void SaveInput (vector<string> & vString)
{
 
           string S1 = ReadString();

           vString.push_back(S1);
}




string JoinString (vector<string>& vString , string Delim)

{
    string S1 ="";

    for (string& s: vString)
    {
        S1 = S1 + s + Delim;
    }
    return S1.substr(0, S1.length()-Delim.length());
}


int main ()
{   
  //  string S1 = "";
    vector<string> vString; //= {"Asaad", "Baz" , "Great", "Developer"};
    cout << "Please Enter Client Data:\n\n";
    cout << "Enter Account Number:\n";
    SaveInput(vString);
    cout << "Enter PinCode:\n";
    SaveInput(vString);
    cout << "Enter Name:\n";
    SaveInput(vString);
    cout<<"Enter Account Balance\n";
    SaveInput(vString);
cout<<"Client Record for Saving is:\n\n";
cout << JoinString(vString, "#//#") << endl;

    return 0;
}
