package solution

// rob returns the maximum amount of money that can be robbed from a street of
// houses represented by nums, without robbing two adjacent houses.
func rob(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	const (
		skip = 0
		take = 1
	)
	best := make([][2]int, len(nums))
	best[0][take] = nums[0]

	for i := 1; i < len(nums); i++ {
		best[i][skip] = max(best[i-1][skip], best[i-1][take])
		best[i][take] = best[i-1][skip] + nums[i]
	}

	last := best[len(nums)-1]
	return max(last[skip], last[take])
}
