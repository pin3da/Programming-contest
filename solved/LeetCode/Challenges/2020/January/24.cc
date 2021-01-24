#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    set<pair<int, ListNode*>> bestList;
    for (auto it : lists) {
      if (it != nullptr) {
        bestList.insert(make_pair(it->val, it));
      }
    }

    ListNode* head = nullptr;
    ListNode* cur = nullptr;
    while (bestList.size() > 0) {
      ListNode* first = bestList.begin()->second;
      ListNode* next = first->next;
      bestList.erase(bestList.begin());
      if (head == nullptr) {
        head = first;
        cur = first;
      } else {
        cur->next = first;
        cur = first;
      }
      if (next != nullptr) {
        bestList.insert(make_pair(next->val, next));
      }
    }
    return head;
  }
};
