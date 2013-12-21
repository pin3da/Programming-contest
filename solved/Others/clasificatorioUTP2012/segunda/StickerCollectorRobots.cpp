using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(0)
#define MAXNODES 1000
#define MP 101

const double pi=acos(-1);

struct point{
    int x,y;
    point() {}
    point(int X, int Y) : x(X), y(Y) {}
};

int dir,a,b,c,ans;
point pos;
char arr[MP][MP];


void jugar(char m){
    if(m=='D'){
        dir++;
        if(dir>3)dir=0;
        return;
    }
    if(m=='E'){
        dir--;
        if(dir<0)dir=3;
        return;
    }
    int dx,dy;
    switch (dir){
        case 0:
            dy=0;
            dx=-1;
            break;
        case 1:
            dy=1;
            dx=0;
            break;
        case 2:
            dy=0;
            dx=1;
            break;
        case 3:
            dy=-1;
            dx=0;
            break;
    }
    if(pos.x + dx < a && pos.y + dy < b && pos.x + dx >=0 && pos.y + dy >=0){
        if(arr[pos.x+dx][pos.y+dy] != '#'){
            pos.x = pos.x+dx;
            pos.y = pos.y + dy;
            if( arr[pos.x][pos.y] == '*'){
                ans++;
            }
           arr[pos.x][pos.y]='X';
           arr[pos.x - dx][pos.y- dy]='.';
        }
    }else return;
}

int main(){
    while(true){
        cin>>a>>b>>c;
        if(a==0 and b==0 and c ==0)break;
        For(i,a){
            For(j,b){
                cin>>arr[i][j];
                switch (arr[i][j]){
                    case 'N':
                        pos.x=i;
                        pos.y=j;
                        dir =0;
                        break;
                    case 'S':
                        pos.x=i;
                        pos.y=j;
                        dir =2;
                        break;
                    case 'L':
                        pos.x=i;
                        pos.y=j;
                        dir =1;
                        break;
                    case 'O':
                        pos.x=i;
                        pos.y=j;
                        dir =3;
                        break;
                }
            }
        }
        Dbg{ mprint();cout<<endl;}
        ans=0;
        char mv;
        For(i,c){
            cin>>mv;
            Dbg D(mv);
            jugar(mv);
            Dbg{ mprint();cout<<endl;}
        }
        cout<<ans<<endl;
    }
    return 0;
}
