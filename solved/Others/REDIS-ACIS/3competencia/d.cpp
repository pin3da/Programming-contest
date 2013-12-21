using namespace std;
#include<iostream>
#include<cstdio>

typedef long long int lli;

int main(){
	lli a,b,n;
	lli m1,m2,q,t;
	while(true){
		scanf("%lli %lli %lli",&a,&b,&n);
		if(a== 0 && b == 0 && n == 0)break;
		if(n == 0){
			printf("%lli\n",a);
			continue;
		}
		if(n == 1){
			printf("%lli\n",b);
			continue;
		}
		m1=b;m2=a;
		q = (1+m1)/m2;
		//cout<<m1<<" "<<m2<<endl;
		//cout<<q;
		for(lli i = 2;i<n;++i){
			t = q;
			q = (1+m1)/m2;
			m1 = m2;
			m2 = t;
		}
		printf("%lli\n",q);
	}
	return 0;
}
