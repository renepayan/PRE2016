#include <bits/stdc++.h>

using namespace std;
struct nodo{
    int posicion;
    int menor;
    vector<int>lista;
};
vector<nodo> exito;
int numeros=1;
int order(int posicion){
    int MINI=INT_MAX;
    for(int i=0;i<exito[posicion].lista.size();i++){
        MINI=min(order(exito[posicion].lista[i]),MINI);
    }
    exito[posicion].posicion=numeros++;
    if(MINI==INT_MAX)exito[posicion].menor=exito[posicion].posicion;
    else exito[posicion].menor=MINI;
    return exito[posicion].menor;
}
int n, q, nel, creatividad;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;
    exito.resize(n+2);
    for(int i=1;i<n;i++){
        cin>>nel>>creatividad;
        //exito[nel].lista.resize(1);
        exito[nel].lista.push_back(creatividad);
    }
    order(1);
    for(int i=1;i<=q;i++){
        cin>>nel>>creatividad;
        if(exito[creatividad].posicion<=exito[nel].posicion and exito[creatividad].posicion>=exito[nel].menor){
            cout<<0<<'\n';
        }else{
            cout<<1<<'\n';
        }
    }
    return 0;
}
