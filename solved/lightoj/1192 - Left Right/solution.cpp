using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl

string solve(){
    int n;
    cin>>n;
    int nim = 0;
    for(int i = 0; i < n; ++i){
        int a,b;cin>>a>>b;
        nim ^= (b-a-1);
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
