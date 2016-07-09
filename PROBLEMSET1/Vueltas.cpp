#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int matriz[1002][1002];
int n;
int m;
int q;
int inserta(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=m-1;j++){
            cin>>matriz[i][j];
        }
    }
}
int vueltaHorizontal(){
    int ola=0;
    for(int i=0;i<=n-1;i++){
            for(int j=m-1;j>ola;j--){
                swap(matriz[i][ola],matriz[i][j]);
                ola++;
            }
            ola=0;
    }
}
int vueltaVertical(){
    int contador=0;
    for(int i=0;i<=m-1;i++){
            for(int j=n-1;j>contador;j--){
                swap(matriz[j][i],matriz[contador][i]);
                contador++;
            }
            contador=0;
    }
}
int hor=0;
int ver=0;
char hola[50002];
int query(){
    cin>>q;
    for(int i=0;i<=q-1;i++){
        cin>>hola[i];
    }
    for (int j=0;j<=q-1;j++){
        if(hola[j]=='H'){
            hor=1-hor;
        }else if(hola[j]=='V'){
            ver=1-ver;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    inserta();
    query();
    if(hor==1){
        vueltaHorizontal();
    }
    if(ver==1){
        vueltaVertical();
    }
    for(int k=0;k<=n-1;k++){
        for(int p=0;p<=m-1;p++){
            cout<<matriz[k][p]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
