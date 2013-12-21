using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);

struct SuffixArray {
  const int L;
  string s;
  vector<vector<int> > P;
  vector<pair<pair<int,int>,int> > M;

  SuffixArray(const string &s) : L(s.length()), s(s), P(1, vector<int>(L, 0)), M(L) {
    for (int i = 0; i < L; i++) P[0][i] = int(s[i]);
    for (int skip = 1, level = 1; skip < L; skip *= 2, level++) {
      P.push_back(vector<int>(L, 0));
      for (int i = 0; i < L; i++) 
    	M[i] = make_pair(make_pair(P[level-1][i], i + skip < L ? P[level-1][i + skip] : -1000), i);
      sort(M.begin(), M.end());
      for (int i = 0; i < L; i++) 
	    P[level][M[i].second] = (i > 0 && M[i].first == M[i-1].first) ? P[level][M[i-1].second] : i;
    }    
  }

  vector<int> GetSuffixArray() { return P.back(); }

  // returns the length of the longest common prefix of s[i...L-1] and s[j...L-1]
  int LongestCommonPrefix(int i, int j) {
    int len = 0;
    if (i == j) return L - i;
    for (int k = P.size() - 1; k >= 0 && i < L && j < L; k--) {
      if (P[k][i] == P[k][j]) {
	    i += 1 << k;
	    j += 1 << k;
	    len += 1 << k;
      }
    }
    return len;
  }
};


int main(){ ___

    string cad;
    while(cin>>cad){
        int m;cin>>m;
        SuffixArray suffix(m);
        
        string q;
        
        vector<int> sa = m.GetSuffixArray();
        int ans = 0;
        while(m--){
            cin>>q;
            
            int l = 0; r = n
            while (l < r){
                int mid = (l+r) / 2
                if q > suffixAt(A[mid]):
                    l = mid + 1
                else:
                    r = mid
            s = l; r = n
            while l < r:
                mid = (l+r) / 2
                if P < suffixAt(A[mid]):
                    r = mid
                else:
                    l = mid + 1
            return (s, r)
            
            
            if(search(q))ans++;
        }
        cout<<ans<<endl;
        
    }
    return 0;
}
