#include <bits/stdc++.h>
using namespace std;
int MCD(long long int a, long long int b){
    if(b==0){
        return a;
    }else{
        return MCD(b,a%b);
    }
}
short n;
long long int a, b;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        if(MCD(a,b)==1){
            cout<<"SI"<<'\n';
        }else{
            cout<<"NO"<<'\n';
        }
    }
    return 0;
}
