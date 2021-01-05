class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if ((head == nullptr) || (head->next == nullptr)) {
            return head;
        }
        int t = head->next->val;
        if (head->val != t) {
            head->next = deleteDuplicates(head->next);
            return head;
        }
        while (head != nullptr && head->val == t) {
            head = head->next;
        }
        return deleteDuplicates(head);
    }
};
