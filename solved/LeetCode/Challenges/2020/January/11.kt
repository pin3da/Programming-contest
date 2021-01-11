class Solution {
  private val inf = 1000_000_000 + 100

  fun merge(A: IntArray, m: Int, B: IntArray, n: Int): Unit {
    for (i in m - 1 downTo 0) {
      A[i + n] = A[i]
    }
    var idA = n
    var idB = 0
    for (i in A.indices) {
      if (get(A, idA) < get(B, idB)) {
        A[i] = A[idA]
        idA++
      } else {
        A[i] = B[idB]
        idB++
      }
    }
  }

  private fun get(arr: IntArray, idx: Int): Int {
    if (idx >= arr.size) {
      return inf
    }
    return arr[idx]
  }
  
