using namespace std;
#include<iostream>
#include<climits>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000
#define MP 21

struct pi{
	int x,y;
	pi(){}
	pi(int xx,int yy) : x(xx),y(yy){}
};

char array[MP][MP];
bool visited[MP][MP];

int w,h,px,py;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void floodfill(int x,int y){
	stack<pi> st;
	st.push(pi (x,y));
	while(!st.empty()){
		pi actual = st.top();st.pop();
        x=actual.x;
        y=actual.y;
		if(array[actual.x][actual.y]=='.');
        for(int i=0;i<4;i++){
            if (x+dx[i]>=0 && x+dx[i]<w && y+dy[i]>=0 && y+dy[i]<h){
                if (visited[x+dx[i]][y+dy[i]])
                    continue;
            	//if (x+dx[i]==w-1 && y+dy[i]==h-1) return true;
            	if(array[x+dx[i]][y+dy[i]]=='.')
                	st.push( pi (x+dx[i],y+dy[i]));
            }
        }
        visited[actual.x][actual.y]=true;
	}
}


int main(){
	int numcas;cin>>numcas;
	int cid=0;
	while(numcas--){
		cin>>h>>w;
		For(i,w)
			For(j,h){
				cin>>array[i][j];
				if(array[i][j]=='@'){px=i;py=j;}
			}
			
//Dbg 	For(i,w){ For(j,h) cout<<m[i][j];cout<<endl;}
		For(i,MP)
			For(j,MP)
				visited[i][j]=false;
		
		floodfill(px,py);
		int ans=0;
		For(i,w){
			For(j,h)
				if(visited[i][j])ans++;
		}
		cout<<"Case "<<++cid<<": "<<ans<<endl;
	}
	return 0;
}
