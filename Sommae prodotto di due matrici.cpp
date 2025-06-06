#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
    int n=3,m1[n][n],m2[n][n],s[n][n], p[n][n];
    srand((time(0)));
    
    for(int i=0; i<n;i++){
        for(int j=0;j<n;j++){
            m1[i][j]=rand()%10+1;
            m2[i][j]=rand()%10+1;
        }
    }
    
    
        cout<<"prima matrice"<<endl;
        for(int i=0; i<n;i++){
        for(int j=0;j<n;j++){
            cout<<m1[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<"seconda matrice"<<endl;
            for(int i=0; i<n;i++){
        for(int j=0;j<n;j++){
            cout<<m2[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
        
    for(int i=0; i<n;i++){
        for(int j=0;j<n;j++){
        s[i][j]=m1[i][j]+m2[i][j];
        p[i][j]=m1[i][j]*m2[i][j];
        }
    }
    
    
        cout<<"somma"<<endl;
            for(int i=0; i<n;i++){
        for(int j=0;j<n;j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
    
            cout<<"prodotto"<<endl;
            for(int i=0; i<n;i++){
        for(int j=0;j<n;j++){
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }

}
