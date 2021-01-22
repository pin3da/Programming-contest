class Solution {
  fun closeStrings(A: String, B: String): Boolean {
    val freqA = A.groupingBy { it }.eachCount()
    val freqB = B.groupingBy { it }.eachCount()
    val keysA = freqA.keys.sorted()
    val keysB = freqB.keys.sorted()
    val valA = freqA.values.sorted()
    val valB = freqB.values.sorted()
    return keysA == keysB && valA == valB
  }
}
