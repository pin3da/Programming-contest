// http://codeforces.com/contest/6/problem/B

using namespace std;
#include<bits/stdc++.h>
#define For(i,n) for(int i = 0; i< (n); ++i)
#define foreach(it,n) for(typeof ((n).begin()) it = n.begin();  it != (n).end(); ++it )
#define D(x) cout<<#x " = "<<(x)<<endl
#define all(x) x.begin(),x.end()


int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main(){
    int n,m;
    char c;
    cin>>n>>m>>c;
    
    char mat[n][m];
    For(i,n)For(j,m)cin>>mat[i][j];
    
    set<char> ans;
    For(i,n)
        For(j,m)
            if(mat[i][j]==c){
                For(k,4){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x >= 0 and x < n and y>=0 and y<m)
                        if(mat[x][y]!='.' and mat[x][y]!=c)
                            ans.insert(mat[x][y]);
                        
                }
            }
        
        
     cout<<ans.size()<<endl;
    return 0;
}