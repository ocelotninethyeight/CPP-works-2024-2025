#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

using namespace std;
int main(){

    srand((time(0)));
    int N=7,v[N][N],max;
   
    for(int i=0; i<N; i++)
    for(int j=0;j<N;j++){
        v[i][j]=rand()%9+1;
        if(i==j){
            v[i][j]=0;
        }
        if(v[i][j]>max){
            max=v[i][j];
        }
    }
   
        for(int i=0; i<N; i++){
        for(int j=0;j<N;j++){
            cout<<v[i][j]<<" ";
           
        }
    cout<<endl;
    }
   
   cout<<"il numero massimo e' "<<max;

    return 0;
}
