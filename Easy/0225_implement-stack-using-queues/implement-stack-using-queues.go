package main

import (
	"fmt"
)

type MyStack struct {
	q []int
}

func Constructor() MyStack {
  return MyStack{q: []int{}}
}

func (this *MyStack) Push(x int)  {
  this.q = append(this.q, x)
	for i := 0; i < len(this.q) - 1; i++ {
		this.q = append(this.q, this.q[0])
		this.q = this.q[1:]
	}
}

func (this *MyStack) Pop() int {
  if len(this.q) == 0 {
		return -1
	}
	val := this.q[0]
	this.q = this.q[1:]
	return val
}

func (this *MyStack) Top() int {
	if len(this.q) == 0 {
		return -1
	}
	return this.q[0]
}

func (this *MyStack) Empty() bool {
  return len(this.q) == 0
}


/**
 * Your MyStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.Empty();
 */

func main() {
	obj := MyStack{}

	fmt.Printf("obj.Push(1)\n")
	obj.Push(1)
	fmt.Printf("obj.Push(2)\n")
	obj.Push(2)
	fmt.Printf("obj.Top(): %d\n", obj.Top())
	fmt.Printf("obj.Pop(): %d\n", obj.Pop())
	fmt.Printf("obj.Empty(): %t\n", obj.Empty())
}
