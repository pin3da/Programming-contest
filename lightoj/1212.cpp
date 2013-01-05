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


int main(){
	int numcas;cin>>numcas;
	for(int cid=1;cid<=numcas;++cid){
		cout<<"Case "<<cid<<":\n";
		int n,m;cin>>n>>m;
    vector<int> vec;
    int num;
    string cad;
		while(m--){
		  num = (1<<30);
		  cin>>cad;
		  if(cad=="pushLeft" or cad == "pushRight"){
		    cin>>num;
		    if(vec.size()==n){
		      cout<<"The queue is full\n";
		      continue;
		    }
		  }

		  if(num==(1<<30)){
		    if(vec.size()==0){
  		    cout<<"The queue is empty\n";
	  	    continue;
	  	  }
	  	  if(cad=="popLeft"){
	  	    cout<<"Popped from left: "<<(*vec.begin())<<"\n";
	  	    vec.erase(vec.begin());
	  	    continue;
	  	  }
 	      cout<<"Popped from right: "<<(*(vec.end()-1))<<"\n";
 	      vec.erase(vec.end()-1);
 	      continue;
		  }
		  if(cad=="pushLeft"){
		    cout<<"Pushed in left: "<<num<<"\n";
		    vec.insert(vec.begin(),num);
		    continue;
		  }
	    cout<<"Pushed in right: "<<num<<"\n";
		  vec.push_back(num);
		}
		
	}
	return 0;
}
