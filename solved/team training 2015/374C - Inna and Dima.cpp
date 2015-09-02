#include<bits/stdc++.h>
using namespace std;

#define INF 100000000

int mx[4] = {1,0,-1,0};
int my[4] = {0,1,0,-1};
int n,m,cycle,ans;


char board[1005][1005];
int memo[1005][1005],DIMA[256], vi[1005][1005];


bool check(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int solve(int x, int y){
    if(vi[x][y] == 2) return memo[x][y];
    if(vi[x][y] == 1){      
        vi[x][y] = 2;        
        return memo[x][y] = INF;
    }   
    
    vi[x][y] = 1;
    int ans = 0;
    for(int i = 0; i < 4; i++){
        int xt = x + mx[i];
        int yt = y + my[i];
        if(check(xt,yt) && DIMA[board[x][y]] == board[xt][yt])
                ans = max(ans,solve(xt,yt)+1);
    }
    
    vi[x][y] = 2;
    return memo[x][y] = min(ans,INF);
    
}


int main(){
    while(cin >> n >> m){
        DIMA['D'] = 'I',DIMA['I'] = 'M',DIMA['M'] = 'A',DIMA['A'] = 'D';
        
        for(int i = 0; i < n; i++)for(int j = 0; j < m; j++) cin >> board[i][j];
        
        ans = 0;
        memset(vi,0,sizeof vi);
        memset(memo,-1,sizeof memo);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'D' && !vi[i][j])
                    ans = max(ans,solve(i,j));
            }
        }
        
        if(ans == INF)        cout << "Poor Inna!" << endl;
        else if(!((ans+1)/4)) cout << "Poor Dima!" << endl;     
        else                  cout << (ans+1)/4 << endl;
    }
}
