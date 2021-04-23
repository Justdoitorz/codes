package main

import (
	"encoding/xml"
	"fmt"
	"os"
)

func main() {
	var info []Website
	file, err := os.Open("./info.xml")
	if err != nil {
		fmt.Println("Open failed", err.Error())
		return
	}
	defer file.Close()

	err = xml.NewDecoder(file).Decode(&info)
	if err != nil {
		fmt.Println("Decoder failed", err.Error())
	} else {
		fmt.Println("Decoder success")
		fmt.Println(info)
	}
}
