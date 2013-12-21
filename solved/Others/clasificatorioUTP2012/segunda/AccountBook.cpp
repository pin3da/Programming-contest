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

#define clear(x) memset(x,0,sizeof(x))
#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MP 28000

int v[40][MP*2];
int tran[40];

int main(){
	int n,f;
	while(cin>>n>>f && n && f){
		clear(v);
		For(i,n)
			cin>>tran[i];
		int t=tran[0];
		v[0][t + MP]="+";
		v[0][t]="-";
		for(int i=0;i<num;++i){
			t+=tran[i];
			for(int j=0;j<=i;++j){
				
			}
		}
	
	}
    return 0;
}
