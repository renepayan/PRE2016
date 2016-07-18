#include <bits/stdc++.h>
struct ura{
    int dato, posicion;
    const bool operator <(const ura &otro)const{
        return  dato<otro.dato;
    }
};
using namespace std;
vector<ura> arreglini;
int n, h, w,lugar=1;
long long int suma=0, caja=0, target=0;
int procesa(){
    if(arreglini[lugar].dato<target){
        caja+=(arreglini[lugar].posicion)*(target-arreglini[lugar].dato);
        lugar++;
        procesa();
    }else{
        suma+=caja;
        return suma;
    }
}
int verifica(){
    int ontoy=1,contador=0;
    while(ontoy<=n and contador<w){
        if(arreglini[ontoy].dato>=h){
            contador++;
        }else{
            contador=0;
        }
        ontoy++;
    }
    if(contador==w){
        return 1;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>h>>w;
    arreglini.resize(n+2);
    for(int i=1;i<=n;i++){
        cin>>arreglini[i].dato;
        arreglini[i].posicion=i;
    }
    if(verifica()==-1){
        sort(arreglini.begin()+1, arreglini.begin()+n+1);
        bool used=false;
        for(int i=1;i<=n and used==false;i++){
            if(arreglini[i].dato>=h){
                used=true;
                target=arreglini[i].dato;
            }
        }
        if(target<h){
            target=h;
        }
        procesa();
        cout<<suma;
    }else{
        cout<<0;
    }
    return 0;
}
