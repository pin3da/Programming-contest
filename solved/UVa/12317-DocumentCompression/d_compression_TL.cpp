using namespace std;
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

#define oo 0x00FFFFFF
#define all(x) x.begin(),x.end()
#define D(x) cout<<  #x " = " <<(x)<<endl

vector<vector<int> > docs, mess;
int dp[1<<17][110];

int solve(int mask,int index,const vector<int> &message){
    if(index == docs.size()) return (mask==0) ? 0: oo;
    if(dp[mask][index] != -1) return dp[mask][index];
    int newmask = mask;
    for(int i = 0; i< 20; ++i)
        if(mask&(1<<i))
            if(find(all(docs[index]),message[i]) != docs[index].end())
                newmask ^= (1<<i);

    int bien = 1;
    for(int i = 0 ; i < docs[index].size(); ++i)
        if(find(all(message),docs[index][i])==message.end()) {
            bien = 0;
            break;
        }
            
    
    int ans = solve(mask,index+1,message);
    if(bien)
        ans = min(ans,solve(newmask,index+1,message)+1);
        
    return dp[mask][index] = ans;
    
}

int main(){
    int n,m;
    while(cin>>n>>m and (n+m)){
        docs = vector<vector<int> >(n);
        mess = vector<vector<int> >(m);
        
        for(int i = 0; i< n; ++i){
            int k;cin>>k;
            docs[i] = vector<int> (k);
            for(int j = 0; j< k; ++j){
                cin>>docs[i][j];
            }
        }
        for(int i = 0; i < m; ++i){
            int k;cin>>k;
            mess[i] = vector<int> (k);
            for(int j = 0; j< k; ++j){
                cin>>mess[i][j];
            }
        }
        for(int i = 0; i < m; ++i){
            memset(dp,-1,sizeof(dp));
            if(i>0)cout<<" ";
            int answer = solve((1<<mess[i].size())-1,0,mess[i]);
            if(answer >= oo) cout<<0;
            else cout<<answer;
        }
        cout<<endl;
        
    }
    return 0;
}

