package main

import "fmt"

type point struct {
	X, Y int
}

func main() {
	p := point{
		X: 66,
		Y: 99,
	}

	fmt.Println(p)

	a := new(int)

	fmt.Printf("%T\n", a)

	*a = 999

	fmt.Println(*a)

	msg := &struct {
		id   int
		data string
	}{
		1024,
		"hello",
	}

	printMsgType(msg)

	c := Car{
		Wheel: Wheel{
			Size: 18,
		},

		Engine: Engine{
			Type:  "1.4T",
			Power: 143,
		},
	}

	fmt.Printf("%+v\n", c)

	cl := CarL{
		Wheel: Wheel{
			Size: 18,
		},

		Engine: struct {
			Power int
			Type  string
		}{
			Type:  "1.6T",
			Power: 143,
		},
	}

	fmt.Printf("%+v\n", cl)

}

func printMsgType(msg *struct {
	id   int
	data string
}) {
	fmt.Printf("%T\n", msg)
}

//Cat ...
type Cat struct {
	Color string
	Name  string
}

//BlackCat ..
type BlackCat struct {
	Cat
}

//NewCat ..
func NewCat(name string) *Cat {
	return &Cat{
		Name: name,
	}
}

//NewBlackCat ..
func NewBlackCat(color string) *BlackCat {
	cat := &BlackCat{}
	cat.Color = color
	return cat
}

//NewCatName ..
func NewCatName(name string) *Cat {
	return &Cat{
		Name: name,
	}
}

//NewCatByColor ..
func NewCatByColor(color string) *Cat {
	return &Cat{
		Color: color,
	}
}

//Wheel ..
type Wheel struct {
	Size int
}

//Engine ...
type Engine struct {
	Power int
	Type  string
}

//Car ..
type Car struct {
	Wheel
	Engine
}

//CarL ..
type CarL struct {
	Wheel
	Engine struct {
		Power int
		Type  string
	}
}
