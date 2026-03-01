#include <iostream>
#include <fstream>
#include <sys/wait.h>
#include <vector>
#include <iomanip>
using namespace std;

const string ClientsFileName = "Clients.text";

struct sClient
{
    string AccountNumebr ;
    string PinCode; 
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};


vector <string> SplitString (string S1, string Delim)
{
    vector<string> vString;
    short pos = 0 ; 
    string sWord; 
     while ((pos = S1.find(Delim)) != std::string::npos)
     {
        sWord = S1.substr(0, pos);
        if(sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
     }

     if (S1 != "" )
     {
         vString.push_back(S1);

     }
     return vString;
}

sClient ConvertLinetoRecord(string line, string Seperator = "#//#")
{
        sClient Client ;
        vector <string> vClientData;
        
        vClientData = SplitString (line , Seperator);

        if(vClientData.size() != 5 )
        {
            cout << "Invalid data format in file!\n";
            return Client;
        }

        Client.AccountNumebr = vClientData[0];
        Client.PinCode = vClientData[1];
        Client.Name = vClientData[2];
        Client.Phone = vClientData[3];
        Client.AccountBalance = stod(vClientData[4]);

        return Client; 
}

string ConvertRecordToLine (sClient Client , string Seperator = "#//#")
{
    string stClientRecord = "";
    stClientRecord += Client.AccountNumebr +Seperator ;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name  + Seperator ;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord; 
}


vector <sClient> LoadClientsDataFromFile (string FileName) 
{
    vector<sClient> vClients;
    fstream MyFile ;
    MyFile.open(FileName, ios::in);
    
    if (MyFile.is_open())
    {
        string Line; 
        sClient Client ;

        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            vClients.push_back(Client);

        }
        MyFile.close();

    }

    return vClients;

}



void PrintClientCard(sClient Client)
{

    cout <<"\nThe Following are the Client details:\n";
    cout <<"\nAccount Number: " << Client.AccountNumebr; 
    cout <<"\nPinCode       : " << Client.PinCode;
    cout <<"\nName          : " << Client.Name;
    cout <<"\nPhone         : " << Client.Phone<< endl;
    cout <<"Account Balance : " << Client.AccountBalance;
}


bool FindClientByAccountNumber (string AccountNumebr , vector <sClient> vClients , sClient& Client)
{
    for (sClient C : vClients) 
    {   
        if(C.AccountNumebr == AccountNumebr) 
        {
            Client = C ;
            return true;
        }
    }
    return false ;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber , vector <sClient>& vClients )

{
    for ( sClient& C : vClients )

    {
        if (C.AccountNumebr == AccountNumber )
        {
            C.MarkForDelete = true ;
            return true;
        }
    }
    return false;
}

vector <sClient> SaveClientToFile(string FileName , vector <sClient> vClients)
{
    fstream MyFile ; 
    MyFile.open(FileName, ios::out); // here to overwrite 
 
    string DataLine;
    if (MyFile.is_open())
    {

         for (sClient  C : vClients )
       {

           if(MyFile.is_open())
             {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
             }
       }
    MyFile.close();
    }

    return vClients;
}


bool DeleteCLientByAccountNumber (string AccountNumebr , vector <sClient>& vClients) 
{
    sClient Client ;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumebr , vClients, Client))
            { 
                PrintClientCard(Client);
                
                cout << "\n\nAre you Sure you want to delete this Client? (Y/N)\n";

                cin >> Answer;
                if (Answer == 'y' || Answer == 'Y')
                {
                    MarkClientForDeleteByAccountNumber(AccountNumebr, vClients); 
                    SaveClientToFile(ClientsFileName, vClients); 
        
                    vClients = LoadClientsDataFromFile(ClientsFileName);

                    cout << "\n\nClient Deleted Successfully.\n";
                    return true;
                }
            }
    else 
    {
        cout << "\nClient witth Account Number (" << AccountNumebr << ") is Not Found! \n";
        return false;
    }
}


string ReadClientAccountNumebr()
{
    string AccountNumber = "";
    cout << "\nPlease Enter Account Number? \n ";
    cin >> AccountNumber;
    return AccountNumber;
}

int main ()
{
    vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumebr = ReadClientAccountNumebr();
        
        DeleteCLientByAccountNumber(AccountNumebr ,vClients);

        return 0;
}





















