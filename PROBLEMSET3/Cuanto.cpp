#include <iostream>
#include <vector>
using namespace std;
int a, b;
vector<int> barras;
int funcion(int valor){
    int suma=0;
    for(int i=1;i<=a;i++){
        int lol=barras[i]/valor;
        suma+=lol;
    }
    return suma;
}
int binaria(int ini, int fin){
    int centro=(ini+fin+1)/2;
    int z=funcion(centro);
    if(ini<fin){
        if(z>=b){
            return binaria(centro, fin);
        }else{
            return binaria(ini, centro-1);
        }
    }else{
        return ini;
    }
}
int main()
{
   cin>>a>>b;
   barras.resize(a+1);
   for(int i=1;i<=a;i++){
    cin>>barras[i];
   }
   cout<<binaria(1, 1000000);
    return 0;
}
