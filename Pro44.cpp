#include<iostream>
#include<string>
#include<vector>

using namespace std;

string RemovePunc (string S1)
    {
         string S2 = "";
        for (short i = 0 ; i < S1.length() ; i ++)
        {
            if(!ispunct(S1[i])){
             S2 += S1[i];
            }
               
            
        }
        return S1;
    }


int main()
{
    string S1 = "Welcome to Syria, Syria is a Great Country\n";
    
    cout << "Orginial String\n" << S1;
    cout <<"\n\nPunctuation Marks Removed\n";
    cout << RemovePunc(S1);
return 0 ;
}
