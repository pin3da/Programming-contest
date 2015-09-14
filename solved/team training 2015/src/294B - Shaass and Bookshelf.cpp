#include<bits/stdc++.h>
using namespace std;

#define INF 32760

pair<int,int>  books[105];
int n;
int memo[105][205][205];


int solve(int idx, int curT, int curW){

    if(idx == n && curT >= curW)  return curT;
    if(idx == n)                  return INF;
    

    if(memo[idx][curT][curW] != -1) return memo[idx][curT][curW];
    
    int ans = INF;
    if(curW + books[idx].second < 203)
        ans = min(ans,solve(idx+1, curT,curW + books[idx].second));
    ans = min(ans,solve(idx+1, curT + books[idx].first, curW ));
    
    return memo[idx][curT][curW] = ans;
}

int main(){

    while(cin >> n ){
        
        for(int i = 0; i < n; i++)
            cin >> books[i].first >> books[i].second;
   
     
        memset(memo, -1, sizeof memo);
        cout << solve(0,0,0) << endl;
    }
}
