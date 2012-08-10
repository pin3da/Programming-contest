//Not solved yet :( 

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
#define Dbg if(1)
#define MAXNODES 1000
#define MP 16 


struct pi{
	int x,y;
	pi(){}
	pi(int xx,int yy) : x(xx),y(yy){}
};

char array[MP][MP];
bool visited[MP][MP];

int w,h,px,py,qx,qy;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

int bfs(int x,int y){
	int ans=0;
	stack<pi> st;
	st.push(pi (x,y));
	while(!st.empty()){
            pi actual=st.top();st.pop();
            if (array[actual.x][actual.y]=='#')
                continue;
            if (actual.x==qx && actual.y==qy)
                return true;
            x=actual.x;
            y=actual.y;
            for(int i=0;i<4;i++){
                if (x+dx[i]>=0 && x+dx[i]<w && y+dy[i]>=0 && y+dy[i]<h){
                    if (visited[x+dx[i]][y+dy[i]])
                        continue;
                    visited[x+dx[i]][y+dy[i]]=true;
                    if (x+dx[i]==qx && y+dy[i]==qy) return true;
                    st.push(pi (x+dx[i],y+dy[i]));
                }
            }
      }
      return false;
}



int main(){
	int numcas;cin>>numcas;
	int cid=0;
	while(numcas--){
		cin>>w>>h;
		For(i,w)
			For(j,h){
				cin>>array[i][j];
				if(array[i][j]=='A'){px=i;py=j;array[i][j]='.';}
				if(array[i][j]=='Q'){qx=i;qy=j;array[i][j]='.';}
			}

		/*For(i,w){
			For(j,h)
				cout<<array[i][j];
			cout<<endl;
		}*/

		For(i,MP)
			For(j,MP)
				visited[i][j]=false;


		int ans=bfs(px,py);
		For(i,w){
			For(j,h)
				cout<<visited[i][j];
			cout<<endl;
		}

		Dbg D(qx);
		Dbg D(qy);
		cout<<"Case "<<++cid<<": ";
		if(!ans)cout<<"impossible"<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
