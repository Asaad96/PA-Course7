#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

sClient ReadNewClient()
{

    sClient Client;
    
    cout<< "Enter Account Number: \n";
    getline(cin, Client.AccountNumber);

    cout << "Enter PinCode: \n";
    getline(cin, Client.PinCode);

    cout << "Enter Name: \n";
    getline(cin, Client.Name);

    cout << "Enter Phone: \n";
    getline(cin, Client.Phone);

    cout << "Enter Account Balance: \n";
    cin>> Client.AccountBalance;

    return Client;
}

string ConvertRecordToLine (sClient Client, string Seperator = "#//#")
{

    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;
}


int main ()
{
    cout << "\nPlease Enter Client Data: \n\n";
    sClient Client ;
    Client = ReadNewClient();

    cout << "\n\nClient Record For Saving is: \n";
    cout << ConvertRecordToLine(Client)<< endl;

    return 0;
}
