#include <iostream>

using namespace std;


int main() {
   int N=5,i,temp;
   int v[N];
   bool f=true;
   for(int i=0; i<N;i++)
       cin>>v[i];
  for(int i=0;i<N-1;i++){  
      do{
          f=false;
       for(int k=i+1;k<N;k++){
           if(v[i]>v[k]){
              temp=v[k];
               v[k]=v[i];
               v[i]=temp;
		        f=true;

           }

       }
   }while(f);
}
for (int i=0;i<N;i++)
cout<<v[i]<<endl;
   return 0;
}



