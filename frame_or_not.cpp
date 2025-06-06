#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
int n=4, v[n][n], colore;
bool cornice=true;
srand((time(0)));

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      v[i][j]=rand()%255+1;
          }
}
    
   for(int i=0; i<n; i++){
            for(int j=0;j<n;j++){
    cout<<v[i][j]<<" ";

    }
           cout<<endl;
    }
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
          if(v[1][j]!=v[0][0]||v[n-1][j]!=v[0][0]||v[i][1]!=v[0][0]||v[i][n-1]!=v[0][0]){
 for(int j=0;j<n;j++){
    if(v[1][j]!=v[0][0]||v[n-1][j]!=v[0][0]){
        cornice=false;
    }
          }
          
         for(int i=0;i<n;i++){
    if(v[i][1]!=v[0][0]||v[i][n-1]!=v[0][0]){
        cornice=false;
    }
          }
    }
          }
}
    
          
if(cornice==true){
cout<<"la cornice e' presente"<<endl;    
}else
cout<<"la cornice non e' presente"<<endl;

}
