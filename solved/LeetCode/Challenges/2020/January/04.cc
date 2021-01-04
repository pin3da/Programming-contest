class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* tail = (val(l1) < val(l2)) ? l1 : l2;
        ListNode* head = tail;
        if (tail == l1) {
            l1 = advance(l1);
        } else {
            l2 = advance(l2);
        }
        
        while ((l1 != nullptr) && (l2 != nullptr)) {
            ListNode* next = (val(l1) < val(l2)) ? l1 : l2;
            if (next == l1) {
                l1 = advance(l1);
            } else {
                l2 = advance(l2);
            }
            tail->next = next;
            tail = advance(tail);
        }
        
        while (l1 != nullptr) {
            tail->next = l1;
            tail = advance(tail);
            l1 = advance(l1);
        }
        
        while (l2 != nullptr) {
            tail->next = l2;
            tail = advance(tail);
            l2 = advance(l2);
        }
        return head;
    }
private:
    ListNode* advance(ListNode* l) {
        if (l == nullptr) {
            return l;
        }
        return l->next;
    }
    
    int val(ListNode* l) {
        if (l == nullptr) {
            return 1000;
        }
        return l->val;
    }
};
