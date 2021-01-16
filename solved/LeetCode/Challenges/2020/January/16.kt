class Solution {
  fun findKthLargest(nums: IntArray, k: Int): Int {
    val sorted = nums.sorted().reversed()
    return sorted[k-1]
  }
}
