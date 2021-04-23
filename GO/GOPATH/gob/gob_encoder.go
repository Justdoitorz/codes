package main

import (
	"encoding/gob"
	"fmt"
	"os"
)


func mainb() {
	info := []int{1, 2, 3, 4, 5, 6}

	file, err := os.Create("info.gob") 
	if err != nil {
		fmt.Println("Create failed", err.Error())
		return 
	}
	defer file.Close()

	err = gob.NewEncoder(file).Encode(info) 
	if err != nil {
		fmt.Println("Encoder failed", err.Error())
	} else {
		fmt.Println("Encoder success")
	}
}