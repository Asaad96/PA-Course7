// Write a program to ask you to enter clients and save them to file

#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

// My Method
// {
//     string S1;
//     getline(cin,S1);
//     return S1;
// }
//
// void SaveInput (vector<string>& vString)
// {
//     string S1 = ReadString();
//     vString.push_back(S1);
// }
//
// string JoinString (vector<string> & vString , string Delim)
// {
//     string S1 = "";
//         
//     for (string& s : vString)
//     {
//         S1 = S1 + s + Delim;
//     }
//     return S1.substr(0,S1.length() - Delim.length());
// }
//
//
// void SaveToFile(string FileName, string Data) {
//     fstream NewFile;
//     NewFile.open(FileName, ios::out);
//     if(NewFile.is_open())
//     {
//         NewFile << Data << endl;        
//         NewFile.close();
//     }
// }
//
//
//
//
// int main()
// {
//     vector<string> vString;
//
//
//
//     cout << "Please Enter Client Data:\n\n";
//     cout << "Enter Account Number:\n";
//     SaveInput(vString);
//     cout << "Enter PinCode:\n";
//     SaveInput(vString);
//     cout << "Enter Name:\n";
//     SaveInput(vString);
//     cout<<"Enter Account Balance\n";
//     SaveInput(vString);
// cout<<"Client Record for Saving is:\n\n";
//
// string ClientRecord =  JoinString(vString, "#//#"); 
//     cout << ClientRecord << endl;
// SaveToFile("/Users/asaadmbaz/Downloads/Cprojects/PA-Course7/ClientData.text", ClientRecord);
//
// return 0;
// }
//
//


// instuctor's Method

const string ClientFileName = "Clients.text";
struct sClient 
{
    string AccountNumber;
    string PinCode;
    string Phone;
    string Name;
    double AccountBalance;
};

sClient ReadNewClient()
{
    sClient Client;

    cout  << "Enter Account Number: ";
    getline(cin >> ws, Client.AccountNumber); // here we use ws to extract all the white space character 
    cout << "Enter PinCode: ";
    getline(cin, Client.PinCode);
    cout << "Enter Phone: ";
    getline(cin, Client.Phone);
    cout << "Enter Name: ";
    getline(cin , Client.Name);
    cout << "Enter AccountClient: ";
    cin  >> Client.AccountBalance;


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

void AddDataLineToFile(string FileName, string stDataLine)
{
    fstream MyFile;

    MyFile.open(FileName, ios::out  | ios::app);

    if (MyFile.is_open())
    {
        MyFile << stDataLine << endl;
        MyFile.close();
    }
}

void AddNewClient ()
{
    sClient Client;
    Client = ReadNewClient();
    AddDataLineToFile(ClientFileName,ConvertRecordToLine(Client));
}
void ClearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


void AddClients()
{
    char AddMore = 'Y';
    do 
    {
        ClearScreen();
        cout << "Adding New Client:\n\n";
        AddNewClient();
        cout << "\nClient Added Successfuly, Do You Want to add More clients ? Y/N? \n";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}

int main ()
{ AddClients();
    return 0;
}
