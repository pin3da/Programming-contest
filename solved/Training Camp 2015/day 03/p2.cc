#include<bits/stdc++.h>

using namespace std;

vector<int> G[500005];
bool v[500005];
bool bad[500005];


void dfs(int n,int padre,vector<int> &ans){
    v[n] = 1;
    if(!G[n].size()){
        if(!bad[n] && !bad[padre]){
            bad[n] =  bad[padre] = 1;
            ans.push_back(n);
        }
        return;
    }
    
    for(int i=0;i<G[n].size();i++){
        int curr = G[n][i];
        if(v[curr])continue;
        dfs(curr,n,ans);
    }
     
    if(!bad[n]){
        if(!bad[padre] && padre){
            bad[n] = bad[padre] = 1;
            ans.push_back(n);
        }
        
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t,n,s;cin>>t;
    
    while(t-- && cin>>n){
        for(int i=1;i<=n;i++)G[i].clear();
        for(int i=2;i<=n;i++){
            cin>>s;
            G[s].push_back(i);
        }
        memset(v,0,sizeof v);
        memset(bad,0,sizeof bad);
        

        vector<int> ans;
        dfs(1,0,ans);
        sort(ans.begin(),ans.end());
        cout<<ans.size()*1000<<endl;
        for(int i=0;i<ans.size();i++){
            if(i)cout<<" ";
            cout<<ans[i];
        }
        cout<<endl;
        if(t)cout<<endl;
    }
}
