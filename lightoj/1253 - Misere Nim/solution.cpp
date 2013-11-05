using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl

string solve(){
    int n;
    cin>>n;
    int ones = 0;
    int nim  = 0;
    for(int i = 0; i < n; ++i){
        int t;cin>>t;
        ones += (t==1);
        nim ^= t;
    }
    
    int no_ones = n - ones;
    if(no_ones >= 1) return (nim)? "Alice":"Bob";
    else return (ones&1)? "Bob":"Alice";
}


int main(){ ___
    
    int tc;
    cin>>tc;
    for(int i = 0; i < tc; ++i)
        cout<<"Case "<<(i+1)<<": "<<solve()<<endl;
    return 0;
}
