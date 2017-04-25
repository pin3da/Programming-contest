// http://codeforces.com/contest/159/problem/A

using namespace std;
#include<bits/stdc++.h>
#define For(i,n) for(int i = 0; i< (n); ++i)
#define foreach(it,n) for(typeof ((n).begin()) it = n.begin();  it != (n).end(); ++it )
#define D(x) cout<<#x " = "<<(x)<<endl
#define all(x) x.begin(),x.end()

int main(){
    int n,d;cin>>n>>d;
    
    map<string,int> cod;
    map<int,string> dec;
    
    vector<int> mat[2*n][2*n];
    string a,b;
    int _index = 0;
    set<pair<string,string> > ans;
    For(i,n){
        cin>>a>>b;
        if(cod.count(a) == 0)
            cod[a] = _index++;
        if(cod.count(b) == 0)
            cod[b] = _index++;
            
        int t;cin>>t;
        mat[cod[a]][cod[b]].push_back(t);
        if(mat[cod[b]][cod[a]].size()>0){
            foreach(kk,mat[cod[b]][cod[a]]){
                int mio = *kk;
                if(((t - mio) <= d) and ((t - mio) > 0)){
                    ans.insert(make_pair(min(a,b),max(a,b)));
                }
           }
        }
    }
    cout<<ans.size()<<endl;    
    
    foreach(it,ans)
        cout<<it->first<<" "<<it->second<<endl;
        
    return 0;
}