package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func mainb() {
	fmt.Println("Go file opt")

	filePath := "./read.rd"
	file, err := os.OpenFile(filePath, os.O_WRONLY|os.O_CREATE, 0666)
	if err != nil {
		fmt.Println("Open file failed")
		return
	}

	defer file.Close()

	str := "Wo cao si ni"
	writer := bufio.NewWriter(file)

	for i := 0; i < 3; i++ {
		writer.WriteString(str)
	}
	writer.Flush()
	fmt.Println("End")

	filer, rerr := os.Open("./read.go")
	if rerr != nil {
		fmt.Println("Open read.go failed")
	}

	defer filer.Close()

	reader := bufio.NewReader(filer)
	for {
		str, err := reader.ReadString('\n')
		if err == io.EOF {
			break
		}
		fmt.Print(str)
	}
	fmt.Println("read end")
}
