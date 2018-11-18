package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	cin := NewReader()
	r := cin.Float()
	n := int((r*1000 + 5) / 10)

	ans := 0
	total := 36000
	for i := 1; i <= 36000; i++ {
		if (total%i) == 0 && (n%(total/i)) == 0 {
			ans = i
			break
		}
	}

	fmt.Println(ans)
}

type Reader struct {
	scanner *bufio.Scanner
	Ended   bool
}

func NewReader() *Reader {
	var reader Reader
	reader.scanner = bufio.NewScanner(os.Stdin)
	reader.scanner.Split(bufio.ScanWords)
	reader.Ended = false
	return &reader
}

func (r *Reader) Int() int {
	tmp := r.Next()
	if !r.Ended {
		res, _ := strconv.Atoi(tmp)
		return res
	}
	return 0
}

func (r *Reader) Float() float64 {
	tmp := r.Next()
	if !r.Ended {
		res, _ := strconv.ParseFloat(tmp, 64)
		return res
	}
	return 0
}

func (r *Reader) IntArray(len int) []int {
	result := make([]int, len)
	for i := 0; i < len; i++ {
		result[i] = r.Int()
	}
	return result
}

func (r *Reader) Next() string {
	if r.scanner.Scan() {
		return r.scanner.Text()
	}
	r.Ended = true
	return ""
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func min64(x, y int64) int64 {
	if x < y {
		return x
	}
	return y
}
