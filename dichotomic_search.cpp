#include <iostream>
using namespace std;
int main()
{
//ricerca dicotomica in un vettore di N numeri ordinati
int N=5,v[N], sup=0, inf=N-1, x, pos=-1,j,temp;

for(int i=0;i<N;i++){
    cout<<"inserisci un numero"<<endl;
    cin>>v[i];
}
for(int i=0;i<N-1;i++){
    for(j=i+1;j<N;j++)
           if(v[i]>v[j]){
               temp=  v[i];
               v[i]=v[j];
               v[j]=temp;    
           }
    }



cout<<"Inserisci il numero da cercare: "<<endl;
cin>>x;
while (sup <= inf && pos==-1) {
       int m =  (inf+sup) / 2;


       // Controllo se x è presente al centro
       if (v[m] == x)
           pos= m;


       // Se x è maggiore, ignora la metà superiore
       if (v[m] < x)
           sup = m + 1;


           // Altrimenti, ignora la metà inferiore
       else
           inf = m - 1;
   }
if (pos==-1)
   cout<<"Numero non trovato: "<<endl;
else
   cout<<"il numero trovato nella posizione: "<<pos<<endl;

}
