using namespace std;
#include<iostream>
#include<queue>
#include<map>
#include<cstring>
#include<cstdio>
#include<cassert>
#define D(x) cout<< #x " = "<<(x)<<endl

char mat[55][55];
int flooded[55][55];
int r,c,water,changes,mmin,vi;
double pressure;

int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

bool possible(){
    int visited[r][c];
    queue<pair<int,int> > Q;
    Q.push(make_pair(0,0));
    memset(visited,0,sizeof(visited));
    while(!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        if(visited[x][y])continue;
        visited[x][y] = true;
        for(int i =0;i<4;++i)
            if(x+dx[i] >= 0 and x+dx[i] < r and y+dy[i] >= 0 and y+dy[i] < c and mat[x+dx[i]][y+dy[i]]!='X')
                Q.push(make_pair(x+dx[i],y+dy[i]));
    }
    int ans =  1;
    for(int i=0;i<r;++i)
        for(int j=0;j<c;++j)
            if(mat[i][j]!='X')
                ans &= visited[i][j];
                
    return ans;
}

void fill(){
    pressure = water;
    vi=0;
    for(int i=0;i<r;++i)
        for(int j=0;j<c;++j)
            if(flooded[i][j] > 0)
                vi++;
    pressure/= vi;
    
    int tmp[55][55];
    memset(tmp,0,sizeof(tmp));
    tmp[0][0] = flooded[0][0];
    for(int x=0;x<r;++x)
        for(int y=0;y<c;++y)
            if(flooded[x][y] > 0)
                for(int i =0;i<4;++i){
                    if(x+dx[i] >= 0 and x+dx[i] < r and y+dy[i] >= 0 and y+dy[i] < c and mat[x+dx[i]][y+dy[i]]!='X'){
                        if(mat[x+dx[i]][y+dy[i]] - '0' <= pressure){
                            if(!flooded[x+dx[i]][y+dy[i]])changes++;
                            tmp[x+dx[i]][y+dy[i]] = flooded[0][0];
                            mat[x+dx[i]][y+dy[i]] = '0';
                        }else{
                            mmin = min(mmin,mat[x+dx[i]][y+dy[i]] - '0');
                        }
                     }
                 }

    memcpy(flooded,tmp,sizeof(flooded));
}

bool finish(){
    int ans = 1;
    for(int i=0;i<r;++i)
        for(int j=0;j<c;++j)
            if(mat[i][j] != 'X')
                ans &= (flooded[i][j]>0);
    return ans;                
}

void debug(){
    D(pressure);
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            cout<<flooded[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    while(cin>>r>>c){
        memset(flooded,0,sizeof(flooded));
        flooded[0][0] = 1;
        water = 1;
        for(int i=0;i<r;++i)
            for(int j=0;j<c;++j)
                cin>>mat[i][j];
                
        
        if(possible()){
            int ans = 0;
            while(true){
                changes = 0;
                mmin = (1<<30);
                fill();
                if(changes==0){
                    int tar = mmin*vi;
                    assert(tar-water>0);
                    ans +=  tar-water;
                    water = tar;
                }else{
                    if(finish())break;
                    water++;
                    ans++;
                }
            }
            cout<<ans<<endl;
        }else{
            cout<<"-1"<<endl;
        }
    }
    return 0;    
}
