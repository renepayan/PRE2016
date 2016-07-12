#include <iostream>

using namespace std;
long long int funcion(long long int dia){
    return (dia*dia)+((dia+1)*(dia+1));
}
long long int another(long long int x){
    return (x*(x+1))/2;
}
long long int minimo=0,maximo;
bool binaria(long long int dias, long long int dimension, long long int x, long long int y, long long int limite){
        long long int altura_superior=max(0ll,dias-(dimension-(y+1)));
        long long int altura_izquierda=max(0ll,dias-x);
        long long int altura_fondo=max(0ll,dias-y);
        long long int altura_derecha=max(0ll,dias-(dimension-(x+1)));
        long long int area_superior=altura_superior*altura_superior;
        long long int area_derecha=altura_derecha*altura_derecha;
        long long int area_izquierda=altura_izquierda*altura_izquierda;
        long long int area_fondo = altura_fondo*altura_fondo;
        long long int centro = funcion(dias)-area_izquierda-area_fondo-area_derecha-area_superior;
        long long int nw = max(0ll,altura_superior-(x+1));
        long long int ne = max(0ll,altura_superior-(dimension-x));
        long long int se = max(0ll,altura_fondo-(dimension-x));
        long long int sw = max(0ll,altura_fondo-(x+1));
        centro+=another(nw)+another(ne)+another(se)+another(sw);
        return centro>=limite;
}
long long int n, x, y, z;
int main()
{
    cin >> n >> x >> y >> z;
    x-=1;
    y-=1;
    maximo=(2*n)+1;
    while(minimo<maximo){
        if(binaria((minimo+(maximo-minimo)/2),n,x,y,z)){
            maximo=minimo+(maximo-minimo)/2;
        } else {
            minimo=(minimo+(maximo-minimo)/2)+1;
        }
    }
    cout<<minimo;
    return 0;
}
