#include <algorithm>
#include <iostream>
using namespace std;
int n, m;
struct ura{
    int Mini,Maxi;
    const bool operator < (const ura &otro)const{
        return Maxi-Mini<otro.Maxi-Mini;
    }
};
struct nel{
    int oi,ci;
    const bool operator < (const nel &otro)const{
            return oi<otro.oi;
    }
};
nel capsulas[2502];
ura Nanobots[2502];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>Nanobots[i].Mini>>Nanobots[i].Maxi;
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>capsulas[i].oi>>capsulas[i].ci;
    }
    sort(Nanobots+1, Nanobots+1+n);
    sort(capsulas+1, capsulas+1+m);
    int salida=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(Nanobots[i].Mini<=capsulas[j].oi and Nanobots[i].Maxi>=capsulas[j].oi and capsulas[j].ci>0){
                capsulas[j].ci--;
                salida++;
                i++;
                j=0;
            }
        }
    }
    cout<<salida;
    return 0;
}
