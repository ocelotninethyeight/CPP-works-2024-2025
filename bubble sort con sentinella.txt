#include iostream
using namespace std;


int main() {
   int N=5,i,temp;
   int v[N];
   bool f=false;


   for(int i=0; iN;i++)
       cinv[i];
   
  i=N-1;
   do{
	  f=false;
       for(int k=0;ki;k++){
           if(v[k]v[k+1]){
              temp=v[k];
               v[k]=v[k+1];
               v[k+1]=temp;
		    f=true;
		     
           }
          
       }
        i--;
   }while(f);

for (int i=0;iN;i++)
coutv[i]endl;
   return 0;
}
