#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
int main()
{


int n,s;
srand((time(0)));
cout<<”inserisci quanti caratteri inserire nella password”<<endl;
cin>>n;
string password;
for(int i=0;i<n;i++){
    s=rand()%74+1;
    password+=48+s;
}

cout<<”la Password generata e’ ”<<password;

    return 0;
}
