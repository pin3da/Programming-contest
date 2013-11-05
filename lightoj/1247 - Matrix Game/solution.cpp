using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl

string solve(){
    int n,m;
    cin>>n>>m;
    int nim = 0;
    for(int i = 0; i < n; ++i){
        int row = 0;
        for(int j = 0; j < m; ++j){
            int t;cin>>t;
            row += t;
        }
        
        nim ^= row;
    }
    return (nim)?"Alice":"Bob";
}


int main(){ ___
    
    int tc;
    cin>>tc;
    for(int i = 0; i < tc; ++i)
        cout<<"Case "<<(i+1)<<": "<<solve()<<endl;
    return 0;
}
