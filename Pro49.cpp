// Write a program to find client by AccountNumber and Print it to the screen


#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const string ClientsFileName = "clients.text";

struct sClient {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;

};

vector <string> SplitString (string S1, string Delim)
{
    vector <string> vString;
    short pos = 0;
    string sWord;

    while ( (pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);

        if (sWord != "") 
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

sClient ConvertLineToRecord (string Line, string Seperator = "#//#")
{
    sClient Client;
    vector<string > vClientData;
    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);

    return Client; 
}


vector <sClient> LoadCleintsDataFromFile(string FileName)
{
vector <sClient> vClients;
fstream MyFile;
MyFile.open(FileName, ios::in);//read Mode
if (MyFile.is_open())
{
string Line;
sClient Client;
while (getline(MyFile, Line))
{
Client = ConvertLineToRecord(Line);
vClients.push_back(Client);
}
MyFile.close();
}
return vClients;
}

void PrintClientCard (sClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "\nAccount Number : " << Client.AccountNumber; 
    cout << "\nPin Code       : " << Client.Name ;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}

string ReadClientAccountNumber()
{
    string AccountNumber = "";
    cout << "\n Please enter AccountNumber! \n";
    cin >> AccountNumber;
    return AccountNumber;
}

bool FindClientByAccountNumber(string AccountNumber, sClient &
Client )
{
vector <sClient> vClients =
LoadCleintsDataFromFile(ClientsFileName);
for (sClient C : vClients)
{
if (C.AccountNumber == AccountNumber)
{
Client = C;
return true;
}
}
return false;
}

int main() 
{ sClient Client;

    string AccountNumber = ReadClientAccountNumber();

        if (FindClientByAccountNumber(AccountNumber, Client))
        {
            PrintClientCard(Client);
        }
        else 
        { cout <<"\nClient with Account Number (" << AccountNumber << "is Not Found!\n";}
        return 0;
}
