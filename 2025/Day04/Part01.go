package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	file, err := os.Open("data.txt")
	if err != nil {
		fmt.Println("Erro ao abrir o arquivo:", err)
		return
	}
	defer file.Close()
	arq := bufio.NewReader(file)
	var mapa []string
	var adjSum [][]int

	totalSum := 0
	for {
		line, _, err := arq.ReadLine()
		if len(line) > 0 {
			fmt.Printf("Readline: %q\n", line)
			mapa = append(mapa, string(line))
			adjSum = append(adjSum, make([]int, len(line)))
		} else {
			break
		}
		if err != nil {
			break
		}
	}
	for i := 0; i < len(mapa); i++ {
		fmt.Printf("Linha %d: %s\n", i, mapa[i])
		for j := 0; j < len(mapa[i]); j++ {
			if i > 0 {

			}
			if i < len(mapa)-1 {

			}
		}
	}

	fmt.Printf("Total Sum: %d\n", totalSum)
}
