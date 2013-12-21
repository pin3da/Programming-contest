using namespace std;
#include<bits/stdc++.h>

class ConvertibleStrings {
	public:
	int leastRemovals(string A, string B) {
        int _m[] = {0,1,2,3,4,5,6,7,8};
        vector<int> index(_m,_m+9);
        
        int ans = A.size();
        do{ 
            string C = B;
            for(int i = 0; i< B.size(); ++i)
                C[i] = index[B[i]-'A'] + 'A';
	        
            int match = 0;
            for(int i = 0; i< B.size(); ++i)
                if(A[i]==C[i])match++;
                
	        ans = min(ans,(int)(A.size() - match));
	    }while(next_permutation(index.begin(),index.end()));
	    
	    return ans;
	}
};
