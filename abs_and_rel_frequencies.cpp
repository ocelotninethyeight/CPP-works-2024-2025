#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main(){
    int r=0,v[6],n,nr=0;
    float fa[6]; 
    
    srand((time(0)));
    
    cout<<"quante volte vuoi lanciare il dado?"<<endl;
    cin>>n;
    
    for(int i=0;i<6;i++){
    v[i]=0;
    fa[i]=0;
    }
    
    for(int i=0;i<n;i++){
        r=rand()%6;
        v[r]++;
    }
    
        for(int i=0;i<6;i++){
        fa[i]=(float)v[i]/(float)n;
    }
    
        for(int i=0;i<6;i++){
            nr=i+1;
       cout<<"il numero "<<nr<<" è uscito "<<v[i]<<" volte,"<<"e la sua frequenza relativa e' "<<fa[i]<<endl;
    }
    return 0;
