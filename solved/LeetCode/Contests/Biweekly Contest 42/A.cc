#include <bits/stdc++.h>
#include "./template.cc"
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
       deque<pair<int, int>> q;
       for (int i = 0; i < students.size(); i++) {
           q.emplace_back(students[i], i);
       }
       map<int, set<int>> unable;
       int i = 0;
       while(i < sandwiches.size()) {
         if (q.front().first == sandwiches[i]) {
             q.pop_front();
             i++;
         } else {
             if (unable[i].count(q.front().second)) {
                 break;
             }
             q.push_back(q.front());
             unable[i].insert(q.front().second);
             q.pop_front();
         }
       }
       return q.size();
    }
};
struct Input {
    vector<int> st;
    vector<int> sand;
};

int main() {
    vector<Input> in = {
        {
            {1,1,0,0},
            {0,1,0,1}
        },
        {
            {1,1,1,0,0,1},
            {1,0,0,0,1,1}
        }
    };

    for (auto &it : in) {
        Solution sol;
        debug(sol.countStudents(it.st, it.sand));
    }
}