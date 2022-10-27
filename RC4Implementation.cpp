// RC4 algo implementation 
// programmed according to example that was given by DR FAHEEM SIR

#include<iostream>
using namespace std;
int S[8]={0,1,2,3,4,5,6,7};//state vector
int KEY[4]={1,2,3,6}; // key
int KEYSTREAM[4]; //keystream
int P[4]={1,2,2,2}; // plaint text
int T[8]={1,2,3,6,1,2,3,6}; // temporary array
int cipherText[4];


//func.. code to swap values of array S for permutation purpose
void swap(int i,int j)
{
    int temp;
    if(i == j)
    {
        return;
    }
    temp = S[i];
    S[i] = S[j];
    S[j] = temp;
}


//func.. to perform initial permutation on S
void KeySchedulingAlgo()
{
    int j=0,i=0;
    
    for (i=0;i<8;i++)
    {
        j = (j+S[i]+T[i]) % 8;
        swap(i,j);
        cout<<"**************************"<<endl;
        cout<<"\tITERATION "<<i+1<<endl;
        cout<<"VAL OF i="<<i<<endl;
        cout<<"VAL OF j="<<j<<endl;
        cout<<S[i]<<" "<<S[j]<<endl;
    }
    cout<<endl;
}


//PRGA to generate a random key stream
void PRGA()
{
    int i=0,j=0;
    int t,k,m=0;;
    while(i<4) //
    {
        i=(i+1) % 8;
        j=(j+S[i]) % 8;
        swap(i,j);
        t = (S[i] + S[j]) % 8;
        k = S[t];

        KEYSTREAM[m]=k; // storing the key stream  for encryption
        m++;
    }
    cout<<endl;
}


//disp key stream
void showKeyStream()
{
    cout<<"KEY STREAM = ";
    for(int n=0;n<4;n++)
    {
        cout<<KEYSTREAM[n]<<" ";
    }
    cout<<endl;
}


// function to display values of S array for testing perpose
void displayS()
{
    for(int i=0;i<8;i++)
    {
        cout<<S[i]<<" ";
    }
    cout<<endl;
}


//ENCRYPTON CODE.......
void encryptionAlgo()
{
    cout<<"**********************************ENCRYPTION ALGORITHM****************************"<<endl;
    //we know CipherText => Plaintext XOR Keystream
    cout<<"Cipher text= "<<endl;
    for(int z=0;z<4;z++)
    {
        cipherText[z] = P[z] xor KEYSTREAM[z];
        cout<<cipherText[z]<<" ";
    }
}


//DECRYPTION ALGO...
void decryptionAlgo()
{
    cout<<"\n**********************************DECRYPTION ALGORITHM****************************"<<endl;
    cout<<"plaint text = ";
    // we know plaintext = ciphertext XOR keystream
    for(int z=0;z<4;z++)
    {
        P[z] = cipherText[z] xor KEYSTREAM[z];
        cout<<P[z]<<" ";
    }

}

int main()
{
    cout<<"values of S before permutaion"<<endl;
    displayS();

    KeySchedulingAlgo();
    cout<<"values of S AFTER permutaion"<<endl;
    displayS();

    PRGA();
    
    showKeyStream();

    encryptionAlgo();

    decryptionAlgo();
}