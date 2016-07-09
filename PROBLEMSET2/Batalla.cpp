#include <iostream>
#include <algorithm>
using namespace std;
int n;
int Mi[51];
int Lira[51];
int usados[51];
int sumatoria=0;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>Mi[i];
        sumatoria+=Mi[i];
    }
    for(int i=1;i<=n;i++){
        cin>>Lira[i];
    }
    sort(Lira+1, Lira+1+n);
    sort(Mi+1, Mi+1+n);
    for(int i=n;i>=1;i--){
        for(int j=n;j>=1;j--){
            if(Mi[i]>Lira[j] && usados[j]==0){
                usados[j]=Mi[i];
                Mi[i]=0;
                j=0;
            }
        }
        if(Mi[i]!=0){
            sumatoria-=Mi[i];
        }
    }
    cout<<sumatoria;
    return 0;
}
