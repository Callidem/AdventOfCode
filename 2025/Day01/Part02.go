package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	file, err := os.Open("arq.txt")
	if err != nil {
		fmt.Println("Erro ao abrir o arquivo:", err)
		return
	}
	defer file.Close()
	arq := bufio.NewReader(file)
	clock := 50
	offset := 0
	zeros := 0
	for {
		line, _, err := arq.ReadLine()
		if len(line) > 0 {
			fmt.Printf("Readline: %q\n", line)
		}
		if err != nil {
			break
		}
		offset, _ = strconv.Atoi(string(line[1:]))
		if line[0] == 'L' {
			if clock == 0 {
				zeros--
			}
			clock -= offset
		} else {
			clock += offset
		}
		for clock < 0 {
			clock += 100
			zeros++
		}
		for clock >= 100 {
			clock -= 100
			if clock != 100 {
				zeros++
			}

		}
		if clock == 0 {
			zeros++
		}
		fmt.Printf("Clock: %d\n", clock)

	}
	fmt.Printf("Total de vezes que o clock chegou a zero: %d\n", zeros)
}
