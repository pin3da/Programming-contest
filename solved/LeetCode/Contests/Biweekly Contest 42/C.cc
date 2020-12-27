#include <bits/stdc++.h>
#include "./template.cc"
using namespace std;

class Solution {
public:
    string maximumBinaryString(string binary) {
        string ans = binary;
        int j = 0;
        while (j < ans.size() && ans[j] == '1') j++;
        for (int i = 0; i < ans.size(); i++) {
           //  debug(ans);
            if (ans[i] == '1') continue;
            if (i + 1 >= ans.size()) continue;
            if (ans[i + 1] == '0') {
                ans[i] = '1';
                j++;
                continue;
            }
            // 0111...110
            j++;
            while (j < ans.size() && ans[j] == '1') j++;
            if (j >= ans.size()) break;
            // debug(i+1, j);
            swap(ans[i+1], ans[j]);
            // 0011...111
            ans[i] = '1';
       }
       return ans;
    }
};

struct Input {
    string b;
};

int main() {
    vector<Input> in = {
        {"000110"},
        {"01"}
    };

    for (auto &it : in) {
        Solution sol;
        print(cout, sol.maximumBinaryString(it.b));
    }
}