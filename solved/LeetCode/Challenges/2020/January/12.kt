class Solution {
    fun addTwoNumbers(A: ListNode?, B: ListNode?): ListNode? {
      var l1 = A
      var l2 = B
      var head = ListNode(0)
      var current = head
      var carry = 0
      
      fun canAdd() = l1 != null || l2 != null || carry != 0
    
      while (canAdd()) {
        val here = (l1?.`val` ?: 0) + (l2?.`val` ?: 0) + carry
        current.`val` = here % 10
        carry = here / 10
        l1 = l1?.let { it.next }
        l2 = l2?.let { it.next }
        if (canAdd()) {
          current.next = ListNode(0)
          current = current.next
        }
      }
      
      return head
    }
}
