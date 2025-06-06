#include <iostream>
using namespace std;
int main()
{
int n=4, v[n][n], somma=0, sommap=0;
bool magico=true;

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>v[i][j];
          }
}

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
  	 if(v[i][j]>n*n){
                 	magico=false;
         		break;
     	 }
              somma=somma+ v[i][j];
     }
    if(somma==sommap||sommap==0){
        sommap=somma;
        somma=0;
    }else if(somma!=sommap){
        magico=false;
        break;
    }
}

somma=0; 
sommap=0;
 if(magico){  
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
          somma=somma+ v[j][i];
       }
       if(somma==sommap||sommap==0){
        sommap=somma;
        somma=0;
      }else if(somma!=sommap){
        magico=false;
        break;
      }
    }
   }
}

 if(magico==true){
     cout<<"il quadrato è magico";
 }else
 cout<<"il quadrato non è magico";

    return 0;
}
