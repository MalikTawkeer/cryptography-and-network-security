//PROGRAM TO ENCODE/CONVERT ANY INPUT PASSWORD STRING ACCORDING TO SOME PATTERN(key)
// needs some modifications
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char passwordUniverse[26]={'a','b','c','e','f','g','h','i','j','k',
                                        'l','m','n','o','p','q','r','s','t','u',
                                        'v','w','x','y','z'};
    char  inputPass[10];
    int key;
    // taking input from user
    cout<<"ENTER A PASSWORD STRING(only 10 alphabets)"<<endl;
    for (int i=0;i<10;i++)
    {
        cin >>inputPass[i];
    }
    cout<<"Enter A Key:";
    cin>>key;
    // ENCODING CODE....
    for(int x=0;x<10;x++)
    {
        for(int j=0;j<26;j++)
        {
            if(inputPass[x]==passwordUniverse[j])
            {
                inputPass[x]=passwordUniverse[j+key];
                break;
            }
        }
    }
    cout<<"Encoded password string:-\t";
     // DISPLAYING ENCODED PASSWORD
    for (int i=0;i<10;i++)
    {
        cout<<inputPass[i];
    }

    //DECODING CODE..
    for(int l=0;l<10;l++)
    {
        for(int m=0;m<26;m++)
        {
            if(inputPass[l]==passwordUniverse[m])
            {
                inputPass[l]=passwordUniverse[m-key];
                break;
            }
        }
    }
    cout<<endl;
     // DISPLAYING DECODED PASSWORD
     cout<<"orginal password string:-\t";
    for (int i=0;i<10;i++)
    {
        cout<<inputPass[i];
    }
return 0;
}                  
