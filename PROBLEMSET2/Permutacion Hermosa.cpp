#include <iostream>

using namespace std;
int n, m;
int arreglini[1000002];
int proceso(int a){
    int inicio;
    if(a%2!=0){
        inicio=2;
        a-=1;
    }else{
        inicio=1;
    }
    while(a>0){
        swap(arreglini[inicio],arreglini[inicio+1]);
        inicio+=2;
        a-=2;
    }
}
int main()
{
    cin>>n>>m;
    if(m==n){
        cout<<-1;
    }else{
        for(int i=1;i<=n;i++){
            arreglini[i]=i;
        }
        proceso(n-m);
        for(int i=1;i<=n;i++){
            cout<<arreglini[i]<<" ";
        }
    }
    return 0;
}
