using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl


class JumpFurther {
	public:
	
	int is_in_way(int n, int current){
	    int x = ceil(sqrt(2.0*n + 0.25) - 0.5);
	    return (((x*(x+1))/2.0) == n) and x <= current;
	}
	
	int furthest(int N, int badStep) {
		return ((N*(N+1))>>1) - is_in_way(badStep, N);
	}
};
