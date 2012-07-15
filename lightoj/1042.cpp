//No accpeted yet
using namespace std;
#include<iostream>
#include<cmath>

int numbits(int a){
	int ans=0;
	while(a>0){
		//cout<<"  "<<a<<endl;
		ans+=a%2;
		a/=2;
	}
	return ans;
}

int main(){
	int numcas;cin>>numcas;
	int n,cas=0,a,i;
	while(numcas--){
		cin>>n;
		cout<<(n&-n)<<endl;
		a = numbits(n);

		
		//for(i = n+1;numbits(i)!=a;++i){}
		//cout<<"Case "<<++cas<<": "<<i<<" "<<numbits(i)<<" "<<i-n<<endl;
	}

	return 0;
}

/**
#include<cstdio>
#include<algorithm>
#define re(i,a,b) for(int i=a;i<=b;++i)
#define sf scanf
#define pf printf
#define ps while(1);
using namespace std;
int t,c;
long long a,i;
int main(){
    sf("%d",&t);
    re(p,1,t){
        sf("%lld",&a);
        c=0;
        for(i=a&-a;((i<<1)&a)!=0;++c,a-=i,i=a&-a);
        a+=i;
        re(j,0,c-1)a|=(1<<j);
        pf("Case %d: %lld\n",p,a);
    }
    return 0;
}

*/
