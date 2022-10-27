// PRNG - Linear Congurential Method
// this algorithm is used to generate sequence of random numbers
#include<iostream>
using namespace std;

//function code to generate random numbers 
void linearCongruentialMethod(int x0,int a,int c,int m)
{
    int i=x0;
    int xi=0;
    cout<<"random numbers are:- "<<endl;
    while(xi != x0)
    {
        xi = ( (a*i) + c) % m;
        i=xi;
        cout<<xi<<" ";
    }
    cout<<endl;
}

//main method
int main()
{
    int x0,a,c,m;
    cout<<"Enter Values For X0, a, c, m :"<<endl;
    cin>>x0>>a>>c>>m;
    linearCongruentialMethod(x0,a,c,m);
}
