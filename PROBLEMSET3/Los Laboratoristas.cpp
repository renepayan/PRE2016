#include <iostream>
#include <stdio.h>
using namespace std;
int datos[1000002];
int binaria(int desde, int hasta, int numero){
    if(desde>hasta){
        return -1;
    }
    int centro=(desde+hasta)/2;
    if(datos[centro]==numero){
        return centro;
    }
    if(numero<datos[centro]){
        return binaria(desde, centro-1, numero);
    }else{
        return binaria(centro+1, hasta, numero);
    }
}
int inicio=1, fin=1, n, q, nuevoInicio=0, temp;
char a;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    fin=n;
    for(int i=1;i<=n;i++){
        cin>>datos[i];
    }
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>a>>temp;
        if(a=='L'){
            int x=binaria(inicio, fin, temp);
            if(x==-1){
                cout << "No Laurencio\n";
            }else{
                int div=(fin-inicio)+1;
                if(div>0){
                  x=(x-inicio+nuevoInicio+1)%div;
                    if(x<1){
                        x=(fin-inicio+1)+x;
                    }
                    cout <<x<< '\n';
                }else{
                    cout<<"No Laurencio"<<'\n';
                }
            }
        }else if(a=='M'){
            if(temp==-1){
                nuevoInicio++;
            }else{
                nuevoInicio--;
            }
            nuevoInicio%=(fin-inicio+1);
        }else{
            if(temp==1){
                fin--;
                if(nuevoInicio>0){
                    nuevoInicio--;
                    int div=fin-inicio+1;
                    if(div>0){
                        nuevoInicio%=div;
                    }else{
                        nuevoInicio=0;
                    }
                }
            }else{
                inicio++;
                if(nuevoInicio<0){
                    nuevoInicio++;
                    int div=fin-inicio+1;
                    if(div>0){
                        nuevoInicio%=div;
                    }else{
                        nuevoInicio=0;
                    }
                }
            }
        }
    }
    return 0;
}
