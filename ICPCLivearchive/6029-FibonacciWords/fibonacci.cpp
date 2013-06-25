using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define all(x) (x).begin(),(x).end()
#define D(x) cout<< #x " = "<<(x)<<endl
#define MAXN 30
#define MMAX 110

vector<unsigned long long> fib_size(MAXN);
vector<string> fib_word(MAXN);
unsigned long long dp[MMAX];

int kmp(const string &needle, const string &haystack) {
  // Precompute border function
    int m = needle.size();
    vector<int> border(m + 1);
    border[0] = -1;
    for (int i = 0; i < m; ++i) {
        border[i+1] = border[i];
        while (border[i+1] > -1 and  needle[border[i+1]] != needle[i])
            border[i+1] = border[border[i+1]];
        border[i+1]++;
    }

    // Now the actual matching
    int n = haystack.size();
    int seen = 0 ,ans = 0;
    for (int i = 0; i < n; ++i){
        while (seen > -1 and needle[seen] != haystack[i])
            seen = border[seen];
        
        if (++seen == m) {
          ans++;
          seen = border[m];
        }
    }
    return ans;
}

void fill_data(){
     fib_size[0] = fib_size[1] = 1;
     fib_word[0] = "0";
     fib_word[1] = "1";
     for(int i = 2; i< MAXN; ++i){
        fib_size[i] = fib_size[i-1] + fib_size[i-2];
        fib_word[i] = fib_word[i-1] + fib_word[i-2];
     }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string p;
    int cid = 1;
    fill_data();
    while(cin>>n>>p){
        int index = upper_bound(all(fib_size), p.size()) - fib_size.begin();
        unsigned long long ans;
        if(n<=1){
            ans = kmp(p,fib_word[n]);
        }else{
            string left = fib_word[index];
            string right = fib_word[index+1];
            int overlap[2];
            string c1 = right + left;
            string c2 = left + right;
            overlap[0] = kmp(p, c1.substr(right.size() - p.size()+1, 2*p.size()-2));
            overlap[1] = kmp(p, c2.substr(left.size() - p.size()+1, 2*p.size()-2));
            
            string t = c1.substr(right.size() - p.size()+1, 2*p.size()-2);
            
            dp[index - 1] = kmp(p,fib_word[index - 1]);
            dp[index] = kmp(p,left);
            dp[index + 1] = kmp(p,right);
            
            
            int parity = 0;
            for ( int i = index + 2; i < 101; i++,parity++ )
                    dp[i] = dp[ i-1 ] + dp[ i-2 ] + overlap[parity&1];
                    
            
            ans = dp[n];
        }
        cout<<"Case "<<cid++<<": "<<ans<<endl;
    }
}
