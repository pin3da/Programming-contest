
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <armadillo>

using namespace std;
using namespace arma;

const vector<string> nums = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

vector<int> counts(const string& s) {
  vector<int> ans('Z' - 'A' + 1, 0);
  for (char c : s) ans[c-'A']++;
  return ans;
}

mat getA() {
  mat A(26, 10);
  for (int j=0; j<10; j++) {
    vector<int> tmp = counts(nums[j]);
    for (int i=0; i<26; i++) {
      A(i,j) = tmp[i];
    }
  }
  return A;
}

string decrypt(const string& s, const mat& A) {
  vector<int> num_letter = counts(s);
  vec v(26);
  for (int i=0; i<26; i++) v[i] = num_letter[i];
  //cout << A << endl << v << endl;
  vec x = solve(A,v);
  //cout << x << endl;
  string ans;
  for (int i=0; i<10; i++) {
    int ntimes = (int)round(x[i]);
    for (int j=0; j<ntimes; j++) ans.push_back(i + '0');
  }
  return ans;
}

int main() {
  int TC;
  cin >> TC;
  string s;
  mat A = getA();
  //cout << A << endl;
  for (int tc=0; tc<TC; tc++) {
    cin >> s;
    string ans = decrypt(s, A);
    cout << "Case #" << tc+1 << ": ";
    cout << ans << endl;
  }
}
