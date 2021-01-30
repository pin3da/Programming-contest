class Solution {
  fun minimumDeviation(nums: IntArray): Int {
    val s = TreeSet<Int>()
    for (i in nums) {
      s.add(i)
    }

    var best = s.last() - s.first()

    while (isOdd(s.first())) {
      s.add(s.pollFirst() * 2)
      best = Math.min(best, s.last() - s.first())
    }

    while (isEven(s.last())) {
      s.add(s.pollLast() / 2)
      best = Math.min(best, s.last() - s.first())
    }

    return best
  }

  private fun isEven(x: Int): Boolean {
    return (x % 2) == 0
  }

  private fun isOdd(x: Int): Boolean {
    return (x % 2) == 1
  }
}
