#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

void process(string &s, vector<string> &bk) {
  int bkt = 0;
  for(int i = 0; i < s.size() && bkt < bk.size(); i++) {
    string st = "";
    while(i < s.size() && st.size() < 5) {
      st.push_back(s[i++]);
    }
    
    if(bkt < bk.size()){
      bk[bkt] = bk[bkt] + st;
      bkt++;
    }
  }

}



int main() {
  map<string, char> nums;
  map<char, string> strings;
  nums["xxxxxx...xx...xx...xx...xx...xxxxxx"] = '0';
  nums["....x....x....x....x....x....x....x"] = '1';
  nums["xxxxx....x....xxxxxxx....x....xxxxx"] = '2';
  nums["xxxxx....x....xxxxxx....x....xxxxxx"] = '3';
  nums["x...xx...xx...xxxxxx....x....x....x"] = '4';
  nums["xxxxxx....x....xxxxx....x....xxxxxx"] = '5';
  nums["xxxxxx....x....xxxxxx...xx...xxxxxx"] = '6';
  nums["xxxxx....x....x....x....x....x....x"] = '7';
  nums["xxxxxx...xx...xxxxxxx...xx...xxxxxx"] = '8';
  nums["xxxxxx...xx...xxxxxx....x....xxxxxx"] = '9';
  nums[".......x....x..xxxxx..x....x......."] = '+';
  for(map<string, char>::iterator it = nums.begin(); it != nums.end(); it++)
    strings[it->second] = it->first;
  vector<string> input;
  string s, st;
  while(cin >> s) {
    int hw =  (s.size() + 1) / 6;
    vector<string> ans(hw);
    // cout << ans.size() << endl;
    process(s, ans);

    for(int i = 0; i < 6; i++) {
      cin >> s;
      process(s, ans);
    }
    st = "";

    for(int i = 0; i < ans.size(); i++) st += nums[ans[i]];
    long long a = atol(st.substr(0, st.find('+')).c_str());
    long long b = atol(st.substr(st.find('+')).c_str());
    a += b;
    stringstream ss; ss << a;
    st = ss.str();
    // cout << st << endl;
    vector<string> sa(st.size());
    for(int i = 0; i < st.size(); i++) {
      sa[i] = strings[st[i]];
    }
    int ts = 0;
    for(int i = 0; i < 7; i++) {
      for(int j = 0; j < sa.size(); j++) {
        if(j > 0) cout << '.';
        cout << sa[j].substr(i * 5, 5);
      }
      cout << endl;
    }
    
  }
}


