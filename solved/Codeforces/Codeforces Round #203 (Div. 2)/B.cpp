// http://codeforces.com/contest/350/problem/B

using namespace std;
#include<bits/stdc++.h>
#define For(i,n) for(int i = 0; i< (n); ++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) (x).begin(),(x).end()
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl

template <class T> string to_str(const T &x){ stringstream s; s << x; return s.str(); }
template <class T> int to_int(const T &x){ stringstream s; s << x; int r; s >> r; return r; }



int main(){ ___
    int n;
    while(cin>>n){
        vector<int> is_hotel(n);
        For(i,n)cin>>is_hotel[i];
        vector<int> g(n);
        vector<int> incoming(n,0);
        For(i,n){
            cin>>g[i];
            g[i]--;
            if(g[i]>=0)
                incoming[g[i]]++;
        }
           
        
        vector<int> visited(n,0);
        int ans = -1;
        int len = 0;
        for(int i = 0 ; i< n; ++i){
            if(!is_hotel[i])continue;
            if(visited[i])continue;
            int tmp = 0;
            int j = i;
            while(g[j]!=-1){
                if(incoming[g[j]]>1)break;
                tmp++;
                j = g[j];
            }
            if(len < tmp){
                ans = i;
                len = tmp;
            }
        }        
        if(ans == -1){
            For(i,n){
                if(is_hotel[i]){
                    cout<<1<<endl<<(i+1)<<endl;
                    break;
                }
            }
        }else{
            vector<int> res;
            int j = ans;
            while(g[j]!=-1){
                res.push_back(j);
                if(incoming[g[j]]>1)break;
                j = g[j];
            }
            if(g[j]==-1)res.push_back(j);
            reverse(all(res));
            cout<<res.size()<<endl;
            For(i,res.size()){if(i)cout<<" ";cout<<(res[i]+1);}
            cout<<endl;
        }
    }
    
    return 0;   
}