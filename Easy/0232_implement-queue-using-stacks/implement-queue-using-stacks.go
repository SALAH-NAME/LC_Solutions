package main

type MyQueue struct {
  inStack []int
	outStack []int
}

func Constructor() MyQueue {
  return MyQueue{
		inStack: []int{},
		outStack: []int{},
	}
}

func (this *MyQueue) Push(x int)  {
  this.inStack = append(this.inStack, x)
}

func (this *MyQueue) Pop() int {
	this.move()
	n := len(this.outStack)
	val := this.outStack[n - 1]
	this.outStack = this.outStack[:n - 1]
	return val
}

func (this *MyQueue) Peek() int {
	this.move()
	return this.outStack[len(this.outStack) - 1]
}

func (this *MyQueue) Empty() bool {
  return len(this.inStack) == 0 && len(this.outStack) == 0
}

func (this *MyQueue) move()  {
	if len(this.outStack) == 0 {
		for len(this.inStack) > 0 {
			n := len(this.inStack)
			this.outStack = append(this.outStack, this.inStack[n - 1])
			this.inStack = this.inStack[:n - 1]
		}
	}
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */

func main() {
	var obj MyQueue

	fmt.Printf("obj.Push(1)\n")
	fmt.Printf("obj.Push(2)\n")
	obj.Push(1)
	obj.Push(2)
	fmt.Printf("obj.Peek(): %d\n", obj.Peek())
	fmt.Printf("obj.Pop(): %d\n", obj.Pop())
	fmt.Printf("obj.Empty(): %d\n", obj.Empty())
}
