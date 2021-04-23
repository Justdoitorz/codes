package main

import (
	"encoding/json"
	"fmt"
	"os"
)

func main() {
	filePtr, err := os.Open("./info.json")
	if err != nil {
		fmt.Println("Open file failed", err.Error())
		return
	}
	defer filePtr.Close()

	var info []Website
	decoder := json.NewDecoder(filePtr)
	err = decoder.Decode(&info)
	if err != nil {
		fmt.Println("Decoder failed", err.Error())
	} else {
		fmt.Println("Decoder success")
		fmt.Println(info)
	}
}
