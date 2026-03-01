// Write a program to read clients file and show them on the screen as follow:


//                                      clients list (3) Client(s) 
// ------------------------------------------------------------------------------------------------
// | Accont Number | Pin Code | Client Name                  | Phone        | Balance    
// ------------------------------------------------------------------------------------------------
// | A150          | 1123     | Asaad Dev                    | 89324729432  | 12000
// | A151          | 1234     | Mike DJ                      | 89324729432  | 12000
// | A152          | 0000     | Jessica Brown                | 89324729432  | 12000
// ------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

const string ClientFileName = "Clients.text";

struct sClient {
    string AccountName;
    string PinCode;
    string Name;
    string Phone;
    short AccountBalance;

};


vector<string> SplitString ( string S1 , string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; 


    while( (pos = S1.find(Delim)) != std::string::npos )
        { 
            sWord = S1.substr(0, pos);
            
            if (sWord != "")
            {
                vString.push_back(sWord);
            }
            S1.erase(0, pos + Delim.length());
        }

    if(S1 != "")
    {
        vString.push_back(S1);
    }

    return vString ;
}


sClient ConvertLineToRecord (string Line , string Seperator = "#//#")
{

    sClient Client;
    vector<string> vClientData;

    vClientData = SplitString(Line, Seperator);

    Client.AccountName = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stoi(vClientData[4]);

    return Client;

}

vector <sClient> LoadClientDataFromFile (string FileName)
{
    vector <sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);

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

void  PrintClientRecord ( sClient Client)
{

    cout << "|  " <<  setw(15) << left << Client.AccountName;
    cout << "|  " <<  setw(10) << left << Client.PinCode;
    cout << "|  " <<  setw(40) << left << Client.Name ;
    cout << "|  " <<  setw(12) << left << Client.Phone;
    cout << "|  " <<  setw(12) << left << Client.AccountBalance ;
}



void PrintAllClientData( vector <sClient> vClients)
{

    cout << "\n\t\t\t\t\t\t\t Clients List ("<< vClients.size() <<  ") Client(s)";
    cout <<"\n--------------------------------------------------------------------------------------------";
    cout <<"-------------------------------------------------------------------------------------------\n" << endl;
    cout << "|  " << left << setw(15) << "Account Number";
    cout << "|  " << left << setw(10) << "Pin Code " ;
    cout << "|  " << left << setw(40) << "Client's Name" ;
    cout << "|  " << left << setw(12) << "Phone " ;
    cout << "|  " << left << setw(12) << "Account Balance " ;
    cout <<"\n--------------------------------------------------------------------------------------------";
    cout <<"-------------------------------------------------------------------------------------------\n" << endl;

    for (sClient Client : vClients)
    {
        
        PrintClientRecord(Client);
        cout << endl;
    }






}

int main ()
{
    vector <sClient> vClient = LoadClientDataFromFile(ClientFileName);
    PrintAllClientData(vClient);

    return 0;
}
