class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (head == nullptr) {
      return head;
    }

    GroupResult group_result = findNextGroup(head, k, k);
    if (!group_result.complete) {
      return head;
    }
    ListNode *next_group = group_result.head;
    ListNode *reversed_next_group = reverseKGroup(next_group, k);
    ListNode *reversed_head = reverseSublist(head, next_group);
    head->next = reversed_next_group;
    return reversed_head;
  }

private:
  struct GroupResult {
    ListNode *head;
    bool complete;
  };

  GroupResult findNextGroup(ListNode *head, int remaining, int k) {
    if (head == nullptr) {
      return {
          .head = head,
          .complete = (remaining == 0),
      };
    }
    if (remaining == 0) {
      return {
          .head = head,
          .complete = true,
      };
    }
    return findNextGroup(head->next, remaining - 1, k);
  }

  // Reverses the list [start, end). Returns the new head of the list.
  // Preconditons:
  //   - start must not be null
  ListNode *reverseSublist(ListNode *start, ListNode *end) {
    ListNode *next = start->next;
    if (next == nullptr || next == end) {
      return start;
    }
    ListNode *new_head = reverseSublist(next, end);
    next->next = start;
    return new_head;
  }
};
