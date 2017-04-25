// http://codeforces.com/contest/216/problem/A

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
#define MP 1010

const double pi=acos(-1);



int main(){
	
	vector<int> mio(3);
	cin>>mio[0]>>mio[1]>>mio[2];
	sort(mio.begin(),mio.end());
	cout<<(mio[1]+mio[0]-1)*((mio[2]+mio[0]-1)) - 2*((mio[0]*(mio[0]-1))/2)<<endl;
	return 0;
}
