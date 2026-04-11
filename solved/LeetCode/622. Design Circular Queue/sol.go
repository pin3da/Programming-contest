type MyCircularQueue struct {
	capacity int
	data     []int
	// where was the first element (inclusive)
	begin int
	// place to put the next element (exclusive)
	end  int
	size int
}

func Constructor(k int) MyCircularQueue {
	return MyCircularQueue{
		capacity: k,
		data:     make([]int, k),
	}
}

func (this *MyCircularQueue) EnQueue(value int) bool {
	if !this.IsFull() {
		this.data[this.end] = value
		this.end = (this.end + 1) % this.capacity
		this.size++
		return true
	}
	return false
}

func (this *MyCircularQueue) DeQueue() bool {
	if this.IsEmpty() {
		return false
	}
	this.begin = (this.begin + 1) % this.capacity
	this.size--
	return true
}

func (this *MyCircularQueue) Front() int {
	if this.IsEmpty() {
		return -1
	}
	return this.data[this.begin]
}

func (this *MyCircularQueue) Rear() int {
	if this.IsEmpty() {
		return -1
	}

	return this.data[(this.end-1+this.capacity)%this.capacity]
}

func (this *MyCircularQueue) IsEmpty() bool {
	return this.size == 0
}

func (this *MyCircularQueue) IsFull() bool {
	return this.size == this.capacity
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * obj := Constructor(k);
 * param_1 := obj.EnQueue(value);
 * param_2 := obj.DeQueue();
 * param_3 := obj.Front();
 * param_4 := obj.Rear();
 * param_5 := obj.IsEmpty();
 * param_6 := obj.IsFull();
 */
