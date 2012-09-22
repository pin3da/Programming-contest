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

const double pi=acos(-1);

struct point{
	int x,y;
	point() {}
	point(int X, int Y) : x(X), y(Y) {}
};

typedef pair<int,string> person;

int main(){
	int numcas;cin>>numcas;
	int cid=0;
	while(numcas--){
		int numper;cin>>numper;
		vector<person> todos(numper);
		For(i,numper){
			cin>>todos[i].second;
			todos[i].first=1;
			int tmp;
			For(j,3){
				cin>>tmp;
				todos[i].first*=tmp;
			}
		}
		sort(rall(todos));
		cout<<"Case "<<++cid<<": ";
		if(todos[0].first == todos[numper-1].first)cout<<"no thief"<<endl;
		else cout<<todos[0].second<<" took chocolate from "<<todos[numper-1].second<<endl;
	}
	return 0;
}
