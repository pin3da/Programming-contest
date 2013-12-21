using namespace std;
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>

#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<cstring>
#define For(i,n) for(int i=0;i<(n);++i)
#define foreach(x,n) for(typeof (n).begin() x = (n).begin(); x!= (n).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<<#x " = "<<(x)<<endl

template <class T> string toStr(const T &x)
{ stringstream s;s<<x;return s.str();}
template <class T> int toInt(const T &x)
{ stringstream s; s<<x; int r; s>>r;return r;}

typedef long long int lli;


int main(){
	string cad;
	while(cin>>cad){
		int p1=0,p2=0,g1=0,g2=0;
		int ngame = 0;
		for(int i = 0;i< cad.size();++i){
			if((ngame%2) == 0){
				if(cad[i]=='S')p1++;
				else p2++;
			}else{
				if(cad[i]=='S')p2++;
				else p1++;
			}
			if(p1 >= p2 +2 and p1 >=4){
				ngame++;
				g1++;
				p1 = 0;
				p2 = 0;
			}else if(p2 >= p1+2 and p2 >=4){
				ngame++;
				g2++;
				p1 = 0;
				p2 = 0;
			}
			if((g1 >= g2 +2 and g1>=6 ) or (g2 >= g1+2 and g2 >=6)){
			
				break;
			}
		}
		cout<<g1<<"-"<<g2<<endl;
	}
	return 0;
}
