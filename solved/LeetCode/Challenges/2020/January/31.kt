class Solution {
  fun nextPermutation(nums: IntArray): Unit {
    if (nums.size <= 1) {
      return
    }
    var last = nums.size - 2
    while (last >= 0) {
      if (nums[last + 1] > nums[last]) {
        var right = last + 1
        for (i in last + 1 until nums.size) {
          if (nums[i] > nums[last]) {
            right = i
          }
        }
        nums[right] = nums[last]. also {
          nums[last] = nums[right]
        } 
        break
      }
      last--
    }
    println(last)
    nums.reverse(last + 1, nums.size)
  }
}


fun IntArray.reverse(fromIndex: Int, toIndex: Int) {
  var left = fromIndex
  var right = toIndex -1
  while (left < right) {
    this[left] = this[right].also {
      this[right] = this[left]
    }
    left++
    right--
  }
}
