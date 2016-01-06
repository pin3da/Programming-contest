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
#define Dbg if(0)
#define MAXNODES 1000

const double pi=acos(-1);

int array[205];

int main(){
	int numcas;cin>>numcas;
	int cid=0;
	int m,n,cant;
	char mio;
	while(numcas--){
		cin>>n>>m;
		For(i,n){
			cin>>array[i];
		}
		For(i,m){
			cin>>mio;
			switch (mio){
				case 'S':
					cin>>cant;
					For(j,n)array[j]+=cant;
					break;
				case 'M':
					cin>>cant;
					For(j,n)array[j]*=cant;
					break;
				case 'D':
					cin>>cant;
					For(j,n)array[j]/=cant;
					break;
				case 'R':
					reverse(array,array+n);
					break;
				case 'P':
					int y,z;cin>>y>>z;
					cant=array[y];
					array[y]=array[z];
					array[z]=cant;
					break;
			}
			Dbg {For(i,n)cout<<array[i]<<" ";cout<<endl;}
		}
		cout<<"Case "<<++cid<<":"<<endl;
		For(i,n)cout<<array[i]<<((i<n-1)?" ":"");
		cout<<endl;
	}
	return 0;
}
