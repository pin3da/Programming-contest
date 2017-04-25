// http://codeforces.com/contest/230/problem/A

using namespace std;
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

#include<cmath>
#include<cstdio>

#define For(i,n) for(int i=0;i<(n); ++i)
#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)

typedef pair<int,int> duelo;

int main(){
	int s,n;cin>>s>>n;
	vector<duelo> mio(n);
	For(i,n){
		cin>>mio[i].first>>mio[i].second;
	}
	sort(mio.begin(),mio.end());
	int acum=0;
	int paila=false;
	For(i,n){
		if(s+acum <= mio[i].first){
			paila=true;
			break;
		}
		acum+=mio[i].second;
	}
	if(paila)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	return 0;
}

