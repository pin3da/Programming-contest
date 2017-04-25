// http://codeforces.com/contest/259/problem/B

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
#define DET(a,b,c,d) ((a)*(d) - (b)*(c))
#define CRAMER(a,b,x,c,d,y) (DET(x,b,y,d)/DET(a,b,c,d))

int grid[3][3];

bool valid(){
    int rows[3]={0,0,0};
    For(k,3)
        For(i,3) rows[k]+=grid[k][i];
    
    if(rows[0]!=rows[1] or rows[0]!=rows[2]) return false;
    
    int cols[3]={0,0,0};
    For(k,3)
        For(i,3) cols[k]+=grid[i][k];
    
    if(cols[0]!=cols[1] or cols[0]!=cols[2]) return false;
    
    if(grid[0][0] + grid[1][1] + grid[2][2] != grid[2][0]+ grid[1][1] + grid[0][2]) return false;
    
    if(rows[0] != cols[0] or cols[0] != grid[0][0] + grid[1][1] + grid[2][2] ) return false;
    
    return true;
    
}

void fill(){
    for(int i=1; i< (1<<17);++i){
        int x = (i + grid[0][1] + grid[0][2]) - grid[1][0] - grid[1][2];
        int k = (i + grid[0][1] + grid[0][2]) - grid[2][0] - grid[2][1];
        
        grid[0][0]=i;
        grid[1][1]=x;
        grid[2][2]=k;
        if(valid()) return;  
    }
}

int main(){
    For(i,3)
        For(j,3)
            cin>>grid[i][j];
            
    fill();
	
	For(i,3){
        For(j,3){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
	return 0;
}
