#include <iostream>

using namespace std;
int a, b;
int main()
{
    cin>>a>>b;
    int d=max(a,b)/min(a,b);
    if(d%2!=0){
        cout<<"tristemil";
    }else{
        cout<<"felizmil";
    }
    return 0;
}
