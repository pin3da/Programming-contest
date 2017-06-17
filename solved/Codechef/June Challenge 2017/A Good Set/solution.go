package main

import "fmt"

func solve() {
	ans := make([]int, 0, 501)
	ans = append(ans, 1, 2, 4)
	for len(ans) < 501 {
		ans = append(ans, ans[len(ans)-1]+3)
	}
	var n int
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(ans[i])
	}
	fmt.Println("")
}

func main() {
	var t int
	fmt.Scanf("%d", &t)
	for i := 0; i < t; i++ {
		solve()
	}
}
