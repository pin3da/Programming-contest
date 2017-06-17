package main

import (
	"fmt"
	"math/rand"
	"time"
)

func genRandom(n int) []int {
	arr := make([]int, n, n)
	for i, _ := range arr {
		arr[i] = rand.Intn(1000000000)
	}
	return arr
}

func printSlice(arr []int) {
	for _, val := range arr {
		fmt.Printf("%d ", val)
	}
	fmt.Println("")
}

func main() {
	rand.Seed(time.Now().UTC().UnixNano())
	t := rand.Intn(100)
	fmt.Println(t)
	for i := 0; i < t; i++ {
		A := genRandom(rand.Intn(100000))
		B := genRandom(rand.Intn(100000))
		C := genRandom(rand.Intn(100000))
		fmt.Printf("%d %d %d\n", len(A), len(B), len(C))
		printSlice(A)
		printSlice(B)
		printSlice(C)
	}
}
