package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	file, err := os.Open("arq.txt")
	if err != nil {
		fmt.Println("Erro ao abrir o arquivo:", err)
		return
	}
	defer file.Close()
	arq := bufio.NewReader(file)
	const trace = '-'
	const comma = ','
	for {
		line, err := arq.ReadString(trace)
		if len(line) > 0 {
			fmt.Printf("Readline: %q\n", line)
		}
		n1 := 0
		if err != nil {
			break
		}

	}
}
