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

class FenwickTree{
  vector<long long> v;
  int maxSize;

public:
  FenwickTree(int _maxSize) : maxSize(_maxSize+1) {
    v = vector<long long>(maxSize, 0LL);
  }

  void add(int where, long long what){
    for (where++; where <= maxSize; where += where & -where){
      v[where] += what;
    }
  }

  long long query(int where){
    long long sum = v[0];
    for (where++; where > 0; where -= where & -where){
      sum += v[where];
    }
    return sum;
  }

  long long query(int from, int to){
    return query(to) - query(from-1);
  }

};

char buffer[100005];

int main(){
	int numcas;scanf("%d",&numcas);
	for(int cid=1;cid<=numcas;++cid){
	    printf("Case %d:\n",cid);

	    scanf("%s",buffer);
	    FenwickTree tree(100005);
	    for(int i=0;buffer[i]!='\0';++i)
	        if(buffer[i]=='1'){
	            tree.add(i,1);
	            tree.add(i+1,-1);
	       }


	    int numq;scanf("%d",&numq);
	    int from,to;
	    char car[] ="I";
	    while(numq--){
	        scanf("%s",car);
	        if(car[0]=='I'){
	            scanf("%d %d",&from,&to);from--;
	            tree.add(from,1);
	            tree.add(to,-1);
	        }else{
	            scanf("%d",&to);to--;
	            printf("%d\n",tree.query(to) & 1);
	        }
	    }
	    
	}
	return 0;
}
