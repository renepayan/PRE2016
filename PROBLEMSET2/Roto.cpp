#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <stdio.h>
using namespace std;
char texto[100005];
char nel[100000];
char prro[100000];
void nelprro(){
	int sal=0;
	int sal2=0;
	int posicion = 0;
	bool direccion = true;
	while(posicion<strlen(texto)){
        if(texto[posicion] == '[' or texto[posicion] == ']' ){
			if(texto[posicion]==']'){
                direccion=true;
			}else{
                direccion=false;
			}
            posicion+=1;
		}else{
            if(direccion==true){
                    for(int i=posicion;posicion<strlen(texto) and texto[posicion]!='[' and texto[posicion]!=']';i++){
                        nel[sal]=texto[i];
                        //nel.insert(sal, 1, texto[posicion]);
                        posicion++;
                        sal++;
                    }
            }else{
                int d=posicion;
                for(int i=0;d<strlen(texto) and texto[d]!='[' and texto[d]!=']';i++){
                    //nel.insert(i, 1,texto[posicion]);
                    d++;
                }
                for(int i=d-1;i>=posicion;i--){
                    prro[sal2]=texto[i];
                    sal2++;
                }
                posicion=d;
            }
        }
    }
    for(int i=sal2;i>=0;i--){
		if(prro[i]!='\000'){
            cout<<prro[i];
        }
	}
	for(int i=0;i<sal;i++){
        cout<<nel[i];
	}
}
int main(){
	while(gets(texto)){
        nelprro();
	}
	return 0;
}
