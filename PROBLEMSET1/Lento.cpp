#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int>arreglini;
int main()
{
    cin>>n;
    arreglini.resize(n+1);
    for(int i=0;i<n;i++){
        cin>>arreglini[i];
    }
    sort(arreglini.begin(), arreglini.end());
    reverse(arreglini.begin(), arreglini.end());
    int sumatoria = arreglini[0];
    for(int i=1;i<n;i++){
        if((arreglini[i]+sumatoria)%2 != 0){
            sumatoria+=arreglini[i];
        }
    }
    if(sumatoria%2!=0){
        cout<<sumatoria;
    }else{
        cout<<0;
    }
    return 0;
}
