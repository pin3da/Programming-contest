// WA
using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(0);cin.tie(0);
#define D(x) cout<< #x " = "<<(x)<<endl

typedef unsigned int hash;
const int pi = 1549;

void solve(){
    string cad;cin>>cad;
    int p,q;cin>>p>>q;

    set<hash> ans;

    for(int i = 0; i + p <= cad.size(); ++i){
        hash h = 0;
        for(int l = 0; l < p; ++l)
            h = (h + (cad[i+l] - 'a' + 1)) * pi;
        ans.insert(h);
        for(int l = p; i+l < cad.size() and l < q; ++l){
            h = (h + (cad[i+l] - 'a' + 1)) * pi;
            ans.insert(h);
        }
    }

    cout<<ans.size()<<endl;
}


int main(){ ___

    int t;cin>>t;
    for(int i = 0; i< t; ++i){
        cout<<"Case "<<(i+1)<<": ";
        solve();
    }
    return 0;

}
