#include <iostream>

using namespace std;

int fact(int );

int main(void)
{
    int n;
    cin>>n;
    
    try
    {
        cout<<n<<"!: "<<fact(n);    
    }
    catch(int n)
    {
        cout<<"n은 자연수여야 합니다. "<<endl;
    }
    
    return 0;
}

int fact(int n)
{
    if(n<=0)
        throw n;
    else if(n==1)
        return 1;
    else
        return n * fact(n-1);
}