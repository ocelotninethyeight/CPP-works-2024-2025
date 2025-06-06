#include <iostream>
#include <string>

using namespace std;

int main()
{
string str;
int parole=1,caratteri[80],r=0;
getline(cin,str);

for(int i=0;i<80;i++){
    caratteri[i]=0;
}

for(int i=0;i<str.length();i++){
    if(str[i]==' '||str[i]=='\0'||str[i]=='\n'){
        parole++;
        r++;
    }else{
        caratteri[r]++;
    }
}

cout<<"ci sono in tutto "<<parole<<" parole"<<endl;
for(int i=0;i<r+1;i++){
    cout<<caratteri[i]<<" ";
}
    return 0;
}
