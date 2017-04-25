// http://codeforces.com/contest/57/problem/A

using namespace std;
#include<bits/stdc++.h>
#define MP 1001


int main(){
   int n, __x1,__y1,__x2,__y2;
   while(cin>>n>>__x1>>__y1>>__x2>>__y2){
        queue<pair<pair<int,int>,int> > Q;
        int visited[MP][MP];
        memset(visited,false , sizeof visited);
        Q.push(make_pair(make_pair(__x1,__y1), 0));
        
        int mio;
        while(!Q.empty()){
            int x = Q.front().first.first;    
            int y = Q.front().first.second;
            int ans = Q.front().second;
            Q.pop();
            if(visited[x][y])continue;
            visited[x][y] = true;
            if(x == __x2 and y == __y2){
                mio = ans;
                break;
            }
            if(x== 0 or x==n){
                Q.push(make_pair(make_pair(x,max(0,y-1)),ans+1));
                Q.push(make_pair(make_pair(x,min(n,y+1)),ans+1));
            }
            if(y == 0 or y == n){
                Q.push(make_pair(make_pair(max(0,x-1),y),ans+1));
                Q.push(make_pair(make_pair(min(n,x+1),y),ans+1));
            }
            
        }
        
        cout<<mio<<endl;
       
   }
    
   return 0;
}