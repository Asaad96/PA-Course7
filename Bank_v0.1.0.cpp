#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

const string ClientsFileName = "/Users/asaadmbaz/Downloads/Cprojects/PA-Course7/Clients.text";

enum Menue  {  Show = 1 , Add = 2  ,  Delete = 3 , Update = 4 , Find = 5 , Exit = 6 };

struct sClient
{
string AccountNumber;
string PinCode; 
string Name ;
string Phone;
double AccountBalance;
};




vector <string> SplitString ( string S1 , string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord ; 

    while ( (pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0,pos);

        if ( sWord != "")
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



sClient ReadNewClient()
{
    sClient Client;
    
    cout << "Enter Account Number: ";
    getline(cin>> ws , Client.AccountNumber);
    cout << "Enter PinCode: ";
    getline(cin, Client.PinCode );
    cout<< "Enter Name: ";
    getline(cin, Client.Name);
    cout << "Enter Phone: ";
    getline(cin, Client.Phone);
    cout << "Enter Account Balance: ";
    cin >> Client.AccountBalance;

    return Client;
}


sClient ConverLineToRecord (string line , string Seperator = "#//#")
{
    sClient Client ;
    vector <string> vClientData;

    vClientData = SplitString(line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode =  vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);
   
    return Client;
}



vector <sClient> LoadClientDataFromFile (string FileName)
{

    vector <sClient> vClients;
    fstream MyFile;

    MyFile.open(FileName, ios::in);

        if(MyFile.is_open())
        {
           
            //cout << " Error: Could not Open file {" << FileName << "]" << endl;
          //  return vClients;
        //}

            string line;
            sClient Client;


            while(getline(MyFile, line))
            {
                Client = ConverLineToRecord(line);
                    vClients.push_back(Client);
            }

            MyFile.close();
        }
    return vClients; 
}

string ConvertRecordToLine(sClient  Client , string Seperator = "#//#")
{
    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator ;
    stClientRecord += to_string(Client.AccountBalance) + Seperator;

    return stClientRecord;
}


void AddDataLineToFile(string FileName, string stDataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

    if(MyFile.is_open())
    { MyFile << stDataLine << endl;
        MyFile.close();
    }
}


void AddNewClient ()
{
    sClient Client;
    Client = ReadNewClient();
    AddDataLineToFile(ClientsFileName,ConvertRecordToLine(Client));
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




void  PrintClientRecord ( sClient Client)
{

    cout << "|  " <<  setw(15) << left << Client.AccountNumber;
    cout << "|  " <<  setw(10) << left << Client.PinCode;
    cout << "|  " <<  setw(40) << left << Client.Name ;
    cout << "|  " <<  setw(12) << left << Client.Phone;
    cout << "|  " <<  setw(12) << left << Client.AccountBalance ;
    cout << endl;

  
}



// void PrintAllClientData( vector <sClient> vClients)
// {
//
//     cout << "\n\t\t\t\t\t\t\t Clients List ("<< vClients.size() <<  ") Client(s)";
//     cout <<"\n--------------------------------------------------------------------------------------------";
//     cout <<"-------------------------------------------------------------------------------------------\n" << endl;
//     cout << "|  " << left << setw(15) << "Account Number";
//     cout << "|  " << left << setw(10) << "Pin Code " ;
//     cout << "|  " << left << setw(40) << "Client's Name" ;
//     cout << "|  " << left << setw(12) << "Phone " ;
//     cout << "|  " << left << setw(12) << "Account Balance " ;
//     cout <<"\n--------------------------------------------------------------------------------------------";
//     cout <<"-------------------------------------------------------------------------------------------\n" << endl;
//
//     for (sClient Client : vClients)
//     {
//         
//         PrintClientRecord(Client);
//         cout << endl;
//     }
//
//
// }:



void PrintIntroFace ()
{
    cout << "======================================================================" << endl;
    cout << "                            Main Menue Screen                       \n" << endl  ;
    cout << "======================================================================" << endl;
    cout << "      [1] Show Client List.     \n";
    cout << "      [2] Add New Client.       \n";
    cout << "      [3] Delete Client.        \n";
    cout << "      [4] Update Client Info.   \n";
    cout << "      [5] Find Client.          \n";
    cout << "      [6] Exit.                 \n";

    cout << "======================================================================" << endl;
    cout << "Choose What do you want to do ? [1 to 6]? \n";

}


void ShowCleintsList ()
{
    vector<sClient> vClients = LoadClientDataFromFile(ClientsFileName);
  //  PrintAllClientData(vClients);


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


void PreformMenuOption( Menue Choice)
{
    switch (Choice) {
        case Show:
            ShowCleintsList();
            break;

    case Add:
             AddClients();
        break;

    case Delete:
        cout << "Delete\n";
        break;


    case Update:
    break;

    
    case Find:
    break;


    case Exit:
    break;
    }
}


Menue start ()
{
    short Choose ;
   
    do {
        PrintIntroFace();
        cin >> Choose ;

        while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "Invalid Number, Enter a valid one" << endl;
        cin >> Choose;
    }
       }
       while(Choose < 1 || Choose > 6 );
    
   

    return (Menue)Choose;
}




int main ()
{


  Menue Choice ;
   do 
   {
        Choice =  start();
        PreformMenuOption(Choice);

    } while (Choice != Exit ); 
   

return 0; 
}

