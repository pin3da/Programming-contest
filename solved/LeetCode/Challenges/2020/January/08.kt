class Solution {
    fun arrayStringsAreEqual(a: Array<String>, b: Array<String>): Boolean {
        return a.joinToString(separator="") == b.joinToString(separator="")
    }
}
