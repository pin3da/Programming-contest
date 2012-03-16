#include<stdio.h>
#define MP 21

long long fac[MP];

int main(){
	int numcas, tcid, n,k,i;
	fac[0]=1;
	for(i=1;i<MP;i++)fac[i]=fac[i-1]*i;
	scanf("%d",&numcas);
	while(numcas--){
		scanf("%d",&tcid);
		printf("%d ",tcid);
		scanf("%d %d",&n,&k);
		if(k==1)
			printf("%lld\n",fac[n-1]);
		else
			printf("%lld\n",fac[n]/((n-k+1)*(n-k+2)));
	}

	return 0;
}
