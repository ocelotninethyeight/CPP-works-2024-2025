#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int n,c;
    string r;

    srand((time(0)));
    n=rand()%10+1;
    for (int i=0;i<3;i++){


            cout<<"vuoi un aiuto prima di provare a indovinare il tuo numero? (rispondi con si o con no)"<<endl;
            cin>>r;
            if(r=="si"){
                switch(n){
                    case 1:{
                        cout<<"questo numero e' divisibile solo per zero e per se stesso"<<endl;
                        break;
                    }
                    case 2:{
                        cout<<"questo e' l'unico numero sia pari che primo"<<endl;
                        break;
                    }
                    case 3:{
                    cout<<"e' un numero sia dispari che primo"<<endl;
                    break;
                }
                    case 5:{
                        cout<<"e' un numero sia dispari che primo"<<endl;
                        break;
                    }
                    case 7:{
                        cout<<"e' un numero sia dispari che primo"<<endl;
                        break;
                    }
                    case 6:{
                    cout<<"e' un numero divisibile per 3"<<endl;
                    break;
                }
                    case 9:{
                        cout<<"e' un numero divisibile per 3"<<endl;
                        break;
                    }
                    case 4:{
                    cout<<"e' un numero divisibile per 2 e per 4"<<endl;
                    break;
                }
                    case 8:{
                        cout<<"è un numero divisibile per 2 e per 4"<<endl;
                        break;
                    }
                }

            }
        cout<<"indovina il numero (MAX 3 TENTATIVI)"<<endl;
        cin>>c;
            if(c>n){
                cout<<"il numero e' minore, riprovare"<<endl;
            } else if(c<n){
                cout<<"il numero e' maggiore, riprovare"<<endl;
            }else{
                cout<<"il numero e' corretto"<<endl;
                return 0;
            }

    }

    return 0;
}
