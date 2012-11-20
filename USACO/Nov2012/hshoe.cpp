 /*
ID: pin3da
PROG: hshoe
LANG: C++
*/
using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000

template <class T> string toStr(const T &x){ stringstream s; s << x; return s.str(); }

struct state{
    int x,y;
    string vis;
    int pin,len,cierra;
    state(){}
    state(int X,int Y,string cad,int i,int L): x(X),y(Y), vis(cad),pin(i), len(L){cierra=0;}
    
};

int main(){
    freopen("hshoe.in","r",stdin);
    freopen("hshoe.out","w",stdout);
    int n;cin>>n;
    char grid[n][n];
    for(int i=0;i<n;++i)
        for(int j=0; j< n; ++j)
            cin>>grid[i][j];
            
    if(grid[0][0]==')')cout<<0<<'\n';
    else{
        queue<state> Q;
        Q.push(state(0,0,"0-",1,1));
        int ans = 0;
        while(!Q.empty()){
            state act = Q.front();
            if(act.x+1<n ){
                if(act.vis.find(toStr( (((act.x+1)*n) + act.y) ) + "-") == string::npos ){
                    act.vis+= toStr(((act.x+1)*n) + act.y)+"-";
                    act.pin+= (grid[act.x+1][act.y]=='(')?1:-1;
                    act.len++;
                    act.cierra|=grid[act.x+1][act.y]==')';
                    if(act.pin == 0){
                        ans = max(ans,act.len);
                    }else{
                        act.x++;
                        if(!(grid[act.x+1][act.y]=='(' and act.cierra))
                        Q.push(act);
                    }
                }
            }

            act = Q.front();
            if(act.x-1>=0){
                if(act.vis.find(toStr( (((act.x-1) * n) + act.y))+"-") == string::npos ){
                    act.vis+= toStr(((act.x-1)*n) + act.y)+"-";
                    act.pin+= (grid[act.x-1][act.y]=='(')?1:-1;
                    act.len++;
                    act.cierra|=grid[act.x-1][act.y]==')';
                    if(act.pin == 0){
                        ans = max(ans,act.len);
                    }else{
                        act.x--;
                        if(!(grid[act.x-1][act.y]=='(' and act.cierra))
                        Q.push(act);
                    }
                }
            }
           act = Q.front();
           if(act.y+1 <  n){
                if(act.vis.find(toStr( ((act.x * n) + act.y+1)) +"-") == string::npos ){
                    act.vis+= toStr((act.x*n) + act.y+1)+"-";
                    act.pin+= (grid[act.x][act.y+1]=='(')?1:-1;
                    act.len++;
                    act.cierra|=grid[act.x][act.y+1]==')';
                    if(act.pin == 0){
                        ans = max(ans,act.len);
                    }else{
                        act.y++;
                        if(!(grid[act.x][act.y+1]=='(' and act.cierra))
                        Q.push(act);
                    }
                }
            }
            act = Q.front();Q.pop();
            if(act.y-1>=0){
                if(act.vis.find(toStr( ((act.x * n) + act.y-1)) +"-") == string::npos ){
                    act.vis+= toStr((act.x*n) + act.y-1)+"-";
                    act.pin+= (grid[act.x][act.y-1]=='(')?1:-1;
                    act.len++;
                    act.cierra|=grid[act.x][act.y-1]==')';                    
                    if(act.pin == 0){
                        ans = max(ans,act.len);
                    }else{
                        act.y--;
                        if(!(grid[act.x][act.y-1]=='(' and act.cierra))
                        Q.push(act);
                    }
                }
            }
            
        }
        cout<<ans<<'\n';
    
    }
            
    
	return 0;
}
