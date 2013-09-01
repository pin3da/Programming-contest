using namespace std;
#include<bits/stdc++.h>
#define For(i,n) for(int i = 0; i< (n); ++i)
#define D(x) cout<< #x " = "<<(x)<<endl
#define foreach(it,x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)


int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int menos(int d){
    if(d == 0)return 3;
    return d-1;
}

int mas(int d){
    if(d == 3) return 0;
    return d+1;
}

int turn(int d){
    return (d+2)%4;
}

int main(){
    int tc;cin>>tc;
    For(tid,tc){
        cout<<"Robot Program #"<<tid+1<<":"<<endl;
        int moves;cin>>moves;
        int x = 0, y = 0;
        int dir = 0;
        For(i,moves){
            string mv;cin>>mv;
            if(mv == "LEFT") dir = mas(dir);
            if(mv == "RIGHT") dir = menos(dir);
            if(mv == "UTURN") dir = turn(dir);
            if(mv == "MOVE"){
                int m;
                cin>>m;
                x += dx[dir]*m;
                y += dy[dir]*m;
            }
        }
        printf("The robot is at (%d,%d)\n",x,y);
        For(i,2){
            int tx,ty;
            cin>>tx>>ty;
            //cout<<"algo"<<endl;
            if(tx < x){
                if(dir == 1) cout<<"LEFT"<<endl;
                if(dir == 3) cout<<"RIGHT"<<endl;
                if(dir == 0) cout<<"UTURN"<<endl;
                cout<<"MOVE "<<x-tx<<endl;
                dir = 2;
                x = tx;
            }else if(tx > x){
                if(dir == 3) cout<<"LEFT"<<endl;
                if(dir == 1) cout<<"RIGHT"<<endl;
                if(dir == 2) cout<<"UTURN"<<endl;
                cout<<"MOVE "<<tx-x<<endl;
                dir = 0;
                x = tx;
            }
            if(ty < y){
                if(dir == 2) cout<<"LEFT"<<endl;
                if(dir == 0) cout<<"RIGHT"<<endl;
                if(dir == 1) cout<<"UTURN"<<endl;
                
                cout<<"MOVE "<<y-ty<<endl;
                dir = 3;
                y = ty;
            }else if(ty > y){
                if(dir == 0) cout<<"LEFT"<<endl;
                if(dir == 2) cout<<"RIGHT"<<endl;
                if(dir == 3) cout<<"UTURN"<<endl;
                
                cout<<"MOVE "<<ty-y<<endl;
                dir = 1;
                y = ty;
            }
        }
        cout<<endl;
    }
    return 0;

}
