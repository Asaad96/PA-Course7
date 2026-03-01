// Write a program to read a string then print the first letter 
// of each word in that string 

// " Hello My Name is Asaad and I'm here "
// H M i A a I h

#include<iostream>
#include<string>

using namespace std;


string ReadString ()
{
    string text;
    cout << "Please enter a string\n";
    getline(cin, text);   

    return text;
}

void PrintEachLetterOfString (string text)
{   
    bool isFirstLetter = true;
    cout << "\n First Letters of this string\n";

    for (int i = 0 ; i < text.length() ; i++)
    {  
        if (text[i] != ' ' && isFirstLetter)
        {
            cout << text[i] << endl;
        }

        isFirstLetter = (text[i] == ' ' ? true : false);

    }
}

int main ()
{

   // ReadString();
   PrintEachLetterOfString(ReadString());
    return 0;
}