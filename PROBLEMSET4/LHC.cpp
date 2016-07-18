#include <bits/stdc++.h>
using namespace std;
int n, a, b;
struct ura{
    int posicion;
    int velocidad;
};
double respuesta=INT_MAX;
queue<ura>derecha;
queue<ura>izquierda;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    ura aux1;
    for(int i=1;i<=n;i++){
        cin>>aux1.posicion>>aux1.velocidad;
        if(aux1.velocidad>0){
            derecha.push(aux1);
        }else{
            izquierda.push(aux1);
        }
    }
   while(!derecha.empty() and !izquierda.empty()){
        ura uno=derecha.front();
        ura dos=izquierda.front();
        if(dos.posicion>=uno.posicion){
            double distancia=dos.posicion-uno.posicion;
            double Velocidad=uno.velocidad-dos.velocidad;
            double lol=distancia/Velocidad;
            respuesta=min(respuesta,lol);
            derecha.pop();
        }else{
            izquierda.pop();
        }
    }
    if(respuesta==double(INT_MAX)){
        cout<<-1;
    }else{
        cout << fixed;
        cout << setprecision(9)<<respuesta;
    }
    return 0;
}
