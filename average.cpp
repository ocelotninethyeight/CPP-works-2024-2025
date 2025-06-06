#include <iostream>
using namespace std;
int main() {

    int c;
    int w=0;
    float n,s=0,m;

    cout<<"inserisci di quanti numeri vuoi fare la media"<<endl;
    cin>>c;

    while(w<c) {
        cout<<"inserisci un numero di cui fare la media"<<endl;
        cin>>n;
        
        s=s+n;
        n=0;
        w++;
    }

    m=s/c;
    cout<<"la media e' risultata "<<m;

    return 0;

}
