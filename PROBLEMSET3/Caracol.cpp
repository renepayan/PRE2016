#include "caracol.h"
int segunda(int desde, int hasta, int veces, int re){
    int centro=(desde+hasta)/2;
    int ask=(centro*veces)-(centro*re);
    int x=pregunta(ask);
    if(x==0){
        return centro;
    }else if(x==2){
        return segunda(desde, centro-1, veces, re+1);
    }else if(x==-2){
        return segunda(desde, centro-1, veces, re+1);
    }else if(x==3){
        return segunda(centro+1, hasta, veces, re+1);
    }else{
        return (ask)/(veces-re);
    }
}
int binaria(int desde, int hasta, int veces){
    int centro=(desde+hasta)/2;
    int ask=centro*veces;
    int x=pregunta(ask);
    if(x==0){
        int z=pregunta(centro*(veces+1));
        if(z==0){
            return centro;
        }else if(z==2){
            return segunda(desde, hasta, veces-2, 2);
        }else{
            return centro;
        }
    }else if(x==1){
        return binaria(centro+1, hasta, veces+1);
    }else if(x==-1){
        return binaria(desde, centro-1, veces+1);
    }else{
        return segunda(desde-1, hasta, veces-1, 2);
    }
}
int velocidad() {
    return binaria(0, 1e6, 1);
}
