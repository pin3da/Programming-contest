using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

#define clear(x) memset(x,0,sizeof(x))
#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MP 28000


int main(){
	int n,f;
	while(cin>>n>>f && n && f){
		int m[n][f];
		//int m[f+5];
		int a[n];
		For(i,n)
			cin>>a[i];
		
		clear(m);
		
		//For(i,n)
			m[0][0]=true;
		
		For(i,f)
			m[0][i]=false;
			
		for(int  i=1; i<n;++i){
			for(int j=0; j<f;++j){
				if(a[i]<j)break;
				m[i][j] = m[i-1][j] or m[i-1][j-a[i]];
				/*if(m[i][j]){
				D(i);
				D(j);
				cout<<endl;
				}*/
			}
		}
		
		int j = f;
		j;
		for (int i = n-1;i >= 0; i --)
			if ( m [i] [j]){
				printf("Use item %d = %d\n", i+1, a [i]);
				j -= a[i];
			}
	
		/*m[0]=1;
		for(int i=0; i<n; i++)
    		for(int j=f; j>=a[i]; j--)
        		m[j] |= m[j-a[i]];
		
		int target=f;
		for(int i=n-1; i>=0; --i){
			if(m[i]){
				cout<<a[i]<<endl;
				target-=a[i];
			}
		}*/
		
	}
    return 0;
}
