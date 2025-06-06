#include <iostream>
#include <cstring>

using namespace std;


typedef struct ciudad{
    string nome;
    string provincia;
    string regione;
    int cap;
    int popolazione;
}citta;

void insertion(citta citta[],int n){

    cout<<"inserisci i tuoi dati"<<endl;
    cout<<"Nome città"<<endl;
    cin>>citta[n].nome;
    cout<<"Provincia"<<endl;
    cin>>citta[n].provincia;
    cout<<"CAP"<<endl;
    cin>>citta[n].cap;
    cout<<"popolazione"<<endl;
    cin>>citta[n].popolazione;
    cout<<"regione"<<endl;
    cin>>citta[n].regione;
   
   
}

 void print(citta citta[],int n){
         for (int i=0; i<n;i++){
     cout<<"Nome: "<<citta[i].nome<<endl;
     cout<<"Provincia: "<<citta[i].provincia<<endl;
     cout<<"CAP: "<<citta[i].cap<<endl;
     cout<<"regione: "<<citta[i].regione<<endl;
     cout<<"popolazione: "<<citta[i].popolazione<<endl;
     cout<<endl;
       
    }
 }

void sort(citta citta[],int n) {
    ciudad temp;

   for(int i=0; i<n;i++){
       for(int k=0;k<n-1;k++)
           if(citta[k].cap>citta[k+1].cap){
              temp=citta[k];
               citta[k]=citta[k+1];
               citta[k+1]=temp;
           }
   }

}

void search(citta citta[],int n){
        int cerca;
        cin>>cerca;
    for(int i=0; i<n; i++){
        if(cerca==citta[i].cap){
         cout<<"modifica la popolazione di "<<citta[i].nome <<"("<<citta[i].popolazione<<")"<<endl;
         cin>>citta[i].popolazione;
        }
    }    
}


int main()
{
   
       
    citta citta[100];
    int scelta;
    int n=0;
   
    while(true){
    cout<<"Scegli che cosa fare:"<<endl;
    cout<<"1:Inserisci una città nuova"<<endl;
    cout<<"2:Guarda la lista di tutte le città"<<endl;
    cout<<"3: Ordina le città in ordine di CAP"<<endl;
    cout<<"4:cambia la popolazione di una città"<<endl;
    
    cin>>scelta;
   
    switch(scelta){
    case 1:
    insertion(citta,n);
    n++;
    break;
   
    case 2:
    print(citta,n);
    break;
   
    case 4:
    cout<<"inserisci il CAP della città"<<endl;
    search(citta, n);
     break;  
     
     case 3:
     sort(citta,n);
     cout<<"le città sono state ordinate per CAP."<<endl;
     print(citta, n);
     
    }
   
   
    }
return 0;
}
