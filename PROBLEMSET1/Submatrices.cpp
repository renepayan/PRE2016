#include <bits/stdc++.h>
using namespace std;
int x, y, x2, y2;
int matriz[1001][1001];
int submatriz[1001][1001];
int matrizini[1001][1001];
int checa(int x, int y){
    int a=0, b=0;
    for(int i=x;i<x2+x;i++){
        a=a+1;
        for(int j=y;j<y2+y;j++){
            b=b+1;
            if(submatriz[a][b]!=matriz[i][j]){
                return false;
            }
        }
        b=0;
    }
    a=0;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>x>>y;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            cin>>matriz[i][j];
        }
    }
    cin>>x2>>y2;
    for(int i=1;i<=x2;i++){
        for(int j=1;j<=y2;j++){
            cin>>submatriz[i][j];
        }
    }
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            matrizini[i][j]=0;
        }
    }
    for(int i=1;i<=x-x2+1;i++){
        for(int j=1;j<=y-y2+1;j++){
            if(matriz[i][j]==submatriz[1][1]){
                if(checa(i, j)==true){
                    for(int k=i;k<x2+i;k++){
                        for(int l=j;l<y2+j;l++){
                            matrizini[k][l]=1;
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            cout<<matrizini[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
