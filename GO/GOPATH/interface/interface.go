package main

import "fmt"

//Invoker 是一个调用器接口
type Invoker interface {
	Call(interface{})
}

//Fucker ..
type Fucker interface {
	Fuck(interface{})
}

//Struct 是一个实例
type Struct struct {
	wtf string
}

//Call 是Struct对Invoker中的接口实现
func (s *Struct) Call(p interface{}) {
	fmt.Println("from Struct", p)
}

func (s *Struct) show() {
	fmt.Println("Show")
}

//FuncCaller 函数调用
type FuncCaller func(interface{})

//Call 是...
func (fn FuncCaller) Call(p interface{}) {
	fn(p)
	fmt.Printf("%T\n", p)
}

type fuckyou struct {
	who string
}

func main() {
	var inv, inv2 Invoker
	var ite interface{}
	s := new(Struct)
	ite = s
	fmt.Println(s)
	//fmt.Printf("inv.Call = %p\n", inv.Call)
	//var p *int

	inv = s
	var s1 Struct
	ii := ite.(Invoker)

	ii.Call("bitch")
	fmt.Printf("s.Call = %p\n", s.Call)
	fmt.Printf("&s = %p\n", &s)
	fmt.Printf("s1.Call = %p\n", s1.Call)
	fmt.Printf("&s1 = %p\n", &s1)
	fmt.Printf("inv.Call = %p\n", inv.Call)
	fmt.Printf("&inv = %p\n", &inv)

	fmt.Printf("ii = %p\n", ii)

	fmt.Printf("inv = %p\n", inv)
	in, ok := inv.(Invoker)
	fmt.Printf("in = %p\n", in)
	fmt.Printf("s = %p\n", s)
	fmt.Println(in, "bitch", ok)

	fmt.Printf("%T\n", in)
	//in.
	in.Call("Wtf")
	s.show()

	inv.Call("Hello")

	var t Struct

	inv = &t

	inv.Call("Fule")

	inv = FuncCaller(func(v interface{}) {
		fmt.Println("from Anonymous", v)
	})

	fmt.Printf("inv.. = %p\n", inv)
	fmt.Printf("inv.Call.. = %p\n", inv.Call)

	inv2 = &s1
	fmt.Printf("inv2.. = %p\n", inv2)
	fmt.Printf("inv2.Call.. = %p\n", inv2.Call)
	inv.Call("Bitch")
	inv.Call(12)

	str := "hello world"

	foo := func() {
		str = "hello dude"
	}
	foo()

	fmt.Println(str)

	fn := Accumulate(100)

	for i := 0; i < 10; i++ {
		fmt.Println(fn())
	}

	gn := fn

	fmt.Println(&fn)
	fmt.Println(&gn)

	fmt.Printf("%p\n", fn)
	fmt.Printf("%p\n", gn)

	player := playerGen("Bitch")
	fmt.Println(player())

	myArgs(1, 2, 3, 4, 5)

	var b byte = 'a'

	var a fuckyou

	c := new(fuckyou)

	myArgsInterface(a, b, c, struct {
	}{})
}

//Accumulate closure
func Accumulate(value int) func() int {
	return func() int {
		value++
		return value
	}
}

func playerGen(name string) func() (string, int) {
	hp := 150

	return func() (string, int) {
		return name, hp
	}

}

func myArgs(args ...int) {
	for _, arg := range args {
		fmt.Println(arg)
	}
}

func myArgsInterface(args ...interface{}) {
	for _, arg := range args {
		switch arg.(type) {
		case int8:
		case int16:
		case int32:
		//case rune:
		case int64:
		case float32:
		case float64:
		case string:
		case int:
		case byte:
		//case uint8:
		case complex64:
		case complex128:

		case struct{}:
			fmt.Println("case struct{}:")
		case func():
			fmt.Println("case func():")
		case []int:
			fmt.Println("case []int:")
		case [3]int:
			fmt.Println("case [3]int:")
		case fuckyou:
			fmt.Println("case fuckyou:")
		case *fuckyou:
			fmt.Println("case *fuckyou:")
		}
		fmt.Printf("%T\n", arg)
	}
}
