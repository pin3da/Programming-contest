class Solution {
  public:

    int getVal(ListNode* l) {
      if (l == nullptr) return 0;
      return l->val;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* head = new ListNode(0);
      ListNode* cur = head;
      int carry = 0;
      while (true) {
        int s = getVal(l1) + getVal(l2) + carry;
        cur->val = s % 10;
        carry = s / 10;
        if (l1 != nullptr) l1 = l1->next;
        if (l2 != nullptr) l2 = l2->next;
        if (l1 != nullptr || l2 != nullptr || carry > 0) {
          cur->next = new ListNode(0);
          cur = cur->next;
        } else {
          break;
        }
      }
      return head;
    }
};
