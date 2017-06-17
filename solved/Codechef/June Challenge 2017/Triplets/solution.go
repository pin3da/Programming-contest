package main

import (
	"fmt"
	"sort"
)

const mod = 1000000007

type sort64 []int64

func (a sort64) Len() int           { return len(a) }
func (a sort64) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a sort64) Less(i, j int) bool { return a[i] < a[j] }

func accumulate(arr []int64) []int64 {
	ans := make([]int64, len(arr), len(arr))
	for i := 0; i < len(arr); i++ {
		ans[i] = arr[i]
		if i > 0 {
			ans[i] = (ans[i-1] + ans[i]) % mod
		}
	}
	return ans
}

func mult(a, b int64) int64 {
	return (a * b) % mod
}

func solve() {
	var p, q, r int
	fmt.Scan(&p, &q, &r)
	p++
	q++
	r++
	A := make([]int64, p, p)
	B := make([]int64, q, q)
	C := make([]int64, r, r)
	for i := 1; i < p; i++ {
		fmt.Scan(&A[i])
	}
	for i := 1; i < q; i++ {
		fmt.Scan(&B[i])
	}
	for i := 1; i < r; i++ {
		fmt.Scan(&C[i])
	}
	A[0] = 0
	B[0] = 0
	C[0] = 0
	sort.Sort(sort64(A))
	sort.Sort(sort64(B))
	sort.Sort(sort64(C))

	acc_x := accumulate(A)
	acc_z := accumulate(C)

	j := 0
	k := 0
	var ans int64 = 0
	for i := 1; i < q; i++ {
		for j < p && A[j] <= B[i] {
			j++
		}
		if j >= p || A[j] > B[i] {
			j--
		}
		for k < r && C[k] <= B[i] {
			k++
		}
		if k >= r || C[k] > B[i] {
			k--
		}
		var tmp int64 = mult(int64(j), int64(k))
		tmp = (((B[i] * B[i]) % mod) * tmp) % mod
		ans = (ans + tmp) % mod
		ans = (ans + mult(B[i], mult(acc_x[j], int64(k)))) % mod
		ans = (ans + mult(B[i], mult(acc_z[k], int64(j)))) % mod
		ans = (ans + (acc_x[j]*acc_z[k])%mod) % mod
	}
	fmt.Println(ans)
}

func main() {
	var t int
	fmt.Scanf("%d", &t)
	for i := 0; i < t; i++ {
		solve()
	}
}
