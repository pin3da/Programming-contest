class Solution {
  fun diagonalSort(mat: Array<IntArray>): Array<IntArray> {
    val rows = mat.size
    val cols = mat[0].size
    
    fun fix(stI: Int, stJ: Int) {
      var i = stI;
      var j = stJ;
      var nums = ArrayDeque<Int>()
      while (i < rows && j < cols) {
        nums.addLast(mat[i][j])
        i++
        j++
      }
      val s = ArrayDeque(nums.sorted())

      j = stJ;
      i = stI;
      while (i < rows && j < cols) {
        mat[i][j] = s.removeFirst()
        i++
        j++
      }
    }
    
    for (i in 0 until rows) {
      fix(i, 0)
    }
    for (i in 1 until cols) {
      fix(0, i)
    }
    return mat
  }
}
