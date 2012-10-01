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
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000

struct point3d{
	int x,y,z;

	point3d(){}
	
	point3d(int xx,int yy,int zz): x(xx),y(yy),z(zz){}
	
	
};

int main(){
	int numcas;cin>>numcas;
	int n;
	for(int i=1;i<=numcas;++i){
		cin>>n;
		point3d ans(0,0,0);
		point3d ans2(3000,3000,3000);
		point3d tmp;
		while(n--){
			cin>>tmp.x>>tmp.y>>tmp.z;
			ans.x=max(ans.x,tmp.x);
			ans.y=max(ans.y,tmp.y);
			ans.z=max(ans.z,tmp.z);
			cin>>tmp.x>>tmp.y>>tmp.z;
			ans2.x=min(ans2.x,tmp.x);
			ans2.y=min(ans2.y,tmp.y);
			ans2.z=min(ans2.z,tmp.z);
		}
		if(ans2.x-ans.x<0 or ans2.y-ans.y < 0 or ans2.z-ans.z<0)
			cout<<"Case "<<i<<": 0"<<endl;
		else cout<<"Case "<<i<<": "<<(ans2.x-ans.x)*(ans2.y-ans.y)*(ans2.z-ans.z)<<endl;
	}
	return 0;
}
