#include <bits/stdc++.h>
using namespace std;
int n, v, r;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>v>>r;
    double temp;
    double maximo=0.0;
    for(int i=1;i<=n;i++){
        cin>>temp;
        temp=temp/r;
        maximo=max(maximo,temp);
    }
    cout << fixed;
    cout << setprecision(9)<<maximo;
    return 0;
}
