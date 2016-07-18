#include <iostream>
#include <vector>
using namespace std;
struct ura{
    int posicion;
    int tama;
};
vector<ura> pila;
vector<int>arreglini;
long long int n, tope=0;
int magia(){
    long long int retorno=0;
    for(int i=1;i<=n;i++){
        int dato=arreglini[i];
        if(dato>=pila[tope].tama){
            tope++;
            pila[tope].tama=dato;
            pila[tope].posicion = i;
        }else{
            while(pila[tope].tama>=dato and tope>=0){
                long long int variable=(i-pila[tope].posicion)*(pila[tope].tama);
                retorno=max(retorno,variable);
                tope--;
            }
            tope++;
            pila[tope].tama=dato;
        }
    }
    return retorno;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    pila.resize(n+1);
    arreglini.resize(n+1);
    for(int i=0;i<n;i++){
        cin>>arreglini[i];
    }
    arreglini[n]=0;
    pila[tope].posicion=0;
    pila[tope].tama=arreglini[0];
    //cout<<magia();
    long long int salida=0;
    for(int i=1;i<=n;i++){
        int altura=arreglini[i];
        if(altura>=pila[tope].tama){
            tope++;
            pila[tope].tama=altura;
            pila[tope].posicion=i;
        }else{
            while( pila[tope].tama>=altura and tope>=0){
                long long int diferencia=i-pila[tope].posicion;
                long long int a=diferencia*pila[tope].tama;
                salida=max(salida,a);
                tope--;
            }
            tope++;
             pila[tope].tama=altura;
        }
    }
    cout<<salida;
    return 0;
}
