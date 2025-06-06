int sumv(int v[],int n){
    int s=0;
    for(int i=0;i<n;i++){
        s+=v[i];
    }
    return s;
}

int avgv(int v[],int n){
    float m=0;
    m=sumv(v,n)/n;
    return m;
}

void cv(int v[],int n){
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
}
void sv(int v[],int n){
    for(int i=0;i<n;i++){
        cout<<v[i]<<endl;
    }
}


int main()
{
int v[100],n=5;
cv(v,n);
sv(v,n);

cout<<sumv(v,n)<<endl;
cout<<avgv(v,n)<<endl;
    return 0;
}
