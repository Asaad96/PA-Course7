// Write a program to convert line data to record and print it 


#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

struct sClient 
{
    string AccountNumber ;
    string PinCode ;
    string Name;
    string Phone;
    double AccountBalance;
};


vector<string> SplitString(string S1, string Delim)
{

    vector<string> vString ;
    short pos = 0 ;
    string sWord ;

        while ( (pos = S1.find(Delim)) != std::string::npos) 
            { 
               sWord = S1.substr(0, pos);
               if(sWord != "")
              { 
                 vString.push_back(sWord);
              }
                S1.erase(0, pos + Delim.length());

            }
        if (S1 != "")
        {
            vString.push_back(S1);
        }
        return vString;
}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{

    sClient Client;

    vector<string> vClientData;
    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);

    return Client ;
}


void PrintClientRecord (sClient Client)

{
    cout << "\n\n The Following is the extracted Client Record: \n";

    cout << "\nAccount Number : " << Client.AccountNumber;
    cout << "\nPin Code       : " << Client.PinCode;
    cout << "\nName           : " << Client.Name;
    cout << "\nPhone          : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}


int main ()
{
  string stLine = "A120#//#1234234sdfsawe#//#Asaad Dev#//#92834237942#//#12000000.000000";

  cout << "\nLine Record is :\n";
  cout << stLine ;  

  sClient Client = ConvertLinetoRecord(stLine);
    
  PrintClientRecord(Client);

  return 0;
}
