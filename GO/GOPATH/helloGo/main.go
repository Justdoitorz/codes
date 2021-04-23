package main

import (
	"fmt"
	"math"
)

//Vertex is pl
type Vertex struct {
	X, Y float64
}

//Abs ...
func (v *Vertex) Abs() float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

func test(x, y int) *int {
	var p *int = &x
	var i = 1
	fmt.Println(p)
	fmt.Println(&i)
	return p
}

func main() {
	fmt.Println("Hello Go!")
	v := &Vertex{Y: 3.0, X: 4.0}
	fmt.Println(v.Abs())
	p := test(1, 2)
	fmt.Println(p)
	*p = 3
	fmt.Println(*p)
}
