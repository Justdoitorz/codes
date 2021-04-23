package demo

import (
	"bytes"
	"fmt"
)

func main() {
	fmt.Println(joinString("I ", "Want ", "to ", "Fuck ", "you! ", "Bitch!"))

	print(1, 2, 3.0, "4")

	//	defer recov()
	//panic("sss")

	//fmt.Println("WTC")
}

func joinString(slist ...string) string {
	var b bytes.Buffer
	for _, arg := range slist {
		b.WriteString(arg)
	}

	return b.String()
}

func rawPrint(args ...interface{}) {
	for _, arg := range args {
		fmt.Println(arg)
	}
}

func print(args ...interface{}) {
	rawPrint("fmt", args)
}

//Sum ..
func Sum(up int) int {
	if up > 0 {
		return up + Sum(up-1)
	}
	return 0
}

func recov() {
	err := recover()

	switch err.(type) {
	//case runtime.Error:
	default:
		fmt.Println(err)
	}
	//entry()
}
