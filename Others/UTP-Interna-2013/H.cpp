using namespace std;
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#include<map>

#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define For(i,n) for(int i=0;i<(n);++i)
#define foreach(x,n) for(typeof (n).begin() x = (n).begin(); x!= (n).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<<#x " = "<<(x)<<endl
#define MP 2000

template <class T> string toStr(const T &x)
{ stringstream s;s<<x;return s.str();}
template <class T> int toInt(const T &x)
{ stringstream s; s<<x; int r; s>>r;return r;}

int pagina[5010];

vector<int> G[5010];
int padre[5010];
int numpag[5010];
int ultimo[5010];


int main(){	
	int n;
	while(cin>>n and n){
		set<int> todos;
		vector<int> mios(n);
		For(i,n){
			cin>>mios[i];
			todos.insert(mios[i]);
		}
		double ans=0;
		for(int i = n-1;i>=0;++i){
			int pos = i>>1;
		}
		
		
	}
	

	return 0;
}
