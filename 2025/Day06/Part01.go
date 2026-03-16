package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	file, err := os.Open("data.txt")
	if err != nil {
		fmt.Println("1Erro ao abrir o arquivo:", err)
		return
	}
	defer file.Close()
	arq := bufio.NewReader(file)
	var ops [][]string

	for arq.Scan() {
		line := arq.Text()            // linha inteira
		words := strings.Fields(line) // separa por espaços
		ops = append(ops, words)
	}

}
