#include <vector>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

  ListNode *addElement(ListNode *node, int val) {
    ListNode *current = new ListNode(val);
    if (node) {
      node->next = current;
    }
    return current;
  }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      set<pair<int, int>> smallest_list;
      auto list_copy = lists;
      for (int i = 0; i < lists.size(); i++) {
        auto l = lists[i];
        if (l != NULL) {
          smallest_list.insert({l->val, i});
        }
      }

      ListNode *head = NULL, *tail = NULL;

      while (smallest_list.size()) {
        auto cur_list = *smallest_list.begin();
        smallest_list.erase(smallest_list.begin());

        int id = cur_list.second;
        tail = addElement(tail, cur_list.first);
        if (head == NULL) {
          head = tail;
        }

        list_copy[id] = list_copy[id]->next;
        if (list_copy[id] != NULL) {
          smallest_list.insert({list_copy[id]->val, id});
        }
      }

      return head;
    }
};
