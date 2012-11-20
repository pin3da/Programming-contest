using namespace std;
#include<algorithm>
#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
#define MP 1000
#define D(x) cout<< #x " = "<<x<<endl

struct point{
    int x,y;
    point(){}
    point(int X,int Y): x(X), y(Y){}
    
    int dist2(point other){
        return (x-other.x)*(x-other.x) + (y-other.y)*(y-other.y);
    }
    double cross(point a){
        return x*a.y - y*a.x;
    }
};


int dist(int a,int b,int c,int d){
    return (a-c)*(a-c) + (b-d)*(b-d);
}

int n,m;
int ix,iy,tx,ty;
int visited[MP+1][MP+1];
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

void marcar(int x, int y){
    for(int i = x-m ; i<= x+m; ++i)
        for(int j = y-m ; j <= y+m; ++j)
            if(dist(x,y,i,j) <= m*m) 
                if(i>=0 and i<=MP and j>=0 and j<=MP )
                    visited[i][j] = true;
}


int main(){
    freopen("message.in","r",stdin);
    point primero,tmp,anterior;
    while(cin>>n>>m and n+m){
        memset(visited,0,sizeof(visited));

        
        cin>>primero.x>>primero.y;
        anterior.x = primero.x;
        anterior.y = primero.y;
        for(int i=0;i<(n-1);++i){
            cin>>tmp.x>>tmp.y;
            if(anterior.x==tmp.x){
                int from = min(tmp.y,anterior.y);
                int to  = max(tmp.y,anterior.y);
                for(int j=from; j <= to; ++j)
                    marcar(anterior.x,j);
            }
            if(anterior.y==tmp.y){
                int from = min(tmp.x,anterior.x);
                int to  = max(tmp.x,anterior.x);
                for(int j=from; j <= to; ++j)
                    marcar(j,anterior.y);
            }
            anterior.x=tmp.x;anterior.y=tmp.y;
        }
  
        if(anterior.x==primero.x){
            int from = min(primero.y,anterior.y);
            int to  = max(primero.y,anterior.y);
            for(int j=from; j <= to; ++j)
                marcar(primero.x,j);
        }
        if(anterior.y==primero.y){
            int from = min(primero.x,anterior.x);
            int to  = max(primero.x,anterior.x);
            for(int j=from; j <= to; ++j)
                marcar(j,primero.y);
        }
        
        cin>>ix>>iy>>tx>>ty;
        /*
        for(int i=0;i<20;++i){
            for(int j =0; j<20; ++j){
                cout<<visited[i][j]<<" ";
            }
            cout<<endl;
        }*/
        
        int solve=false;
        queue<point> Q;
        Q.push(point(ix,iy));
        while(!Q.empty()){
            point act = Q.front();Q.pop();
            for(int i =0; i< 8;++i){
                if(act.x+dx[i]>=0 and act.x+dx[i]<MP and act.y+dy[i]>=0 and act.y+dy[i]<MP){
                    if(!visited[act.x+dx[i]][act.y+dy[i]]){
                        if(act.x+dx[i]==tx and act.y+dy[i]==ty){ solve = true;break;}
                        visited[act.x+dx[i]][act.y+dy[i]]=true;
                        Q.push(point(act.x+dx[i],act.y+dy[i]));
                    }
                }
            }
            if(solve)break;
        }

        
        
        cout<<((solve)?"Yes":"No")<<endl;
    
    }

    return 0;
}
