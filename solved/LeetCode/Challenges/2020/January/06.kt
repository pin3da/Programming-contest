class Solution {
    fun findKthPositive(arr: IntArray, k: Int): Int {
        var missing = 0
        var cur = 0
        for (i in 1..(arr.size + k)) {
            if (cur < arr.size && arr[cur] == i) {
                cur++
            } else {
                missing++
            }
            if (missing == k) {
                return i
            }
        }
        error("Answer not found")
    }
}
