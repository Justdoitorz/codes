package main

import (
	"encoding/gob"
	"fmt"
	"os"
)

func main() {
	var info []int

	file, err := os.Open("info.gob")
	if err != nil {
		fmt.Println("Open failed", err.Error())
		return
	}
	defer file.Close()

	err = gob.NewDecoder(file).Decode(&info)
	if err != nil {
		fmt.Println("Decode failed", err.Error())
	} else {
		fmt.Println("Decode success")
		fmt.Println(info)
	}
}
