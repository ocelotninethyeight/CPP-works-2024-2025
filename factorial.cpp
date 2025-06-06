#include <iostream>

using namespace std;

int factorial(int n){
    int v=1;
    for(int i=n;i>1;i--){
        v=v*i;
    }
    return v;
}


int main()
{
    int n,v;
    cout<<"inserisci un numero"<<endl;
    cin>>n;
    v=factorial(n);
    cout<<"il suo fattoriale e' "<<v<<endl;
    return 0;
}
