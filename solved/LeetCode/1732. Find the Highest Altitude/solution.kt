class Solution {
  fun largestAltitude(gain: IntArray): Int {
    var cur = 0
    var best = 0
    for (i in gain) { 
      cur += i
      best = best.coerceAtLeast(cur)
    }
    return best
  }
}