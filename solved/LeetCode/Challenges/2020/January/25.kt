class Solution {
  fun kLengthApart(nums: IntArray, k: Int): Boolean {
    var posOnes = mutableListOf<Int>()
    for ((i, v) in nums.withIndex()) {
      if (v == 1) {
        posOnes.add(i)
      }
    }
    for (i in 1 until posOnes.size) {
      if (posOnes[i] - posOnes[i - 1] <= k) {
        return false
      }
    }
    return true
  }
}
