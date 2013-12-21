using namespace std;
#include <iostream>
#include <vector>
#include <string>

void kmp(const string &needle, const string &haystack) {
    int m = needle.size();
    vector<int> border(m + 1);
    border[0] = -1;
    for (int i = 0; i < m; ++i) {
        border[i+1] = border[i];
        while (border[i+1] > -1 and
                     needle[border[i+1]] != needle[i]) {
            border[i+1] = border[border[i+1]];
        }
        border[i+1]++;
    }

    // Now the actual matching
    int n = haystack.size();
    int seen = 0;
    for (int i = 0; i < n; ++i){
        while (seen > -1 and needle[seen] != haystack[i]) {
            seen = border[seen];
        }
        if (++seen == m) {
            cout<<(i-m+1)<<endl;
            seen = border[m];
        }
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin>>n){
        string needle;cin>>needle;
        string haystack;cin>>haystack;
        kmp(needle,haystack);
    }
}
