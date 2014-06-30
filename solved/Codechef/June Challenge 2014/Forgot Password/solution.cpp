using namespace std;
#include<bits/stdc++.h>

const int MN = 222;
char de[MN];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int tc;cin>>tc;
  while (tc--) {

    for (int i = 0; i < MN; ++i)
      de[i] = i;

    int n;cin>>n;

    for (int i = 0; i < n; ++i) {
      char a, b;
      cin>>a>>b;
      de[a] = b;
    }
    string line;cin>>line;
    bool dot = 0;
    for (int i = 0; i < line.size(); ++i) {
      line[i] = de[line[i]];
      if (line[i] == '.')
        dot = true;
    }

    deque<char> ans(line.begin(), line.end());


    while (!ans.empty() and ans.front() == '0') ans.pop_front();
    if (dot) while (!ans.empty() and ans.back() == '0') ans.pop_back();
    if (!ans.empty() and ans.back() == '.') ans.pop_back();

    for (int i = 0 ; i < ans.size(); ++i) {
      cout<<ans[i];
    }
    if (ans.size() == 0) cout<<"0";
    cout<<endl;

  }
  return 0;
}
