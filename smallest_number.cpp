#include <iostream>

using namespace std;


int main () {
	int w=0,n,nmin;
	while (true){
		cout<<"conteggio numero minore"<<endl<<"inserisci un numero"<<endl;
		cin>>n;
		if (n<0){
			cout<<"operazione impossibile, riprovare"<<endl;
			cin>>n;
		}else {
			if (n==0) {
				break;
			}
				}
				if(nmin==0){
					nmin=n;
				}
					
			if(n<nmin){
				nmin=n;
			}
			
			cout<<"il numero minore e' "<<nmin<<endl;
	
	}
		cout<<"il conteggio dei numeri e' finito, con  "<<nmin<<" come numero minore"<<endl;
		return 0;
}
