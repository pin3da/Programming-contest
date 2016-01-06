/**
Manuel Pineda
Simulation.
*/

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
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000


int main(){
	int numcas;cin>>numcas;
	int cid=0,pin=1;
	while(numcas--){
		cout<<"Case "<<++cid<<":"<<endl;
		stack<string> f;
		stack<string> b;
		string mio,url,current="http://www.lightoj.com/";
		while(cin>>mio && mio!="QUIT"){
			pin=1;
			if(mio=="VISIT"){
				b.push(current);
				cin>>current;
				f = stack<string> ();
			}
			if(mio=="FORWARD"){
				if(f.empty())
					pin=0;
				else{
					b.push(current);
					current=f.top();f.pop();
				}
			}
			if(mio=="BACK"){
				if(b.empty())
					pin=0;
				else{
					f.push(current);
					current=b.top();b.pop();
				}
			}
			if(pin)	cout<<current<<endl;
			else cout<<"Ignored"<<endl;

		}

	}
	return 0;
}
